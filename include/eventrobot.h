//
//  eventrobot.h
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#ifndef EvRobot_eventrobot_h
#define EvRobot_eventrobot_h

/** The robot event object;
 * - store the user's callback pointer
 * - the event queue with event data
 */
class EventRobot
{
public:
    EventRobot(uint32_t queueEventSize);
    
    EventId id();
    void setCallback(EventNotification * object, EventNotification::Callback callback);
    void setId(EventId id);
    
    void callback(EventMessage * data);
    
    MessageQueue *   queue();
    
    
private:
    EventId                     mId;        // Event's Identifier
    MessageQueue *              mQueue;     // Queue for storing data event
    EventNotification *         mThisCode;  // The this object for the event's callback
    EventNotification::Callback mCallback;  // The callback
};


#endif
