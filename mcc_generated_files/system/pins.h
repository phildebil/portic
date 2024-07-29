/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  1.1.0
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

#ifndef PINS_H_INCLUDED
#define PINS_H_INCLUDED

#include <avr/io.h>
#include "./port.h"

//get/set ADDriveCurrent aliases
#define ADDriveCurrent_SetHigh() do { PORTA_OUTSET = 0x8; } while(0)
#define ADDriveCurrent_SetLow() do { PORTA_OUTCLR = 0x8; } while(0)
#define ADDriveCurrent_Toggle() do { PORTA_OUTTGL = 0x8; } while(0)
#define ADDriveCurrent_GetValue() (VPORTA.IN & (0x1 << 3))
#define ADDriveCurrent_SetDigitalInput() do { PORTA_DIRCLR = 0x8; } while(0)
#define ADDriveCurrent_SetDigitalOutput() do { PORTA_DIRSET = 0x8; } while(0)
#define ADDriveCurrent_SetPullUp() do { PORTA_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define ADDriveCurrent_ResetPullUp() do { PORTA_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define ADDriveCurrent_SetInverted() do { PORTA_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define ADDriveCurrent_ResetInverted() do { PORTA_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define ADDriveCurrent_DisableInterruptOnChange() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define ADDriveCurrent_EnableInterruptForBothEdges() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define ADDriveCurrent_EnableInterruptForRisingEdge() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define ADDriveCurrent_EnableInterruptForFallingEdge() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define ADDriveCurrent_DisableDigitalInputBuffer() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define ADDriveCurrent_EnableInterruptForLowLevelSensing() do { PORTA.PIN3CTRL = (PORTA.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA3_SetInterruptHandler ADDriveCurrent_SetInterruptHandler

//get/set ADCrepSoll aliases
#define ADCrepSoll_SetHigh() do { PORTC_OUTSET = 0x1; } while(0)
#define ADCrepSoll_SetLow() do { PORTC_OUTCLR = 0x1; } while(0)
#define ADCrepSoll_Toggle() do { PORTC_OUTTGL = 0x1; } while(0)
#define ADCrepSoll_GetValue() (VPORTC.IN & (0x1 << 0))
#define ADCrepSoll_SetDigitalInput() do { PORTC_DIRCLR = 0x1; } while(0)
#define ADCrepSoll_SetDigitalOutput() do { PORTC_DIRSET = 0x1; } while(0)
#define ADCrepSoll_SetPullUp() do { PORTC_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define ADCrepSoll_ResetPullUp() do { PORTC_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define ADCrepSoll_SetInverted() do { PORTC_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define ADCrepSoll_ResetInverted() do { PORTC_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define ADCrepSoll_DisableInterruptOnChange() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define ADCrepSoll_EnableInterruptForBothEdges() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define ADCrepSoll_EnableInterruptForRisingEdge() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define ADCrepSoll_EnableInterruptForFallingEdge() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define ADCrepSoll_DisableDigitalInputBuffer() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define ADCrepSoll_EnableInterruptForLowLevelSensing() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC0_SetInterruptHandler ADCrepSoll_SetInterruptHandler

//get/set ADAubeSoll aliases
#define ADAubeSoll_SetHigh() do { PORTC_OUTSET = 0x4; } while(0)
#define ADAubeSoll_SetLow() do { PORTC_OUTCLR = 0x4; } while(0)
#define ADAubeSoll_Toggle() do { PORTC_OUTTGL = 0x4; } while(0)
#define ADAubeSoll_GetValue() (VPORTC.IN & (0x1 << 2))
#define ADAubeSoll_SetDigitalInput() do { PORTC_DIRCLR = 0x4; } while(0)
#define ADAubeSoll_SetDigitalOutput() do { PORTC_DIRSET = 0x4; } while(0)
#define ADAubeSoll_SetPullUp() do { PORTC_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define ADAubeSoll_ResetPullUp() do { PORTC_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define ADAubeSoll_SetInverted() do { PORTC_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define ADAubeSoll_ResetInverted() do { PORTC_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define ADAubeSoll_DisableInterruptOnChange() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define ADAubeSoll_EnableInterruptForBothEdges() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define ADAubeSoll_EnableInterruptForRisingEdge() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define ADAubeSoll_EnableInterruptForFallingEdge() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define ADAubeSoll_DisableDigitalInputBuffer() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define ADAubeSoll_EnableInterruptForLowLevelSensing() do { PORTC.PIN2CTRL = (PORTC.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC2_SetInterruptHandler ADAubeSoll_SetInterruptHandler

