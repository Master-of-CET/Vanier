/**************************************************************************************************
* FileName: threadKeybd.c
*
* Name: Leonardo Fusser (1946995)	Lab 3   Moving Snake Application
*
* Description: This code provides the display thread with the selected user input from the keyboard
*			   and ensures that the snake head does get printed beyond defined window bounds in the
*			   display thread.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author        	Date                Version     Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Leonardo Fusser	28 January 2022		v1.0.0		First version of source file.
*													Created keyboard thread routine.
*													Created mutex for keyboard thread routine.
* Leonardo Fusser	6 February 2022		v1.0.1		Added limits for X and Y values.
*													Added macros for portability.
*													Added comments.
*													GITHUB COMMIT & PUSH TEST.
* Leonardo Fusser	11 February 2022	v1.0.2		Completed source file.
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/* Includes. */
#include "../laboratory/header/threadKeybd.h"


static pthread_t ID_threadKeybd;								//Keyboard thread ID.
static pthread_mutex_t mutex_xy = PTHREAD_MUTEX_INITIALIZER;	//Mutex init.
static int X = 0;												//Private global value.
static int Y = 13;												//" ".


/**********************************************************************************************
* Name: void *threadKeybd(void *threadid)
* Description: Keyboard thread routine for Lab 3. User input from the keyboard is continously 
*			   read below. The possible good inputs are the "w", "a", "s" and "d" keys. If the
*			   "x" key is pressed, the game will stop and terminate.
*
***********************************************************************************************/
void* threadKeybd(void* threadid) {
	int temp_X;		//Temp value for getting current X value.
	int temp_Y;		//Temp value for getting current Y value.
	int UserInput;	//Value to store user input from keyboard.
	
	/* Mini while loop. */
	while (1) {
		UserInput = getch();	//Gets user input from keyboard.
		temp_X = mutex_GetX();	//Gets current X value.
		temp_Y = mutex_GetY();	//Gets current Y value.
		if (UserInput == 'w') {								//If "w" key is pressed...
			mutex_SetXandY(temp_X = temp_X, temp_Y - 1);	//Change X and Y values accordingly.
			Sleep(20);										//Small blocking delay to prevent CPU stress and keep snake printing clean.
		}
		else if (UserInput == 'a') {						//If "a" key is pressed...
			mutex_SetXandY(temp_X - 1, temp_Y = temp_Y);	//Change X and Y values accordingly.
			Sleep(20);										//Small blocking delay to prevent CPU stress and keep snake printing clean.
		}
		else if (UserInput == 's') {						//If "s" key is pressed...
			mutex_SetXandY(temp_X = temp_X, temp_Y + 1);	//Change X and Y values accordingly.
			Sleep(20);										//Small blocking delay to prevent CPU stress and keep snake printing clean.
		}
		else if (UserInput == 'd') {						//If "d" key is pressed...
			mutex_SetXandY(temp_X + 1, temp_Y = temp_Y);	//Change X and Y values accordingly.
			Sleep(20);										//Small blocking delay to prevent CPU stress and keep snake printing clean.
		}
		else if (UserInput == 'x') {						//If "x" key is pressed...
			exit(0);										//Quits program.
		}
	}
	return NULL;											//Returns to main thread (if possible).
}


/**********************************************************************************************
* Name: void create_threadKeybd(void)
* Description: Keyboard thread routine creation function for Lab 3. The following code creates
*			   the actual thread for the keyboard thread routine.
*
***********************************************************************************************/
void create_threadKeybd(void) {
	pthread_create(&ID_threadKeybd, NULL, threadKeybd, NULL);	//Creates keyboard thread.
}


/**********************************************************************************************
* Name: void join_threadKeybd(void)
* Description: Keyboard thread routine joining function for Lab 3. The following code forces the
*			   main thread to wait for the keyboard thread routine to finish before terminating
*			   alltogether.
*
***********************************************************************************************/
void join_threadKeybd(void) {
	pthread_join(ID_threadKeybd, NULL);	//Joins keyboard thread.
}


/**********************************************************************************************
* Name: void mutex_SetXandY(int temp_SetX, int temp_SetY)
* Description: Mutex-protected setter function for X and Y values. Depending on the user input,
*			   either X or Y updates in a safe manner and certain window boundries are enforced
*			   here to prevent the snake head from printing outside the window boundries.
*
***********************************************************************************************/
void mutex_SetXandY(int temp_SetX, int temp_SetY) {
	pthread_mutex_lock(&mutex_xy);							//Protects.
	if (X > X2_WindowLimit || X < X1_WindowLimit) {			//If X value goes beyond X window bounds...
		if (X > X2_WindowLimit) {							//If X value goes past X window...
			X = X - 1;										//Decrement X by 1 (keeps snake inside box).
		}
		else {												//Otherwise, if X value goes below X window... 
			X = X + 1;										//Increment X by 1 (keeps snake inside box).
		}
	}
	else if (Y > Y2_WindowLimit || Y < Y1_WindowLimit) {	//If Y value goes beyond Y window bounds...
		if (Y > Y2_WindowLimit) {							//If Y value goes past Y window...
			Y = Y - 1;										//Decrement Y by 1 (keeps snake inside box).
		}
		else {												//Otherwise, if Y value goes below Y window...
			Y = Y + 1;										//Increment Y by 1 (keeps snake inside box).
		}
	}
	else {													//Otherwise, if X and Y values are not beyond bounds...
		X = temp_SetX;										//Sets X value.
		Y = temp_SetY;										//Sets Y value.
	}
	pthread_mutex_unlock(&mutex_xy);						//Un-protects.
}


/**********************************************************************************************
* Name: int mutex_GetX(void)
* Description: Mutex-protected getter function for X value. Every time this function is called,
*			   the current X value will be returned in a safe manner.
*
***********************************************************************************************/
int mutex_GetX(void) {
	int temp_GetX;						//Temp value for returning X value.
	pthread_mutex_lock(&mutex_xy);		//Protects.
	temp_GetX = X;						//X value is retrieved.
	pthread_mutex_unlock(&mutex_xy);	//Un-protects.
	return temp_GetX;					//Returns X value.
}


/**********************************************************************************************
* Name: int mutex_GetY(void)
* Description: Mutex-protected getter function for Y value. Every time this function is called,
*			   the current Y value will be returned in a safe manner.
*
***********************************************************************************************/
int mutex_GetY(void) {
	int temp_GetY;						//Temp value for returning Y value.
	pthread_mutex_lock(&mutex_xy);		//Protects.
	temp_GetY = Y;						//Y value is retrieved.
	pthread_mutex_unlock(&mutex_xy);	//Un-protects.
	return temp_GetY;					//Returns Y value.
}
