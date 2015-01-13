//
//  eventrobot.cpp
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#include <babcode.h>
#include "../include/evrobot.h"

#define EVENT_ID_SIZE       32


EventRobot::EventRobot()
{
    mSynchro = new Synchronizer();
    mQueue = new Queue<EventData>(new EventData[EVENT_ID_SIZE], EVENT_ID_SIZE);
}

void EventRobot::setId(EventId id)
{
    mId = id;
}


void EventRobot::post()
{
    EventData e;
    
    e.id = mId;
    e.data = 0;
    
    mQueue->write(e);
    mSynchro->wakeup();
}

bool EventRobot::get()
{
    
    mSynchro->wait();
    
    EventData e;
    return mQueue->read(&e);
}
