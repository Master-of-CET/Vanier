/**************************************************************************************************
* FileName: vTaskTechnician.c
*
* Name: Leonardo Fusser (1946995)       Lab 4       Vending Machine II
*
* Description: vTaskTechnician source file for Lab4. This file contains the vending machine's
*              technician algorithm. A thread only runs to operate the vending machine's 
*              technician algorithm when the user has sent some characters through a console. The 
*              user can interact with the vending machine technician task using a console like
*              TeraTerm or PuTTy.
*              Macro constants can be found in the vTaskTechnician.h or public.h file.
*
* REVISION HISTORY: 
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser   10 March 2022       v1.0.0      First version of source file.
*                                                   Added includes.
*                                                   Created all init functions.
*                                                   Created thread routine.
* Leonardo Fusser   3  April 2022       v1.0.1      Partially populated thread routine.
*                                                   Added comments.
* Leonardo Fusser   10 April 2022       v1.0.2      Completed thread routine.
*                                                   Added comments.
*                                                   Completed source file.
* Leonardo Fusser   17 April 2022       v1.0.3      Modified receiving queue to print received 
*                                                   values to console.
*                                                   Added comments.
* Leonardo Fusser   21 May 2022         v1.0.4      Minor changes.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/* Includes. */
#include "include/vTaskTechnician.h"


/* Private queue declaration. */
static QueueHandle_t xQueue_TaskTechnician = NULL;


