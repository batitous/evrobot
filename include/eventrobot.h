//
//  eventrobot.h
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#ifndef EvRobot_eventrobot_h
#define EvRobot_eventrobot_h

#define EVENT_QUEUE_SIZE       32




class EventRobot
{
public:
    EventRobot();
    
    EventId id();
    void setCallback(EventCode * code, EventCode::Callback callback);
    void setId(EventId id);
    
    void callback(uint32_t data);
    
    Queue<uint32_t> *   queue();
    
    
private:
    EventId                     mId;        // Event's Identifier
    Queue<uint32_t> *           mQueue;     // Queue for storing data event
    EventCode *                 mThisCode;  // The this object for the event's callback
    EventCode::Callback         mCallback;  // The callback
};


#endif