//get/set ADTemp2Soll aliases
#define ADTemp2Soll_SetHigh() do { PORTD_OUTSET = 0x4; } while(0)
#define ADTemp2Soll_SetLow() do { PORTD_OUTCLR = 0x4; } while(0)
#define ADTemp2Soll_Toggle() do { PORTD_OUTTGL = 0x4; } while(0)
#define ADTemp2Soll_GetValue() (VPORTD.IN & (0x1 << 2))
#define ADTemp2Soll_SetDigitalInput() do { PORTD_DIRCLR = 0x4; } while(0)
#define ADTemp2Soll_SetDigitalOutput() do { PORTD_DIRSET = 0x4; } while(0)
#define ADTemp2Soll_SetPullUp() do { PORTD_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define ADTemp2Soll_ResetPullUp() do { PORTD_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define ADTemp2Soll_SetInverted() do { PORTD_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define ADTemp2Soll_ResetInverted() do { PORTD_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define ADTemp2Soll_DisableInterruptOnChange() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define ADTemp2Soll_EnableInterruptForBothEdges() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define ADTemp2Soll_EnableInterruptForRisingEdge() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define ADTemp2Soll_EnableInterruptForFallingEdge() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define ADTemp2Soll_DisableDigitalInputBuffer() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define ADTemp2Soll_EnableInterruptForLowLevelSensing() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD2_SetInterruptHandler ADTemp2Soll_SetInterruptHandler

//get/set ADTemp1Soll aliases
#define ADTemp1Soll_SetHigh() do { PORTD_OUTSET = 0x10; } while(0)
#define ADTemp1Soll_SetLow() do { PORTD_OUTCLR = 0x10; } while(0)
#define ADTemp1Soll_Toggle() do { PORTD_OUTTGL = 0x10; } while(0)
#define ADTemp1Soll_GetValue() (VPORTD.IN & (0x1 << 4))
#define ADTemp1Soll_SetDigitalInput() do { PORTD_DIRCLR = 0x10; } while(0)
#define ADTemp1Soll_SetDigitalOutput() do { PORTD_DIRSET = 0x10; } while(0)
#define ADTemp1Soll_SetPullUp() do { PORTD_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define ADTemp1Soll_ResetPullUp() do { PORTD_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define ADTemp1Soll_SetInverted() do { PORTD_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define ADTemp1Soll_ResetInverted() do { PORTD_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define ADTemp1Soll_DisableInterruptOnChange() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define ADTemp1Soll_EnableInterruptForBothEdges() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define ADTemp1Soll_EnableInterruptForRisingEdge() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define ADTemp1Soll_EnableInterruptForFallingEdge() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define ADTemp1Soll_DisableDigitalInputBuffer() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define ADTemp1Soll_EnableInterruptForLowLevelSensing() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD4_SetInterruptHandler ADTemp1Soll_SetInterruptHandler

//get/set ADLight aliases
#define ADLight_SetHigh() do { PORTD_OUTSET = 0x20; } while(0)
#define ADLight_SetLow() do { PORTD_OUTCLR = 0x20; } while(0)
#define ADLight_Toggle() do { PORTD_OUTTGL = 0x20; } while(0)
#define ADLight_GetValue() (VPORTD.IN & (0x1 << 5))
#define ADLight_SetDigitalInput() do { PORTD_DIRCLR = 0x20; } while(0)
#define ADLight_SetDigitalOutput() do { PORTD_DIRSET = 0x20; } while(0)
#define ADLight_SetPullUp() do { PORTD_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define ADLight_ResetPullUp() do { PORTD_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define ADLight_SetInverted() do { PORTD_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define ADLight_ResetInverted() do { PORTD_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define ADLight_DisableInterruptOnChange() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define ADLight_EnableInterruptForBothEdges() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define ADLight_EnableInterruptForRisingEdge() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define ADLight_EnableInterruptForFallingEdge() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define ADLight_DisableDigitalInputBuffer() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define ADLight_EnableInterruptForLowLevelSensing() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD5_SetInterruptHandler ADLight_SetInterruptHandler

