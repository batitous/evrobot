//
//  eventsystem.h
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#ifndef EvRobot_eventsystem_h
#define EvRobot_eventsystem_h


/** The system event interface :
 * - Responsible of start / stop system
 * - update the dispatch event
 *
 */
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
