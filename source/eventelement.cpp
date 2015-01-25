//
//  eventrobot.cpp
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#include "../include/evrobot.h"


EventElement::EventElement(uint32_t queueEventSize)
{
    mThisCode = 0;
    mCallback = 0;
    mQueue = new MessageQueue(queueEventSize);
}

EventId EventElement::id()
{
    return mId;
}

void EventElement::setCallback(EventNotification * object, EventNotification::Callback callback)
{
    mThisCode = object;
    mCallback = callback;
}

void EventElement::setId(EventId id)
{
    mId = id;
}

MessageQueue * EventElement::queue()
{
    return mQueue;
}

void EventElement::callback(EventMessage * data)
{
    if (mThisCode!=0)
    {
        (mThisCode->*mCallback)(data);
    }
}
