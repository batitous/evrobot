//
//  evqueue.cpp
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#include "../include/queue.h"



template <typename T>
Queue<T>::Queue(T* buffer, uint32_t size)
{
    mHead = 0;
    mTail = 0;
    mSize = size;
    mPending = buffer;
}

template <typename T>
void Queue<T>::reset()
{
    mHead = 0;
    mTail = 0;
}

template <typename T>
uint32_t Queue<T>::elementNumber()
{
    return mTail - mHead;
}

template <typename T>
bool Queue<T>::write(T value)
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

template <typename T>
bool Queue<T>::read(T* value)
{
    if (mHead == mTail)
    {
        return false;
    }
    
    *value= mPending[mHead & (mSize-1)];
    mHead++;
    
    return true;
}

template <typename T>
void Queue<T>::read(T *array, uint32_t want)
{
    T * ptr = array;
    uint32_t size = mSize -1;
    for(uint32_t i=0;i<want;i++)
    {
        *ptr = mPending[mHead & (size)];
        ptr++;
        mHead++;
    }
}


template Queue<uint8_t>::Queue(uint8_t * buffer, uint32_t size);
template void Queue<uint8_t>::reset();
template uint32_t Queue<uint8_t>::elementNumber();
template bool Queue<uint8_t>::write(uint8_t value);
template bool Queue<uint8_t>::read(uint8_t* value);
template void Queue<uint8_t>::read(uint8_t *array, uint32_t want);

template Queue<uint16_t>::Queue(uint16_t * buffer, uint32_t size);
template void Queue<uint16_t>::reset();
template uint32_t Queue<uint16_t>::elementNumber();
template bool Queue<uint16_t>::write(uint16_t value);
template bool Queue<uint16_t>::read(uint16_t* value);
template void Queue<uint16_t>::read(uint16_t *array, uint32_t want);

template Queue<uint32_t>::Queue(uint32_t * buffer, uint32_t size);
template void Queue<uint32_t>::reset();
template uint32_t Queue<uint32_t>::elementNumber();
template bool Queue<uint32_t>::write(uint32_t value);
template bool Queue<uint32_t>::read(uint32_t* value);
template void Queue<uint32_t>::read(uint32_t *array, uint32_t want);



#include "evtypes.h"

template Queue<EventData>::Queue(EventData * buffer, uint32_t size);
template void Queue<EventData>::reset();
template uint32_t Queue<EventData>::elementNumber();
template bool Queue<EventData>::write(EventData value);
template bool Queue<EventData>::read(EventData* value);
template void Queue<EventData>::read(EventData *array, uint32_t want);
