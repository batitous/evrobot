//
//  evtypes.h
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#ifndef EvRobot_evtypes_h
#define EvRobot_evtypes_h


#define EVENT_ID_INVALID    0   // Invalid event identifier


typedef uint32_t EventId;       // The type for an event


struct EventMessage
{
    uint32_t    type;
    uint32_t    size;
    
    union _value_
    {
        bool        boolean;
        
        uint8_t     unsignedByte;
        int8_t      signedByte;
        
        uint16_t    unsignedShort;
        int16_t     signedShort;
        
        uint32_t    unsignedInteger;
        int32_t     signedInteger;
        
        float       signedFloat;
        
        void *      rawByteArray;
        
    } value;
  
    
    EventMessage()
    {
    }
    
    ~EventMessage()
    {
    }
    
};



/** You have to inherit this class if you want a callback on an event
 *
 */
class EventNotification
{
public:
    typedef void (EventNotification::*Callback)(EventMessage * data);
    
private:
    
};


#endif
