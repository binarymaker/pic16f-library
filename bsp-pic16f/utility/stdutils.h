
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

#ifndef _STD_UTIL_H_
#define  _STD_UTIL_H_


/***************************************************************************************************
    Basic data types
 ***************************************************************************************************/

/**----------char 8-bit--------
     char (-128 to 127)
     signed char (-128 to 127)
     unsigned char (0 - 255)
  -----------------------------*/

/**---------int 16-bit----------
   int (-32768 to 32767)
   signed int (-32768 to 32767)
     unsigned int (0 to 65535)
   -----------------------------*/

typedef signed char     sint8_t;
typedef unsigned char   uint8_t;

typedef signed int      sint16_t;
typedef unsigned int    uint16_t;

typedef signed long int    sint32_t;
typedef unsigned long int  uint32_t;

#define C_SINT8_MAX   0x7F
#define C_SINT8_MIN  -128

#define C_UINT8_MAX   0xFFu
#define C_UINT8_MIN   0x00u

#define C_SINT16_MAX  32767
#define C_SINT16_MIN -32768

#define C_UINT16_MAX  0xFFFFu
#define C_UINT16_MIN  0x00u

#define C_SINT32_MAX  2147483647
#define C_SINT32_MIN -2147483648

#define C_UINT32_MAX  0xFFFFFFFFu
#define C_UINT32_MIN  0x00u
/***************************************************************************************************/



/***************************************************************************************************
                           Definition of common Bit-Masks
 ***************************************************************************************************/
#define  MASK_BIT0   0x0001u
#define  MASK_BIT1   0x0002u
#define  MASK_BIT2   0x0004u
#define  MASK_BIT3   0x0008u
#define  MASK_BIT4   0x0010u
#define  MASK_BIT5   0x0020u
#define  MASK_BIT6   0x0040u
#define  MASK_BIT7   0x0080u
#define  MASK_BIT8   0x0100u
#define  MASK_BIT9   0x0200u
#define  MASK_BIT10  0x0400u
#define  MASK_BIT11  0x0800u
#define  MASK_BIT12  0x1000u
#define  MASK_BIT13  0x2000u
#define  MASK_BIT14  0x4000u
#define  MASK_BIT15  0x8000u
/**************************************************************************************************/





/***************************************************************************************************
                           Port Direction configurations
 ***************************************************************************************************/
#define C_PinOutput_U8     0x00u
#define C_PinInput_U8      0x01u
#define C_PortOutput_U8    0x00u
#define C_PortInput_U8     0xFFu

#define INPUT              C_PinInput_U8
#define OUTPUT             C_PinOutput_U8
#define LOW                0x00u
#define HIGH               0x01u
/**************************************************************************************************/



/***************************************************************************************************
                                Standard Enumerations and Constants
***************************************************************************************************/
typedef enum
{
   FALSE,
   TRUE   
}Boolean_t;


typedef enum
{
    FAILED,
    SUCCESS,
    BUSY,
    TIMEOUT
}Status_t;


typedef enum
{
  BINARY=2,
  DECIMAL = 10,
  HEX = 16
}NumericSystem_t;
/**************************************************************************************************/ 







/***************************************************************************************************
                                Macros for Bit Manipulation
 ****************************************************************************************************/
#define  util_GetBitMask(bit)          (1<<(bit))
#define  util_BitSet(x,bit)            ((x) |=  util_GetBitMask(bit))
#define  util_BitClear(x,bit)          ((x) &= ~util_GetBitMask(bit))
#define  util_BitToggle(x,bit)         ((x) ^=  util_GetBitMask(bit))
#define  util_UpdateBit(x,bit,val)     ((val)? util_BitSet(x,bit): util_BitClear(x,bit))


#define  util_GetBitStatus(x,bit)      (((x)&(util_GetBitMask(bit)))!=0u)
#define  util_IsBitSet(x,bit)          (((x)&(util_GetBitMask(bit)))!=0u)
#define  util_IsBitCleared(x,bit)      (((x)&(util_GetBitMask(bit)))==0u)


#define  util_AreAllBitsSet(x,BitMask) (((x)&(BitMask))==BitMask)
#define  util_AreAnyBitsSet(x,BitMask) (((x)&(BitMask))!=0x00u)
/**************************************************************************************************/





/***************************************************************************************************
                             Macros to find the mod of a number
 ***************************************************************************************************/
#define util_GetMod8(dividend,divisor)  (uint8_t) (dividend - (divisor * (uint8_t) (dividend/divisor)))
#define util_GetMod16(dividend,divisor) (uint16_t)(dividend - (divisor * (uint16_t)(dividend/divisor)))
#define util_GetMod32(dividend,divisor) (uint32_t)(dividend - (divisor * (uint32_t)(dividend/divisor)))
/***************************************************************************************************/





/***************************************************************************************************
                          Macros for Dec2Ascii,Hec2Ascii and Acsii2Hex conversion
 ****************************************************************************************************/
#define util_Dec2Ascii(Dec)   ((Dec)+0x30)
#define util_Ascii2Dec(Asc)   ((Asc)-0x30)
#define util_Hex2Ascii(Hex)  (((Hex)>0x09) ? ((Hex) + 0x37): ((Hex) + 0x30)) 
#define util_Ascii2Hex(Asc)  (((Asc)>0x39) ? ((Asc) - 0x37): ((Asc) - 0x30))
/***************************************************************************************************/





/***************************************************************************************************
                     Macros to extract the nibbles
 ***************************************************************************************************/
#define util_ExtractNibble0to4(x)    (uint8_t) ((x) & 0x0Fu)
#define util_ExtractNibble4to8(x)    (uint8_t) (((x)>>4)  & 0x0Fu)
#define util_ExtractNibble8to12(x)   (uint8_t) (((x)>>8)  & 0x0Fu)
#define util_ExtractNibble12to16(x)  (uint8_t) (((x)>>12) & 0x0Fu)
/**************************************************************************************************/






/***************************************************************************************************
                     Macros to extract the Byte
***************************************************************************************************/
#define util_ExtractByte0to8(x)    (uint8_t) ((x) & 0xFFu)
#define util_ExtractByte8to16(x)   (uint8_t) (((x)>>8) & 0xFFu)
#define util_ExtractByte16to28(x)  (uint8_t) (((x)>>16) & 0xFFu)
#define util_ExtractByte28to32(x)  (uint8_t) (((x)>>28) & 0xFFu)
/**************************************************************************************************/






/***************************************************************************************************
                      Other Macros
***************************************************************************************************/
#define util_GetMax(num1,num2)     (((num1)>(num2))? (num1): (num2)) 
#define util_GetMin(num1,num2)     (((num1)<(num2))? (num1): (num2)) 

#define util_swap(x,y)             (x ^= y ^= x ^= y)
#define util_GetAbsolute(x)         (((x) < 0) ? -(x) : (x))
/**************************************************************************************************/

#endif  

