/**************************************************************************************************
* FileName: main.cpp
*
* Name: Leonardo Fusser (1946995)       Lab 1       Computerized Systems Optimization
*
* Description: This code provides the main interface for the functionality of Lab1. Two threads are 
*              initialized and created. When either thread is running, a unique message prints from
*              inside the thread. The threads should normally return to the main function and quit.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Serge Hould       ?                   v1.0.0      First version of source file.
* Leonardo Fusser   21 January 2022     v1.0.1      Completed main.cpp file.
*                                                   Created two threads (with appropriate init).
*                                                   Added comments and macros for portability.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/* Includes. */
#include <Windows.h> 
#include <stdio.h>
#include <string.h>
#define HAVE_STRUCT_TIMESPEC    //For win32 only. Because TIMESPEC is re-defined inside pthread.h
#include <pthread.h>


/* Macro to swap between one and two threads. */
//#define ONE_THREAD

/* Macro to swap between blocking and non-blocking delay. */
//#define BLOCKING

/* Macro to swap between infinite message printing and finite message printing. */
//#define INFINITE_PRINT

/* Macro to swap between joining the thread in the main or not. */
//#define JOIN_THREAD


/**********************************************************************************************
* Name: void *thread2(void *threadid)
* Description: thread2 routine. Depending on macro set above, a message prints from this thread
*              when this thread is running.
*
***********************************************************************************************/
void* thread2(void* threadid) {

    #ifdef INFINITE_PRINT                       //Prints message from thread2 endlessly.
        while (1) {
            printf("Hello from thread2!\n");
            Sleep(1000);                        //Prints every 1 second.
        }

    #else                                       //Prints message from thread2 10 times.
        for (int i = 0; i < 10; i++) {
            printf("Hello from thread2!\n");
            Sleep(1000);                        //Prints every 1 second.
        }

    #endif

    return NULL;                                //Returns.
}


/**********************************************************************************************
* Name: void *thread1(void *threadid)
* Description: thread1 routine. Depending on macro set above, a message prints from this thread
*              when this thread is running.
*
***********************************************************************************************/
void* thread1(void* threadid) {

    #ifdef INFINITE_PRINT                       //Prints message from thread1 endlessly.
        while (1) {
            printf("Hello from thread1!\n");
            Sleep(500);                         //Prints every 500mS.
        }

    #else                                       //Prints message from thread1 10 times.
        for (int i = 0; i < 10; i++) {
            printf("Hello from thread1!\n");
            Sleep(500);                         //Prints every 500mS.
        }

    #endif
    
    return NULL;                                //Returns.
}

          
/**********************************************************************************************
* Name: int main(void)
* Description: Main function for Lab1. Here, all thread initialization and handling is done.
*
***********************************************************************************************/
int main(void){
    
    #ifdef ONE_THREAD                                               //For creating one thread.
        pthread_t ID_thread1;                                       //Thread ID.
        printf("Hello from main: creating one thread!\n");
        pthread_create(&ID_thread1, NULL, thread1, NULL);           //Creates one thread.
        
        #ifdef BLOCKING                                             //Blocks.
            Sleep(5000);                                            //5-second blocking delay.
        
        #else                                                       //Does not block.
            #ifndef JOIN_THREAD                                     //Does not return thread.
                pthread_exit(NULL);                                 //thread1 executes until completion and does not return.
            
            #else                                                   //Returns thread.
                pthread_join(ID_thread1, NULL);                     //thread1 executes until completion and returns (joins).

            #endif

        #endif

    #else                                                           //For creating two threads.
        pthread_t ID_thread1, ID_thread2;                           //Thread IDs.
        printf("Hello from main: creating two threads!\n");
        pthread_create(&ID_thread1, NULL, thread1, NULL);           //Creates first thread.
        pthread_create(&ID_thread2, NULL, thread2, NULL);           //Creates second thread.
            
            #ifndef JOIN_THREAD                                     //Only joins thread1 in main.
                pthread_join(ID_thread1, NULL);                     //Joins.
            
            #else                                                   //Joins thread1 and thread2 in main.
                pthread_join(ID_thread1, NULL);                     //Joins.
                pthread_join(ID_thread2, NULL);                     //" ".

            #endif
        
    #endif

    printf("Update from main: thread returns!\n");                  //Prints if thread(s) returns successfully.
            
}
