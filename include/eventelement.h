//
//  eventrobot.h
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#ifndef EvRobot_eventelement_h
#define EvRobot_eventelement_h

/** An event element object;
 * - store the user's callback pointer
 * - store the event queue with message data
 */
class EventElement
{
public:
    EventElement(uint32_t queueEventSize);
    
    EventId id();
    void setCallback(EventNotification * object, EventNotification::Callback callback);
    void setId(EventId id);
    
    void callback(EventMessage * data);
    
    MessageQueue *   queue();
    
    
private:
    EventId                     mId;        // Event's Identifier
    MessageQueue *              mQueue;     // Queue for storing message event
    EventNotification *         mThisCode;  // The this object for the event's callback
    EventNotification::Callback mCallback;  // The callback
};


#endif
