/*************************************************************************************
 * FileName:  rpn.h				             								         *
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


#ifndef rpn_h
#define rpn_h

#include <stdio.h>
#include <stdlib.h>						//for atof()
#include <ctype.h>
#include <string.h>
#include <conio.h>						//for getch()

#define STACK_DEPTH 10					//depth is 10 bytes deep (for stack)
#define MAX   5							//maximum number of digits user can enter for 1 number				

void RPN_calculator(void);				//function prototype
int getop(char*);						//" "
void push(double);						//" "
double pop(void);						//" "
void displayStack(void);				//" "

#endif