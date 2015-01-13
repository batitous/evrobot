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
    
    
    bool registerEvent(const EventId id, const EventRobot & ev);
    
    
    void postEvent(const EventId id);
    void waitEvent(const EventId id);
    
    
    
private:
    HashTable   mStores;
    
    
    
};

#endif
