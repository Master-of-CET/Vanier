/**************************************************************************************************
* FileName: vTaskUI.c
*
* Name: Leonardo Fusser (1946995)       Lab 3       Vending Machine
*                                       Lab 4       Vending Machine II 
*
* Description: vTaskUI source file for Lab3 and Lab4. This file contains the core vending machine 
*              operation algorithm. A thread continously runs to operate the vending machine's 
*              functions. The user can interact with the vending machine using three pushbuttons on 
*              the Explorer 16/32 board (S3, S4 and S6).
*              Macro constants can be found in the vTaskUI.h or public.h file.     
*  
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   17 February 2022    v1.0.0      First version of source file.
*                                                   Added includes. 
*                                                   Partially populated vTaskUI() function.
*                                                   Created vInit_vTaskUI() function.
*                                                   Created vInit_StartTaskUI() function.
*                                                   Implemented macros.
*                                                   Added comments.
* Leonardo Fusser   5 March 2022        v1.0.1      Partially populated vTaskUI() task.
*                                                   Created delay_Blocking() function.
*                                                   Added comments.
* Leonardo Fusser   9 March 2022        v1.0.2      Completed vTaskUI() task.
*                                                   Added comments.
* Leonardo Fusser   10 April 2022       v2.0.0      Added new features to user interface.
*                                                   Added disable feature for temperature issue.
*                                                   Added disable feature for technician servicing.
*                                                   Added vending machine internal quarter tracking.
*                                                   Added vending machine transaction time tracking.
*                                                   Added comments.
*                                                   Completed source file.
* Leonardo Fusser   17 April 2022       v2.0.1      Modified vending machine disable printing to
*                                                   appear automatically on the console.
*                                                   Added comments.
* Leonardo Fusser   21 May 2022         v2.0.2      Minor changes.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/* Includes. */
#include "include/vTaskUI.h"