//get/set ADTemp1 aliases
#define ADTemp1_SetHigh() do { PORTD_OUTSET = 0x40; } while(0)
#define ADTemp1_SetLow() do { PORTD_OUTCLR = 0x40; } while(0)
#define ADTemp1_Toggle() do { PORTD_OUTTGL = 0x40; } while(0)
#define ADTemp1_GetValue() (VPORTD.IN & (0x1 << 6))
#define ADTemp1_SetDigitalInput() do { PORTD_DIRCLR = 0x40; } while(0)
#define ADTemp1_SetDigitalOutput() do { PORTD_DIRSET = 0x40; } while(0)
#define ADTemp1_SetPullUp() do { PORTD_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define ADTemp1_ResetPullUp() do { PORTD_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define ADTemp1_SetInverted() do { PORTD_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define ADTemp1_ResetInverted() do { PORTD_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define ADTemp1_DisableInterruptOnChange() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define ADTemp1_EnableInterruptForBothEdges() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define ADTemp1_EnableInterruptForRisingEdge() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define ADTemp1_EnableInterruptForFallingEdge() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define ADTemp1_DisableDigitalInputBuffer() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define ADTemp1_EnableInterruptForLowLevelSensing() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD6_SetInterruptHandler ADTemp1_SetInterruptHandler

//get/set ADTemp2 aliases
#define ADTemp2_SetHigh() do { PORTD_OUTSET = 0x80; } while(0)
#define ADTemp2_SetLow() do { PORTD_OUTCLR = 0x80; } while(0)
#define ADTemp2_Toggle() do { PORTD_OUTTGL = 0x80; } while(0)
#define ADTemp2_GetValue() (VPORTD.IN & (0x1 << 7))
#define ADTemp2_SetDigitalInput() do { PORTD_DIRCLR = 0x80; } while(0)
#define ADTemp2_SetDigitalOutput() do { PORTD_DIRSET = 0x80; } while(0)
#define ADTemp2_SetPullUp() do { PORTD_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define ADTemp2_ResetPullUp() do { PORTD_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define ADTemp2_SetInverted() do { PORTD_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define ADTemp2_ResetInverted() do { PORTD_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define ADTemp2_DisableInterruptOnChange() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define ADTemp2_EnableInterruptForBothEdges() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define ADTemp2_EnableInterruptForRisingEdge() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define ADTemp2_EnableInterruptForFallingEdge() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define ADTemp2_DisableDigitalInputBuffer() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define ADTemp2_EnableInterruptForLowLevelSensing() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD7_SetInterruptHandler ADTemp2_SetInterruptHandler

//get/set Jumper2 aliases
#define Jumper2_SetHigh() do { PORTF_OUTSET = 0x1; } while(0)
#define Jumper2_SetLow() do { PORTF_OUTCLR = 0x1; } while(0)
#define Jumper2_Toggle() do { PORTF_OUTTGL = 0x1; } while(0)
#define Jumper2_GetValue() (VPORTF.IN & (0x1 << 0))
#define Jumper2_SetDigitalInput() do { PORTF_DIRCLR = 0x1; } while(0)
#define Jumper2_SetDigitalOutput() do { PORTF_DIRSET = 0x1; } while(0)
#define Jumper2_SetPullUp() do { PORTF_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define Jumper2_ResetPullUp() do { PORTF_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define Jumper2_SetInverted() do { PORTF_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define Jumper2_ResetInverted() do { PORTF_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define Jumper2_DisableInterruptOnChange() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define Jumper2_EnableInterruptForBothEdges() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define Jumper2_EnableInterruptForRisingEdge() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define Jumper2_EnableInterruptForFallingEdge() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define Jumper2_DisableDigitalInputBuffer() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define Jumper2_EnableInterruptForLowLevelSensing() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PF0_SetInterruptHandler Jumper2_SetInterruptHandler

