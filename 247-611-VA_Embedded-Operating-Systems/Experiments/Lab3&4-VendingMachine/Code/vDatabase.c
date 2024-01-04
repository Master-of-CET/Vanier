/**************************************************************************************************
* FileName: vDatabase.c
*
* Name: Leonardo Fusser (1946995)       Lab 3       Vending Machine
*                                       Lab 4       Vending Machine II
*
* Description: vDatabase source file for Lab3 and Lab4. This file contains all the mutex-protected
*              setters and getters for the vending machine. A thread runs only once to initialize
*              the vending machine and its contents.
*              Macro constants can be found in the vDatabase.h or public.h file.
*  
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   17 February 2022    v1.0.0      First version of source file.
*                                                   Added includes.
* Leonardo Fusser   24 February 2022    v1.0.1      Created vDatabase() function.
*                                                   Created vInit_vDatabase() function.
*                                                   Created vInit_StartDatabase() function.
*                                                   Created vInitSemaphore_vDatabase() function.
*                                                   Created mutex_InitSetVM() function.
*                                                   Created mutex_SetQtyVM() function.
*                                                   Created mutex_GetQtyVM() function.
*                                                   Created mutex_GetPriceVM() function.
*                                                   Created mutex_GetNameVM() function.
*                                                   Added comments.
* Leonardo Fusser   3 March 2022        v1.0.2      Created mutex_SetPriceVM() function.
* Leonardo Fusser   5 March 2022        v1.0.3      Added vTaskDelete(NULL) function call in task.
*                                                   Added comments.
* Leonardo Fusser   9 March 2022        v1.0.4      Minor changes.
*                                                   Added comments.
* Leonardo Fusser   22 March 2022       v1.0.5      Minor changes.
* Leonardo Fusser   24 March 2022       v1.0.6      Minor changes.
* Leonardo Fusser   10 April 2022       v2.0.0      Added more mutex setter/getter functions.
*                                                   Added comments.
*                                                   Completed source file.  
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/* Includes. */
#include "include/vDatabase.h"


/* Private mutex and struct declarations. */
static SemaphoreHandle_t xMutex_vDatabase = NULL;
static SemaphoreHandle_t xMutex_UserCredit = NULL;
static SemaphoreHandle_t xMutex_CreditQuantity = NULL;
static SemaphoreHandle_t xMutex_TransactionTime = NULL;
static SemaphoreHandle_t xMutex_FridgeTemperature = NULL;
static SemaphoreHandle_t xMutex_TechnicianStatus = NULL;
static product_t VM_internals[STRUCT_DEPTH];


/* Globals. */
static int      totalCredit;
static int      totalCreditQuantity;
static int64_t  TransactionTime;
static int      FridgeTemperature;
static int      TechnicianStatus;


/**********************************************************************************************
* Name: static void vDatabase(void *pvParameters) 
* Description: Private static function definition for Lab3 and Lab4 RTOS vDatabase. This is the 
*              thread routine that runs only once to initialize the vending machine and its 
*              drinks.
* 
***********************************************************************************************/
static void vDatabase( void *pvParameters ){
    pvParameters = pvParameters;   //This is to get rid of annoying warnings.
    mutex_InitSetVM();             //Init struct function call.
    mutex_SetCreditVM(0);          //Init user credit to 0Q.
    mutex_SetCreditQuantity(0);    //Init internal quarter quantity to 0.
    vTaskDelete(NULL);             //Deletes task once execution is complete.
}


/**********************************************************************************************
* Name: void vInit_vDatabase(void) 
* Description: Public function definition for Lab3 and Lab4 RTOS vDatabase. This function calls 
*              initializing functions for vDatabase.
* 
***********************************************************************************************/
void vInit_vDatabase(void){
    vInitSemaphore_vDatabase();    //Calls mutex init function for vDatabase.
    vInit_StartDatabase();         //Calls task init function for vDatabase.
}


