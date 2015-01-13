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
    
private:
    bool    mStopThread;
    Thread  mThread;
    
    static void * privateThreadLauncher(void * p);
    
};

#endif
