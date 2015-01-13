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


EventManager::EventManager(uint32_t queueEventSize)
{
    mQueueSize = queueEventSize;
    mSynchro = new Synchronizer();
    mQueue = new Queue<uint32_t>(new uint32_t[queueEventSize], queueEventSize);
    hashTableInit(&mStores, STORE_DEFAULT_SIZE);
}

EventManager::~EventManager()
{
}

EventRobot * EventManager::registerEvent(const EventId id, EventCode * code, EventCode::Callback callback)
{
    EventRobot * robotEvent = (EventRobot *)hashTableLookup(&mStores, id);
    if (robotEvent!=0)
    {
        printf("EventManager::registerEvent %d already exists\r\n", id);
        return robotEvent;
    }
    
    robotEvent = new EventRobot(mQueueSize);
    robotEvent->setCallback(code, callback);
    robotEvent->setId(id);
    
    hashTableInsert(&mStores, id, robotEvent);
    
    return robotEvent;
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
    e->queue()->write(data);
    
    mSynchro->wakeup();
}

EventId EventManager::waitAndDispatchEvent()
{
    EventId id;
    
    if (mQueue->read(&id)==true)
    {
        return id;
    }
    
    mSynchro->wait();
    
    if (mQueue->read(&id)==true)
    {
        return id;
    }
    
    return EVENT_ID_INVALID;
}

