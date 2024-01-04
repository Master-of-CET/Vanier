/**************************************************************************************************
* FileName: main.c
*
* Name: Leonardo Fusser (1946995)   Lab 2   Introduction to mutex synchronization & Ncurses library
*                                   Lab 3   Moving Snake Application
*
* Description: This code provides the main interface for the functionality of Lab2 and Lab 3. 
*
*              [Lab 2]
*              Two threads are initialized and created in the main thread below. When either thread 
*              is running, a unique message prints from the thread, three different ways (user 
*              selectable below). For this lab, the threads should normally NOT return to the main 
*              function, instead they will execute forever.
*
*              [Lab 3]
*              Two thread initialization and joining functions are called in the main thread below.
*              The keyboard thread is responsible for reading user input from the keyboard and the 
*              display thread is responsible for printing functionality. A snake head is printed
*              from the display thread and it moves around a screen according to the user input
*              read in the keyboard thread. There is no direct communication between the two threads.
* 
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Serge Hould       ?                   v1.0.0      First version of source file.
* Leonardo Fusser   25 January 2022     v1.0.1      Completed source file.
*                                                   Created two threads.
*                                                   Created mutex print function.
*                                                   Added comments.
*                                                   Added macros for portability.
* Leonardo Fusser   28 January 2022     v2.0.0      Beginning of Lab 3.
*                                                   Added ifdef statements to seperate Lab 2 & 3.
*                                                   Added init functions for keyboard & display 
*                                                   threads inside main thread.
*                                                   GITHUB COMMIT & PUSH TEST.
* Leonardo Fusser   11 February 2022    v2.0.1      Completed source file.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/* Includes. */
#include "../header/public.h"


#ifdef LAB2                                                         //If Lab 2 is selected...
    static pthread_mutex_t mutex_print = PTHREAD_MUTEX_INITIALIZER; //Mutex instantion.
    void print_mutex(int l, int c, char* str);                      //Function prototype.

#endif


/**********************************************************************************************
* Name: void *thread2(void *threadid)
* Description: thread2 routine for Lab 2. Depending on the macros defined above, this thread 
*              can print a hardcoded message to a console three different ways. The ways are: 
*              1) without mutexes, 2) with mutexes and 3) with mutexes and small blocking delay. 
*              If this thread ever terminates, it will return to the main thread.
*
***********************************************************************************************/
#ifdef LAB2                                     //If Lab 2 is selected...
void* thread2(void* threadid) {

    while (1) {
        
        #ifndef MUTEX_PRINT                     //If protected print not defined...
            attron(GREEN_BLACK);                //Prints message with green colour.
            mvprintw(5, 0, "Good morning!");    //Prints at line 5, column 0.
            attroff(GREEN_BLACK);               //Wipes print from console.
            refresh();                          //Refreshes console (for subsequent prints).
        
        #else                                   //If protected print defined...
            attron(GREEN_BLACK);                //Prints message with green colour.
            print_mutex(5, 0, "Good morning!"); //Calls mutex print function (prints at line 5, column 0).
            attroff(GREEN_BLACK);               //Wipes print from console.
            refresh();                          //Refreshes console (for subsequent prints).

            #ifdef BLOCKING                     //If small blocking delay defined...
                Sleep(10);                      //Applies a 10mS blocking delay.
            
            #endif
        #endif
    }

    return NULL;                                //Returns (if this thread ever reaches here).
}
#endif


