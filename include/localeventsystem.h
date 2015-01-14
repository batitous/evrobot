//
//  localeventsystem.h
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#ifndef EvRobot_localeventsystem_h
#define EvRobot_localeventsystem_h

/** A local event system on your computer
 *
 */
class LocalEventSystem : public EventSystem
{
public:
    LocalEventSystem(EventManager * m);
    
    void start();
    void update();
    void stop();
    
    void post(const EventId id, uint32_t data);
    
private:
    bool                mStopThread;
    Thread              mThread;
    Synchronizer *      mSynchro;       // Inter-thread synchronization
    
    static void * privateThreadLauncher(void * p);
    
};

#endif
