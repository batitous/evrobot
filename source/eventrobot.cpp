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
    mQueue = new MessageQueue(queueEventSize);
}

EventId EventRobot::id()
{
    return mId;
}

void EventRobot::setCallback(EventNotification * object, EventNotification::Callback callback)
{
    mThisCode = object;
    mCallback = callback;
}

void EventRobot::setId(EventId id)
{
    mId = id;
}

MessageQueue * EventRobot::queue()
{
    return mQueue;
}

void EventRobot::callback(EventMessage * data)
{
    if (mThisCode!=0)
    {
        (mThisCode->*mCallback)(data);
    }
}
