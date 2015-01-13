//
//  evrobot.h
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#ifndef EvRobot_evrobot_h
#define EvRobot_evrobot_h


typedef uint32_t EventId;


typedef struct _event_
{
    EventId    id;
    
    //todo
    uint32_t    data;
    void *      specific;
    uint32_t    size;
} EventRobot;


#include "eventmanager.h"




#endif
