//
//  main.cpp
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#include <stdio.h>

#include <babcode.h>

#include "../../include/evrobot.h"


#define MY_EVENT1    1
#define MY_EVENT2    2



class MySystem : public EventSystem
{
public:
    MySystem(EventManager * m) : EventSystem(m)
    {
        
    }
    
    void start()
    {
        threadInit(&thread, MySystem::privateThreadLauncher, this);
    }
    
    
    void update()
    {
        printf("MySystem::update\r\n");
        
        EventId id;
        
        while(1)
        {
            id = mEventManager->waitEvent();
            
            printf("Event: %d\r\n", id);
            
        }
    }
    
    
    void stop()
    {
        
    }
    
    
private:
    Thread thread;
   
    
    static void * privateThreadLauncher(void * p)
    {
        MySystem * s = (MySystem *)p;
        
        s->update();
        
        return 0;
    }
    
};


int main(void)
{
    printf("Test EvRobot !\r\n");
    
    
    EventManager    manager;
    EventRobot      myRobotEvent1;
    EventRobot      myRobotEvent2;
    
    manager.registerEvent(MY_EVENT1, &myRobotEvent1);
    manager.registerEvent(MY_EVENT2, &myRobotEvent2);
    
    
    MySystem system(&manager);
    
    system.start();
    
    while(1)
    {
        manager.post(MY_EVENT1, 12345);
        waitMs(100);
    }
    
    return 0;
}