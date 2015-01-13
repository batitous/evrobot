//
//  eventmanager.cpp
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#include <babcode.h>
#include "../include/evrobot.h"


#define STORE_DEFAULT_SIZE  32


EventManager::EventManager()
{
    mSynchro = new Synchronizer();
    mQueue = new Queue<uint32_t>(new uint32_t[EVENT_QUEUE_SIZE], EVENT_QUEUE_SIZE);
    hashTableInit(&mStores, STORE_DEFAULT_SIZE);
}

EventManager::~EventManager()
{
    
}


bool EventManager::registerEvent(const EventId id, EventRobot * ev)
{
    EventRobot * robotEvent = (EventRobot *)hashTableLookup(&mStores, id);
    if (robotEvent!=0)
    {
        printf("EventManager::registerEvent %d already exists\r\n", id);
        return false;
    }
    
    ev->setId(id);
    
    hashTableInsert(&mStores, id, ev);
    
    return true;
}

void EventManager::removeEvent(const EventId id)
{
    hashTableDelete(&mStores, id);
}

EventRobot * EventManager::getRobotEvent(const EventId id)
{
    return (EventRobot *)hashTableLookup(&mStores, id);
}

void EventManager::post(const EventId id, uint32_t data)
{
    EventRobot * e = getRobotEvent(id);
    if (e==0)
    {
        return;
    }
    
    mQueue->write(id);
    e->post(data);
    
    mSynchro->wakeup();
}

EventId EventManager::waitEvent()
{
    mSynchro->wait();
    
    EventId id;
    if (mQueue->read(&id)==false)
    {
        printf("EventManager::waitEvent id queue empty !\r\n");
        return EVENT_ID_INVALID;
    }
    
    EventRobot * e = getRobotEvent(id);
    
    if (e->get()==false)
    {
        printf("EventManager::waitEvent data queue empty !\r\n");
        return EVENT_ID_INVALID;
    }
    
    return id;
}

