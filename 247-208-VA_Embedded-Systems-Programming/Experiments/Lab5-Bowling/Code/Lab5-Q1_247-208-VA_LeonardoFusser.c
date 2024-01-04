//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//This program calculates the average game score from a user and compares it to the previous average game score for that user (bowling).//
//Embedded Systems Programming																										    //
//Subash Handa																														    //
//Lab 5, Question 1																														//
//Program made by: Leonardo Fusser (1946995)																							//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

void main() {

	//variable definitions
	int TW_total_score; //this week total score
	int Avg_LWscore; //last week average score
	int Avg_TWscore; //this week average score
	int Game1;
	int Game2;
	int Game3;
	int i = 0; //loop variable


	printf("Enter last weeks average score: ");
	scanf_s("%d", &Avg_LWscore); //entered last weeks average score

	//1 iterations
	while (i < 3) {

		printf("Enter the score of game number 1: ");
		scanf_s("%d", &Game1); //entered this week game 1 score

		printf("Enter the score of game number 2: ");
		scanf_s("%d", &Game2); //entered this week game 2 score

		printf("Enter the score of game number 3: ");
		scanf_s("%d", &Game3); //entered this week game 3 score

		printf("-------------------------------------\n");
		
		i = +2; //increment
		
		break;
	}

	TW_total_score = (Game1 + Game2 + Game3); //this week total score
	printf("Total score for your 3 games this week is: %d points.\n", TW_total_score);

	Avg_TWscore = ((TW_total_score) / 3); //average this week score
	printf("Your avrage score for this weeks game is: %d points.\n", Avg_TWscore);

	printf("-------------------------------------\n");

	//if better or worse
	if (Avg_TWscore > Avg_LWscore) {
		printf("You did better than last week. Well done!");
	}
	else {
		printf("You did worse. Better luck next time!");
	}
	return 0;
}