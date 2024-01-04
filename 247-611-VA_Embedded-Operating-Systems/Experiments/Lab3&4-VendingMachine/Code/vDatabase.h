/**************************************************************************************************
* FileName: vDatabase.h
*
* Name: Leonardo Fusser (1946995)       Lab 3       Vending Machine
*                                       Lab 4       ... 
*
* Description: Header file for vDatabase.c source file. Macro definitions and function prototypes for
*              the corresponding source file can be found here. Other macro constants can be found 
*              in public.h file.
*  
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   February 17 2022    v1.0.0      First version of header file.
*                                                   Added includes.
*                                                   Added comments.
* Leonardo Fusser   February 24 2022    v1.0.1      Added function prototypes.
*                                                   Added comments.
* Leonardo Fusser   3 March 2022        v1.0.2      Added mutex_SetPriceVM() prototype.
*                                                   Added mutex_SetCreditVM() prototype.
*                                                   Added mutex_GetCreditVM() prototype.
* Leonardo Fusser   5 March 2022        v1.0.3      Added remaining function prototypes.
* Leonardo Fusser   22 March 2022       v1.0.4      ...
* Leonardo Fusser   24 March 2022       v1.0.5      ...   
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef VDATABASE_H
#define VDATABASE_H

/* Includes. */
#include "public.h"

/* Function prototypes. */
static void vDatabase( void *pvParameters );
void vInit_vDatabase(void);
void vInit_StartDatabase(void);
void vInitSemaphore_vDatabase(void);
void mutex_InitSetVM(void);
void mutex_SetQtyVM(int temp_set, int operation);
int mutex_GetQtyVM(int operation);
void mutex_SetPriceVM(int temp_set, int operation);
int mutex_GetPriceVM(int operation);
char mutex_GetNameVM(int operation);
void mutex_SetCreditVM(int temp_set);
int mutex_GetCreditVM(void);
void mutex_SetCreditQuantity(int temp_set);
int mutex_GetCreditQuantity(void);
void mutex_SetTransactionTime(int64_t temp_set);
int mutex_GetTransactionTime(void);
void mutex_SetFridgeTemperature(int temp_set);
int mutex_GetFridgeTemperature(void);
void mutex_SetTechnicianStatus(int temp_set);
int mutex_GetTechnicianStatus(void);

#endif
