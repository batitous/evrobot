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

#include <stdio.h>

#define STORE_DEFAULT_SIZE  32


EventSystem::EventSystem()
{
    hashTableInit(&mStores, STORE_DEFAULT_SIZE);
}

EventSystem::~EventSystem()
{
}

EventElement * EventSystem::registerEvent(const EventId id, EventNotification * object, EventNotification::Callback callback)
{
    EventElement * event = (EventElement *)hashTableLookup(&mStores, id);
    if (event!=0)
    {
        printf("EventManager::registerEvent %d already exists\r\n", id);
        return event;
    }
    
    event = new EventElement();
    event->setCallback(object, callback);
    event->setId(id);
    
    hashTableInsert(&mStores, id, event);
    
    return event;
}

void EventSystem::removeEvent(const EventId id)
{
    hashTableDelete(&mStores, id);
}

EventElement * EventSystem::getEvent(const EventId id)
{
    return (EventElement *)hashTableLookup(&mStores, id);
}

