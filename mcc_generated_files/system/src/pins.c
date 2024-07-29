/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 1.1.0
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

#include "../pins.h"

static void (*ADDriveCurrent_InterruptHandler)(void);
static void (*ADCrepSoll_InterruptHandler)(void);
static void (*ADAubeSoll_InterruptHandler)(void);
static void (*ADTemp2Soll_InterruptHandler)(void);
static void (*ADTemp1Soll_InterruptHandler)(void);
static void (*ADLight_InterruptHandler)(void);
static void (*ADTemp1_InterruptHandler)(void);
static void (*ADTemp2_InterruptHandler)(void);
static void (*Jumper2_InterruptHandler)(void);
static void (*Jumper1_InterruptHandler)(void);
static void (*CMDActivation_InterruptHandler)(void);
static void (*CMDRelDry1_InterruptHandler)(void);
static void (*CMDRelDry2_InterruptHandler)(void);
static void (*CMDRelUp_InterruptHandler)(void);
static void (*CMDRelDown_InterruptHandler)(void);
static void (*LEDSys_InterruptHandler)(void);
static void (*LEDTemp1_InterruptHandler)(void);
static void (*LEDAube_InterruptHandler)(void);
static void (*LEDTemp2_InterruptHandler)(void);
static void (*IOFree1_InterruptHandler)(void);
static void (*LEDCrep_InterruptHandler)(void);

void PIN_MANAGER_Initialize()
{
  /* DIR Registers Initialization */
    PORTA.DIR = 0xF7;
    PORTC.DIR = 0xA;
    PORTD.DIR = 0xA;
    PORTF.DIR = 0x0;

  /* OUT Registers Initialization */
    PORTA.OUT = 0x0;
    PORTC.OUT = 0x0;
    PORTD.OUT = 0x0;
    PORTF.OUT = 0x0;

  /* PINxCTRL registers Initialization */
    PORTA.PIN0CTRL = 0x0;
    PORTA.PIN1CTRL = 0x0;
    PORTA.PIN2CTRL = 0x0;
    PORTA.PIN3CTRL = 0x0;
    PORTA.PIN4CTRL = 0x0;
    PORTA.PIN5CTRL = 0x0;
    PORTA.PIN6CTRL = 0x0;
    PORTA.PIN7CTRL = 0x0;
    PORTC.PIN0CTRL = 0x0;
    PORTC.PIN1CTRL = 0x0;
    PORTC.PIN2CTRL = 0x0;
    PORTC.PIN3CTRL = 0x0;
    PORTC.PIN4CTRL = 0x0;
    PORTC.PIN5CTRL = 0x0;
    PORTC.PIN6CTRL = 0x0;
    PORTC.PIN7CTRL = 0x0;
    PORTD.PIN0CTRL = 0x0;
    PORTD.PIN1CTRL = 0x0;
    PORTD.PIN2CTRL = 0x0;
    PORTD.PIN3CTRL = 0x0;
    PORTD.PIN4CTRL = 0x0;
    PORTD.PIN5CTRL = 0x0;
    PORTD.PIN6CTRL = 0x0;
    PORTD.PIN7CTRL = 0x0;
    PORTF.PIN0CTRL = 0x0;
    PORTF.PIN1CTRL = 0x0;
    PORTF.PIN2CTRL = 0x0;
    PORTF.PIN3CTRL = 0x0;
    PORTF.PIN4CTRL = 0x0;
    PORTF.PIN5CTRL = 0x0;
    PORTF.PIN6CTRL = 0x0;
    PORTF.PIN7CTRL = 0x0;

  /* PORTMUX Initialization */
    PORTMUX.CCLROUTEA = 0x0;
    PORTMUX.EVSYSROUTEA = 0x1;
    PORTMUX.SPIROUTEA = 0x0;
    PORTMUX.TCAROUTEA = 0x0;
    PORTMUX.TCBROUTEA = 0x0;
    PORTMUX.TCDROUTEA = 0x0;
    PORTMUX.TWIROUTEA = 0x0;
    PORTMUX.USARTROUTEA = 0x0;

  // register default ISC callback functions at runtime; use these methods to register a custom function
    ADDriveCurrent_SetInterruptHandler(ADDriveCurrent_DefaultInterruptHandler);
    ADCrepSoll_SetInterruptHandler(ADCrepSoll_DefaultInterruptHandler);
    ADAubeSoll_SetInterruptHandler(ADAubeSoll_DefaultInterruptHandler);
    ADTemp2Soll_SetInterruptHandler(ADTemp2Soll_DefaultInterruptHandler);
    ADTemp1Soll_SetInterruptHandler(ADTemp1Soll_DefaultInterruptHandler);
    ADLight_SetInterruptHandler(ADLight_DefaultInterruptHandler);
    ADTemp1_SetInterruptHandler(ADTemp1_DefaultInterruptHandler);
    ADTemp2_SetInterruptHandler(ADTemp2_DefaultInterruptHandler);
    Jumper2_SetInterruptHandler(Jumper2_DefaultInterruptHandler);
    Jumper1_SetInterruptHandler(Jumper1_DefaultInterruptHandler);
    CMDActivation_SetInterruptHandler(CMDActivation_DefaultInterruptHandler);
    CMDRelDry1_SetInterruptHandler(CMDRelDry1_DefaultInterruptHandler);
    CMDRelDry2_SetInterruptHandler(CMDRelDry2_DefaultInterruptHandler);
    CMDRelUp_SetInterruptHandler(CMDRelUp_DefaultInterruptHandler);
    CMDRelDown_SetInterruptHandler(CMDRelDown_DefaultInterruptHandler);
    LEDSys_SetInterruptHandler(LEDSys_DefaultInterruptHandler);
    LEDTemp1_SetInterruptHandler(LEDTemp1_DefaultInterruptHandler);
    LEDAube_SetInterruptHandler(LEDAube_DefaultInterruptHandler);
    LEDTemp2_SetInterruptHandler(LEDTemp2_DefaultInterruptHandler);
    IOFree1_SetInterruptHandler(IOFree1_DefaultInterruptHandler);
    LEDCrep_SetInterruptHandler(LEDCrep_DefaultInterruptHandler);
}

