/******************************************************************************/
/*File      : MainProgram0.c                                                   */
/*Version   : 1.0                                                             */
/*Author    : chp                                                             */
/*Date      : 09.06.2023                                                      */
/******************************************************************************/


#include "mcc_generated_files/system/system.h"     /*Load specific declaration for uC*/

#include "MainProgram0.h"

extern bool AllResultsArrayReady;
extern uint16_t  AllResultsArray[8];        /*let access to AD results array */



/**
 * @ingroup Program
 * @brief Manage the Linear actuator depending on outdoor light condition
 * @param : pointer on Output values structure and global vars containing conversion results
 * @return None.
 */
bool Program0(struct OutputStates *data)
{
    static bool Program0FirstPassDone = false ;
    static bool ActuallyIsDay = false ;
    static int DayToNightCnt = 0;                   /*used to filter transition day to night */
    static int NghtToDayCnt = 0;                    /*used to filter transition night to day */
    

    /*Manage first pass to define Day or Nicht under progress*/
    /*start also the appropriate sequence, open or close*/
    
    if (Program0FirstPassDone == false)     
    {
        /*first pass way*/
        if (AllResultsArray[5] >= AllResultsArray[4])
            /*Actual daylight is higher than Aube sollwert, it is day*/
        {
            ActuallyIsDay =  true;
            data->RelaySequence = 2;
        }
        else if (AllResultsArray[5] < AllResultsArray[4])
            /*Actual daylight is lower than Aube sollwert, it is night*/
        {
            ActuallyIsDay =  false;
            data->RelaySequence = 1;
        }    
    
        Program0FirstPassDone = true;
        
    }
        /*standard execution pass*/
    else if (Program0FirstPassDone == true) 
    {
        if (ActuallyIsDay == true)
            /*manage day and transition from day to night*/
        {
            if (AllResultsArray[5] >= AllResultsArray[4])   /* check if actually is daylight*/
                /*we are on daylight and it is still day, update cnt and check limit*/
            {
                DayToNightCnt -= 1;
                if (DayToNightCnt < 0)
                {
                    DayToNightCnt = 0;                      /*apply cnt low limit*/
                }    
            }    
            
            else if (AllResultsArray[5] < AllResultsArray[4])
                /*we on daylight but new light value is lower than limit*/
            {
                    /*transition to night in progress, update cnt*/
                DayToNightCnt +=1 ;
                if (DayToNightCnt >= DAYTRANSITION)
                        /*delay reached, clr cnt, start close sequence, set Night and LED*/
                {
                    if (data->RelaySequence == 0)
                            /*ensure no other sequence in progress*/ 
                    {
                        DayToNightCnt = 0;      
                        ActuallyIsDay = false;  
                        data->RelaySequence = 1;                    
                    } 
                    else
                            /*otehr sequence in progress, reload cnt*/
                    {
                        DayToNightCnt = DAYTRANSITION; 
                    }
                }    
                    
            }    
            
        }    
       
        else if (ActuallyIsDay == false)
            /*manage night and transition from night to day*/
        {
            if (AllResultsArray[5] <= AllResultsArray[4])   /* check if actually is daylight*/
                /*we are on night light and it is still night, update cnt and check limit*/
            {
                NghtToDayCnt -= 1;
                if (NghtToDayCnt < 0)
                {
                    NghtToDayCnt = 0;                      /*apply cnt low limit*/
                }    
            }    
            
            else if (AllResultsArray[5] > AllResultsArray[4])
                /*we are on night light but new light value is higher than limit*/
            {
                    /*transition to day in progress, update cnt*/
                NghtToDayCnt +=1 ;
                if (NghtToDayCnt >= DAYTRANSITION)
                        /*delay reached, clr cnt, start close sequence, set Night and LED*/
                {
                    if (data->RelaySequence == 0)
                           /*ensure no other sequence in progress*/ 
                    {
                        NghtToDayCnt = 0;      
                        ActuallyIsDay = true;  
                        data->RelaySequence = 2;
                    }
                    else 
                            /*otehr sequence in progress, reload cnt*/
                    {
                        NghtToDayCnt = DAYTRANSITION; 
                    }
                    
                    
                    
               }    
                    
            }
        }    
     }        
    /* Reset flag to inform for fresh datas*/
    return false;
   
}