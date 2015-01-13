//
//  eventrobot.cpp
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#include <babcode.h>
#include "../include/evrobot.h"


EventRobot::EventRobot()
{
    mQueue = new Queue<uint32_t>(new uint32_t[EVENT_QUEUE_SIZE], EVENT_QUEUE_SIZE);
}

EventId EventRobot::id()
{
    return mId;
}

void EventRobot::setId(EventId id)
{
    mId = id;
}

Queue<uint32_t> * EventRobot::queue()
{
    return mQueue;
}