/**
  Allows selecting an interrupt handler for ADDriveCurrent at application runtime
*/
void ADDriveCurrent_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADDriveCurrent_InterruptHandler = interruptHandler;
}

void ADDriveCurrent_DefaultInterruptHandler(void)
{
    // add your ADDriveCurrent interrupt custom code
    // or set custom function using ADDriveCurrent_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADCrepSoll at application runtime
*/
void ADCrepSoll_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADCrepSoll_InterruptHandler = interruptHandler;
}

void ADCrepSoll_DefaultInterruptHandler(void)
{
    // add your ADCrepSoll interrupt custom code
    // or set custom function using ADCrepSoll_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADAubeSoll at application runtime
*/
void ADAubeSoll_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADAubeSoll_InterruptHandler = interruptHandler;
}

void ADAubeSoll_DefaultInterruptHandler(void)
{
    // add your ADAubeSoll interrupt custom code
    // or set custom function using ADAubeSoll_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADTemp2Soll at application runtime
*/
void ADTemp2Soll_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADTemp2Soll_InterruptHandler = interruptHandler;
}

void ADTemp2Soll_DefaultInterruptHandler(void)
{
    // add your ADTemp2Soll interrupt custom code
    // or set custom function using ADTemp2Soll_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADTemp1Soll at application runtime
*/
void ADTemp1Soll_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADTemp1Soll_InterruptHandler = interruptHandler;
}

void ADTemp1Soll_DefaultInterruptHandler(void)
{
    // add your ADTemp1Soll interrupt custom code
    // or set custom function using ADTemp1Soll_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADLight at application runtime
*/
void ADLight_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADLight_InterruptHandler = interruptHandler;
}

void ADLight_DefaultInterruptHandler(void)
{
    // add your ADLight interrupt custom code
    // or set custom function using ADLight_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADTemp1 at application runtime
*/
void ADTemp1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADTemp1_InterruptHandler = interruptHandler;
}

void ADTemp1_DefaultInterruptHandler(void)
{
    // add your ADTemp1 interrupt custom code
    // or set custom function using ADTemp1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for ADTemp2 at application runtime
*/
void ADTemp2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    ADTemp2_InterruptHandler = interruptHandler;
}

void ADTemp2_DefaultInterruptHandler(void)
{
    // add your ADTemp2 interrupt custom code
    // or set custom function using ADTemp2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for Jumper2 at application runtime
*/
void Jumper2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    Jumper2_InterruptHandler = interruptHandler;
}

void Jumper2_DefaultInterruptHandler(void)
{
    // add your Jumper2 interrupt custom code
    // or set custom function using Jumper2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for Jumper1 at application runtime
*/
void Jumper1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    Jumper1_InterruptHandler = interruptHandler;
}

void Jumper1_DefaultInterruptHandler(void)
{
    // add your Jumper1 interrupt custom code
    // or set custom function using Jumper1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CMDActivation at application runtime
*/
void CMDActivation_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CMDActivation_InterruptHandler = interruptHandler;
}

void CMDActivation_DefaultInterruptHandler(void)
{
    // add your CMDActivation interrupt custom code
    // or set custom function using CMDActivation_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CMDRelDry1 at application runtime
*/
void CMDRelDry1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CMDRelDry1_InterruptHandler = interruptHandler;
}

