//
//  eventsystem.cpp
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#include <babextended.h>
#include "../include/evrobot.h"


EventSystem::EventSystem(EventManager * em)
{
    mEventManager = em;
}

EventSystem::~EventSystem()
{
}

EventManager * EventSystem::eventManager()
{
    return mEventManager;
}
