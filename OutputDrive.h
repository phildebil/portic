/* 
 * File:   OutputDrive.h
 * Author: ArcticBear
 *
 * Created on 14. juin 2023, 17:17
 */

#ifndef OUTPUTDRIVE_H
#define	OUTPUTDRIVE_H


/* DEFINE STATE MACHINE STATES*/
#define START_STATE 1 
#define SET_DIRECTION_STATE 2 
#define ACTIVE_MOTOR_STATE 3
#define MOTOR_I_OK_STATE 4
#define MOTOR_STOP_STATE 5
#define FINAL_STATE 6

/* define motor controle error flag*/
#define NO_ERROR 0
#define OVER_CURRENT_ERROR 1 
#define UNDER_CURRENT_ERROR 2 
#define TIEMOUT_ERROR 3



#define CNT_RESET 0
#define CNT_PERIOD 66                      /*30ms @32768Hz/16 */

#define MOTOR_CURRENT_CTRL_DURATIOM 1024        /*500ms @32768Hz/16 */
#define MOTOR_TOTAL_DURATIOM 20480              /*10s @32768Hz/16 */  

#define MOTOR_CURRENT_MAX_LIMIT_CLOSE 96        /* current limit high */    
#define MOTOR_CURRENT_MIN_LIMIT_CLOSE 24        /* current limit high */

#define MOTOR_CURRENT_MAX_LIMIT_OPEN 96         /* current limit high */    
#define MOTOR_CURRENT_MIN_LIMIT_OPEN 24         /* current limit high */


#include "mcc_generated_files/system/system.h" 


void OutputStateApply(struct OutputStates *data); 


#endif	/* OUTPUTDRIVE_H */