/**********************************************************************************************
* Name: void vInit_StartDatabase(void)
* Description: Public function definition for Lab3 and Lab4 RTOS vDatabase. This function
*              creates vDatabase.
*              Macro constants can be found in public.h file or vDatabase.h file. 
* 
***********************************************************************************************/
void vInit_StartDatabase(void){
    /* Creates vDatabase task with user-set priority. */
    xTaskCreate( vDatabase, ( char * ) "Database", 240, NULL, PRIORITY_Database, NULL );
}


/**********************************************************************************************
* Name: void vInitSemaphore_vDatabase(void)
* Description: Public function definition for Lab3 and Lab4 RTOS vDatabase. This function 
*              creates multiple mutex semaphores for vDatabase.
*
***********************************************************************************************/
void vInitSemaphore_vDatabase(void){
    /* Creates mutex semaphores. */
    xMutex_UserCredit = xSemaphoreCreateMutex();
    xMutex_vDatabase = xSemaphoreCreateMutex();
    xMutex_CreditQuantity = xSemaphoreCreateMutex();
    xMutex_TransactionTime = xSemaphoreCreateMutex();
    xMutex_FridgeTemperature = xSemaphoreCreateMutex();
    xMutex_TechnicianStatus = xSemaphoreCreateMutex();
}


/**********************************************************************************************
* Name: void mutex_InitSetVM(void)
* Description: Public function definition for Lab3 and Lab4 RTOS vDatabase. The following code 
*              initializes the vending machine drinks to a pre-defined value. The name, price
*              and quantity for the drinks are fixed-set below when this function is called. 
* 
***********************************************************************************************/
void mutex_InitSetVM(void){
    xSemaphoreTake(xMutex_vDatabase, portMAX_DELAY);    //Takes.
    
    strcpy(VM_internals[ORANGE].name, "Orange");        //Sets initial name for orange drink.
    strcpy(VM_internals[YELLOW].name, "Yellow");        //Sets initial name for yellow drink.
    strcpy(VM_internals[RED].name, "Red");              //Sets initial name for red drink.
    
    VM_internals[ORANGE].price = 7;                     //Sets initial price for orange drink.
    VM_internals[YELLOW].price = 8;                     //Sets initial price for yellow drink.
    VM_internals[RED].price = 9;                        //Sets initial price for red drink.
    
    VM_internals[ORANGE].qty = 5;                       //Sets initial quantity for orange drink.
    VM_internals[YELLOW].qty = 5;                       //Sets initial quantity for yellow drink.
    VM_internals[RED].qty = 5;                          //Sets initial quantity for red drink.
        
    xSemaphoreGive(xMutex_vDatabase);                   //Releases.
}


/**********************************************************************************************
* Name: void mutex_SetQtyVM(int temp_set, int operation)
* Description: Public function definition for Lab3 and Lab4 RTOS vDatabase. The following code 
*              sets the quantity for any of the vending machine drinks. Two arguments need to 
*              be passed: the first being the new drink quantity value and the second being the 
*              drink that you want to modify.
*              Macro constants can be found in public.h or vDatabase.h file.    
* 
***********************************************************************************************/
void mutex_SetQtyVM(int temp_set, int operation){
    xSemaphoreTake(xMutex_vDatabase, portMAX_DELAY);    //Takes.
    
    if(temp_set < 0){                                   //If drink quantity less than 0...
        temp_set = 0;                                   //Set drink quantity to 0.
    }
    if(operation == ORANGE){                            //If orange drink is desired...
        VM_internals[ORANGE].qty = temp_set;            //Sets quantity for orange drink.
    }
    else if(operation == YELLOW){                       //If yellow drink is desired...
        VM_internals[YELLOW].qty = temp_set;            //Sets quantity for yellow drink.
    }
    else if(operation == RED){                          //If red drink is desired...
        VM_internals[RED].qty = temp_set;               //Sets quantity for red drink.
    }
    
    xSemaphoreGive(xMutex_vDatabase);                   //Releases.
}


