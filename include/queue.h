//
//  evqueue.h
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#ifndef EvRobot_evqueue_h
#define EvRobot_evqueue_h


#include <stdint.h>


/**
 * A queue object
 */
template<typename T>
class Queue
{
public:
    
    /**
     * @brief Create a new Queue object
     * @param buffer    Storing's buffer
     * @param size_t    Size of buffer
     */
    Queue<T>(T* buffer, uint32_t size);
    
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
    bool write(T value);
    
    /**
     * @brief Read a value from the queue
     * @param value     Pointer to a value
     * @return false if queue empty
     */
    bool read(T* value);
    
    /** 
     * @brief Read an array of element.
     * Warning : you have to be sure there is enough element to be read with elementNumber
     *
     * @param array     Array where store the element read
     * @param want      Number of element to read
     */
    void read(T *array, uint32_t want);
    
private:
    uint32_t    mHead;  /**< queue head */
    uint32_t    mTail;  /**< queue tail */
    uint32_t    mSize;  /**< queue size */
    T*          mPending;   /**< buffer where store the value */
    
};


#endif
