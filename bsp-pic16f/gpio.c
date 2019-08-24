
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

#include "gpio.h"
#include "xc.h"

void
GPIO_PinDirection(gpioPins_t pin, gpioDirection_t direction)
{
    gpioPort_t port;
    
    port = (pin >> 3); /* Divide the pin number by 8 go get the PORT number */
    pin  = pin & 0x07; /* lower 3-bits contains the bit number of a byte */
    
    switch(port)
    {
        case PA:
            util_UpdateBit(TRISA, pin, direction);
            break;
        
        case PB:
            util_UpdateBit(TRISB, pin, direction);
            break;
            
        case PC:
            util_UpdateBit(TRISC, pin, direction);
            break;
            
        case PD:
            util_UpdateBit(TRISD, pin, direction);
            break;
            
        case PE:
            util_UpdateBit(TRISE, pin, direction);
            break;
            
        default:
            break;
    }
    
}

void
GPIO_PinWrite(gpioPins_t pin, gpioState_t state)
{
    gpioPort_t port;
    
    port = (pin >> 3); /* Divide the pin number by 8 go get the PORT number */
    pin  = pin & 0x07; /* lower 3-bits contains the bit number of a byte */
    
    switch(port)
    {
        case PA:
            util_UpdateBit(PORTA, pin, state);
            break;
        
        case PB:
            util_UpdateBit(PORTB, pin, state);
            break;
            
        case PC:
            util_UpdateBit(PORTC, pin, state);
            break;
            
        case PD:
            util_UpdateBit(PORTD, pin, state);
            break;
            
        case PE:
            util_UpdateBit(PORTE, pin, state);
            break;
            
        default:
            break;
    }
    
}
