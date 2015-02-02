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

#ifndef EvRobot_messagequeue_h
#define EvRobot_messagequeue_h

class MessageQueue
{
public:
    
    /**
     * @brief Create a new message queue object
     * @param size_t    Size of buffer
     */
    MessageQueue(uint32_t size);
    
    /**
     * @brief Reset the internal state of the queue
     */
    void reset();
    
    /**
     * @brief Get number of element in queue
     * @return
     */
    uint32_t elementNumber();
    
    
    /**
     * @brief Write a value into the queue
     * @param value     Value to be written
     * @return False if queue full
     */
    bool writeUint32(uint32_t value);
    bool writeInt32(int32_t value);
    bool writeFloat(float value);
    bool writeRawArray(uint8_t * ptr, uint32_t size);
    
    
    /**
     * @brief Read a value from the queue
     * @param value     Pointer to a value
     * @return false if queue empty
     */
    bool read(EventMessage ** value);
    
private:
    uint32_t        mHead;  /**< queue head */
    uint32_t        mTail;  /**< queue tail */
    uint32_t        mSize;  /**< queue size */
    EventMessage *  mPending;   /**< buffer where store the value */
    
};


#endif