/**********************************************************************************************
* Name: void *thread1(void *threadid)
* Description: thread1 routine for Lab 2. Depending on the macros defined above, this thread 
*              can print a hardcoded message to a console three different ways. The ways are: 
*              1) without mutexes, 2) with mutexes and 3) with mutexes and small blocking delay. 
*              If this thread ever terminates, it will return to the main thread.
*
***********************************************************************************************/
#ifdef LAB2                                             //If Lab 2 is selected...
void* thread1(void* threadid) {

    while (1) {
        
        #ifndef MUTEX_PRINT                             //If protected print not defined...
            attron(RED_BLACK);                          //Prints message with red colour.
            mvprintw(4, 0, "Hello from thread 1!");     //Prints at line 4, column 0.
            attroff(RED_BLACK);                         //Wipes print from console.
            refresh();                                  //Refreshes console (for subsequent prints).

        #else                                           //If protected print defined...
            attron(RED_BLACK);                          //Prints message with red colour.
            print_mutex(4, 0, "Hello from thread 1!");  //Calls mutex print function (prints at line 4, column 0).
            attroff(RED_BLACK);                         //Wipes print from console.
            refresh();                                  //Refreshes console (for subsequent prints).

            #ifdef BLOCKING                             //If small blocking delay defined...
                Sleep(10);                              //Applies a 10mS blocking delay.
            
            #endif  
        #endif
    }

    return NULL;                                        //Returns (if this thread ever reaches here).
}
#endif


/**********************************************************************************************
* Name: int main(void)
* Description: Main function for Lab2 and Lab 3. 
*
*              [Lab 2]
*              Here, all initialization and handling is done. Two threads are initially created 
*              below. The main thread waits for the two threads to complete before it terminates 
*              all together. The main thread provides a basic user interface to the user via 
*              console.
* 
*              [Lab 3]
*              Here, all thread routine initialization functions are called and all thread routine
*              joining functions are called. The main thread waits for all the threads to complete
*              before it terminates all together.
*
***********************************************************************************************/
int main(void){

    init_ncurses();                                                 //Init ncurse library.
	
    #ifdef LAB2                                                     //If Lab2 is selected...
        pthread_t ID_thread1, ID_thread2;                           //Thread IDs.
    
        attron(WHITE_BLACK);                                        //Prints message with white colour.
        mvprintw(2, 0, "Hello from main: creating two threads!");   //Prints at line 2, column 0.
        attroff(WHITE_BLACK);                                       //Wipes print from console.                              
        refresh();                                                  //Refreshes console (for subsequent prints).
    
        pthread_create(&ID_thread1, NULL, thread1, NULL);           //Creates first thread.
        pthread_create(&ID_thread2, NULL, thread2, NULL);           //Creates second thread.
        pthread_join(ID_thread1, NULL);                             //Joins.
        pthread_join(ID_thread2, NULL);                             //" ".

        /* Main thread prints this message if the two above threads ever return to the main thread. */
        attron(WHITE_BLACK);                                        //Prints message with white colour.
        mvprintw(7, 0, "Update from main: thread(s) returns!");     //Prints at line 7, column 0.
        attroff(WHITE_BLACK);                                       //Wipes print from console.
        refresh();                                                  //Refreshes console (for subsequent prints).

	    return 1;

    #else                                                           //Otherwise, Lab 3 is selected...
        create_threadKeybd();                                       //Creates keyboard thread routine.
        create_threadDisplay();                                     //Creates display thread routine.
        join_threadKeybd();                                         //Joins keyboard thread routine.
        join_threadDisplay();                                       //Joins display thread routine.

    #endif

}  


/**********************************************************************************************
* Name: print_mutex(int l, int c, char *str)
* Description: Mutex print function. When this function is called, it will prevent other prints
*              from occuring. Only one print can occur at any time. This is to solve printing
*              issues from multiple running threads that do not use mutexes. Arguments passed 
*              to this function are line number, column number and the string that needs to be 
*              printed.
*
***********************************************************************************************/
#ifdef LAB2                                 //If Lab 2 is selected...
void print_mutex(int l, int c, char* str) {
    
    pthread_mutex_lock(&mutex_print);       //Protects print below.
    mvprintw(l, c, str);                    //Prints passed string to console.
    pthread_mutex_unlock(&mutex_print);     //Un-protects print above (allows for subsequent prints).
}
#endif
