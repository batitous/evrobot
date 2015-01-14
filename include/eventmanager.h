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
    
    EventRobot * registerEvent(const EventId id, EventNotification * object, EventNotification::Callback callback);
    void removeEvent(const EventId id);
    
    void post(const EventId id, uint32_t data);
    
    EventId getEventIdPosted();

    EventRobot * getRobotEvent(const EventId id);
    
    
private:
    uint32_t            mQueueSize;     // Number of event maximum
    HashTable           mStores;        // Robot's event storage object
    Queue<EventId> *    mQueue;         // Queue of event posted
};

#endif