/**********************************************************************************************
* Name: int mutex_GetQtyVM(int operation)
* Description: Public function definition for Lab3 and Lab4 RTOS vDatabase. The following code
*              returns the vending machine's drink's quantity. One argument needs to be 
*              passed: the first being the drink that you want to get the quantity from.
*              Macro constants can be found in public.h or vDatabase.h file.     
* 
***********************************************************************************************/
int mutex_GetQtyVM(int operation){
    int temp_qty;                                       //Temp variable.
    xSemaphoreTake(xMutex_vDatabase, portMAX_DELAY);    //Takes.
    
    if(operation == ORANGE){                            //If orange drink is desired...
        temp_qty = VM_internals[ORANGE].qty;            //Gets orange drink quantity.
    }
    else if(operation == YELLOW){                       //If yellow drink is desired...
        temp_qty = VM_internals[YELLOW].qty;            //Gets yellow drink quantity.
    }
    else if(operation == RED){                          //If red drink is desired...
        temp_qty = VM_internals[RED].qty;               //Gets red drink quantity.
    }
    
    xSemaphoreGive(xMutex_vDatabase);                   //Releases.
    return temp_qty;                                    //Returns desired drink quantity.
}


/**********************************************************************************************
* Name: int mutex_SetPriceVM(int operation)
* Description: Public function definition for Lab3 and Lab4 RTOS vDatabase. The following code 
*              sets a drink's price. One argument needs to be passed: the first being the drink 
*              that you want to set the price for.
*              Macro constants can be found in public.h or vDatabase.h file.  
* 
***********************************************************************************************/
void mutex_SetPriceVM(int temp_set, int operation){
    xSemaphoreTake(xMutex_vDatabase, portMAX_DELAY);    //Takes.
    
    if(temp_set < 0){                                   //If drink price is less than 0Q...
        temp_set = 0;                                   //Set drink price to 0Q.
    }
    else if(temp_set > MAX_CREDIT){                     //If drink price exceeds maximum user credit.
        temp_set = MAX_CREDIT;                          //Set drink price to maximum user credit.
    }
    if(operation == ORANGE){                            //If orange drink is desired...
        VM_internals[ORANGE].price = temp_set;          //Gets orange drink price.
    }
    else if(operation == YELLOW){                       //If yellow drink is desired...
        VM_internals[YELLOW].price = temp_set;          //Gets yellow drink price.
    }
    else if(operation == RED){                          //If red drink is desired...
        VM_internals[RED].price = temp_set;             //Gets red drink price.
    }
    
    xSemaphoreGive(xMutex_vDatabase);                   //Releases.
}


/**********************************************************************************************
* Name: int mutex_GetPriceVM(int operation)
* Description: Public function definition for Lab3 and Lab4 RTOS vDatabase. The following code 
*              returns the price of a drink. One argument needs to be passed: the first being 
*              the drink that you want to get the price from.
*              Macro constants can be found in public.h or vDatabase.h file. 
* 
***********************************************************************************************/
int mutex_GetPriceVM(int operation){
    int temp_price;                                     //Temp variable.
    xSemaphoreTake(xMutex_vDatabase, portMAX_DELAY);    //Takes.
    
    if(operation == ORANGE){                            //If orange drink is desired...
        temp_price = VM_internals[ORANGE].price;        //Gets orange drink price.
    }
    else if(operation == YELLOW){                       //If yellow drink is desired...
        temp_price = VM_internals[YELLOW].price;        //Gets yellow drink price.
    }
    else if(operation == RED){                          //If red drink is desired...
        temp_price = VM_internals[RED].price;           //Gets red drink price.
    }
    
    xSemaphoreGive(xMutex_vDatabase);                   //Releases.
    return temp_price;                                  //Returns desired drink price.
}


/**********************************************************************************************
* Name: char mutex_GetNameVM(int operation)
* Description: Public function definition for Lab3 and Lab4 RTOS vDatabase. The following code 
*              returns the name of a drink. One argument needs to be passed: the first being 
*              the drink that you want to get the name from.
*              Macro constants can be found in public.h or vDatabase.h file. 
* 
***********************************************************************************************/
char mutex_GetNameVM(int operation){
    char* temp_name;                                    //Temp variable.
    xSemaphoreTake(xMutex_vDatabase, portMAX_DELAY);    //Takes.
    
    if(operation == ORANGE){                            //If orange drink is desired...
        temp_name = VM_internals[ORANGE].name;          //Gets orange drink name.
    }
    else if(operation == YELLOW){                       //If yellow drink is desired...
        temp_name = VM_internals[YELLOW].name;          //Gets yellow drink name.
    }
    else if(operation == RED){                          //If red drink is desired...
        temp_name = VM_internals[RED].name;             //Gets red drink name.
    }
    
    xSemaphoreGive(xMutex_vDatabase);                   //Releases.
    return *temp_name;                                  //Returns desired drink name.
}


