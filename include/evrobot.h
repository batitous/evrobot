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
#include "eventelement.h"
#include "eventmanager.h"
#include "eventsystem.h"
#include "localeventsystem.h"


/** The global robot event object
 */
class EvRobot
{
public:

    // get a singleton of the local event system
    static LocalEventSystem * localEventSystem();
    
    
private:
    static EventManager *          mLocalManager;
    static LocalEventSystem *      mLocalEventSystem;
    
};


#endif
