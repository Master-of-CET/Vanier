/*************************************************************************************
 * FileName:  main.cpp			             								         *
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
 *										 -Created push() & pop() functions.	         *
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

//main function
int main(void)
{
	RPN_calculator();					  //calls RPN_calculator() function in rpn.cpp	
	return 0;
}