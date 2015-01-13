//
//  synchronizer.h
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#ifndef EvRobot_synchronizer_h
#define EvRobot_synchronizer_h

/**
 * A synchronization object for shared value
 */
class Synchronizer
{
public:
    Synchronizer();
    
    /**
     * @brief Wait...
     */
    void wait();
    
    /**
     * @brief Wake up !
     */
    void wakeup();
    
private:
    int32_t         mShared;    /**< shared value between the reader and writer */
    Mutex           mMutex;
    ConditionVar    mCondition;
};


#endif
