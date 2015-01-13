//
//  localeventsystem.cpp
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#include <babcode.h>
#include "../include/evrobot.h"


void * LocalEventSystem::privateThreadLauncher(void * p)
{
    LocalEventSystem * s = (LocalEventSystem *)p;
    
    s->update();
    
    return 0;
}

LocalEventSystem::LocalEventSystem(EventManager * m) : EventSystem(m)
{
    mStopThread = false;
}


void LocalEventSystem::start()
{
    threadInit(&mThread, LocalEventSystem::privateThreadLauncher, this);
}

void LocalEventSystem::update()
{
    EventId     id;
    uint32_t    value;
    
    Queue<EventId> * queueFromEvent;
    EventRobot * eventRobot;
    
    while(mStopThread==false)
    {
        id = mEventManager->waitAndDispatchEvent();
        
        if (id!=EVENT_ID_INVALID)
        {
            eventRobot = mEventManager->getRobotEvent(id);
            queueFromEvent = eventRobot->queue();
            
            printf("Event: %d\r\n", id);
            
            while(queueFromEvent->read(&value)==true)
            {
                printf("\t%d\r\n", value);
                
                eventRobot->callback(value);
                
            }
        }
        
    }
}

void LocalEventSystem::stop()
{
    mStopThread = true;
    
    // todo wake up thread ?
    
}
