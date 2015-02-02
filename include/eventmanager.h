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

#ifndef EvRobot_eventmanager_h
#define EvRobot_eventmanager_h


/** The Event manager object :
 * - register / remove your event
 * - get event posted
 * - post event
 *
 * Warning, this class don't manage synchronization : this object consume 100 % CPU
 * To avoid this, you have to use the EventSystem interface
 */
class EventManager
{
public:
    EventManager(uint32_t queueEventSize);
    ~EventManager();
    
    EventElement * registerEvent(const EventId id, EventNotification * object, EventNotification::Callback callback);
    void removeEvent(const EventId id);
    
    // Post an event with specified data
    void post(const EventId id, uint32_t data);
    void post(const EventId id, float data);
    void post(const EventId id, int32_t data);
    
    // Get the last event identifier posted
    EventId getEventIdPosted();

    // Get the registered event from the specified identifier
    EventElement * getEvent(const EventId id);
    
    
private:
    uint32_t            mQueueSize;     // Number of event maximum
    HashTable           mStores;        // Event storage object
    Queue<EventId> *    mQueue;         // Queue of event posted
};

#endif
