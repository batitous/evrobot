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

#include "../include/evrobot.h"


void * LocalEventSystem::privateThreadLauncher(void * p)
{
    LocalEventSystem * s = (LocalEventSystem *)p;
    
    s->update();
    
    return 0;
}

LocalEventSystem::LocalEventSystem(EventManager * m) : EventSystem(m)
{
    mSynchro = new Synchronizer();
    mStopThread = false;
}


void LocalEventSystem::start()
{
    threadInit(&mThread, LocalEventSystem::privateThreadLauncher, this);
}

void LocalEventSystem::update()
{
    EventId         id;
    EventMessage *  value;
    
    MessageQueue *  messageQueue;
    EventElement *  event = 0;
    
    while(mStopThread==false)
    {
        while (  (id = mEventManager->getEventIdPosted()) != EVENT_ID_INVALID )
        {
            event = mEventManager->getEvent(id);
            messageQueue = event->queue();
            
//            printf("Event: %d\r\n", id);
            
            while( (messageQueue->read(&value))!=0)
            {
//                printf("\t%d\r\n", value);
                
                //todo
                
                event->callback(value);
                
            }
        }
        
        mSynchro->wait();
        
    }
}

void LocalEventSystem::post(const EventId id, uint32_t data)
{
    mEventManager->post(id, data);
    mSynchro->wakeup();
}

void LocalEventSystem::post(const EventId id, float data)
{
    mEventManager->post(id, data);
    mSynchro->wakeup();
}

void LocalEventSystem::post(const EventId id, int32_t data)
{
    mEventManager->post(id, data);
    mSynchro->wakeup();
}

void LocalEventSystem::stop()
{
    mStopThread = true;
    
    // todo wake up thread ?
    
}