/**********************************************************************************************
* Name: void mutex_SetCreditVM(int temp_set)
* Description: Public function definition for Lab3 and Lab4 RTOS vDatabase. The following code 
*              sets the user's credit for the vending machine. One argument needs to be 
*              passed: the user has to pass the credit quantity upon calling this function.
*              Macro constants can be found in public.h or vDatabase.h file.  
* 
***********************************************************************************************/
void mutex_SetCreditVM(int temp_set){
    xSemaphoreTake(xMutex_UserCredit, portMAX_DELAY);   //Takes.
    
    if(temp_set < 0){                                   //If user credit less than 0Q...
        totalCredit = 0;                                //Set user credit to 0Q.
    }
    else{                                               //Otherwise...
        totalCredit = temp_set;                         //Sets user credit.
    }
    
    xSemaphoreGive(xMutex_UserCredit);                  //Releases.
}


/**********************************************************************************************
* Name: int mutex_GetCreditVM(void)
* Description: Public function definition for Lab3 and Lab4 RTOS vDatabase. The following code 
*              gets the user's credit for the vending machine. No arguments need to be passed. 
*              Macro constants can be found in public.h or vDatabase.h file. 
* 
***********************************************************************************************/
int mutex_GetCreditVM(void){
    int temp_get;                                       //Temp variable.
    xSemaphoreTake(xMutex_UserCredit, portMAX_DELAY);   //Takes.
    
    temp_get = totalCredit;                             //Retrieves user credit.
    
    xSemaphoreGive(xMutex_UserCredit);                  //Releases.
    return temp_get;                                    //Returns user credit.
}


/**********************************************************************************************
* Name: void mutex_SetCreditQuantity(int temp_set)
* Description: Public function definition for Lab4 RTOS vDatabase. The following code sets the
*              vending machine's internal quarter quantity. One argument needs to be passed:
*              the user needs to pass the quarter quantity upon calling this function.
*              Macro constants can be found in public.h or vDatabase.h file. 
* 
***********************************************************************************************/
void mutex_SetCreditQuantity(int temp_set){
    xSemaphoreTake(xMutex_CreditQuantity, portMAX_DELAY);   //Takes.
    
    if(temp_set < 0){                                       //If credit quantity less than 0Q...
        totalCreditQuantity = 0;                            //Set credit quantity to 0Q.
    }
    else{                                                   //Otherwise...
        totalCreditQuantity = temp_set;                     //Sets credit quantity.
    }
    
    xSemaphoreGive(xMutex_CreditQuantity);                  //Releases.
}


/**********************************************************************************************
* Name: int mutex_GetCreditQuantity(void)
* Description: Public function definition for Lab4 RTOS vDatabase. The following code gets the
*              vending machine's internal quarter quantity. No arguments needs to be passed.
*              Macro constants can be found in public.h or vDatabase.h file. 
* 
***********************************************************************************************/
int mutex_GetCreditQuantity(void){
    int temp_get;                                           //Temp variable.
    xSemaphoreTake(xMutex_CreditQuantity, portMAX_DELAY);   //Takes.
    
    temp_get = totalCreditQuantity;                         //Retrieves credit quantity.
    
    xSemaphoreGive(xMutex_CreditQuantity);                  //Releases.
    return temp_get;
}


/**********************************************************************************************
* Name: void mutex_SetTransactionTime(int64_t temp_set)
* Description: Public function definition for Lab4 RTOS vDatabase. The following code sets the
*              vending machine's latest successful transaction time. Only one argument needs to
*              be passed: the user has to pass the timestamp of the transaction upon calling
*              this function.
*              Macro constants can be found in public.h or vDatabase.h file.
* 
***********************************************************************************************/
void mutex_SetTransactionTime(int64_t temp_set){
    xSemaphoreTake(xMutex_TransactionTime, portMAX_DELAY);  //Takes.

    TransactionTime = temp_set;                             //Sets VM transaction time.
    
    xSemaphoreGive(xMutex_TransactionTime);                 //Releases.
}