/**********************************************************************************************
* Name: static void vTaskTechnician(void *pvParameters) 
* Description: Private static function definition for Lab4 RTOS vTaskTechnician. This is the 
*              thread routine that runs the vending machine technician task. When the user
*              connects to a console, after entering any key, the user will be prompted with
*              a main menu with all related possible technician tasks.
*              Macro constants can be found in public.h or vTaskTechnician.h file.
*
***********************************************************************************************/
static void vTaskTechnician( void *pvParameters ){
    
    pvParameters = pvParameters;            //This is to get rid of annoying warnings.
    char Queue_rx;                          //Receiving queue data variable. 
    char TaskTechnician_rx[QUEUE_DEPTH];    //Receiving string array.
    char temp_buffer[QUEUE_DEPTH];          //Buffer for atoi().
    char PrintBuff[20];                     //Printing buffer.
    int PollFlag = 1;                       //Control flag for initial user console prompt.
    int QueueFlag = 0;                      //Control flag for receiving queue.
    int PriceFlag = 0;                      //Control flag for vending machine drink prices.
    int i = 0;                              //Receiving string array element variable.
    int DrinkQty;                           //Stores result from atoi() for drink quantity.
    int DrinkPrice;                         //Stores result from atoi() for drink price.
    
    enum {SM_QUEUE_WAIT, SM_POLL, SM_MENU, SM_LOAD,                             //State machine states.
          SM_READ_TEMPERATURE, SM_REMOVE_MONEY, SM_TRANSACTION_TIME,            //" ".
          SM_READ_MONEY, SM_READ_STOCK, SM_CHANGE_PRICES}stateTECHNICIAN = 0;   //" ".
    
    /* Mini infinite loop. */
    while(1){
        
        vTaskDelay(DELAY_TaskTechnician/portTICK_RATE_MS);                                  //Gives slack time to the system.
        
        switch(stateTECHNICIAN){
            
            /* Queue reception state (blocking queue). *//////////////////////////////////////////////////////////////////////////////////////////////////////
            case SM_QUEUE_WAIT:
                
                if(QueueFlag == 0){                                                         //If receiving queue is enabled...
                    
                    /* Blocking queue reception. */
                    xQueueReceive(xQueue_TaskTechnician, &Queue_rx, portMAX_DELAY);
                    
                    /* Prints received user input. */
                    sprintf(temp_buffer, "%c", Queue_rx);
                    fprintf2(CONSOLE_TaskTechnician, temp_buffer);
                    
                    mutex_SetTechnicianStatus(BUSY);                                        //Disables vending machine for user.
                
                    if (PollFlag == 0){                                                     //If initial user console prompt not selected...
                        if(PriceFlag == 1){                                                 //If control flag for vending machine drink prices selected...
                            if(Queue_rx == '\n' || Queue_rx == '\r'){                       //Wait until end-of-string is received...
                                i = 0;                                                      //Clear receiving count.
                                QueueFlag = 1;                                              //Disables control flag for receiving queue.
                                fprintf2(CONSOLE_TaskTechnician, "\n");                     //Prints newline character onto console.
                                stateTECHNICIAN = SM_CHANGE_PRICES;                         //Move on to next state.
                            }
                            else if(Queue_rx != '\n' || Queue_rx != '\r'){                  //If end-of-string has not been received...
                                TaskTechnician_rx[i] = Queue_rx;                            //Store received character in array.
                                i += 1;                                                     //Increment receiving count for subsequent characters.
                            }
                        }
                        else if(PriceFlag == 0){                                            //If control flag for vending machine drink prices not selected...
                            if(Queue_rx == '\n' || Queue_rx == '\r'){                       //Wait until end-of-string is received...
                                i = 0;                                                      //Clear receiving count.
                                QueueFlag = 1;                                              //Disables control flag for receiving queue.
                                fprintf2(CONSOLE_TaskTechnician, "\n");                     //Prints newline character onto console.
                                stateTECHNICIAN = SM_POLL;                                  //Move on to next state.
                            }
                            else if(Queue_rx != '\n' || Queue_rx != '\r'){                  //If end-of-string has not been received...
                                TaskTechnician_rx[i] = Queue_rx;                            //Store received character in array.
                                i += 1;                                                     //Increment receiving count for subsequent characters.
                            }
                        }
                    }
                    else if(PollFlag == 1){                                                 //Otherwise, if initial user console prompt selected...
                        if(Queue_rx == '\n' || Queue_rx == '\r'){                           //Wait until end-of-string is received...
                            QueueFlag = 1;                                                  //Disables control flag for receiving queue.
                            stateTECHNICIAN = SM_MENU;                                      //Move on to next state.
                        }
                    }
                }
            break;
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            /* Technician main menu state. */////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            case SM_MENU:
                fprintf2(CONSOLE_TaskTechnician, "\n\r");                                                                                           //Prints main menu.
                fprintf2(CONSOLE_TaskTechnician, "******************************************************************************************\n\r"); //" ".
                fprintf2(CONSOLE_TaskTechnician, "[Explorer 16/32 Vending Machine]\n\r");                                                           //" ".
                fprintf2(CONSOLE_TaskTechnician, "Enter 'd' to refresh display.\n\r");                                                              //" ".
                fprintf2(CONSOLE_TaskTechnician, "Enter 'o' followed by a 2 digit value between 00 and 99 to load orange bottles.\n\r");            //" ".
                fprintf2(CONSOLE_TaskTechnician, "Enter 'r' followed by a 2 digit value between 00 and 99 to load red bottles.\n\r");               //" ".
                fprintf2(CONSOLE_TaskTechnician, "Enter 'y' followed by a 2 digit value between 00 and 99 to load yellow bottles.\n\r");            //" ".
                fprintf2(CONSOLE_TaskTechnician, "Enter 't' to read the vending machine fridge temperature.\n\r");                                  //" ".
                fprintf2(CONSOLE_TaskTechnician, "Enter 'e' when the vending machine money has been emptied.\n\r");                                 //" ".
                fprintf2(CONSOLE_TaskTechnician, "Enter 'h' to determine the last successful vending machine transaction time (in seconds).\n\r");  //" ".
                fprintf2(CONSOLE_TaskTechnician, "Enter 'm' to read the number of quarters inside the vending machine.\n\r");                       //" ".
                fprintf2(CONSOLE_TaskTechnician, "Enter 's' to read the vending machine soda stock.\n\r");                                          //" ".
                fprintf2(CONSOLE_TaskTechnician, "Enter 'p' to change the vending machine soda prices.\n\r");                                       //" ".
                fprintf2(CONSOLE_TaskTechnician, "Enter 'k' to check out from servicing.\n\r");                                                     //" ".
                fprintf2(CONSOLE_TaskTechnician, "******************************************************************************************\n\r"); //" ".
                PollFlag = 0;                                                                                   //Disables control flag for initial user console prompt.
                PriceFlag = 0;                                                                                  //Disables control flag for vending machine drink prices.
                QueueFlag = 0;                                                                                  //Enables control flag for receiving queue.
                memset(TaskTechnician_rx, 0, sizeof TaskTechnician_rx);                                         //Clears receiving string array.
                stateTECHNICIAN = SM_QUEUE_WAIT;                                                                //Move on to next state.
            break;
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            /* Polling state. *//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            case SM_POLL:
            
                if(TaskTechnician_rx[0] == 'd'){                                                                                            //If "d" has been received...
                    stateTECHNICIAN = SM_MENU;                                                                                              //Move on to next state.
                }
                else if(TaskTechnician_rx[0] == 'o' ||                                                                                      //If "o" has been received...
                        TaskTechnician_rx[0] == 'r' ||                                                                                      //Or if "r" has been received...
                        TaskTechnician_rx[0] == 'y'){                                                                                       //Or if "y" has been received...
                    stateTECHNICIAN = SM_LOAD;                                                                                              //Move on to next state.
                }
                else if(TaskTechnician_rx[0] == 't'){                                                                                       //If "t" has been received...
                    stateTECHNICIAN = SM_READ_TEMPERATURE;                                                                                  //Move on to next state.
                }
                else if(TaskTechnician_rx[0] == 'e'){                                                                                       //If "e" has been received...
                    stateTECHNICIAN = SM_REMOVE_MONEY;                                                                                      //Move on to next state.
                }
                else if(TaskTechnician_rx[0] == 'h'){                                                                                       //If "h" has been received...
                    stateTECHNICIAN = SM_TRANSACTION_TIME;                                                                                  //Move on to next state.
                }
                else if(TaskTechnician_rx[0] == 'm'){                                                                                       //If "m" has been received...
                    stateTECHNICIAN = SM_READ_MONEY;                                                                                        //Move on to next state.
                }
                else if(TaskTechnician_rx[0] == 's'){                                                                                       //If "s" has been received...
                    stateTECHNICIAN = SM_READ_STOCK;                                                                                        //Move on to next state.
                }
                else if(TaskTechnician_rx[0] == 'p'){                                                                                       //If "p" has been received...
                    fprintf2(CONSOLE_TaskTechnician, "\n\r");                                                                               //Prints drink price sub-menu.
                    fprintf2(CONSOLE_TaskTechnician, "***************************************************************************\n\r");    //" ".
                    fprintf2(CONSOLE_TaskTechnician, "Enter 'op' followed by a 2 digit number to change orange price in quarters.\n\r");    //" ".
                    fprintf2(CONSOLE_TaskTechnician, "Enter 'rp' followed by a 2 digit number to change red price in quarters.\n\r");       //" ".
                    fprintf2(CONSOLE_TaskTechnician, "Enter 'yp' followed by a 2 digit number to change yellow price in quarters.\n\r");    //" ".
                    fprintf2(CONSOLE_TaskTechnician, "Enter 'd' to return to the main menu.\n\r");                                          //" ".
                    fprintf2(CONSOLE_TaskTechnician, "***************************************************************************\n\r");    //" ".
                    QueueFlag = 0;                                                                                                          //Enables control flag for receiving queue.
                    PriceFlag = 1;                                                                                                          //Disables control flag for vending machine drink prices.
                    memset(TaskTechnician_rx, 0, sizeof TaskTechnician_rx);                                                                 //Clears receiving string array.
                    stateTECHNICIAN = SM_QUEUE_WAIT;                                                                                        //Move on to next state.
                }
                else if(TaskTechnician_rx[0] == 'k'){                                                                                       //If "k" has been received...
                    fprintf2(CONSOLE_TaskTechnician, "\n\r");                                                                               //Prints checkout sub-menu.
                    fprintf2(CONSOLE_TaskTechnician, "**************************\n\r");                                                     //" ".
                    fprintf2(CONSOLE_TaskTechnician, "Checking out. Goodbye! ...\n\r");                                                     //" ".
                    fprintf2(CONSOLE_TaskTechnician, "**************************\n\r");                                                     //" ".
                    mutex_SetTechnicianStatus(FREE);                                                                                        //Enables vending machine for user.
                    QueueFlag = 0;                                                                                                          //Enables control flag for receiving queue.
                    memset(TaskTechnician_rx, 0, sizeof TaskTechnician_rx);                                                                 //Clears receiving string array.
                    stateTECHNICIAN = SM_QUEUE_WAIT;                                                                                        //Move on to next state.
                }
                else{                                                                                                                       //Otherwise...
                    QueueFlag = 0;                                                                                                          //Enables control flag for receiving queue.
                    memset(TaskTechnician_rx, 0, sizeof TaskTechnician_rx);                                                                 //Clears receiving string array.
                    stateTECHNICIAN = SM_QUEUE_WAIT;                                                                                        //Move on to next state.
                }
            
            break;
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            /* Soda quantity loading state. *//////////////////////////////////////////////////////////////////////////////////////////////////////
            case SM_LOAD:
                
                sprintf(temp_buffer, "%c%c", TaskTechnician_rx[1], TaskTechnician_rx[2]);               //Stores ASCI number in buffer.
                DrinkQty = atoi(temp_buffer);                                                           //Converts ASCI number to integer.
                
                if(TaskTechnician_rx[0] == 'o'){                                                        //If orange drink selected...
                    mutex_SetQtyVM(mutex_GetQtyVM(ORANGE) + DrinkQty, ORANGE);                          //Sets new orange drink quantity.
                    fprintf2(CONSOLE_TaskTechnician, "\n\r");                                           //Prints new orange drink stock.
                    fprintf2(CONSOLE_TaskTechnician, "********************************\n\r");           //" ".
                    fprintf2(CONSOLE_TaskTechnician, "Orange stock updated!\n\r");                      //" ".
                    sprintf(PrintBuff, "Orange stock is now: %d bottles.\n\r", mutex_GetQtyVM(ORANGE)); //" ".
                    fprintf2(CONSOLE_TaskTechnician, PrintBuff);                                        //" ".
                    fprintf2(CONSOLE_TaskTechnician, "********************************\n\r");           //" ".                    
                }
                else if(TaskTechnician_rx[0] == 'r'){                                                   //If red drink selected...
                    mutex_SetQtyVM(mutex_GetQtyVM(RED) + DrinkQty, RED);                                //Sets new red drink quantity.
                    fprintf2(CONSOLE_TaskTechnician, "\n\r");                                           //Prints new red drink stock.
                    fprintf2(CONSOLE_TaskTechnician, "*****************************\n\r");              //" ".
                    fprintf2(CONSOLE_TaskTechnician, "Red stock updated!\n\r");                         //" ".
                    sprintf(PrintBuff, "Red stock is now: %d bottles.\n\r", mutex_GetQtyVM(RED));       //" ".
                    fprintf2(CONSOLE_TaskTechnician, PrintBuff);                                        //" ".
                    fprintf2(CONSOLE_TaskTechnician, "*****************************\n\r");              //" ".
                }
                else if(TaskTechnician_rx[0] == 'y'){                                                   //If yellow drink selected...
                    mutex_SetQtyVM(mutex_GetQtyVM(YELLOW) + DrinkQty, YELLOW);                          //Sets new yellow drink quantity.
                    fprintf2(CONSOLE_TaskTechnician, "\n\r");                                           //Prints new yellow drink stock.
                    fprintf2(CONSOLE_TaskTechnician, "********************************\n\r");           //" ".
                    fprintf2(CONSOLE_TaskTechnician, "Yellow stock updated!\n\r");                      //" ".
                    sprintf(PrintBuff, "Yellow stock is now: %d bottles.\n\r", mutex_GetQtyVM(YELLOW)); //" ".
                    fprintf2(CONSOLE_TaskTechnician, PrintBuff);                                        //" ".
                    fprintf2(CONSOLE_TaskTechnician, "********************************\n\r");           //" ".   
                }
                
                QueueFlag = 0;                                                                          //Enables control flag for receiving queue.
                memset(TaskTechnician_rx, 0, sizeof TaskTechnician_rx);                                 //Clears receiving string array.
                stateTECHNICIAN = SM_QUEUE_WAIT;                                                        //Move on to next state.
                
            break;
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            /* Read vending machine temperature state. *///////////////////////////////////////////////////////////////////////////////////////////////////////////////
            case SM_READ_TEMPERATURE:
                
                fprintf2(CONSOLE_TaskTechnician, "\n\r");                                                                   //Prints fridge temperature.
                fprintf2(CONSOLE_TaskTechnician, "*************************************************\n\r");                  //" ".
                sprintf(PrintBuff, "The fridge temperature is currently %d degrees C.\n\r", mutex_GetFridgeTemperature());  //" ".
                fprintf2(CONSOLE_TaskTechnician, PrintBuff);                                                                //" ".
                fprintf2(CONSOLE_TaskTechnician, "*************************************************\n\r");                  //" ".
                
                QueueFlag = 0;                                                                                              //Enables control flag for receiving queue.
                memset(TaskTechnician_rx, 0, sizeof TaskTechnician_rx);                                                     //Clears receiving string array.
                stateTECHNICIAN = SM_QUEUE_WAIT;                                                                            //Move on to next state.
                
            break;
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            /* Empty vending machine money state. *///////////////////////////////////////////////////////////////////////////////////////////////////////////////
            case SM_REMOVE_MONEY:
                mutex_SetCreditQuantity(0);                                                                         //Sets vending machine quarter quantity to 0.
                mutex_SetCreditVM(0);
                fprintf2(CONSOLE_TaskTechnician, "\n\r");                                                           //Prints empty quarter quantity.
                fprintf2(CONSOLE_TaskTechnician, "*****************************************\n\r");                  //" ".
                sprintf(PrintBuff, "There are currently %d quarters in the VM.\n\r", mutex_GetCreditQuantity());    //" ".
                fprintf2(CONSOLE_TaskTechnician, PrintBuff);                                                        //" ".
                fprintf2(CONSOLE_TaskTechnician, "*****************************************\n\r");                  //" ".
                
                QueueFlag = 0;                                                                                      //Enables control flag for receiving queue.
                memset(TaskTechnician_rx, 0, sizeof TaskTechnician_rx);                                             //Clears receiving string array.
                stateTECHNICIAN = SM_QUEUE_WAIT;                                                                    //Move on to next state.
                
            break;
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            /* Last successful vending machine transaction state. *///////////////////////////////////////////////////////////////////////////////////////////////
            case SM_TRANSACTION_TIME:
                fprintf2(CONSOLE_TaskTechnician, "\n\r");                                                               //Prints last successful transaction time.
                fprintf2(CONSOLE_TaskTechnician, "***********************************************\n\r");                //" ".
                sprintf(PrintBuff, "The latest transaction happened %d seconds ago.\n\r", mutex_GetTransactionTime());  //" ".
                fprintf2(CONSOLE_TaskTechnician, PrintBuff);                                                            //" ".
                fprintf2(CONSOLE_TaskTechnician, "***********************************************\n\r");                //" ".
                
                QueueFlag = 0;                                                                                          //Enables control flag for receiving queue.
                memset(TaskTechnician_rx, 0, sizeof TaskTechnician_rx);                                                 //Clears receiving string array.
                stateTECHNICIAN = SM_QUEUE_WAIT;                                                                        //Move on to next state.
                
            break;
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            /* Read number of quarters inside the vending machine state. */////////////////////////////////////////////////////////////////////////////////////////////
            case SM_READ_MONEY:
                fprintf2(CONSOLE_TaskTechnician, "\n\r");                                                           //Prints number of quarters inside vending machine.
                fprintf2(CONSOLE_TaskTechnician, "*****************************************\n\r");                  //" ".
                sprintf(PrintBuff, "There are currently %d quarters in the VM.\n\r", mutex_GetCreditQuantity());    //" ".
                fprintf2(CONSOLE_TaskTechnician, PrintBuff);                                                        //" ".
                fprintf2(CONSOLE_TaskTechnician, "*****************************************\n\r");                  //" ".
                
                QueueFlag = 0;                                                                                      //Enables control flag for receiving queue.
                memset(TaskTechnician_rx, 0, sizeof TaskTechnician_rx);                                             //Clears receiving string array.
                stateTECHNICIAN = SM_QUEUE_WAIT;                                                                    //Move on to next state.
                
            break;
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            /* Read soda stock inside the vending machine state. *//////////////////////////////////////////////////////////////////////////////////////////////
            case SM_READ_STOCK:
                fprintf2(CONSOLE_TaskTechnician, "\n\r");                                                           //Prints drink stock inside vending machine.
                fprintf2(CONSOLE_TaskTechnician, "***********************************************\n\r");            //" ".
                sprintf(PrintBuff, "There are currently %d orange drinks in the VM.\n\r", mutex_GetQtyVM(ORANGE));  //" ".
                fprintf2(CONSOLE_TaskTechnician, PrintBuff);                                                        //" ".
                sprintf(PrintBuff, "There are currently %d yellow drinks in the VM.\n\r", mutex_GetQtyVM(YELLOW));  //" ".
                fprintf2(CONSOLE_TaskTechnician, PrintBuff);                                                        //" ".
                sprintf(PrintBuff, "There are currently %d red drinks in the VM.\n\r", mutex_GetQtyVM(RED));        //" ".
                fprintf2(CONSOLE_TaskTechnician, PrintBuff);                                                        //" ".
                fprintf2(CONSOLE_TaskTechnician, "***********************************************\n\r");            //" ".
                
                QueueFlag = 0;                                                                                      //Enables control flag for receiving queue.
                memset(TaskTechnician_rx, 0, sizeof TaskTechnician_rx);                                             //Clears receiving string array.
                stateTECHNICIAN = SM_QUEUE_WAIT;                                                                    //Move on to next state.
                
            break;
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            /* Changes soda prices inside the vending machine. *////////////////////////////////////////////////////////////////////////////////////////////////////
            case SM_CHANGE_PRICES:
                if(TaskTechnician_rx[0] == 'd'){                                                            //If "d" has been received...
                    stateTECHNICIAN = SM_MENU;                                                              //Move on to next state.
                }
                else{
                    
                    sprintf(temp_buffer, "%c%c", TaskTechnician_rx[2], TaskTechnician_rx[3]);               //Stores ASCI number in buffer.
                    DrinkPrice = atoi(temp_buffer);                                                         //Converts ASCI number to integer.
                    
                    if(TaskTechnician_rx[0] == 'o' && TaskTechnician_rx[1] == 'p'){
                        mutex_SetPriceVM(DrinkPrice, ORANGE);                                               //Sets new orange drink price.
                        fprintf2(CONSOLE_TaskTechnician, "\n\r");                                           //Prints new orange drink price.
                        fprintf2(CONSOLE_TaskTechnician, "*************************\n\r");                  //" ".
                        sprintf(PrintBuff, "Orange price is now: %dQ.\n\r", mutex_GetPriceVM(ORANGE));      //" ".
                        fprintf2(CONSOLE_TaskTechnician, PrintBuff);                                        //" ".
                        fprintf2(CONSOLE_TaskTechnician, "*************************\n\r");                  //" ".
                    }
                    else if(TaskTechnician_rx[0] == 'r' && TaskTechnician_rx[1] == 'p'){
                        mutex_SetPriceVM(DrinkPrice, RED);                                                  //Sets new orange drink price.
                        fprintf2(CONSOLE_TaskTechnician, "\n\r");                                           //Prints new red drink price.
                        fprintf2(CONSOLE_TaskTechnician, "**********************\n\r");                     //" ".
                        sprintf(PrintBuff, "Red price is now: %dQ.\n\r", mutex_GetPriceVM(RED));            //" ".
                        fprintf2(CONSOLE_TaskTechnician, PrintBuff);                                        //" ".
                        fprintf2(CONSOLE_TaskTechnician, "**********************\n\r");                     //" ".
                    }
                    
                    else if(TaskTechnician_rx[0] == 'y' && TaskTechnician_rx[1] == 'p'){
                        mutex_SetPriceVM(DrinkPrice, YELLOW);                                               //Sets new orange drink price.
                        fprintf2(CONSOLE_TaskTechnician, "\n\r");                                           //Prints new yellow drink price.
                        fprintf2(CONSOLE_TaskTechnician, "*************************\n\r");                  //" ".
                        sprintf(PrintBuff, "Yellow price is now: %dQ.\n\r", mutex_GetPriceVM(YELLOW));      //" ".
                        fprintf2(CONSOLE_TaskTechnician, PrintBuff);                                        //" ".
                        fprintf2(CONSOLE_TaskTechnician, "*************************\n\r");                  //" ".
                    }
                
                    PriceFlag = 1;                                                                          //Enables control flag for vending machine drink prices.
                    QueueFlag = 0;                                                                          //Enables control flag for receiving queue.
                    memset(TaskTechnician_rx, 0, sizeof TaskTechnician_rx);                                 //Clears receiving string array.
                    stateTECHNICIAN = SM_QUEUE_WAIT;                                                        //Move on to next state.
                    
                }
                
            break;
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
        }
    }
}


