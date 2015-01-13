//
//  evtypes.h
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#ifndef EvRobot_evtypes_h
#define EvRobot_evtypes_h

typedef uint32_t EventId;


#define EVENT_ID_INVALID    0


typedef struct _event_
{
    EventId    id;
    
    //todo
    uint32_t    data;
    //void *      specific;
    //uint32_t    size;
} EventData;


#endif