//get/set Jumper1 aliases
#define Jumper1_SetHigh() do { PORTF_OUTSET = 0x2; } while(0)
#define Jumper1_SetLow() do { PORTF_OUTCLR = 0x2; } while(0)
#define Jumper1_Toggle() do { PORTF_OUTTGL = 0x2; } while(0)
#define Jumper1_GetValue() (VPORTF.IN & (0x1 << 1))
#define Jumper1_SetDigitalInput() do { PORTF_DIRCLR = 0x2; } while(0)
#define Jumper1_SetDigitalOutput() do { PORTF_DIRSET = 0x2; } while(0)
#define Jumper1_SetPullUp() do { PORTF_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define Jumper1_ResetPullUp() do { PORTF_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define Jumper1_SetInverted() do { PORTF_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define Jumper1_ResetInverted() do { PORTF_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define Jumper1_DisableInterruptOnChange() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define Jumper1_EnableInterruptForBothEdges() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define Jumper1_EnableInterruptForRisingEdge() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define Jumper1_EnableInterruptForFallingEdge() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define Jumper1_DisableDigitalInputBuffer() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define Jumper1_EnableInterruptForLowLevelSensing() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PF1_SetInterruptHandler Jumper1_SetInterruptHandler

//get/set CMDActivation aliases
#define CMDActivation_SetHigh() do { PORTA_OUTSET = 0x1; } while(0)
#define CMDActivation_SetLow() do { PORTA_OUTCLR = 0x1; } while(0)
#define CMDActivation_Toggle() do { PORTA_OUTTGL = 0x1; } while(0)
#define CMDActivation_GetValue() (VPORTA.IN & (0x1 << 0))
#define CMDActivation_SetDigitalInput() do { PORTA_DIRCLR = 0x1; } while(0)
#define CMDActivation_SetDigitalOutput() do { PORTA_DIRSET = 0x1; } while(0)
#define CMDActivation_SetPullUp() do { PORTA_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CMDActivation_ResetPullUp() do { PORTA_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CMDActivation_SetInverted() do { PORTA_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define CMDActivation_ResetInverted() do { PORTA_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CMDActivation_DisableInterruptOnChange() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CMDActivation_EnableInterruptForBothEdges() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CMDActivation_EnableInterruptForRisingEdge() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CMDActivation_EnableInterruptForFallingEdge() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CMDActivation_DisableDigitalInputBuffer() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CMDActivation_EnableInterruptForLowLevelSensing() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA0_SetInterruptHandler CMDActivation_SetInterruptHandler

//get/set CMDRelDry1 aliases
#define CMDRelDry1_SetHigh() do { PORTA_OUTSET = 0x2; } while(0)
#define CMDRelDry1_SetLow() do { PORTA_OUTCLR = 0x2; } while(0)
#define CMDRelDry1_Toggle() do { PORTA_OUTTGL = 0x2; } while(0)
#define CMDRelDry1_GetValue() (VPORTA.IN & (0x1 << 1))
#define CMDRelDry1_SetDigitalInput() do { PORTA_DIRCLR = 0x2; } while(0)
#define CMDRelDry1_SetDigitalOutput() do { PORTA_DIRSET = 0x2; } while(0)
#define CMDRelDry1_SetPullUp() do { PORTA_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CMDRelDry1_ResetPullUp() do { PORTA_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CMDRelDry1_SetInverted() do { PORTA_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define CMDRelDry1_ResetInverted() do { PORTA_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CMDRelDry1_DisableInterruptOnChange() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CMDRelDry1_EnableInterruptForBothEdges() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CMDRelDry1_EnableInterruptForRisingEdge() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CMDRelDry1_EnableInterruptForFallingEdge() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CMDRelDry1_DisableDigitalInputBuffer() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CMDRelDry1_EnableInterruptForLowLevelSensing() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA1_SetInterruptHandler CMDRelDry1_SetInterruptHandler

//get/set CMDRelDry2 aliases
#define CMDRelDry2_SetHigh() do { PORTA_OUTSET = 0x4; } while(0)
#define CMDRelDry2_SetLow() do { PORTA_OUTCLR = 0x4; } while(0)
#define CMDRelDry2_Toggle() do { PORTA_OUTTGL = 0x4; } while(0)
#define CMDRelDry2_GetValue() (VPORTA.IN & (0x1 << 2))
#define CMDRelDry2_SetDigitalInput() do { PORTA_DIRCLR = 0x4; } while(0)
#define CMDRelDry2_SetDigitalOutput() do { PORTA_DIRSET = 0x4; } while(0)
#define CMDRelDry2_SetPullUp() do { PORTA_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CMDRelDry2_ResetPullUp() do { PORTA_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CMDRelDry2_SetInverted() do { PORTA_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define CMDRelDry2_ResetInverted() do { PORTA_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CMDRelDry2_DisableInterruptOnChange() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CMDRelDry2_EnableInterruptForBothEdges() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CMDRelDry2_EnableInterruptForRisingEdge() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CMDRelDry2_EnableInterruptForFallingEdge() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CMDRelDry2_DisableDigitalInputBuffer() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CMDRelDry2_EnableInterruptForLowLevelSensing() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA2_SetInterruptHandler CMDRelDry2_SetInterruptHandler

