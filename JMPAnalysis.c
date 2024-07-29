/******************************************************************************/
/*File      : JMPAnalysis.c                                                   */
/*Version   : 1.0                                                             */
/*Author    : chp                                                             */
/*Date      : 09.06.2023                                                      */
/******************************************************************************/


#include "mcc_generated_files/system/system.h"      /*Load specific declaration for uC*/



/* fct that made an oversample of 128 for each digital input*/
int getJMPCode(void)
{
    static int JMP1StateCnt = 0;            /*state cnt, 128x same state will be validated */
    static int JMP2StateCnt = 0;            /*state cnt, 128x same state will be validated */
    
    static bool JMP1FirstPassDone = false; /*init control */
    static bool JMP2FirstPassDone = false; /*init control */

/*    static uint8_t JMP1ActualValue = 0;   */         /*entry state value */
/*    static uint8_t JMP2ActualValue = 0;    */        /*entry state value */
    static unsigned char JMP1ActualValue = 0;            /*entry state value */
    static unsigned char JMP2ActualValue = 0;            /*entry state value */
    
    static int JMP1State = 2;               /*validated entry state */
    static int JMP2State = 2;               /*validated entry state */
    
    static int JMPCode = 0;                        /*value returned by function*/




    
    /**************************************************************************/
    /* Start with Jumper1 entry check and cnt (oversampling)*/
        /*check first pass*/
    if (JMP1FirstPassDone == false)
    {
            /*first pass, read actual state*/
        /*JMP1ActualValue = Jumper1_GetValue();   */    /*read actual input state */
        JMPCode = 0;
        JMP1ActualValue = (VPORTF.IN & (1 << 0));
        
            /*init state cnt depending on input state*/
        if (JMP1ActualValue == 0)
        {
            JMP1StateCnt = 120;
            JMP1FirstPassDone = true;
        }    
        else 
        {
            JMP1StateCnt = 8;
            JMP1FirstPassDone = true;
        }
          
    }   /*first pass was already made, normal entry check */
    else
    {
        JMP1ActualValue = Jumper1_GetValue();       /*read actual input state */
        
        if (JMP1ActualValue == 0)
        {
            JMP1StateCnt -= 1;
            if (JMP1StateCnt < 0)
            {
                JMP1StateCnt = 0;
            }
        }    
        else 
        {
            JMP1StateCnt += 1;
            if (JMP1StateCnt > 128)
            {
                JMP1StateCnt = 128;
            }

        }
    }    


    /**************************************************************************/
    /* Start with Jumper2 entry check and cnt (oversampling)*/
        /*check first pass*/
    if (JMP2FirstPassDone == false)
    {
            /*first pass, read actual state*/
        JMP2ActualValue = Jumper2_GetValue();       /*read actual input state */
        
            /*init state cnt depending on input state*/
        if (JMP2ActualValue == 0)
        {
            JMP2StateCnt = 120;
            JMP2FirstPassDone = true;
        }    
        else 
        {
            JMP2StateCnt = 8;
            JMP2FirstPassDone = true;
        }
          
    }   /*first pass was already made, normal entry check */
    else
    {
        JMP2ActualValue = Jumper1_GetValue();       /*read actual input state */
        
        if (JMP2ActualValue == 0)
        {
            JMP2StateCnt -= 1;
            if (JMP2StateCnt < 0)
            {
                JMP2StateCnt = 0;
            }
        }    
        else 
        {
            JMP2StateCnt += 1;
            if (JMP2StateCnt > 128)
            {
                JMP2StateCnt = 128;
            }

        }
    }    
 
    
    /**************************************************************************/
    /*Jumper cnt control and limitation, so is kept between 0..128 */
        /*Jumper 1*/
    if (JMP1StateCnt == 0)
    {
        JMP1State = 0;
    }
    else if (JMP1StateCnt == 128)
    {
        JMP1State = 1;
    }
    
        /*Jumper 2*/
    if (JMP2StateCnt == 0)
    {
        JMP2State = 0;
    }
    else if (JMP2StateCnt == 128)
    {
        JMP2State = 1;
    }
     
    
    /**************************************************************************/
    /*build actual jumper value, between 0..3 when ready and something else if not ready */
    JMPCode = (JMP1State + (2*JMP2State));

    return JMPCode ;
    
    
    
} 



