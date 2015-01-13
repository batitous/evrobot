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
        
        EventId     id;
        uint32_t    value;
        
        Queue<EventId> * queueFromEvent;
        
        while(1)
        {
            id = mEventManager->waitAndDispatchEvent();
            
            if (id!=EVENT_ID_INVALID)
            {
                queueFromEvent = mEventManager->getRobotEvent(id)->queue();
            
                printf("Event: %d\r\n", id);
            
                while(queueFromEvent->read(&value)==true)
                {
                    printf("\t%d\r\n", value);
                    
                    //todo callback ?
                    
                    
                }
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
    
    EventManager    manager;
    EventRobot      myRobotEvent1;
    EventRobot      myRobotEvent2;
    
    manager.registerEvent(MY_EVENT1, &myRobotEvent1);
    manager.registerEvent(MY_EVENT2, &myRobotEvent2);
    
    
    MySystem system(&manager);
    
    system.start();
    
    Thread t;
    
    threadInit(&t, toto, &manager);
    
    while(1)
    {
        manager.post(MY_EVENT1, 12345);
        waitMs(100);
    }
    
    return 0;
}