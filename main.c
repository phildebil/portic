 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
� [2023] Microchip Technology Inc. and its subsidiaries.

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
#include "mcc_generated_files/system/system.h"  

#include "JMPAnalysis.h"

#include "MainProgram0.h"

#include "OutputDrive.h" 

    
/*Global var to transfert datas fron INT to code core, so volatile since unexpected changes can occur*/
volatile bool AllResultsArrayReady = false;


/*AD conversion results array */
/*The array contains in order :
 * - ADDriveCurrent
 * - ADCrepSoll
 * - ADAubeSoll
 * - ADTemp2Soll
 * - ADTemp1Soll
 * - ADLight
 * - ADTemp1
 * - ADTemp2 etc
 * */
volatile uint16_t  AllResultsArray[8]={0};


/*Output stage command values */
struct OutputStates OutputValues;


/*
    Main application
*/

int main(void)
{
    
    SYSTEM_Initialize();

  
    /*local varaibles declaration and init*/

        /*used for jumpers code */
    unsigned int ActualJMPCode = 6;  /*0-3 = actual 2bit jumper code when valid*/
 
    /*declaration and init of output values structure*/


    
        /*Led boolean value and blink value and duration*/
    OutputValues.LEDSysState = true;
    OutputValues.LEDSysBlinkRatio = 0;
    OutputValues.LEDSysBlinkCodeWanted = false;
    OutputValues.LEDSysBlinkCode = 0;
    
    OutputValues.LEDTemp1State = false;
    OutputValues.LEDTemp1BlinkRatio = 0;
    OutputValues.LEDTemp1BlinkCodeWanted = false;
    OutputValues.LEDTemp1BlinkCode = 0;
 
    OutputValues.LEDTemp2State = false;
    OutputValues.LEDTemp2BlinkRatio = 0;
    OutputValues.LEDTemp2BlinkCodeWanted = false;
    OutputValues.LEDTemp2BlinkCode = 0;
    
    OutputValues.LEDAubeState = false;
    OutputValues.LEDAubeBlinkRatio = 0;
    OutputValues.LEDAubeBlinkCodeWanted = false;
    OutputValues.LEDAubeBlinkCode = 0;

    OutputValues.LEDCrepState = false;
    OutputValues.LEDCrepBlinkRatio = 0;
    OutputValues.LEDCrepBlinkCodeWanted = false;
    OutputValues.LEDCrepBlinkCode = 0;


        /*Dry relays cmd*/
    OutputValues.CMDRelDry1Command = false;     /*0 = OFF, 1 = ON*/
    OutputValues.CMDRelDry2Command = false;     /*0 = OFF, 1 = ON*/

    OutputValues.RelaySequence = 0;             /*0 = nothing, 1 = close, 2 = open */   
    OutputValues.CMDRelCommand = false;         /*0 = OFF, 1 = ON*/
    OutputValues.CMDRelDirection = 0;           /*0= nothing, 1 = UP, 2 =  down */
    OutputValues.MotorErrorFlags =NO_ERROR;
    
    
    
    /* main infinite loop*/
    /* in order it will :*/
    /* - wait for fresh datas*/
    /* - analyse and update system with datas*/
    /* - Apply results */
    
    
    while(1)
    {
     /*Begin with Datas acquisition:
       - Start conversion by timer event
       - At each Int data is saved and new MUX channel select
       - Save values into data array to used here
       => all thoses steps are automated and managed by system and INT */   
        
 
         /*check fresh datas availability flag*/    
        if (AllResultsArrayReady == true)
        {

        /*****************************************************/
        /*****************************************************/
            /*new fresh datas available, compute new values*/


                /*to compute correctly, check which JMP code is selected*/
            ActualJMPCode = getJMPCode();

            switch (ActualJMPCode)
            {   
                case 0:     /*Execute program 0*/
                    /*..*/
                    AllResultsArrayReady = Program0(&OutputValues);
                    break;

                case 1:     /*Execute program 1*/
                    /*..*/
                    break;

                case 2:     /*Execute program 2*/
                    /*..*/
                    break;

                case 3:     /*Execute program 3*/
                    /*..*/
                    break;

                default:    /*jumpers not defined actually, just exit */
                    /*..*/     
                    break;
            }

        }
    
    OutputStateApply(&OutputValues);
  
    }    
}