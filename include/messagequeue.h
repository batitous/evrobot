//
//  messagequeue.h
//  EvRobot
//
//  Created by Baptiste on 14/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

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
    bool write(EventMessage * value);
    
    /**
     * @brief Read a value from the queue
     * @param value     Pointer to a value
     * @return false if queue empty
     */
    EventMessage * read();
    
private:
    uint32_t        mHead;  /**< queue head */
    uint32_t        mTail;  /**< queue tail */
    uint32_t        mSize;  /**< queue size */
    EventMessage**  mPending;   /**< buffer where store the value */
    
};


#endif
