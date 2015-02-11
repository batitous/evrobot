/*The MIT License (MIT)
 
 Copyright (c) Baptiste Burles, Evotion SAS, 2015
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#include "../../include/evrobot.h"

#include <stdio.h>


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
//       printf("Titi:event1 %d\r\n", d->value.unsignedInteger);
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
    
    
    EventElement *    myRobotEvent1;
    EventElement *    myRobotEvent2;
    
    // Register 2 events into the manager
    myRobotEvent1 = localSystem->registerEvent(MY_EVENT1, &myTiti, (EventNotification::Callback)&Titi::event1);
    myRobotEvent2 = localSystem->registerEvent(MY_EVENT2, &myTiti, (EventNotification::Callback)&Titi::event2);
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