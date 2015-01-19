//
//  evrobot.h
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#ifndef EvRobot_evrobot_h
#define EvRobot_evrobot_h

#include <babextended.h>

#include "evtypes.h"
#include "queue.h"
#include "messagequeue.h"
#include "synchronizer.h"
#include "eventrobot.h"
#include "eventmanager.h"
#include "eventsystem.h"
#include "localeventsystem.h"

class EvRobot
{
public:
    static LocalEventSystem * localEventSystem();
    
    
private:
    static EventManager *          mLocalManager;
    static LocalEventSystem *      mLocalEventSystem;
    
};


#endif
