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
    mSynchro = new Synchronizer();
    mStopThread = false;
}


void LocalEventSystem::start()
{
    threadInit(&mThread, LocalEventSystem::privateThreadLauncher, this);
}

void LocalEventSystem::update()
{
    EventId         id;
    EventMessage *   value;
    
    MessageQueue * messageQueue;
    EventRobot * eventRobot = 0;
    
    while(mStopThread==false)
    {
        while (  (id = mEventManager->getEventIdPosted()) != EVENT_ID_INVALID )
        {
            eventRobot = mEventManager->getRobotEvent(id);
            messageQueue = eventRobot->queue();
            
//            printf("Event: %d\r\n", id);
            
            while( (value = messageQueue->read())!=0)
            {
//                printf("\t%d\r\n", value);
                
                
                //todo
                
                eventRobot->callback(value);
                
                delete value;
            }
        }
        
        mSynchro->wait();
        
    }
}

void LocalEventSystem::post(const EventId id, uint32_t data)
{
    mEventManager->post(id, data);
    mSynchro->wakeup();
}

void LocalEventSystem::stop()
{
    mStopThread = true;
    
    // todo wake up thread ?
    
}
