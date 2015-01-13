//
//  eventrobot.cpp
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#include <babcode.h>
#include "../include/evrobot.h"


EventRobot::EventRobot(uint32_t queueEventSize)
{
    mThisCode = 0;
    mCallback = 0;
    mQueue = new Queue<uint32_t>(new uint32_t[queueEventSize], queueEventSize);
}

EventId EventRobot::id()
{
    return mId;
}

void EventRobot::setCallback(EventCode * code, EventCode::Callback callback)
{
    mThisCode = code;
    mCallback = callback;
}

void EventRobot::setId(EventId id)
{
    mId = id;
}

Queue<uint32_t> * EventRobot::queue()
{
    return mQueue;
}

void EventRobot::callback(uint32_t data)
{
    if (mThisCode!=0)
    {
        (mThisCode->*mCallback)(data);
    }
}
