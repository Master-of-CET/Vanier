////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//This program is an adaptaion to the zyBooks online book additional exercise 12 (The dice roll program).													      //
//																																								  //
//Program made by: Leonardo Fusser (1946995)																													  //
//																																								  //
//For: Subash Handa																																			      //
//Embedded Systems Programming																																      //
//																																								  //
//Online lab 1, Question 2																																	      //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <stdio.h>
#include <stdlib.h> //enables use of rand()
#include <time.h>   //enables use of time()

int main()
{
	int i; //loop iterator
	int j; //loop iterator for graphical representation (*)
	int Dice1; //Dice 1
	int Dice2; //Dice 2
	int NumRolls; //Number of rolls the user will play
	int DiceSum[13]; //Dice sum array

	//do-while loop
	do {
		//user input number of rolls
		printf("Enter the number of rolls you will play this game: ");
		scanf_s("%d", &NumRolls);
		
		//if user enters NumRolls less than 0
		if (NumRolls <= 0) {
			//page break
			printf("---------------------------------------------------------------\n");
			printf("The program has ended because you entered a bad value.\n");
			printf("Please try again by restarting the program. Goodbye!\n");
			//page break
			printf("---------------------------------------------------------------\n");
			break;
		}

		//main dice program
		if (NumRolls > 0) {
			//if number of rolls are valid (1 and above)
			if (NumRolls > 0) {
				//prints user input
				printf("Results for (%d) rolls played are shown below...\n", NumRolls);
				//page break
				printf("---------------------------------------------------------------\n");
				printf("(Dice roll statistics and histogram:)\n");

				//stores possibilities for dice sum in DiceSum[] array
				for (i = 2; i < 13; ++i) {
					DiceSum[i] = 0;
				}

				srand(time(0)); //creates a unique seed when the prgram is run
				//loop that gerneates random rolls
				for (i = 0; i < NumRolls; ++i) {
					Dice1 = rand() % 6 + 1;
					Dice2 = rand() % 6 + 1;
					//stores in array
					DiceSum[Dice1 + Dice2] = DiceSum[Dice1 + Dice2] + 1;
				}

				//loop that prints out statistics and graphical representations in array
				for (i = 2; i < 13; ++i) {
					printf("Dice sum of (%d) yields (%d) possibilities. (Graphical representation: ", i, DiceSum[i]);
					//loop that prints graphical representaion
					for (j = 1; j <= DiceSum[i]; j++) {
						//graphical representation
						printf("*");
					}
					printf(")");
					printf("\n");
				}
				
				//page break
				printf("---------------------------------------------------------------\n");
				printf("***Note: if there is no graphical representation, then there are no posibilities!\n");
				//page break
				printf("---------------------------------------------------------------\n");
			}
			//if the program encounters any unexpected issues
			else {
				//page break
				printf("---------------------------------------------------------------\n");
				printf("The program has encountered an error. Please try again!\n");
				//page break
				printf("---------------------------------------------------------------\n");
			}
		}
	} 
	//------------------------------------------------------------------------------------------------------------------------------------------------------
	//while part from (do-while)
	while (NumRolls > 0);
		//main program
		if (NumRolls > 0) {
			//if number of rolls are valid (1 and above)
			if (NumRolls > 0) {
				//prints user input
				printf("Results for (%d) rolls played are shown below...\n", NumRolls);
				//page break
				printf("---------------------------------------------------------------\n");
				printf("(Dice roll statistics and histogram:)\n");

				//stores possibilities for dice sum in DiceSum[] array
				for (i = 2; i < 13; ++i) {
					DiceSum[i] = 0;
				}

				srand(time(0)); //creates a unique seed when the prgram is run
				//loop that gerneates random rolls
				for (i = 0; i < NumRolls; ++i) {
					Dice1 = rand() % 6 + 1;
					Dice2 = rand() % 6 + 1;
					//stores in array
					DiceSum[Dice1 + Dice2] = DiceSum[Dice1 + Dice2] + 1;
				}

				//loop that prints out statistics and graphical representations stores in array
				for (i = 2; i < 13; ++i) {
					printf("Dice sum of (%d) yields (%d) possibilities. (Graphical representation: ", i, DiceSum[i]);
					//loop that prints graphical representaion
					for (j = 1; j <= DiceSum[i]; j++) {
						//graphical representation
						printf("*");
					}
					printf(")");
					printf("\n");
				}
				
				//page break
				printf("---------------------------------------------------------------\n");
				printf("***Note: if there is no graphical representation, then there are no posibilities!\n");
				//page break
				printf("---------------------------------------------------------------\n");
			}
			//if the program encounters any unexpected issues
			else {
				//page break
				printf("---------------------------------------------------------------\n");
				printf("The program has encountered an error. Please try again!\n");
				//page break
				printf("---------------------------------------------------------------\n");
			}
		}
}