void CMDRelDry1_DefaultInterruptHandler(void)
{
    // add your CMDRelDry1 interrupt custom code
    // or set custom function using CMDRelDry1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CMDRelDry2 at application runtime
*/
void CMDRelDry2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CMDRelDry2_InterruptHandler = interruptHandler;
}

void CMDRelDry2_DefaultInterruptHandler(void)
{
    // add your CMDRelDry2 interrupt custom code
    // or set custom function using CMDRelDry2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CMDRelUp at application runtime
*/
void CMDRelUp_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CMDRelUp_InterruptHandler = interruptHandler;
}

void CMDRelUp_DefaultInterruptHandler(void)
{
    // add your CMDRelUp interrupt custom code
    // or set custom function using CMDRelUp_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for CMDRelDown at application runtime
*/
void CMDRelDown_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    CMDRelDown_InterruptHandler = interruptHandler;
}

void CMDRelDown_DefaultInterruptHandler(void)
{
    // add your CMDRelDown interrupt custom code
    // or set custom function using CMDRelDown_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for LEDSys at application runtime
*/
void LEDSys_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    LEDSys_InterruptHandler = interruptHandler;
}

void LEDSys_DefaultInterruptHandler(void)
{
    // add your LEDSys interrupt custom code
    // or set custom function using LEDSys_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for LEDTemp1 at application runtime
*/
void LEDTemp1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    LEDTemp1_InterruptHandler = interruptHandler;
}

void LEDTemp1_DefaultInterruptHandler(void)
{
    // add your LEDTemp1 interrupt custom code
    // or set custom function using LEDTemp1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for LEDAube at application runtime
*/
void LEDAube_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    LEDAube_InterruptHandler = interruptHandler;
}

void LEDAube_DefaultInterruptHandler(void)
{
    // add your LEDAube interrupt custom code
    // or set custom function using LEDAube_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for LEDTemp2 at application runtime
*/
void LEDTemp2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    LEDTemp2_InterruptHandler = interruptHandler;
}

void LEDTemp2_DefaultInterruptHandler(void)
{
    // add your LEDTemp2 interrupt custom code
    // or set custom function using LEDTemp2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for IOFree1 at application runtime
*/
void IOFree1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    IOFree1_InterruptHandler = interruptHandler;
}

void IOFree1_DefaultInterruptHandler(void)
{
    // add your IOFree1 interrupt custom code
    // or set custom function using IOFree1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for LEDCrep at application runtime
*/
void LEDCrep_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    LEDCrep_InterruptHandler = interruptHandler;
}

void LEDCrep_DefaultInterruptHandler(void)
{
    // add your LEDCrep interrupt custom code
    // or set custom function using LEDCrep_SetInterruptHandler()
}
ISR(PORTA_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTA.INTFLAGS & PORT_INT3_bm)
    {
       ADDriveCurrent_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT0_bm)
    {
       CMDActivation_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT1_bm)
    {
       CMDRelDry1_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT2_bm)
    {
       CMDRelDry2_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT4_bm)
    {
       CMDRelUp_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT5_bm)
    {
       CMDRelDown_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT6_bm)
    {
       LEDSys_InterruptHandler(); 
    }
    if(VPORTA.INTFLAGS & PORT_INT7_bm)
    {
       LEDTemp1_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTA.INTFLAGS = 0xff;
}

ISR(PORTC_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTC.INTFLAGS & PORT_INT0_bm)
    {
       ADCrepSoll_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT2_bm)
    {
       ADAubeSoll_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT1_bm)
    {
       LEDAube_InterruptHandler(); 
    }
    if(VPORTC.INTFLAGS & PORT_INT3_bm)
    {
       LEDTemp2_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTC.INTFLAGS = 0xff;
}

ISR(PORTD_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTD.INTFLAGS & PORT_INT2_bm)
    {
       ADTemp2Soll_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT4_bm)
    {
       ADTemp1Soll_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT5_bm)
    {
       ADLight_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT6_bm)
    {
       ADTemp1_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT7_bm)
    {
       ADTemp2_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT1_bm)
    {
       IOFree1_InterruptHandler(); 
    }
    if(VPORTD.INTFLAGS & PORT_INT3_bm)
    {
       LEDCrep_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTD.INTFLAGS = 0xff;
}

ISR(PORTF_PORT_vect)
{ 
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTF.INTFLAGS & PORT_INT0_bm)
    {
       Jumper2_InterruptHandler(); 
    }
    if(VPORTF.INTFLAGS & PORT_INT1_bm)
    {
       Jumper1_InterruptHandler(); 
    }
    /* Clear interrupt flags */
    VPORTF.INTFLAGS = 0xff;
}

/**
 End of File
*/