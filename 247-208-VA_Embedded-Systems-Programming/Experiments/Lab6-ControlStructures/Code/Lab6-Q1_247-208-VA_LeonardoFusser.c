/*
This program is desgined for a user to guess a number. A number between 1 and 50 is randomly selected by the computer and the user is asked to guess that number.
The program stops when the user guesses the correct number.

Embedded Systems Programming
Lab 6, Question 1
Subash Handa

Program made by: Leonardo Fusser (1946995)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {

	//varible definitions
	int randNum; //random number
	int guessNum; //user number (guess)
	int numTries = 1; //loop (count) variable

	srand((int)time(0)); //create seed
	randNum = (rand() % 50) + 1; //generated random number between 1 and 50

	//user input
	printf("-----------------------------------------------------\n"); //page break
	printf("Enter a guess between 1 & 50: "); //user input number between 1 and 50
	scanf_s("%d", &guessNum);
	
	//guess check (if guessed number isn't equal to random number)
	while (guessNum != randNum) { //logical NOT check
		
		//input check (if outside range)
		while (guessNum <= 0 || guessNum >= 51) {
			printf("Please try again!\n");
			printf("The number entered is not between 1 and 50.\n");
			printf("Guessed number: %d\n", guessNum); //print guessed number
			printf("-----------------------------------------------------\n"); //page break
			printf("Enter a guess between 1 & 50: "); //take user input again, else infinite loop
			scanf_s("%d", &guessNum);
		}
			
			//if guessed number is greater than random number
			if (guessNum > randNum) {
				printf("Please try again!\n");
				printf("Your guess is too high! Try guessing a lower number.\n");
				printf("Guessed number: %d\n", guessNum); //print guessed number
				printf("-----------------------------------------------------\n"); //page break
				printf("Enter a guess between 1 & 50: "); //take user input again, else infinite loop
				scanf_s("%d", &guessNum);

				//count +1 for successful try
				numTries += 1;
			}
			//if guessed number is less than random number
			else if (guessNum < randNum) {
				printf("Please try again!\n");
				printf("Your guess is too low! Try guessing a higher number.\n");
				printf("Guessed number: %d\n", guessNum); //print guessed number
				printf("-----------------------------------------------------\n"); //page break
				printf("Enter a guess between 1 and 50: "); //take user input again, else infinite loop
				scanf_s("%d", &guessNum);

				//count +1 for successful try
				numTries += 1;
			}
			//if all else fails
			else {
				printf("An internal error has occured! Please try to run the program again.");
			}
	}
	//if guessed number is = to random number
	printf("-----------------------------------------------------\n"); //page break
	printf("You guessed the correct number! The mysterious number was %d.\n", randNum); //print to user the  number
	printf("You guessed %d times to get the correct answer.\n", numTries); //print to user the number of successful guessed attempts
}