//get/set CMDRelUp aliases
#define CMDRelUp_SetHigh() do { PORTA_OUTSET = 0x10; } while(0)
#define CMDRelUp_SetLow() do { PORTA_OUTCLR = 0x10; } while(0)
#define CMDRelUp_Toggle() do { PORTA_OUTTGL = 0x10; } while(0)
#define CMDRelUp_GetValue() (VPORTA.IN & (0x1 << 4))
#define CMDRelUp_SetDigitalInput() do { PORTA_DIRCLR = 0x10; } while(0)
#define CMDRelUp_SetDigitalOutput() do { PORTA_DIRSET = 0x10; } while(0)
#define CMDRelUp_SetPullUp() do { PORTA_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CMDRelUp_ResetPullUp() do { PORTA_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CMDRelUp_SetInverted() do { PORTA_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define CMDRelUp_ResetInverted() do { PORTA_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CMDRelUp_DisableInterruptOnChange() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CMDRelUp_EnableInterruptForBothEdges() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CMDRelUp_EnableInterruptForRisingEdge() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CMDRelUp_EnableInterruptForFallingEdge() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CMDRelUp_DisableDigitalInputBuffer() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CMDRelUp_EnableInterruptForLowLevelSensing() do { PORTA.PIN4CTRL = (PORTA.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA4_SetInterruptHandler CMDRelUp_SetInterruptHandler

//get/set CMDRelDown aliases
#define CMDRelDown_SetHigh() do { PORTA_OUTSET = 0x20; } while(0)
#define CMDRelDown_SetLow() do { PORTA_OUTCLR = 0x20; } while(0)
#define CMDRelDown_Toggle() do { PORTA_OUTTGL = 0x20; } while(0)
#define CMDRelDown_GetValue() (VPORTA.IN & (0x1 << 5))
#define CMDRelDown_SetDigitalInput() do { PORTA_DIRCLR = 0x20; } while(0)
#define CMDRelDown_SetDigitalOutput() do { PORTA_DIRSET = 0x20; } while(0)
#define CMDRelDown_SetPullUp() do { PORTA_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define CMDRelDown_ResetPullUp() do { PORTA_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define CMDRelDown_SetInverted() do { PORTA_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define CMDRelDown_ResetInverted() do { PORTA_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define CMDRelDown_DisableInterruptOnChange() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define CMDRelDown_EnableInterruptForBothEdges() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define CMDRelDown_EnableInterruptForRisingEdge() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define CMDRelDown_EnableInterruptForFallingEdge() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define CMDRelDown_DisableDigitalInputBuffer() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define CMDRelDown_EnableInterruptForLowLevelSensing() do { PORTA.PIN5CTRL = (PORTA.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA5_SetInterruptHandler CMDRelDown_SetInterruptHandler

//get/set LEDSys aliases
#define LEDSys_SetHigh() do { PORTA_OUTSET = 0x40; } while(0)
#define LEDSys_SetLow() do { PORTA_OUTCLR = 0x40; } while(0)
#define LEDSys_Toggle() do { PORTA_OUTTGL = 0x40; } while(0)
#define LEDSys_GetValue() (VPORTA.IN & (0x1 << 6))
#define LEDSys_SetDigitalInput() do { PORTA_DIRCLR = 0x40; } while(0)
#define LEDSys_SetDigitalOutput() do { PORTA_DIRSET = 0x40; } while(0)
#define LEDSys_SetPullUp() do { PORTA_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define LEDSys_ResetPullUp() do { PORTA_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define LEDSys_SetInverted() do { PORTA_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define LEDSys_ResetInverted() do { PORTA_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define LEDSys_DisableInterruptOnChange() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define LEDSys_EnableInterruptForBothEdges() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define LEDSys_EnableInterruptForRisingEdge() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define LEDSys_EnableInterruptForFallingEdge() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define LEDSys_DisableDigitalInputBuffer() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define LEDSys_EnableInterruptForLowLevelSensing() do { PORTA.PIN6CTRL = (PORTA.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA6_SetInterruptHandler LEDSys_SetInterruptHandler

