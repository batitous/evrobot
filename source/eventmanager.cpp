//
//  eventmanager.cpp
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#include <babextended.h>
#include "../include/evrobot.h"


#define STORE_DEFAULT_SIZE  32


EventManager::EventManager(uint32_t queueEventSize)
{
    mQueueSize = queueEventSize;
    mQueue = new Queue<uint32_t>(new uint32_t[queueEventSize], queueEventSize);
    hashTableInit(&mStores, STORE_DEFAULT_SIZE);
}

EventManager::~EventManager()
{
}

EventElement * EventManager::registerEvent(const EventId id, EventNotification * object, EventNotification::Callback callback)
{
    EventElement * event = (EventElement *)hashTableLookup(&mStores, id);
    if (event!=0)
    {
        
        
        
        printf("EventManager::registerEvent %d already exists\r\n", id);
        return event;
    }
    
    event = new EventElement(mQueueSize);
    event->setCallback(object, callback);
    event->setId(id);
    
    hashTableInsert(&mStores, id, event);
    
    return event;
}

void EventManager::removeEvent(const EventId id)
{
    hashTableDelete(&mStores, id);
}

EventElement * EventManager::getEvent(const EventId id)
{
    return (EventElement *)hashTableLookup(&mStores, id);
}

void EventManager::post(const EventId id, uint32_t data)
{
    EventElement * e = getEvent(id);
    if (e==0)
    {
        return;
    }
    
    mQueue->write(id);
    e->queue()->writeUint32(data);
}

void EventManager::post(const EventId id, float data)
{
    EventElement * e = getEvent(id);
    if (e==0)
    {
        return;
    }
    
    mQueue->write(id);
    e->queue()->writeFloat(data);
}

void EventManager::post(const EventId id, int32_t data)
{
    EventElement * e = getEvent(id);
    if (e==0)
    {
        return;
    }
    
    mQueue->write(id);
    e->queue()->writeInt32(data);
}

EventId EventManager::getEventIdPosted()
{
    EventId id;
    
    if (mQueue->read(&id)==true)
    {
        return id;
    }
        
    return EVENT_ID_INVALID;
}

