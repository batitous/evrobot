//
//  messagequeue.cpp
//  EvRobot
//
//  Created by Baptiste on 14/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#include <babcode.h>
#include "../include/evrobot.h"


MessageQueue::MessageQueue(uint32_t size)
{
    mHead = 0;
    mTail = 0;
    mSize = size;
    mPending = new EventMessage *[size];
}

void MessageQueue::reset()
{
    mHead = 0;
    mTail = 0;
}

uint32_t MessageQueue::elementNumber()
{
    return mTail - mHead;
}

bool MessageQueue::write(EventMessage * value)
{
    uint32_t size = mSize-1;
    if ( ((mTail+1) & (size)) == ((mHead) & (size)) )
    {
        return false;
    }
    
    mPending[mTail & (size)] = value;
    mTail++;
    
    return true;
}

EventMessage* MessageQueue::read()
{
    if (mHead == mTail)
    {
        return 0;
    }
 
    EventMessage * message;
    
    message = mPending[mHead & (mSize-1)];
    mHead++;
    
    return message;
}
