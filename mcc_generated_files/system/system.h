/**
 * System Driver Header File
 * 
 * @file system.h
 * 
 * @defgroup systemdriver System Driver
 * 
 * @brief This file contains the API prototypes for the System driver.
 *
 * @version Driver Version 1.0.1
*/
/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/


#ifndef MCC_H
#define	MCC_H



#include "../system/utils/compiler.h"
#include "config_bits.h"
#include "../system/clock.h"
#include "../system/pins.h"
#include "../adc/adc0.h"
#include "../evsys/evsys.h"
#include "../timer/rtc.h"
#include "../vref/vref.h"
#include "../system/interrupt.h"
    
#include "xc.h"
#include "stdio.h"     


/* define output values in a structure*/
struct OutputStates
{
        /*Led boolean value and blink value and duration*/
    bool LEDSysState;                   /*Indicate the desired LED state */
    unsigned int LEDSysBlinkRatio;      /*generic blink duration ratio, in % */    
    bool LEDSysBlinkCodeWanted;         /*indicates a code will be displayed */
    unsigned int LEDSysBlinkCode;       /*contain the blink cnt */
    
    bool LEDTemp1State;                 /*Indicate the desired LED state */
    unsigned int LEDTemp1BlinkRatio;    /*generic blink duration ratio, in % */ 
    bool LEDTemp1BlinkCodeWanted;       /*indicates a code will be displayed */
    unsigned int LEDTemp1BlinkCode;     /*contain the blink cnt */
 
    bool LEDTemp2State;                 /*Indicate the desired LED state */
    unsigned int LEDTemp2BlinkRatio;    /*generic blink duration ratio, in % */ 
    bool LEDTemp2BlinkCodeWanted;       /*indicates a code will be displayed */
    unsigned int LEDTemp2BlinkCode;     /*contain the blink cnt */
    
    bool LEDAubeState;                  /*Indicate the desired LED state */
    unsigned int LEDAubeBlinkRatio;     /*generic blink duration ratio, in % */
    bool LEDAubeBlinkCodeWanted;        /*indicates a code will be displayed */
    unsigned int LEDAubeBlinkCode;      /*contain the blink cnt */

    bool LEDCrepState;                  /*Indicate the desired LED state */
    unsigned int LEDCrepBlinkRatio;     /*generic blink duration ratio, in % */
    bool LEDCrepBlinkCodeWanted;        /*indicates a code will be displayed */
    unsigned int LEDCrepBlinkCode;      /*contain the blink cnt */


        /*Dry relays cmd*/
    bool CMDRelDry1Command;             /*0 = OFF, 1 = ON*/
    bool CMDRelDry2Command;             /*0 = OFF, 1 = ON*/

        /*actuator relay control*/
    int RelaySequence;                  /*0 = nothing, 1 = close, 2 = open */
    bool CMDRelCommand;                 /*0 = OFF, 1 = ON*/
    int CMDRelDirection ;               /*0= nothing, 1 = UP, 2 =  down */
    int MotorErrorFlags ;               
};

    
/**
 * @ingroup systemdriver
 * @brief Initializes the system module. This routine must be called only once during the system initialization and before any other routine is called.
 * @param None.
 * @return None.
*/
void SYSTEM_Initialize(void);






#endif	/* MCC_H */
/**
 End of File
*/