//get/set LEDTemp1 aliases
#define LEDTemp1_SetHigh() do { PORTA_OUTSET = 0x80; } while(0)
#define LEDTemp1_SetLow() do { PORTA_OUTCLR = 0x80; } while(0)
#define LEDTemp1_Toggle() do { PORTA_OUTTGL = 0x80; } while(0)
#define LEDTemp1_GetValue() (VPORTA.IN & (0x1 << 7))
#define LEDTemp1_SetDigitalInput() do { PORTA_DIRCLR = 0x80; } while(0)
#define LEDTemp1_SetDigitalOutput() do { PORTA_DIRSET = 0x80; } while(0)
#define LEDTemp1_SetPullUp() do { PORTA_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define LEDTemp1_ResetPullUp() do { PORTA_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define LEDTemp1_SetInverted() do { PORTA_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define LEDTemp1_ResetInverted() do { PORTA_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define LEDTemp1_DisableInterruptOnChange() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define LEDTemp1_EnableInterruptForBothEdges() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define LEDTemp1_EnableInterruptForRisingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define LEDTemp1_EnableInterruptForFallingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define LEDTemp1_DisableDigitalInputBuffer() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define LEDTemp1_EnableInterruptForLowLevelSensing() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PA7_SetInterruptHandler LEDTemp1_SetInterruptHandler

//get/set LEDAube aliases
#define LEDAube_SetHigh() do { PORTC_OUTSET = 0x2; } while(0)
#define LEDAube_SetLow() do { PORTC_OUTCLR = 0x2; } while(0)
#define LEDAube_Toggle() do { PORTC_OUTTGL = 0x2; } while(0)
#define LEDAube_GetValue() (VPORTC.IN & (0x1 << 1))
#define LEDAube_SetDigitalInput() do { PORTC_DIRCLR = 0x2; } while(0)
#define LEDAube_SetDigitalOutput() do { PORTC_DIRSET = 0x2; } while(0)
#define LEDAube_SetPullUp() do { PORTC_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define LEDAube_ResetPullUp() do { PORTC_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define LEDAube_SetInverted() do { PORTC_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define LEDAube_ResetInverted() do { PORTC_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define LEDAube_DisableInterruptOnChange() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define LEDAube_EnableInterruptForBothEdges() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define LEDAube_EnableInterruptForRisingEdge() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define LEDAube_EnableInterruptForFallingEdge() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define LEDAube_DisableDigitalInputBuffer() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define LEDAube_EnableInterruptForLowLevelSensing() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC1_SetInterruptHandler LEDAube_SetInterruptHandler

//get/set LEDTemp2 aliases
#define LEDTemp2_SetHigh() do { PORTC_OUTSET = 0x8; } while(0)
#define LEDTemp2_SetLow() do { PORTC_OUTCLR = 0x8; } while(0)
#define LEDTemp2_Toggle() do { PORTC_OUTTGL = 0x8; } while(0)
#define LEDTemp2_GetValue() (VPORTC.IN & (0x1 << 3))
#define LEDTemp2_SetDigitalInput() do { PORTC_DIRCLR = 0x8; } while(0)
#define LEDTemp2_SetDigitalOutput() do { PORTC_DIRSET = 0x8; } while(0)
#define LEDTemp2_SetPullUp() do { PORTC_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define LEDTemp2_ResetPullUp() do { PORTC_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define LEDTemp2_SetInverted() do { PORTC_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define LEDTemp2_ResetInverted() do { PORTC_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define LEDTemp2_DisableInterruptOnChange() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define LEDTemp2_EnableInterruptForBothEdges() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define LEDTemp2_EnableInterruptForRisingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define LEDTemp2_EnableInterruptForFallingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define LEDTemp2_DisableDigitalInputBuffer() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define LEDTemp2_EnableInterruptForLowLevelSensing() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC3_SetInterruptHandler LEDTemp2_SetInterruptHandler