/**********************************************************************************************
* Name: void vInit_vTaskTechnician(void) 
* Description: Public function definition for Lab4 RTOS vTaskTechnician. This function calls 
*              initializing functions for vTaskTechnician.
* 
***********************************************************************************************/
void vInit_vTaskTechnician(void){
    vInitQueue_TaskTechnician();   //Calls queue init function for vTaskTechnician.
    vInit_StartTechnician();       //Calls task init function for vTaskTechnician.
}


/**********************************************************************************************
* Name: void vInit_StartTechnician(void)
* Description: Public function definition for Lab4 RTOS vTaskTechnician. This function creates 
*              vTaskTechnician. 
*              Macro constants can be found in public.h file or vTaskTechnician.h file. 
* 
***********************************************************************************************/
void vInit_StartTechnician(void){
    /* Creates vTaskTechnician task with user-set priority. */
    xTaskCreate( vTaskTechnician, ( char * ) "Technician", 240, NULL, PRIORITY_Technician, NULL );
}


/**********************************************************************************************
* Name: void vInitQueue_TaskTechnician(void) 
* Description:  Public function definition for Lab4 RTOS vTaskTechnician. This function 
*               initializes a queue for vTaskTechnician.
*               Macro constants can be found in public.h file or vTaskTechnician.h file.
* 
***********************************************************************************************/
void vInitQueue_TaskTechnician(void){
    xQueue_TaskTechnician = xQueueCreate( QUEUE_DEPTH, sizeof( char ) );
}


/**********************************************************************************************
* Name: void vSendQueue_TaskTechnician(void) 
* Description: Public function definition for Lab4 RTOS vTaskTechnician. This function allows 
*              other tasks to send data to vTaskTechnician through using a queue.
* 
***********************************************************************************************/
void vSendQueue_TaskTechnician(char temp_data){
    xQueueSendFromISR(xQueue_TaskTechnician, &temp_data, 0);
}
