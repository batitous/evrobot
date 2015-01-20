//
//  messagequeue.cpp
//  EvRobot
//
//  Created by Baptiste on 14/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#include <babextended.h>
#include "../include/evrobot.h"

#define CHECK_QUEUE     uint32_t size = mSize-1; if ( ((mTail+1) & (size)) == ((mHead) & (size)) ){ return false; }

MessageQueue::MessageQueue(uint32_t size)
{
    mHead = 0;
    mTail = 0;
    mSize = size;
    mPending = new EventMessage[size];
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

bool MessageQueue::writeFloat(float value)
{
    CHECK_QUEUE
    
    EventMessage * m = &mPending[mTail & (size)];
    m->size = 0;
    m->value.signedFloat = value;
    mTail++;
    
    return true;
}

bool MessageQueue::writeRawArray(uint8_t * array, uint32_t arraySize)
{
    CHECK_QUEUE
    
    EventMessage * m = &mPending[mTail & (size)];
    m->size = arraySize;
    m->value.rawByteArray = array;
    mTail++;
    
    return true;
}

bool MessageQueue::writeUint32(uint32_t rawValue)
{
    CHECK_QUEUE
    
    EventMessage * m = &mPending[mTail & (size)];
    m->size = 0;
    m->value.unsignedInteger = rawValue;
    mTail++;
    
    return true;
}

bool MessageQueue::writeInt32(int32_t rawValue)
{
    CHECK_QUEUE
    
    EventMessage * m = &mPending[mTail & (size)];
    m->size = 0;
    m->value.signedInteger = rawValue;
    mTail++;
    
    return true;
}

bool MessageQueue::read(EventMessage ** value)
{
    if (mHead == mTail)
    {
        return false;
    }
 
    *value = &mPending[mHead & (mSize-1)];
    mHead++;
    
    return true;
}
