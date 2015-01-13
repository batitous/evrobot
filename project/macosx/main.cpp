//
//  main.cpp
//  EvRobot
//
//  Created by Baptiste on 13/01/2015.
//  Copyright (c) 2015 Evotion. All rights reserved.
//

#include <stdio.h>

#include <babcode.h>

#include "../../include/evrobot.h"




int main(void)
{
    
    
    
    printf("Test EvRobot !\r\n");
    
    
    EventManager manager;
    
    EventRobot myEvent;
    
    
    
    manager.registerEvent(1, myEvent);
    manager.registerEvent(1, myEvent);
    
    
    
    return 0;
}