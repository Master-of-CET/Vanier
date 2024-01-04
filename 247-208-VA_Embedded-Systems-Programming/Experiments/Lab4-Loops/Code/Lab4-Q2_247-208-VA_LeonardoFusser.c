/////////////////////////////////////////////////////////////////////////////////////////////////////
//This program computes AMICABLE operations from two numbers. The numbers are inputted by the user.//
//Lab 4-Question 2																				   //
//Embedded Systems Programming																	   //
//Subash Handa																					   //
//Program made by: Leonardo Fusser (1946995)													   //
/////////////////////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <math.h>

void main() {

	//variable declarations
	int num1;
	int num2;
	int sumw = 0;
	int sumx = 0;
	int w;
	int x;

	//user input
	printf("Enter the first number (between 200 and 6000): "); //first number
	scanf_s("%d", &num1);

	printf("Enter the second number (between 200 and 6000): "); //second number
	scanf_s("%d", &num2);

	//AMICABLE check
	for (w = 1; w < num1; w++) {
		if (num1 % w == 0) {
			(sumw = sumw + w);
		}
	}
	for (x = 1; x < num2; x++) {
		if (num2 % x == 0) {
			(sumx = sumx + x);
		}
	}

	//if and else: output print to user
	if ((num1 == sumx) && (num2 == sumw)) {
		printf("%d ", num1);
		printf("and %d ", num2);
		printf("are AMICABLE.\n");
	}
	else {
		printf("%d ", num1);
		printf("and %d ", num2);
		printf("are not AMICABLE.\n");
	}
}