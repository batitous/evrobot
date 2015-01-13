//
//  eventrobot.h
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#ifndef EvRobot_eventrobot_h
#define EvRobot_eventrobot_h

#define EVENT_QUEUE_SIZE       32


class EventRobot
{
public:
    EventRobot();
    
    EventId id();
    void setId(EventId id);
    
    void post(uint32_t data);
    bool get();
    
    
private:
    EventId                 mId;
    Queue<uint32_t> *       mQueue;
};


#endif