/**********************************************************************************************
* Name: int mutex_GetTransactionTime(void)
* Description: Public function definition for Lab4 RTOS vDatabase. The following code gets the
*              vending machine's latest successful transaction time. No arguments need to be
*              passed.
*              Macro constants can be found in public.h or vDatabase.h file.
* 
***********************************************************************************************/
int mutex_GetTransactionTime(void){
    static int64_t  TickDiff;                               //Temp variables.
    static int64_t  lastTick;                               //" ".
    int temp_get;
    xSemaphoreTake(xMutex_TransactionTime, portMAX_DELAY);  //Takes.

    lastTick = TickGet();                                   //Timestamp.
    TickDiff = lastTick - TransactionTime;                  //Calculates last transaction time in ticks.
    temp_get = TickDiff/TICKS_PER_SECOND;                   //Calculates last transaction time in seconds.
    
    xSemaphoreGive(xMutex_TransactionTime);                 //Releases.
    return temp_get;                                        //Returns last transaction time in seconds.
}


/**********************************************************************************************
* Name: void mutex_SetFridgeTemperature(int temp_set)
* Description: Public function definition for Lab4 RTOS vDatabase. The following code sets the
*              vending machine's internal temperature. One argument needs to be passed: the 
*              user needs to pass the temperature value upon calling this function.
*              Macro constants can be found in public.h or vDatabase.h file.
* 
***********************************************************************************************/
void mutex_SetFridgeTemperature(int temp_set){
    xSemaphoreTake(xMutex_FridgeTemperature, portMAX_DELAY);    //Takes.
    
    FridgeTemperature = temp_set;                               //Sets fridge temperature.
    
    xSemaphoreGive(xMutex_FridgeTemperature);                   //Releases.
}


/**********************************************************************************************
* Name: int mutex_GetFridgeTemperature(void)
* Description: Public function definition for Lab4 RTOS vDatabase. The following code gets the
*              vending machine's internal temperature. No arguments need to be passed.
*              Macro constants can be found in public.h or vDatabase.h file.
* 
***********************************************************************************************/
int mutex_GetFridgeTemperature(void){
    int temp_get;                                               //Temp variable.
    xSemaphoreTake(xMutex_FridgeTemperature, portMAX_DELAY);    //Takes.
    
    temp_get = FridgeTemperature;                               //Gets fridge temperature.
    
    xSemaphoreGive(xMutex_FridgeTemperature);                   //Releases.
    return temp_get;
}


/**********************************************************************************************
* Name: void mutex_SetTechnicianStatus(int temp_set)
* Description: Public function definition for Lab4 RTOS vDatabase. The following code sets the
*              status of the vending machine technician task. One argument needs to be passed:
*              the user needs to specify if the technician task is running or not (1 or 0).
*              Macro constants can be found in public.h or vDatabase.h file.
* 
***********************************************************************************************/
void mutex_SetTechnicianStatus(int temp_set){
    xSemaphoreTake(xMutex_TechnicianStatus, portMAX_DELAY);     //Takes.
    
    TechnicianStatus = temp_set;                                //Sets technician task status.
   
    xSemaphoreGive(xMutex_TechnicianStatus);                    //Gives.
}


/**********************************************************************************************
* Name: int mutex_GetTechnicianStatus(void)
* Description: Public function definition for Lab4 RTOS vDatabase. The following code gets the
*              status of the vending machine task. No arguments need to be passed.
*              Macro constants can be found in public.h or vDatabase.h file.
* 
***********************************************************************************************/
int mutex_GetTechnicianStatus(void){
    int temp_get;                                               //Temp variable.
    xSemaphoreTake(xMutex_TechnicianStatus, portMAX_DELAY);     //Takes.
    
    temp_get = TechnicianStatus;                                //Gets technician task status.
    
    xSemaphoreGive(xMutex_TechnicianStatus);                    //Gives.
    return temp_get;                                            //Returns.
}
