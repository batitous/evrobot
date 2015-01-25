//
//  evrobot.cpp
//  EvRobot
//
//  Created by Baptiste on 19/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#include "../include/evrobot.h"

EventManager *          EvRobot::mLocalManager = 0;
LocalEventSystem *      EvRobot::mLocalEventSystem = 0;


LocalEventSystem * EvRobot::localEventSystem()
{
    if (mLocalEventSystem==0)
    {
        mLocalManager = new EventManager(32);
        mLocalEventSystem = new LocalEventSystem(mLocalManager);
    }
    
    return mLocalEventSystem;
}
