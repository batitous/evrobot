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

#define UDP_EVENT_PROTOCOL_ID   0xBABADEAD


void * LocalEventSystem::privateThreadLauncher(void * p)
{
    LocalEventSystem * s = (LocalEventSystem *)p;
    
    s->update();
    
    return 0;
}

LocalEventSystem::LocalEventSystem() : EventSystem()
{
    mStopThread = false;
    
    mBuffer = new uint8_t[UDP_CONNECTION_PACKET_DATA_MAX];
    mStream = newByteStream(mBuffer, UDP_CONNECTION_PACKET_DATA_MAX);
    
    mConnection = new UdpConnection(UDP_EVENT_PROTOCOL_ID);
}

void LocalEventSystem::connect(const IpAddress * address)
{
    mConnection->connect(address);
}

void LocalEventSystem::start()
{
    threadInit(&mThread, LocalEventSystem::privateThreadLauncher, this);
}

void LocalEventSystem::update()
{
    EventId         id;
    EventMessage    value;
    int32_t         size;
    EventElement *  event;
    
    uint8_t * packet = new uint8_t[UDP_CONNECTION_PACKET_DATA_MAX];
    ByteStream * stream = newByteStream(packet, UDP_CONNECTION_PACKET_DATA_MAX);
    
    
    mConnection->start(CONNECTION_EVENT_REMOTE_PORT);
    
    
    while(mStopThread==false)
    {
        size = mConnection->waitAndReceive(packet, UDP_CONNECTION_PACKET_DATA_MAX);
        
        if (size > 0)
        {
            resetByteStream(stream);
            id = read32BitsFromStream(stream);
            value.type = read32BitsFromStream(stream);
            value.value.unsignedInteger = read32BitsFromStream(stream);
            
            event = getEvent(id);
            if (event!=0)
            {
                event->callback(&value);
            }
        }
    }
}

void LocalEventSystem::sendEvent(const EventId id, EventDataType type, uint32_t data)
{
    EventElement * e = getEvent(id);
    if (e==0)
    {
        return;
    }

    resetByteStream(mStream);
    write32BitsToStream(mStream, id);
    write32BitsToStream(mStream, id);
    write32BitsToStream(mStream, data);
    
    mConnection->send(mStream->buffer, getByteStreamSize(mStream));
}

void LocalEventSystem::post(const EventId id, uint32_t data)
{
    sendEvent(id, EVENT_DATA_UINT32, (uint32_t)data);
}

void LocalEventSystem::post(const EventId id, float data)
{
    sendEvent(id, EVENT_DATA_FLOAT32, (uint32_t)data);
}

void LocalEventSystem::post(const EventId id, int32_t data)
{
    sendEvent(id, EVENT_DATA_INT32, (uint32_t)data);
}

void LocalEventSystem::stop()
{
    mStopThread = true;
    
    // todo wake up thread ?
    
}
