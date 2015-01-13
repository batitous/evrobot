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





class Titi : public EventCode
{
public:
    Titi()
    {
        
    }
    
    void event1(uint32_t d)
    {
        printf("Titi:event1 %d\r\n", d);
    }
    
    void event2(uint32_t d)
    {
        
    }
    
private:
    
};


void * toto(void * p)
{
    
    EventManager    * manager = (EventManager *)p;
    while(1)
    {
        manager->post(MY_EVENT2, 345);
        manager->post(MY_EVENT2, 678);
        waitMs(50);
    }
    
    return 0;
}

int main(void)
{
    printf("Test EvRobot !\r\n");
    
    
    Titi            myTiti;
    
    EventManager    manager(32);
    EventRobot *    myRobotEvent1;
    EventRobot *    myRobotEvent2;
    
    // Register 2 events into the manager
    myRobotEvent1 = manager.registerEvent(MY_EVENT1, &myTiti, (EventCode::Callback)&Titi::event1);
    myRobotEvent2 = manager.registerEvent(MY_EVENT2, 0, 0);
    
    
    // Create the local event system with the manager and start it !
    LocalEventSystem localSystem(&manager);
    localSystem.start();
    
    
    Thread t;
    threadInit(&t, toto, &manager);
    
    
    while(1)
    {
        manager.post(MY_EVENT1, 12345);
        waitMs(100);
    }
    
    return 0;
}