/**********************************************************************************************
* Name: static void vTaskUI(void *pvParameters) 
* Description: Private static function definition for Lab3 and Lab4 RTOS vTaskUI. This is the 
*              thread routine that continously runs to provide the user with the vending machine
*              functionality.  
*              Macro constants can be found in public.h file or vTaskUI.h file.
* 
***********************************************************************************************/
static void vTaskUI( void *pvParameters ){
    
    pvParameters = pvParameters ;                                                       //This is to get rid of annoying warnings.
    
    int16_t statePB = 0;                                                                //Variable to hold all PB states.
    int64_t lastTick;                                                                   //Timestamp variable.
    char PrintBuffer[20];                                                               //Printing buffer.
    char* DrinkName;                                                                    //Variable to store drink names.
    int Menu_DrinkPrice, Menu_UserCredit,                                               //Multiple other variables.
        Menu_DrinkQty, Menu_CycleCount = 0,                                             //" ".
        Vending_PrintFlag = 0, Disable_PrintFlag = 0;                                   //" ".
    
    enum {SM_MAIN_MENU, SM_DEB, SM_POLL, SM_DRINK_MENU,                                 //State machine states.
          SM_CREDIT_CRUNCHING, SM_CREDIT_PRINT,                                         //" ".
          SM_VENDING_CRUNCHING, SM_VENDING_PRINT,                                       //" ".
          SM_DISABLE_VM_PRINT, SM_DISABLE_VM_CRUNCH}stateUI = 0;                        //" ".
    	    
    /* Mini infinite loop. */
    while(1){
        
        vTaskDelay(DELAY_TaskUI/portTICK_RATE_MS);                                      //Gives slack time to the system.
        
        switch(stateUI){
            
            /* Main menu state. *////////////////////////////////////////////////////////////////////////////////////////////////////////
            case SM_MAIN_MENU:
                if(mutex_GetTechnicianStatus() == BUSY){                                            //If vTaskTemperature() running...
                    Disable_PrintFlag = 1;                                                          //Sets printing flag accordingly.
                    stateUI = SM_DISABLE_VM_PRINT;                                                  //Move on to next state.
                }
                else if(mutex_GetFridgeTemperature() <= -5 || mutex_GetFridgeTemperature() >= 5){   //Otherwise, if fridge temp error...
                    Disable_PrintFlag = 2;                                                          //Sets printing flag accordingly.
                    stateUI = SM_DISABLE_VM_PRINT;                                                  //Move on to next state.
                }
                else{                                                                               //Otherwise...
                    Menu_CycleCount = 0;                                                            //Resets drink menu count upon reset.
                    
                    /* Prints main menu. */
                    sprintf(PrintBuffer, "Select items        \nPress S3++        \n");
                    fprintf2(CONSOLE_1, PrintBuffer);                                       
                
                    stateUI = SM_POLL;                                                              //Moves on to next state.    
                }
            break;
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            /* PB polling state. *//////////////////////////////////////////////////////////////////////////////////////////////////////
            case SM_POLL:
                if(mutex_GetTechnicianStatus() == BUSY){                                            //If vTaskTemperature() running...
                    Disable_PrintFlag = 1;                                                          //Sets printing flag accordingly.
                    stateUI = SM_DISABLE_VM_PRINT;                                                  //Move on to next state.
                }
                else if(mutex_GetFridgeTemperature() <= -5 || mutex_GetFridgeTemperature() >= 5){   //Otherwise, if fridge temp error...
                    Disable_PrintFlag = 2;                                                          //Sets printing flag accordingly.
                    stateUI = SM_DISABLE_VM_PRINT;                                                  //Move on to next state.
                }
                else{                                                                               //Otherwise...                                                              
                    statePB = (S6 << 2 | S4 << 1 | S3) & NO_PRESS;                                  //Read all PBs.
                    if(statePB == S3_PRESS){                                                        //If S3 is pressed...
                        stateUI = SM_DEB;                                                           //Moves on to next state.
                        lastTick = TickGet();                                                       //Timestamp.
                    }
                }
            break;
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            /* PB debouncing state. *///////////////////////////////////////////////////////////////////////////////////
            case SM_DEB:
                if(TickGet() - lastTick <= (DELAY_3S)){                 //If 3-seconds has not elapsed...
                    if(TickGet() - lastTick >= (DELAY_200mS)){          //If 200mS has elapsed...
                        statePB = (S6 << 2 | S4 << 1 | S3) & NO_PRESS;  //Read all PBs again.
                        if(statePB == S3_PRESS){                        //If S3 is pressed...
                            if(Menu_CycleCount == STRUCT_DEPTH){        //If drink menu count has reached its end...
                                Menu_CycleCount = 0;                    //Reset drink menu count to 0.
                            }
                            stateUI = SM_DRINK_MENU;                    //Moves on to next state.
                            lastTick = TickGet();                       //Timestamp.
                        }
                        else if(statePB == S4_PRESS){                   //If S4 is pressed...
                            stateUI = SM_CREDIT_CRUNCHING;              //Moves on to next state.
                            lastTick = TickGet();                       //Timestamp.
                        }
                        else if(statePB == S6_PRESS){                   //If S6 is pressed...
                            stateUI = SM_VENDING_CRUNCHING;             //Moves on to next state.
                            lastTick = TickGet();                       //Timestamp.
                        }
                    }
                }
                else if(TickGet() - lastTick >= (DELAY_3S)){            //Otherwise, if 3-seconds has elapsed...
                    stateUI = SM_MAIN_MENU;                             //Moves on to next state (go back to main menu).
                }
            break;
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            /* Drink menu SM. *////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            case SM_DRINK_MENU:
                if(Menu_CycleCount < 0){Menu_CycleCount = 0;}                           //Prevents drink menu from printing incorrectly.
                if(Menu_CycleCount >= STRUCT_DEPTH){Menu_CycleCount = STRUCT_DEPTH-1;}  //" ".
                if(Menu_CycleCount == ORANGE){DrinkName = "Orange";}                    //If S3 pressed once, change drink name to first drink.
                if(Menu_CycleCount == YELLOW){DrinkName = "Yellow";}                    //If S3 pressed twice, change dink name to second drink.
                if(Menu_CycleCount == RED){DrinkName = "Red";}                          //If S3 pressed three times, change drink name to third drink.
                Menu_DrinkPrice = mutex_GetPriceVM(Menu_CycleCount);                    //Gets current drink price.
                Menu_UserCredit = mutex_GetCreditVM();                                  //Gets current user credit.
                
                /* Prints drink menu. */
                sprintf(PrintBuffer, "%s price: %dQ        \nCredit: %dQ        \n", DrinkName, Menu_DrinkPrice, Menu_UserCredit);
                fprintf2(CONSOLE_1, PrintBuffer);
                
                vTaskDelay(400/portTICK_RATE_MS);                                       //Gives more slack time and slows down menu cycling.

                Menu_CycleCount += 1;                                                   //Increment drink menu count by 1.
                stateUI = SM_DEB;                                                       //Moves on to next state.
                lastTick = TickGet();                                                   //Timestamp.
            break;
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            /* Credit crunching SM. *////////////////////////////////////////////////////////////////////////////////////////////////////
            case SM_CREDIT_CRUNCHING:
                Menu_CycleCount -= 1;                                                   //Prevents drink menu from printing incorrectly.
                if(Menu_CycleCount < 0){Menu_CycleCount = 0;}                           //" ".
                Menu_UserCredit = mutex_GetCreditVM();                                  //Gets current user credit.
                if(Menu_UserCredit > MAX_CREDIT){                                       //If user enters too much credit...
                    stateUI = SM_CREDIT_PRINT;                                          //Moves on to next state.
                    lastTick = TickGet();                                               //Timestamp.
                }
                else{                                                                   //Otherwise...
                    mutex_SetCreditVM(Menu_UserCredit += 1);                            //Increment user credit by 1Q.
                    stateUI = SM_DRINK_MENU;                                            //Moves on to next state.
                    lastTick = TickGet();                                               //Timestamp.
                }
            break;
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            /* Vending crunching SM. *////////////////////////////////////////////////////////////////////////////////////////////////////////////
            case SM_VENDING_CRUNCHING:
                Menu_CycleCount -= 1;                                                   //Prevents drink menu from printing incorrectly.
                if(Menu_CycleCount < 0){Menu_CycleCount = 0;}                           //" ".
                Menu_UserCredit = mutex_GetCreditVM();                                  //Gets current user credit.
                Menu_DrinkPrice = mutex_GetPriceVM(Menu_CycleCount);                    //Gets current drink price.
                Menu_DrinkQty = mutex_GetQtyVM(Menu_CycleCount);                        //Gets current drink quantity.
                if(Menu_UserCredit < Menu_DrinkPrice){                                  //If user has too little credit...
                    Vending_PrintFlag = 1;                                              //Flag to print insufficient credit menu.
                    stateUI = SM_VENDING_PRINT;                                         //Moves on to next state.
                    lastTick = TickGet();                                               //Timestamp.
                }
                else if(Menu_DrinkQty == 0){                                            //If selected drink quantity is 0...
                    Vending_PrintFlag = 2;                                              //Flag to print out of stock menu.
                    stateUI = SM_VENDING_PRINT;                                         //Moves on to next state.
                    lastTick = TickGet();                                               //Timestamp.
                }
                else if(Menu_UserCredit >= Menu_DrinkPrice && Menu_DrinkQty > 0){       //If user has enough credit and drinks are available...
                    mutex_SetCreditQuantity(mutex_GetCreditQuantity() +                 //Sets VM internal quarter quantity.
                                            Menu_DrinkPrice);                           //" ".
                    mutex_SetTransactionTime(TickGet());                                //Sets successful transaction time.
                    mutex_SetCreditVM(Menu_UserCredit - Menu_DrinkPrice);               //Sets new user credit.
                    mutex_SetQtyVM(Menu_DrinkQty -= 1, Menu_CycleCount);                //Sets new drink quantity.
                    Vending_PrintFlag = 3;                                              //Flag to print vending menu.
                    stateUI = SM_VENDING_PRINT;                                         //Moves on to next state.
                    lastTick = TickGet();                                               //Timestamp.
                }
            break;
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            /* Vending print SM. */////////////////////////////////////////////////////////////////////////////////////////////////////
            case SM_VENDING_PRINT:
                if(TickGet() - lastTick <= (DELAY_3S)){                                 //If 3-seconds has not elapsed...                
                    if(Vending_PrintFlag == 1){                                         //If insufficient credit menu selected...
                        
                        /* Prints insufficient credit menu. */
                        sprintf(PrintBuffer, "Insuffi credits!        \nMissing: %dQ        \n", Menu_DrinkPrice - Menu_UserCredit);
                        fprintf2(CONSOLE_1, PrintBuffer);
                    
                    }
                    else if(Vending_PrintFlag == 2){                                    //If out of stock menu selected...
                        
                        /* Prints out of drinks menu. */
                        sprintf(PrintBuffer, "Sorry!               \nOut of drinks.        \n");
                        fprintf2(CONSOLE_1, PrintBuffer);
                    
                    }
                    else if(Vending_PrintFlag == 3){                                    //If vending menu selected...
                        
                        /* Prints vending menu. */
                        sprintf(PrintBuffer, "Vending...        \n                \n");
                        fprintf2(CONSOLE_1, PrintBuffer);
                    
                    }
                }
                else if(TickGet() - lastTick >= (DELAY_3S)){                            //Otherwise, if 3-seconds has elapsed...
                    stateUI = SM_DRINK_MENU;                                            //Moves on to next state (go back to main menu).
                    lastTick = TickGet();                                               //Timestamp.
                }
            break;
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            /* Credit print SM. *///////////////////////////////////////////////////////////////////////////////////////////////////////
            case SM_CREDIT_PRINT:
                if(TickGet() - lastTick <= (DELAY_3S)){                                 //If 3-seconds has not elapsed...   
                    
                    /* Prints credit exceeded menu. */
                    sprintf(PrintBuffer, "Credit exceeded!        \nCoin returned.        \n");
                    fprintf2(CONSOLE_1, PrintBuffer);
                
                }
                else if(TickGet() - lastTick >= (DELAY_3S)){                            //Otherwise, if 3-seconds has elapsed...
                    stateUI = SM_DRINK_MENU;                                            //Moves on to next state (go back to main menu).
                    lastTick = TickGet();                                               //Timestamp.
                }
            break;
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            /* Disable VM SM. *//////////////////////////////////////////////////////////////////
            case SM_DISABLE_VM_PRINT:
                if(Disable_PrintFlag == 1){             //If printing flag set to 1...
                    
                    /* Prints "out of order" message. */
                    sprintf(PrintBuffer, "Out of order.        \nIn service!        \n");
                    fprintf2(CONSOLE_1, PrintBuffer);
                    
                }
                else if(Disable_PrintFlag == 2){        //Otherwise, if printing flag set to 2...
                    
                    /* Prints "out of order" message. */
                    sprintf(PrintBuffer, "Out of order.        \nTemp. issue!        \n");
                    fprintf2(CONSOLE_1, PrintBuffer);
                    
                }
                stateUI = SM_DISABLE_VM_CRUNCH;         //Moves on to next state.
            break;
            /////////////////////////////////////////////////////////////////////////////////////
            
            /* VM disable SM. *////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            case SM_DISABLE_VM_CRUNCH:
                if(mutex_GetTechnicianStatus() == FREE){                                            //If vTaskTechnician() no longer running... 
                    if(mutex_GetFridgeTemperature() >= -5 || mutex_GetFridgeTemperature() <= 5){    //If no fridge temp. issue...
                        stateUI = SM_MAIN_MENU;                                                     //Move on to next state.
                    }
                }
                else{                                                                               //Otherwise...
                    stateUI = SM_DISABLE_VM_CRUNCH;                                                 //Stay in this state.
                }
            break;
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
        }
    }
}


/**********************************************************************************************
* Name: void vInit_TaskUI(void) 
* Description: Public function definition for Lab3 and Lab4 RTOS vTaskUI. This function calls a 
*              initializing function for vTaskUI.
* 
***********************************************************************************************/
void vInit_vTaskUI(void){
    /* Calls init function for vTaskUI. */
    vInit_StartTaskUI();
}


/**********************************************************************************************
* Name: void vInit_StartTaskUI(void) 
* Description: Public function definition for Lab3 and Lab4 RTOS vTaskUI. This function creates 
*              vTaskUI.
*              Macro constants can be found in public.h file or vTaskUI.h file. 
* 
***********************************************************************************************/
void vInit_StartTaskUI(void){
    /* Creates task with user-set priority. */
    xTaskCreate( vTaskUI, ( char * ) "TaskUI", 240, NULL, PRIORITY_TaskUI, NULL );
}
