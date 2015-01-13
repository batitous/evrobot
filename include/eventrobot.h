//
//  eventrobot.h
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#ifndef EvRobot_eventrobot_h
#define EvRobot_eventrobot_h


class EventRobot
{
public:
    EventRobot();
    
    void setId(EventId id);
    
    void post();
    bool get();
    
    
private:
    EventId                 mId;
    Queue<EventData> *      mQueue;
    Synchronizer *          mSynchro;
};


#endif
