/*The MIT License (MIT)
 
 Copyright (c) Baptiste Burles, Evotion SAS, 2015
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

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
