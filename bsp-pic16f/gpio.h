
/**
  ******************************************************************************
  * ______  _                             ___  ___        _               
  * | ___ \(_)                            |  \/  |       | |              
  * | |_/ / _  _ __    __ _  _ __  _   _  | .  . |  __ _ | | __ ___  _ __ 
  * | ___ \| || '_ \  / _` || '__|| | | | | |\/| | / _` || |/ // _ \| '__|
  * | |_/ /| || | | || (_| || |   | |_| | | |  | || (_| ||   <|  __/| |   
  * \____/ |_||_| |_| \__,_||_|    \__, | \_|  |_/ \__,_||_|\_\\___||_|   
  *                                 __/ |                                 
  *                                |___/                                  
  *                                                                       
  * Copyright (C) 2019 Binary Maker - All Rights Reserved
  *
  * This program and the accompanying materials are made available
  * under the terms described in the LICENSE file which accompanies
  * this distribution.
  * Written by Binary Maker <https://github.com/binarymaker>
  ******************************************************************************
  */

#ifndef PIC16F_BSP_3efe6aca_c68b_11e9_96c0_6eadeaa124f7
#define PIC16F_BSP_3efe6aca_c68b_11e9_96c0_6eadeaa124f7

#include "utility/stdutils.h"

typedef enum
{
    PA0,PA1,PA2,PA3,PA4,PA5,PA6,PA7,
    PB0,PB1,PB2,PB3,PB4,PB5,PB6,PB7,
    PC0,PC1,PC2,PC3,PC4,PC5,PC6,PC7,
    PD0,PD1,PD2,PD3,PD4,PD5,PD6,PD7,
    PE0,PE1,PE2,PE3,PE4,PE5,PE6,PE7,
    PNC = 0xff
}gpioPins_t;

typedef enum
{
    PA,
    PB,
    PC,
    PD,
    PE
}gpioPort_t;

typedef enum
{
    GPIO_OUTPUT,
    GPIO_INPUT
}gpioDirection_t;

typedef enum
{
    GPIO_RESET,
    GPIO_SET
}gpioState_t;

void
GPIO_PinDirection(gpioPins_t pin, gpioDirection_t direction);

void
GPIO_PinWrite(gpioPins_t pin, gpioState_t state);

gpioState_t
GPIO_PinRead(gpioPins_t pin);

void
GPIO_PortWrite(gpioPort_t port, uint8_t value);

uint8_t
GPIO_PortRead(gpioPort_t port);

#endif // PIC16F_BSP_3efe6aca_c68b_11e9_96c0_6eadeaa124f7
