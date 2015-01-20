//
//  main.cpp
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#include <stdio.h>

#include <babextended.h>

#include "../../include/evrobot.h"


#define MY_EVENT1    1
#define MY_EVENT2    2





class Titi : public EventNotification
{
public:
    Titi()
    {
        counter = 0;
    }
    
    void event1(EventMessage * d)
    {
       printf("Titi:event1 %d\r\n", d->value.unsignedInteger);
    }
    
    void event2(EventMessage * d)
    {
        if (counter==0)
        {
            begin = getTicks();
        }
        
        counter++;
        
        if (counter==100000)
        {
            printf("Process %d events in %f\n", counter, (float)(getTicks() - begin)/1000.0 );
            counter = 0;
        }
        
//        printf("Titi:event2 %d\r\n", d->data.data);
    }
    
private:
    uint32_t begin;
    uint32_t counter;
    
};


void * toto(void * p)
{
    uint32_t index = 0;
    
//    EventSystem    * system = (EventSystem *)p;
    
    LocalEventSystem * localSystem = EvRobot::localEventSystem();
    
    while(1)
    {
        //system->post(MY_EVENT2, index);
        localSystem->post(MY_EVENT2, index++);

        //waitMs(50);
    }
    
    return 0;
}

int main(void)
{
    printf("Test EvRobot !\r\n");
    
    
    Titi            myTiti;
    
    LocalEventSystem * localSystem = EvRobot::localEventSystem();
    EventManager * manager = localSystem->eventManager();
    
    
    EventElement *    myRobotEvent1;
    EventElement *    myRobotEvent2;
    
    // Register 2 events into the manager
    myRobotEvent1 = manager->registerEvent(MY_EVENT1, &myTiti, (EventNotification::Callback)&Titi::event1);
    myRobotEvent2 = manager->registerEvent(MY_EVENT2, &myTiti, (EventNotification::Callback)&Titi::event2);
    //myRobotEvent3 = manager.registerEvent(MY_EVENT2, &myTiti, (EventCode::Callback)&Titi::event1);
    
    
    // Create the local event system with the manager and start it !
    localSystem->start();
    
    
    Thread t;
    threadInit(&t, toto, &localSystem);
    
    
    while(1)
    {
        localSystem->post(MY_EVENT1, 12345);
        waitMs(100);
    }
    
    return 0;
}