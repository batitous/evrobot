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
    hashTableInit(&mStores, STORE_DEFAULT_SIZE);
}

EventManager::~EventManager()
{
    
}


bool EventManager::registerEvent(const EventId id, EventRobot & ev)
{
    EventRobot * robotEvent = (EventRobot *)hashTableLookup(&mStores, id);
    if (robotEvent!=0)
    {
        printf("EventManager::registerEvent %d already exists\r\n", id);
        return false;
    }
    
    ev.setId(id);
    
    hashTableInsert(&mStores, id, (void *)&ev);
    
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

