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

#ifndef EvRobot_evtypes_h
#define EvRobot_evtypes_h


#define EVENT_ID_INVALID    0   // Invalid event identifier


typedef uint32_t EventId;       // The type for an event


// Type of event's data
enum EventDataType
{
    EVENT_DATA_BOOLEAN  = 0,
    EVENT_DATA_INT8     = 1,
    EVENT_DATA_UINT8    = 2,
    EVENT_DATA_INT32    = 3,
    EVENT_DATA_UINT32   = 4,
    EVENT_DATA_FLOAT32  = 5
};


// An event's message
struct EventMessage
{
    EventDataType   type;
    uint32_t        size;
    
    union _value_
    {
        bool        boolean;
        
        uint8_t     unsignedByte;
        int8_t      signedByte;
                
        uint32_t    unsignedInteger;
        int32_t     signedInteger;
        
        float       signedFloat;
        
        void *      rawByteArray;
        
    } value;
  
    
    EventMessage()
    {
    }
    
    ~EventMessage()
    {
    }
    
};



/** You have to inherit this class if you want a callback on an event
 *
 */
class EventNotification
{
public:
    typedef void (EventNotification::*Callback)(EventMessage * data);
    
private:
    
};


#endif