//get/set IOFree1 aliases
#define IOFree1_SetHigh() do { PORTD_OUTSET = 0x2; } while(0)
#define IOFree1_SetLow() do { PORTD_OUTCLR = 0x2; } while(0)
#define IOFree1_Toggle() do { PORTD_OUTTGL = 0x2; } while(0)
#define IOFree1_GetValue() (VPORTD.IN & (0x1 << 1))
#define IOFree1_SetDigitalInput() do { PORTD_DIRCLR = 0x2; } while(0)
#define IOFree1_SetDigitalOutput() do { PORTD_DIRSET = 0x2; } while(0)
#define IOFree1_SetPullUp() do { PORTD_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IOFree1_ResetPullUp() do { PORTD_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IOFree1_SetInverted() do { PORTD_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define IOFree1_ResetInverted() do { PORTD_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IOFree1_DisableInterruptOnChange() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IOFree1_EnableInterruptForBothEdges() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IOFree1_EnableInterruptForRisingEdge() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IOFree1_EnableInterruptForFallingEdge() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IOFree1_DisableDigitalInputBuffer() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IOFree1_EnableInterruptForLowLevelSensing() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD1_SetInterruptHandler IOFree1_SetInterruptHandler

//get/set LEDCrep aliases
#define LEDCrep_SetHigh() do { PORTD_OUTSET = 0x8; } while(0)
#define LEDCrep_SetLow() do { PORTD_OUTCLR = 0x8; } while(0)
#define LEDCrep_Toggle() do { PORTD_OUTTGL = 0x8; } while(0)
#define LEDCrep_GetValue() (VPORTD.IN & (0x1 << 3))
#define LEDCrep_SetDigitalInput() do { PORTD_DIRCLR = 0x8; } while(0)
#define LEDCrep_SetDigitalOutput() do { PORTD_DIRSET = 0x8; } while(0)
#define LEDCrep_SetPullUp() do { PORTD_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define LEDCrep_ResetPullUp() do { PORTD_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define LEDCrep_SetInverted() do { PORTD_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define LEDCrep_ResetInverted() do { PORTD_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define LEDCrep_DisableInterruptOnChange() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define LEDCrep_EnableInterruptForBothEdges() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define LEDCrep_EnableInterruptForRisingEdge() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define LEDCrep_EnableInterruptForFallingEdge() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define LEDCrep_DisableDigitalInputBuffer() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define LEDCrep_EnableInterruptForLowLevelSensing() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PD3_SetInterruptHandler LEDCrep_SetInterruptHandler

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize();

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADDriveCurrent pin. 
 *        This is a predefined interrupt handler to be used together with the ADDriveCurrent_SetInterruptHandler() method.
 *        This handler is called every time the ADDriveCurrent ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADDriveCurrent_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADDriveCurrent pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADDriveCurrent at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADDriveCurrent_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADCrepSoll pin. 
 *        This is a predefined interrupt handler to be used together with the ADCrepSoll_SetInterruptHandler() method.
 *        This handler is called every time the ADCrepSoll ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADCrepSoll_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADCrepSoll pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADCrepSoll at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADCrepSoll_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADAubeSoll pin. 
 *        This is a predefined interrupt handler to be used together with the ADAubeSoll_SetInterruptHandler() method.
 *        This handler is called every time the ADAubeSoll ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADAubeSoll_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADAubeSoll pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADAubeSoll at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADAubeSoll_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADTemp2Soll pin. 
 *        This is a predefined interrupt handler to be used together with the ADTemp2Soll_SetInterruptHandler() method.
 *        This handler is called every time the ADTemp2Soll ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADTemp2Soll_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADTemp2Soll pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADTemp2Soll at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADTemp2Soll_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADTemp1Soll pin. 
 *        This is a predefined interrupt handler to be used together with the ADTemp1Soll_SetInterruptHandler() method.
 *        This handler is called every time the ADTemp1Soll ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADTemp1Soll_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADTemp1Soll pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADTemp1Soll at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADTemp1Soll_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADLight pin. 
 *        This is a predefined interrupt handler to be used together with the ADLight_SetInterruptHandler() method.
 *        This handler is called every time the ADLight ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADLight_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADLight pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADLight at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADLight_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADTemp1 pin. 
 *        This is a predefined interrupt handler to be used together with the ADTemp1_SetInterruptHandler() method.
 *        This handler is called every time the ADTemp1 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADTemp1_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADTemp1 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADTemp1 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADTemp1_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for ADTemp2 pin. 
 *        This is a predefined interrupt handler to be used together with the ADTemp2_SetInterruptHandler() method.
 *        This handler is called every time the ADTemp2 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void ADTemp2_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for ADTemp2 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for ADTemp2 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void ADTemp2_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for Jumper2 pin. 
 *        This is a predefined interrupt handler to be used together with the Jumper2_SetInterruptHandler() method.
 *        This handler is called every time the Jumper2 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void Jumper2_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for Jumper2 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for Jumper2 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void Jumper2_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for Jumper1 pin. 
 *        This is a predefined interrupt handler to be used together with the Jumper1_SetInterruptHandler() method.
 *        This handler is called every time the Jumper1 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void Jumper1_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for Jumper1 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for Jumper1 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void Jumper1_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CMDActivation pin. 
 *        This is a predefined interrupt handler to be used together with the CMDActivation_SetInterruptHandler() method.
 *        This handler is called every time the CMDActivation ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CMDActivation_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CMDActivation pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CMDActivation at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CMDActivation_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CMDRelDry1 pin. 
 *        This is a predefined interrupt handler to be used together with the CMDRelDry1_SetInterruptHandler() method.
 *        This handler is called every time the CMDRelDry1 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CMDRelDry1_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CMDRelDry1 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CMDRelDry1 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CMDRelDry1_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CMDRelDry2 pin. 
 *        This is a predefined interrupt handler to be used together with the CMDRelDry2_SetInterruptHandler() method.
 *        This handler is called every time the CMDRelDry2 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CMDRelDry2_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CMDRelDry2 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CMDRelDry2 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CMDRelDry2_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CMDRelUp pin. 
 *        This is a predefined interrupt handler to be used together with the CMDRelUp_SetInterruptHandler() method.
 *        This handler is called every time the CMDRelUp ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CMDRelUp_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CMDRelUp pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CMDRelUp at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CMDRelUp_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for CMDRelDown pin. 
 *        This is a predefined interrupt handler to be used together with the CMDRelDown_SetInterruptHandler() method.
 *        This handler is called every time the CMDRelDown ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void CMDRelDown_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for CMDRelDown pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for CMDRelDown at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void CMDRelDown_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for LEDSys pin. 
 *        This is a predefined interrupt handler to be used together with the LEDSys_SetInterruptHandler() method.
 *        This handler is called every time the LEDSys ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void LEDSys_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for LEDSys pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for LEDSys at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void LEDSys_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for LEDTemp1 pin. 
 *        This is a predefined interrupt handler to be used together with the LEDTemp1_SetInterruptHandler() method.
 *        This handler is called every time the LEDTemp1 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void LEDTemp1_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for LEDTemp1 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for LEDTemp1 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void LEDTemp1_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for LEDAube pin. 
 *        This is a predefined interrupt handler to be used together with the LEDAube_SetInterruptHandler() method.
 *        This handler is called every time the LEDAube ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void LEDAube_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for LEDAube pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for LEDAube at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void LEDAube_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for LEDTemp2 pin. 
 *        This is a predefined interrupt handler to be used together with the LEDTemp2_SetInterruptHandler() method.
 *        This handler is called every time the LEDTemp2 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void LEDTemp2_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for LEDTemp2 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for LEDTemp2 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void LEDTemp2_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for IOFree1 pin. 
 *        This is a predefined interrupt handler to be used together with the IOFree1_SetInterruptHandler() method.
 *        This handler is called every time the IOFree1 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void IOFree1_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for IOFree1 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for IOFree1 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void IOFree1_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for LEDCrep pin. 
 *        This is a predefined interrupt handler to be used together with the LEDCrep_SetInterruptHandler() method.
 *        This handler is called every time the LEDCrep ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void LEDCrep_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for LEDCrep pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for LEDCrep at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void LEDCrep_SetInterruptHandler(void (* interruptHandler)(void)) ; 
#endif /* PINS_H_INCLUDED */
