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


#define MY_EVENT    1



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
        
        EventRobot * myRobotEvent = mEventManager->getRobotEvent(MY_EVENT);
        
        while(1)
        {
            if (myRobotEvent->get()==true)
            {
                printf("Event receveid !\r\n");
            }
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
    EventRobot      myRobotEvent;
    
    
    manager.registerEvent(MY_EVENT, myRobotEvent);
    manager.registerEvent(MY_EVENT, myRobotEvent);
    
    
    MySystem system(&manager);
    
    system.start();
    
    while(1)
    {
        myRobotEvent.post();
        waitMs(100);
    }
    
    return 0;
}