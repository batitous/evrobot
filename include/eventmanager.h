//
//  eventmanager.h
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#ifndef EvRobot_eventmanager_h
#define EvRobot_eventmanager_h


class EventManager
{
public:
    EventManager();
    ~EventManager();
    
    bool registerEvent(const EventId id, EventRobot * ev);
    void removeEvent(const EventId id);
    
    void post(const EventId id, uint32_t data);
    EventId waitEvent();
    
    
private:
    HashTable           mStores;
    Queue<EventId> *    mQueue;
    Synchronizer *      mSynchro;
    
    EventRobot * getRobotEvent(const EventId id);
};

#endif
