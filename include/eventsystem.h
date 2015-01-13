//
//  eventsystem.h
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#ifndef EvRobot_eventsystem_h
#define EvRobot_eventsystem_h

class EventSystem
{
public:
    EventSystem(EventManager * em);
    virtual ~EventSystem();
    
    virtual void start() = 0;
    virtual void update() = 0;
    virtual void stop() = 0;
    
protected:
    EventManager*  mEventManager;
};

#endif
