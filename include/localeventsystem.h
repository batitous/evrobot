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
#ifndef EvRobot_localeventsystem_h
#define EvRobot_localeventsystem_h


#define CONNECTION_EVENT_LOCAL_PORT     21789
#define CONNECTION_EVENT_REMOTE_PORT    21788



/** A local event system that can be extended on the local network
 *
 */
class LocalEventSystem : public EventSystem
{
public:
    LocalEventSystem();
    
    // Set the remote address of a remote event system
    void setRemoteAddress(const IpAddress * address);
    
    // Start the event system on the local network
    void startListenOnNetwork();
    
    void start();
    void update();
    void stop();
    
    void post(const EventId id, uint32_t data);
    void post(const EventId id, float data);
    void post(const EventId id, int32_t data);
    
private:
    bool                mStopThread;
    Thread              mThread;
    UdpConnection *     mConnection;
    uint8_t *           mBuffer;
    ByteStream *        mStream;
    IpAddress           mLocalIp;
    IpAddress           mRemoteIp;
    
    void dispatchLoop(UdpConnection * connection, uint16_t port);
    void sendEvent(const EventId id, EventDataType type, uint32_t data);
    
    static void * privateThreadLauncher(void * p);
    
    void threadRemote(void);
    static void * privateThreadRemoteLauncher(void *p);
    
};

#endif
