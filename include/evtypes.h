//
//  evtypes.h
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#ifndef EvRobot_evtypes_h
#define EvRobot_evtypes_h


#define EVENT_ID_INVALID    0   // Event invalid identifier


typedef uint32_t EventId;       // The type for an event



typedef void *  EventData;





/*typedef struct _event_
{
    EventId    id;
    
    //todo
    uint32_t    data;
    //void *      specific;
    //uint32_t    size;
} EventData;
*/



/** You have to inherit this class if you want a callback on an event
 *
 */
class EventCode
{
public:
    typedef void (EventCode::*Callback)(uint32_t data);
    
private:
    
};


#endif
