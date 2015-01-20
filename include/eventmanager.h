//
//  eventmanager.h
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#ifndef EvRobot_eventmanager_h
#define EvRobot_eventmanager_h


/** The Event manager object :
 * - register / remove your event
 * - get event posted
 * - post event
 *
 * Warning, this class don't manage synchronization : this object consume 100 % CPU
 * To avoid this, you have to use the EventSystem interface
 */
class EventManager
{
public:
    EventManager(uint32_t queueEventSize);
    ~EventManager();
    
    EventElement * registerEvent(const EventId id, EventNotification * object, EventNotification::Callback callback);
    void removeEvent(const EventId id);
    
    // Post an event with specified data
    void post(const EventId id, uint32_t data);
    void post(const EventId id, float data);
    void post(const EventId id, int32_t data);
    
    // Get the last event identifier posted
    EventId getEventIdPosted();

    // Get the registered event from the specified identifier
    EventElement * getEvent(const EventId id);
    
    
private:
    uint32_t            mQueueSize;     // Number of event maximum
    HashTable           mStores;        // Event storage object
    Queue<EventId> *    mQueue;         // Queue of event posted
};

#endif
