//
//  synchronizer.cpp
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#include <babcode.h>
#include "../include/synchronizer.h"


Synchronizer::Synchronizer()
{
    mShared = 0;
    mutexInit(&mMutex);
    conditionVarInit(&mCondition);
}

void Synchronizer::wait()
{
    mutexLock(&mMutex);
    while(!mShared)
    {
        conditionVarWait(&mCondition, &mMutex);
    }
    
    mShared = 0;
    mutexUnlock(&mMutex);
}

void Synchronizer::wakeup()
{
    mutexLock(&mMutex);
    mShared = 1;
    conditionVarSignal(&mCondition);
    mutexUnlock(&mMutex);
}
