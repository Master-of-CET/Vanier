//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//This program is designed to perform 10 addition operations, where the user is asked to input the sum. The numbers are random	//
//(between 1 and 500).																											//
//																																//
//Program made by: Leonardo Fusser (1946995)																					//
//For: Subash Handa																												//
//Embedded Systems Programming																									//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>  //enables use of random() function
#include <time.h>    //enables use of time() function


/*Start of functions*/

//name function
char NameFunction() {
	
	char UserName[30]; //name stored in array

	printf("-----------------------------------------------\n"); //page break
	printf("\n"); //line skip

	printf("Please enter your name (Max 30 characters): ");
	fgets(UserName, 30, stdin); //reads a whole line entered by the user (up to limit)

	printf("\n"); //line skip
	printf("-----------------------------------------------\n"); //page break

	RandomFunction(UserName); //call to random number generator function (passing name entered by user)
}

//random number generator function
int RandomFunction(char UserName[]) {

	int RandomNumberArray1[10]; //array to store 1st numbers (10 for 10 questions)
	int RandomNumberArray2[10]; //array to store 2nd numbers (10 for 10 questions)

	srand((int)time(0)); //creates a unique seed

	//for loop to generate 1st random numbers
	//(10 iterations for 10 questions)
	for (int i = 0; i < 10; ++i) {
		RandomNumberArray1[i] = rand() % 500 + 1; //number generated stored in coresponding element location in array
	}

	//for loop to generate 2nd random numbers
	//(10 iterations for 10 questions)
	for (int i = 0; i < 10; ++i) {
		RandomNumberArray2[i] = rand() % 500 + 1; //number generated stored is coresponding element location in array
	}

	EquationShowFunction(RandomNumberArray1, RandomNumberArray2, UserName); //call to equation display function
	//(passing 1st numbers, 2nd numbers and name entered by user)
}

//equation (summation) display function
 int EquationShowFunction(int RandomNumberArray1[], int RandomNumberArray2[], char UserName[]) {

	int UsrAnsInput = 0; //user answer input
	int UsrAnsArray[10]; //stores user answer input into array

	//for loop to print summation question and takes answer from user
	//(10 iterations for 10 questions)
	for (int i = 0; i < 10; ++i) {
		printf("\n");                                                //line skip
		printf("(Question %d)\n", i + 1);                            //question # based on loop iteration (up to 10)
		printf("What is the answer to the following equation?\n");
		printf("%d\n", RandomNumberArray1[i]);                       //takes random number stored in 1st number array and prints to user (based on question #)
		printf("+\n");												 //line skip
		printf("%d\n", RandomNumberArray2[i]);						 //takes random number stored in 2nd number array and prints to user (based on question #)
		printf("What is the sum: ");
		scanf_s("%d", &UsrAnsInput);								 //takes user answer
		UsrAnsArray[i] = UsrAnsInput;								 //stores user answer in corresponding element location in array
		printf("\n");												 //line skip
	}

	ResultFunction(RandomNumberArray1, RandomNumberArray2, UsrAnsArray, UserName); //call to result function
	//(passing 1st numbers, 2nd numbers, user's answers and name entered by user)
}

//result function
int ResultFunction(int RandomNumberArray1[], int RandomNumberArray2[], int UsrAnsArray[], char UserName[]) {

	int RandomNumberSum[10]; //stores summation of 1st and 2nd numbers in array

	//for loop to calculate sum of 1st and 2nd numbers
	//(10 iterations for 10 questions)
	for (int i = 0; i < 10; ++i) {
		RandomNumberSum[i] = RandomNumberArray1[i] + RandomNumberArray2[i]; //summation stored in corresponding element location in array
	}

	EquationCheckFunction(RandomNumberSum, UsrAnsArray, UserName); //call to user's answer validation function
	//(passing summation answers, user's answers and name entered by user)
}

//user answer validation function
int EquationCheckFunction(int RandomNumberSum[], int UsrAnsArray[], char UserName[]) {

	int UsrNumPoints = 0; //number of correct answers user has

	printf("-----------------------------------------------\n"); //page break
	printf("\n");												 //line skip

	//for loop to check whether user's answers are correct or not
	//(10 iterations for 10 questions)
	for (int i = 0; i < 10; ++i) {
		//if user answer is correct
		if (RandomNumberSum[i] == UsrAnsArray[i]) {
			printf("Question %d: answer correct! (Answer: %d)\n", i + 1, RandomNumberSum[i]); //prints correct answer and shows answer
			UsrNumPoints = UsrNumPoints + 1; //points (correct answers) tracked (+1 point each time)
		}
		//or if user answer is incorrect
		else {
			printf("Question %d: answer incorrect! Your answer: %d (Correct answer: %d)\n", i + 1, UsrAnsArray[i], RandomNumberSum[i]); //prints incorrect answer, entered answer and expected answer
			UsrNumPoints = UsrNumPoints + 0; //no points obtained for answer
		}
	}
	printf("\n"); //line skip

	DisplayFunction(UsrNumPoints, UserName); //call to user statistic function (passing number of correct answers and name entered by user)
}

//user statistic function
int DisplayFunction(int NumPoints, char UserName[]) {

	float UsrAverage; //user average for correct answers

	printf("-----------------------------------------------\n"); //page break
	printf("\n"); //line skip

	printf("Statistics for user: %s", UserName);					//print name entered by user
	printf("Number of answers correct: %d\n", NumPoints);			//print number of correct answers 
	UsrAverage = (NumPoints / 10.0) * 100.0;						//calculate average of correct answers
	printf("Average of correct answers: %.1f %%\n", UsrAverage);	//print average

	printf("\n"); //line skip
	printf("-----------------------------------------------\n"); //page break
}

/*End of functions*/

//main function
void main() {

	NameFunction(); //call to name function

}