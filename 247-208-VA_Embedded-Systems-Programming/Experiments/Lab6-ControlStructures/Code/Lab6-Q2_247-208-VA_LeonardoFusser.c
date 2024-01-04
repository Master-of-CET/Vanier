//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//This program is a simple loan calculation. The user enters the value of the loan, the duration and the interest given to the user.//
//The program then calculates the monthly payment and other costs associated with the user's loan.									//
//																																	//
//Embedded Systems Programming (Lab 6, Question 2)																					//
//Subash Handa																														//
//																																	//
//Program made by: Leonardo Fusser (1946995)																						//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <math.h>

void main() {
	//variable definition
	double usrLoanAmount;
	double usrInterest;
	double usrInterestRate;
	double usrDuration;
	double usrMonths;
	double MonthlyPayment;
	double MonthlyTerm;
	double Term;
	double CalculatedInterest;
	double CalculatedPrincipal;
	double CalculatedBalance;

	printf("---------------------------------------------\n"); //page break
	printf("Enter the amount of the loan (in $): ");
	scanf_s("%lf", &usrLoanAmount); //usr's loan
	printf("Enter the interest rate (in %%): ");
	scanf_s("%lf", &usrInterest); //usr's interest
	printf("Enter the duration of the loan (in years): ");
	scanf_s("%lf", &usrDuration); //usr's duration of the loan
	printf("---------------------------------------------\n"); //page break
	printf("Entered loan amount is: %.2lf $.\n", usrLoanAmount);
	printf("Entered interest rate is: %.1lf %%.\n", usrInterest);
	printf("Entered loan duration is: %.1lf years.\n", usrDuration);
	printf("---------------------------------------------\n"); //page break

	usrMonths = usrDuration * 12; //convert usr's months to years
	usrInterest = usrInterest / 100; //convert usr's interest (%) to decimal
	usrInterestRate = usrInterest / 12; //convert yearly interest and convert to monthly interest

	printf("You need to make a total of: %.1lf payments.\n", usrMonths);
	MonthlyTerm = pow((1 + usrInterestRate / 12), (usrDuration * 12)); //usr monthly payment calculation
	MonthlyPayment = (usrLoanAmount * usrInterestRate / 12 * MonthlyTerm)/ (MonthlyTerm - 1); //usr monthly payment calculation
	printf("Each monthly payment is: %.2lf $.\n", MonthlyPayment);
	
	printf("---------------------------------------------\n"); //page break
	printf("\tMonth\tInterest\tPrincipal\tBalance\n"); //print months, interest, principal and balance headers
	printf("\t------------------------------------------------\n"); //page break

	//iterate depending on loan duration and calculate interest, principal and balance for each month
	for (int i = 1; i < usrMonths + 1; ++i) {
		Term = pow((1 + usrInterestRate / 12), (usrDuration * 12));
		CalculatedBalance = (usrLoanAmount - (i * MonthlyPayment)); //calculated balance
		CalculatedInterest = (CalculatedBalance * usrInterestRate); //calculated interest
		CalculatedPrincipal = (MonthlyPayment * CalculatedInterest); //calculated principal

		if (CalculatedBalance < 0) {
			CalculatedBalance = 0.00; //ensure that balance at last month is = 0.00
		}
		printf("\t%d\t%.2lf$\t\t%.2lf\t\t%.2lf\n", i, CalculatedInterest, CalculatedPrincipal, CalculatedBalance); //print months, interest, principal and balance
	}
}