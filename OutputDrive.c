/******************************************************************************/
/*File      : OutputDrive.c                                                   */
/*Version   : 1.0                                                             */
/*Author    : chp                                                             */
/*Date      : 09.06.2023                                                      */
/*Function  : upddate all outputs state as asked in the received structure    */
/******************************************************************************/


#include "mcc_generated_files/system/system.h"     /*Load specific declaration for uC*/

#include "OutputDrive.h" 


extern uint16_t  AllResultsArray[8];        /*let access to AD results array */


/**
 * @ingroup Program
 * @brief Apply requested states to all outputs
 * @param : pointer on Output values structure 
 * @return None.
 */

void OutputStateApply(struct OutputStates *data)
{
    /*used for state machine control*/
    static int CloseStMCurrentState = START_STATE;
    static int OpenStMCurrentState = START_STATE;
    
    static bool SetDirectStateDelayStarted = false;
    static bool ActiveMotorStateDelayStarted = false;
    static bool MotorIOkStateDelayStarted = false;
    
    static int MotorCurrentMeanVal = 0;
    
    
    /*CHECK FOR DAY/NIGHT CHANG REQUEST*/
    if (data->RelaySequence == 1)
        /*close sequence asked, access state machine*/
    {
        /*ensure OPEN state machine is in init before starting CLOSE*/
        if (OpenStMCurrentState == START_STATE)
        
            /*ok, no OPEN seq in progress, start or continue CLOSE*/
        {
            /*state access*/
            switch (CloseStMCurrentState)
            {
                case START_STATE : 
                    /*initial state, first pass, set simply next state*/
                    CloseStMCurrentState = SET_DIRECTION_STATE ;
                    break;
            
                case SET_DIRECTION_STATE :
                    /*it means :                
                     - set relay in close direction and start establishing delay
                     - check delay, when elapsed go to next state
                    */
                    if (SetDirectStateDelayStarted == false)
                    {
                        CMDRelDown_SetHigh();                          /* set CLOSE direction */
                        RTC_WriteCounter(CNT_RESET);                /*init RTC cnt */
                        RTC_WritePeriod(CNT_PERIOD);                /* set relay establishing delay */
                        RTC.INTFLAGS |= RTC_OVF_bm;                 /*clr int flag for this measure */
                        SetDirectStateDelayStarted = true;          /*denay access next pass */
                    }    
                    else if (SetDirectStateDelayStarted == true)                                                      
                    {
                        if (RTC.INTFLAGS & RTC_OVF_bm)      /* check period int flag */
                            /* period int occured, change to next state and clear int*/
                        {
                            RTC.INTFLAGS |= RTC_OVF_bm;
                            SetDirectStateDelayStarted = false;         /*denay access next pass */
                            CloseStMCurrentState = ACTIVE_MOTOR_STATE;
                        }                                                           
                    } 
                    break;
            
                case ACTIVE_MOTOR_STATE :
                    /*it means :                
                     - Start the motor
                     - check the current for MOTOR_CURRENT_CTRL_DURATIOM
                    */    
                    if (ActiveMotorStateDelayStarted == false)
                        /* Activate motor and start current control duration */
                    {
                        CMDActivation_SetHigh();
                        RTC_WriteCounter(CNT_RESET);                        /*init RTC cnt */
                        RTC_WritePeriod(MOTOR_CURRENT_CTRL_DURATIOM);       /* set relay establishing delay */
                        RTC.INTFLAGS |= RTC_OVF_bm;                         /*clr int flag for this measure */
                        MotorCurrentMeanVal = 0;                            /*clear current moy var*/
                        ActiveMotorStateDelayStarted = true;                /*denay access next pass */
                    
                    }    
                     else if (ActiveMotorStateDelayStarted == true)                                                      
                    {
                        if (RTC.INTFLAGS & RTC_OVF_bm)  /* check period int flag */
                            /* period int occured, celar int flag, check current measure mean value and jump to dedicated state*/
                        {
                            RTC.INTFLAGS |= RTC_OVF_bm;
                            
                            if (MotorCurrentMeanVal > MOTOR_CURRENT_MAX_LIMIT_CLOSE)
                                /*too much current, set fault and change state*/
                            {
                                ActiveMotorStateDelayStarted = false;                /*allow access next pass */
                                data->MotorErrorFlags = OVER_CURRENT_ERROR;
                                CloseStMCurrentState = MOTOR_STOP_STATE;       
                            }
                            else if (MotorCurrentMeanVal < MOTOR_CURRENT_MIN_LIMIT_OPEN)
                                /*not enough current, set fault and change state*/
                            {
                                ActiveMotorStateDelayStarted = false;                /*allow access next pass */
                                data->MotorErrorFlags = UNDER_CURRENT_ERROR;
                                CloseStMCurrentState = MOTOR_STOP_STATE;       
                            }
                            else if ((MotorCurrentMeanVal <= MOTOR_CURRENT_MAX_LIMIT_CLOSE) & (MotorCurrentMeanVal >= MOTOR_CURRENT_MIN_LIMIT_CLOSE))
                                /*current in correct window, go to next state*/
                            {
                                ActiveMotorStateDelayStarted = false;                /*allow access next pass */
                                CloseStMCurrentState = MOTOR_I_OK_STATE;
                            }                           
                        }                   
                        else 
                            /* sum current measures*/
                        {
                            MotorCurrentMeanVal += AllResultsArray[0];  /*sum actual current measure */
                            MotorCurrentMeanVal /= 2;                   /*mean by divid by sum cnt, here 2 */
                        }       
                    }
                    break;
                    
                case MOTOR_I_OK_STATE :
                    /*it means :                
                     - current is in correct window, so let continue
                     - start overall timeout
                     - when elapsed, check current going low 
                    */    
                    if (MotorIOkStateDelayStarted == false)
                        /* Activate motor and start current control duration */
                    {
                        RTC_WriteCounter(CNT_RESET);                /*init RTC cnt */
                        RTC_WritePeriod(MOTOR_TOTAL_DURATIOM);      /* set relay establishing delay */
                        RTC.INTFLAGS |= RTC_OVF_bm;                 /*clr int flag for this measure */
                        MotorIOkStateDelayStarted = true;           /*denay access next pass */    
                    }
                    else if (MotorIOkStateDelayStarted == true)
                        /* delay started, check and if not moy current*/
                    {    
                        if (RTC.INTFLAGS & RTC_OVF_bm)  /* check period int flag */
                            /* period int occured, celar int flag, check current measure mean value and jump to dedicated state*/
                        {
                            RTC.INTFLAGS |= RTC_OVF_bm;
                            if (MotorCurrentMeanVal > MOTOR_CURRENT_MIN_LIMIT_CLOSE)
                                /*too much current, set fault and change state*/
                            {
                                MotorIOkStateDelayStarted = false;           /*allow access next pass */
                                data->MotorErrorFlags = TIEMOUT_ERROR;
                                CloseStMCurrentState = MOTOR_STOP_STATE;       
                            }
                            else if (MotorCurrentMeanVal < MOTOR_CURRENT_MIN_LIMIT_CLOSE)
                                /*current is low, activation done, CLOSE done, change state*/
                            {
                                MotorIOkStateDelayStarted = false;           /*allow access next pass */
                                data->MotorErrorFlags = NO_ERROR;
                                CloseStMCurrentState = MOTOR_STOP_STATE;       
                            }
                        }
                        else 
                            /*delay in progress, update current moy*/
                        {
                            MotorCurrentMeanVal += AllResultsArray[0];  /*sum actual current measure */
                            MotorCurrentMeanVal /= 2;                   /*mean by divid by sum cnt, here 2 */
                        }       
                    }
                    break;
                            
                case MOTOR_STOP_STATE : 
                    /*it means :                
                     - everything is ok, CLOSE sequence done
                     - open relays in intial state
                    */    
                    {
                        CMDActivation_SetLow();
                        CMDRelDown_SetLow();                          /* set NO direction */
                        CloseStMCurrentState = FINAL_STATE; 
                    }   
                    break;
                    
                case FINAL_STATE :
                    /*it means :                
                     - If not error, update led, init state machine
                     - if error, update led, init state machine
                    */    
                    {
                        if (data->MotorErrorFlags != NO_ERROR)
                            /*analys error, update leds*/
                        {
                            if (data->MotorErrorFlags == OVER_CURRENT_ERROR)
                            {
                                data->LEDSysState = true;
                                data->LEDSysBlinkCodeWanted = true;
                                data->LEDSysBlinkCode = OVER_CURRENT_ERROR;        
                            }
                            
                            else if (data->MotorErrorFlags == UNDER_CURRENT_ERROR)
                            {
                                data->LEDSysState = true;
                                data->LEDSysBlinkCodeWanted = true;
                                data->LEDSysBlinkCode = UNDER_CURRENT_ERROR;        
                            }
                            
                            else if (data->MotorErrorFlags == TIEMOUT_ERROR)
                            {
                                data->LEDSysState = true;
                                data->LEDSysBlinkCodeWanted = true;
                                data->LEDSysBlinkCode = TIEMOUT_ERROR;        
                            }
                            
                            else if (data->MotorErrorFlags == NO_ERROR)
                            {
                                data->LEDSysState = false;
                                data->LEDSysBlinkCodeWanted = false;
                                data->LEDSysBlinkCode = NO_ERROR;
                            
                            }    
                                
                        }
                        
                        /* it is night time, set led crep*/
                        data->LEDCrepState = true;
                        data->LEDAubeState = false;
                        
                        /* SEquence is done, set to Nothing to do*/
                        data->RelaySequence = 0;   
                        
                        /*set state machine init state*/
                        CloseStMCurrentState = START_STATE; 
                    }
                                      
            }
                                
        }    
            
        else if (OpenStMCurrentState != START_STATE)    
            
            /*error state, CLOSE seq asked during OPEN seq*/
        {
        
        }    
            
            
    }
 
/******************************************************************************/    
/******************************************************************************/    
/******************************************************************************/    
/******************************************************************************/    
    
    
    else if (data->RelaySequence == 2)
        /*OPEN sequence asked, access state machine*/
    {
        /*ensure CLOSE state machine is in init before starting CLOSE*/
        if (CloseStMCurrentState == START_STATE)
        
            /*ok, no CLOSE seq in progress, start or continue OPEN*/
        {
            /*state access*/
            switch (OpenStMCurrentState)
            {
                case START_STATE : 
                    /*initial state, first pass, set simply next state*/
                    OpenStMCurrentState = SET_DIRECTION_STATE ;
                    break;
            
                case SET_DIRECTION_STATE :
                    /*it means :                
                     - set relay in close direction and start establishing delay
                     - check delay, when elapsed go to next state
                    */
                    if (SetDirectStateDelayStarted == false)
                    {
                        CMDRelUp_SetHigh();                          /* set OPEN direction */
                        RTC_WriteCounter(CNT_RESET);                    /*init RTC cnt */
                        RTC_WritePeriod(CNT_PERIOD);                /* set relay establishing delay */
                        RTC.INTFLAGS |= RTC_OVF_bm;                 /*clr int flag for this measure */
                        SetDirectStateDelayStarted = true;          /*denay access next pass */
                    }    
                    else if (SetDirectStateDelayStarted == true)                                                      
                    {
                        if (RTC.INTFLAGS & RTC_OVF_bm)      /* check period int flag */
                            /* period int occured, change to next state and clear int*/
                        {
                            RTC.INTFLAGS |= RTC_OVF_bm;
                            SetDirectStateDelayStarted = false;         /*denay access next pass */
                            OpenStMCurrentState = ACTIVE_MOTOR_STATE;
                        }                                                           
                    } 
                    break;
            
                case ACTIVE_MOTOR_STATE :
                    /*it means :                
                     - Start the motor
                     - check the current for MOTOR_CURRENT_CTRL_DURATIOM
                    */    
                    if (ActiveMotorStateDelayStarted == false)
                        /* Activate motor and start current control duration */
                    {
                        CMDActivation_SetHigh();
                        RTC_WriteCounter(CNT_RESET);                        /*init RTC cnt */
                        RTC_WritePeriod(MOTOR_CURRENT_CTRL_DURATIOM);       /* set relay establishing delay */
                        RTC.INTFLAGS |= RTC_OVF_bm;                         /*clr int flag for this measure */
                        ActiveMotorStateDelayStarted = true;                /*denay access next pass */
                    
                    }    
                     else if (ActiveMotorStateDelayStarted == true)                                                      
                    {
                        if (RTC.INTFLAGS & RTC_OVF_bm)  /* check period int flag */
                            /* period int occured, celar int flag, check current measure mean value and jump to dedicated state*/
                        {
                            RTC.INTFLAGS |= RTC_OVF_bm;
                            
                            if (MotorCurrentMeanVal > MOTOR_CURRENT_MAX_LIMIT_OPEN)
                                /*too much current, set fault and change state*/
                            {
                                ActiveMotorStateDelayStarted = false;                /*allow access next pass */
                                data->MotorErrorFlags = OVER_CURRENT_ERROR;
                                OpenStMCurrentState = MOTOR_STOP_STATE;       
                            }
                            else if (MotorCurrentMeanVal < MOTOR_CURRENT_MIN_LIMIT_OPEN)
                                /*not enough current, set fault and change state*/
                            {
                                ActiveMotorStateDelayStarted = false;                /*allow access next pass */
                                data->MotorErrorFlags = UNDER_CURRENT_ERROR;
                                OpenStMCurrentState = MOTOR_STOP_STATE;       
                            }
                            else if ((MotorCurrentMeanVal <= MOTOR_CURRENT_MAX_LIMIT_OPEN) & (MotorCurrentMeanVal >= MOTOR_CURRENT_MIN_LIMIT_OPEN))
                                /*current in correct window, go to next state*/
                            {
                                ActiveMotorStateDelayStarted = false;                /*allow access next pass */
                                OpenStMCurrentState = MOTOR_I_OK_STATE;
                            }                           
                        }                   
                        else 
                            /* sum current measures*/
                        {
                            MotorCurrentMeanVal += AllResultsArray[0];  /*sum actual current measure */
                            MotorCurrentMeanVal /= 2;                   /*mean by divid by sum cnt, here 2 */
                        }       
                    }
                    break;
                    
                case MOTOR_I_OK_STATE :
                    /*it means :                
                     - current is in correct window, so let continue
                     - start overall timeout
                     - when elapsed, check current going low 
                    */    
                    if (MotorIOkStateDelayStarted == false)
                        /* Activate motor and start current control duration */
                    {
                        RTC_WriteCounter(CNT_RESET);                /*init RTC cnt */
                        RTC_WritePeriod(MOTOR_TOTAL_DURATIOM);      /* set relay establishing delay */
                        RTC.INTFLAGS |= RTC_OVF_bm;                 /*clr int flag for this measure */
                        MotorIOkStateDelayStarted = true;           /*denay access next pass */    
                    }
                    else if (MotorIOkStateDelayStarted == true)
                        /* delay started, check and if not moy current*/
                    {    
                        if (RTC.INTFLAGS & RTC_OVF_bm)  /* check period int flag */
                            /* period int occured, celar int flag, check current measure mean value and jump to dedicated state*/
                        {
                            RTC.INTFLAGS |= RTC_OVF_bm;
                            if (MotorCurrentMeanVal > MOTOR_CURRENT_MIN_LIMIT_OPEN)
                                /*too much current, set fault and change state*/
                            {
                                MotorIOkStateDelayStarted = false;           /*allow access next pass */
                                data->MotorErrorFlags = TIEMOUT_ERROR;
                                OpenStMCurrentState = MOTOR_STOP_STATE;       
                            }
                            else if (MotorCurrentMeanVal < MOTOR_CURRENT_MIN_LIMIT_OPEN)
                                /*current is low, activation done, CLOSE done, change state*/
                            {
                                MotorIOkStateDelayStarted = false;           /*allow access next pass */
                                OpenStMCurrentState = MOTOR_STOP_STATE;       
                            }
                        }
                        else 
                            /*delay in progress, update current moy*/
                        {
                            MotorCurrentMeanVal += AllResultsArray[0];  /*sum actual current measure */
                            MotorCurrentMeanVal /= 2;                   /*mean by divid by sum cnt, here 2 */
                        }       
                    }
                    break;
                            
                case MOTOR_STOP_STATE : 
                    /*it means :                
                     - everything is ok, OPEN sequence done
                     - open relays in intial state
                    */    
                    {
                        CMDActivation_SetLow();
                        CMDRelUp_SetLow();                          /* set NO direction */
                        OpenStMCurrentState = FINAL_STATE; 
                    }   
                    break;
                    
                case FINAL_STATE :
                    /*it means :                
                     - If not error, update led, init state machine
                     - if error, update led, init state machine
                    */    
                    {
                        if (data->MotorErrorFlags != NO_ERROR)
                            /*analys error, update leds*/
                        {
                            if (data->MotorErrorFlags == OVER_CURRENT_ERROR)
                            {
                                data->LEDSysState = true;
                                data->LEDSysBlinkCodeWanted = true;
                                data->LEDSysBlinkCode = OVER_CURRENT_ERROR;        
                            }
                            
                            else if (data->MotorErrorFlags == UNDER_CURRENT_ERROR)
                            {
                                data->LEDSysState = true;
                                data->LEDSysBlinkCodeWanted = true;
                                data->LEDSysBlinkCode = UNDER_CURRENT_ERROR;        
                            }
                            
                            else if (data->MotorErrorFlags == TIEMOUT_ERROR)
                            {
                                data->LEDSysState = true;
                                data->LEDSysBlinkCodeWanted = true;
                                data->LEDSysBlinkCode = TIEMOUT_ERROR;        
                            }
                            
                            else if (data->MotorErrorFlags == NO_ERROR)
                            {
                                data->LEDSysState = false;
                                data->LEDSysBlinkCodeWanted = false;
                                data->LEDSysBlinkCode = NO_ERROR;
                            
                            }    
                                
                        }
                        
                        /* it is night time, set led crep*/
                        data->LEDCrepState = false;
                        data->LEDAubeState = true;
                        
                        /* SEquence is done, set to Nothing to do*/
                        data->RelaySequence = 0;
                        
                        /*set state machine init state*/
                        OpenStMCurrentState = START_STATE; 
                    }
                    break;
                                      
            }
                                
        }    
            
        else if (CloseStMCurrentState != START_STATE)    
            
            /*error state, CLOSE seq asked during OPEN seq*/
        {
           
            
        }    
                       
    }
    


/******************************************************************************/    
    /*LED update state from structure*/
    if (data->LEDSysState == true)
    {
        if (data->LEDSysBlinkCodeWanted == false)
        {
            LEDSys_SetHigh();
        }

    }
    else if (data->LEDSysState == false)
    {
        if (data->LEDSysBlinkCodeWanted == false)
        {
            LEDSys_SetLow();
        }
    }    

    if (data->LEDTemp1State == true)
    {
        if (data->LEDTemp1BlinkCodeWanted == false)
        {
        /*    LEDTemp1_SetHigh();*/
        }

    }
    else if (data->LEDTemp1State == false)
    {
        if (data->LEDTemp1BlinkCodeWanted == false)
        {
            /*LEDTemp1_SetLow();*/
        }
    }

    if (data->LEDTemp2State == true)
    {
        if (data->LEDTemp2BlinkCodeWanted == false)
        {
            LEDTemp2_SetHigh();
        }

    }
    else if (data->LEDTemp2State == false)
    {
        if (data->LEDTemp2BlinkCodeWanted == false)
        {
            LEDTemp2_SetLow();
        }
    }

    if (data->LEDAubeState == true)
    {
        if (data->LEDAubeBlinkCodeWanted == false)
        {
            LEDAube_SetHigh();
        }

    }
    else if (data->LEDAubeState == false)
    {
        if (data->LEDAubeBlinkCodeWanted == false)
        {
            LEDAube_SetLow();
        }
    }

    if (data->LEDCrepState == true)
    {
        if (data->LEDCrepBlinkCodeWanted == false)
        {
            LEDCrep_SetHigh();
        }

    }
    else if (data->LEDCrepState == false)
    {
        if (data->LEDCrepBlinkCodeWanted == false)
        {
            LEDCrep_SetLow();
        }
    }

}

