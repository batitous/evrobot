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
 * - dispatch the event to the user callback
 * - can post event
 *
 */
class EventManager
{
public:
    EventManager(uint32_t queueEventSize);
    ~EventManager();
    
    EventRobot * registerEvent(const EventId id, EventCode * code, EventCode::Callback callback);
    void removeEvent(const EventId id);
    
    void post(const EventId id, uint32_t data);
    
    EventId waitAndDispatchEvent();

    EventRobot * getRobotEvent(const EventId id);
    
    
private:
    uint32_t            mQueueSize;     // Number of event maximum
    HashTable           mStores;        // Robot's event storage object
    Queue<EventId> *    mQueue;         // Queue of event posted
    Synchronizer *      mSynchro;       // Inter-thread synchronization
};

#endif
