/*************************************************************************************
 * FileName:  rpn.cpp			             								         *
 *																					 *
 * Name:  Lab 7, Advanced Embedded Systems Programming (Serge Hould)			     *
 *																					 *
 * Description: This program is a calculator based off of reverse polish notation.	 *
 *																					 *
 * REVISION HISTORY:																 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     *
 * Leonardo Fusser (1946995)		     [Sixth commit]						         *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     *
 * November 25th, 2020                   v1.0.1										 *
 *										 -Created push() & pop() functions.			 *
 * December 2nd, 2020					 v1.0.2										 *	
 *										 -Created getop() & displayStack() functions.*
 * December 8th, 2020					 v1.0.3										 *
 *										 -Created RPN_calculator & other bug fixes.  *
 * December 12th, 2020					 v1.0.4										 *
 *										 -Cleaned up error handling & other bug fixes*
 * December 17th, 2020					 v1.0.5										 *
 *										 -Added comments							 *
 *										                                             *
 ************************************************************************************/


#include "rpn.h"

double RPNstack[STACK_DEPTH];																//creates stack based on depth "DEPTH"
int sp = 0;																					//creates stack position variable "sp"
int count = 0;																				//creates counter variable "count"


//calculator function
void RPN_calculator(void) {

	char str_buf[MAX];																		//charcter stored in str_buf
	char type;																		

	while ((type = getop(str_buf)) != 0) {

		switch (type) {

		//case to push value to stack
		case '=':
			push(atof(str_buf));															//CONVERTS STRING TO FLOAT AND PUSHES ON THE STACK
			break;

		//case to add two numbers from the stack
		case '+':
			printf("+ operator selected...\n");
			--count;																		//decrement counter by 1
			push(pop() + pop());															//POPS THE LATEST TWO VALUES, ADDS THEM AND PUSHES THE RESULT
			break;

		//case to multiply two numbers from the stack
		case '*':
			printf("* operator selected...\n");
			--count;																		//decrement counter by 1	
			push(pop() * pop());															//POPS THE LATEST TWO VALUES, MULTIPLIES THEM AND PUSHES THE RESULT
			break;

		//case to subtract two numbers from the stack
		case '-':
			printf("- operator selected...\n");
			--count;																		//decrement counter by 1
			push(pop() - pop());															//POPS THE LATEST TWO VALUES, SUBSTRACTS THEM AND PUSHES THE RESULT
			break;

		//case to divide two numbers from the stack
		case '/':
			printf("/ operator selected...\n");
			--count;																		//decrement counter by 1

			//if value in stack is 0...
			if (pop() == 0 || pop() == 0) {
				printf("\n");
				printf("error: zero divis\n");
				exit(0);																	//leave calculator
			}
			//else value in stack is not 0...
			else {
				push((pop()/pop()));														//POPS THE LATEST TWO VALUES, DIVIDES THEM AND PUSHES THE RESULT
				break;
			}

		//if none of the cases above yield TRUE...
		default:
			exit(0);																		//leave calculator
			break;

		}
		displayStack();																		//call displayStack() function
	}
}


//function to add a value to the stack
void push(double val) {
	
	//if next push reaches 1 count higher then maximum stack depth...
	if (count == STACK_DEPTH + 1) {															//stack is full
		printf("\n");																		//newline
		printf("\n");																		//newline	
		printf("error: stack full\n");
		exit(0);																			//leave calculator
	}
	//else stack is not full (count is < 1 + maximum stack depth)...
	else {
		RPNstack[sp] = val;																	//push value to position "sp" of stack
		sp++;																				//increment "sp" so that next valued is stored on TOS
	}
}


//function to remove a value from the stack
double pop(void) {

	double temp;																			//temporary variable

	//if next pop reaches count of 0 or -1...
	if (count == 0 || count == -1) {														//stack is empty
		printf("\n");																		//newline
		printf("error: stack empty\n");
		exit(0);																			//leave calculator
	}
	//else stack is not empty (count is > 0)...
	else {
		sp--;																				//decrement "sp" so that value returned is from position 1 less TOS
		temp = RPNstack[sp];																//assign "temp"	value with value at "sp"
		RPNstack[sp] = 0;																	//fill poped "sp" value with 0
		return temp;																		//return poped value (from temp)
	}
}


//function to read character from keyboard
int getop(char* str_buffer) {

	char key;																				//temporary variable

	while (true) {

		key = _getch();																		//key = character entered on keyboard

		//if character represents a number...
		if ('0' <= key && key <= '9' || key == '.') {
			printf("%c", key);
			*str_buffer = key;																//assign character to current memory address of str_buffer
			++str_buffer;																	//increment position of str_buffer to store next character
		}
		//if character entered is '='...
		else if (key == '=') {																//user has entered the complete number to be pushed to the stack
			*str_buffer = '\0';																//assign as NULL (end of array)	
			++count;																		//increment counter for push function to check if stack overflowed
			return '=';																		//return '=' character to RPN_calculator() function
		}
		//if character entered is '+'...
		else if (key == '+') {
			return '+';																		//return '+' character to RPN_calculator() function
		}
		//if character entered is '-'...
		else if (key == '-') {
			return '-';																		//return '-' character to RPN_calculator() function
		}
		//if character entered is '/'...
		else if (key == '/') {
			return '/';																		//return '/' character to RPN_calculator() function
		}
		//if character entered is '*'...
		else if (key == '*') {
			return '*';																		//return '*' character to RPN_calculator() function		
		}
		//if character entered if 'x' or 'X'...
		else if (key == 'x' || key == 'X') {
			printf("X key pressed. Goodbye! Leaving the calculator...\n");
			exit(0);																		//leave calculator
		}
		//if all other statements yeild FALSE...
		else {
			printf("\n");
			printf("Error! Unknown key pressed! Leaving the calculator...\n");
			exit(0);																		//leave calculator	
		}
	}	
}


//function to display contents of stack
void displayStack(void) {

	printf("\n");																			//newline
	printf("----------------------------------------------------\n");						//display formatting
	printf("[LIFO stack display]\n");														
	printf("\n");																			//newline

	//for i less than the value of the counter...
	for (int i = 0; i < count; i++) {														
		printf("%.2f ", RPNstack[i]);														//prints the number of elements currently in the stack
	}

	printf("\n");																			//newline	
	printf("----------------------------------------------------\n");						//display formatting
	printf("\n");																			//newline
}