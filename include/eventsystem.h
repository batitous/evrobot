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

#ifndef EvRobot_eventsystem_h
#define EvRobot_eventsystem_h


/** The system event interface :
 * - Register and retrieve event element
 * - Responsible of start / stop system
 * - update the dispatch event loop
 *
 */
class EventSystem
{
public:
    EventSystem();
    virtual ~EventSystem();
    
    // Register a new event with the specified user object and callback
    EventElement * registerEvent(const EventId id, EventNotification * object, EventNotification::Callback callback);

    void removeEvent(const EventId id);
    
    // Get the registered event from the specified identifier
    EventElement * getEvent(const EventId id);
    
    
    
    virtual void start() = 0;
    virtual void update() = 0;
    virtual void stop() = 0;
    
    virtual void post(const EventId id, uint32_t data) = 0;
    virtual void post(const EventId id, int32_t data) = 0;
    virtual void post(const EventId id, float data) = 0;
    
protected:
    
    HashTable           mStores;        // Event storage object
    
};

#endif
