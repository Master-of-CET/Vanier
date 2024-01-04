//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//This program calculates the commision of an employee with other conditions (advanced pay) taken into account. The employee's total sales are provided by themselves.					//
//Embedded Systems Programming (Lab 3)(Question 2)																																		//
//Subash Handa																																											//			
//Program made by: Leonardo fusser (1946995)																																			//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

void main() {
	//variable definitions
	double employeeAdvance;
	double userInput_Sales;
	double employeeMustPay;
	double ammountDifference;
	double employeeSalary;

	//user inputs
	printf("Enter the sales for this month (in dollars): \n");
	scanf_s("%lf", &userInput_Sales);
	printf("-----------------------------------------------\n");
	printf("Enter the amount of money you would like to take in advance: \n");
	scanf_s("%lf", &employeeAdvance);
	printf("-----------------------------------------------\n");
	
	//input validation and calculations
	if (userInput_Sales <= 0) {
		printf("Please check your inputs and try again! *Note: sales amount has to be bigger than 0 dollars!\n");
		printf("-----------------------------------------------\n");
	}
	//if sales less than $10'000
	else if (userInput_Sales < 10000) {
		employeeMustPay = employeeAdvance - (userInput_Sales * 0.05);
		printf("Sales person's commsion is: %lf dollars.\n", userInput_Sales * 0.05);
		printf("Employee must pay %lf dollars to the company!\n", employeeMustPay);
		printf("-----------------------------------------------\n");
	}
	//if sales greater than or equal to $10'000 and less than $15'000
	else if (userInput_Sales >= 10000 && userInput_Sales < 15000) {
		employeeMustPay = employeeAdvance - (userInput_Sales * 0.1);
		printf("Sales person's commision is: %lf dollars.\n", userInput_Sales * 0.1);
		printf("Employee must pay %lf dollars to the company!\n", employeeMustPay);
		printf("-----------------------------------------------\n");
	}
	//if sales greater than or equal to $15'000 and less than $18'000
	else if (userInput_Sales >= 15000 && userInput_Sales < 18000) {
		employeeSalary = (userInput_Sales * 0.12) - employeeAdvance;
		printf("Sales person's commision is: %lf dollars.\n", userInput_Sales * 0.12);
		printf("Employee deserves %lf dollars from the company!\n.", employeeSalary);
		printf("-----------------------------------------------\n");
	}
	//if sales greater than or equal to $18'000 and less than $22'000
	else if (userInput_Sales >= 18000 && userInput_Sales < 22000) {
		employeeSalary = (userInput_Sales * 0.14) - employeeAdvance;
		printf("Sales person's commision is: %lf dollars.\n", userInput_Sales * 0.14);
		printf("Employee deserves %lf dollars from the company!\n.", employeeSalary);
		printf("-----------------------------------------------\n");
	}
	//if sales greater than or equal to $22'000
	else if (userInput_Sales >= 22000) {
		employeeSalary = (userInput_Sales * 0.16) - employeeAdvance;
		printf("Sales person's commision is: %lf dollars.\n", userInput_Sales * 0.16);
		printf("Employee deserves %lf dollars from the company!\n", employeeSalary);
		printf("-----------------------------------------------\n");
	}
	//if all above fails
	else {
		printf("An error occured. Please try again!\n");
		printf("-----------------------------------------------\n");
	}
}