//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//This program is designed to perform multiple matrix operations that are chosen by the user. Either Addition, Subtraction or Multiplication are chosen by the user.	//
//																																										//
//Program made by: Leonardo Fusser (1946995)																															//
//																																										//
//For: Subash Handa																																						//
//Embedded Systems Programming																																			//
//Lab2Online, Question 3																																				//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>

void main() {

	char UserSelection; //stores character input from the user
	int i; //loop iterator
	int j; //loop iterator
	int k; //loop iterator
	
	//Matrix 1 characteristics
	int MatrixRow1;
	int MatrixColum1;
	
	//Matrix 2 characteristics
	int MatrixRow2;
	int MatrixColum2;
	
	//First matrix (2D array)
	int FirstMatrix[30][30]; //max 30 by 30 first matrix
	
	//Second matrix (2D array)
	int SecondMatrix[30][30]; //max 30 by 30 second matrix
	
	//Reults stored in Result matrix (2D array)
	int ResultMatrix[30][30]; //max 30 by 30 result matrix

	//user selection (used later for switch statement)
	printf("Please select one of the following matrix operations:\n");
	printf("A (Addition), S (Subtraction), M (Multiplication): ");
	scanf_s("%c", &UserSelection); //selection stored in UserSelection


	//if user selects Addition or Subtraction
	if (UserSelection == 'A' || UserSelection == 'S') {

		printf("---------------------------------------------------------------------\n"); //Page break

		//user enters characteristics for first matrix
		printf("Please enter the number of rows and columns for the first matrix (seperated by a space)(Max 30 by 30): ");
		scanf_s("%d %d", &MatrixRow1, &MatrixColum1); //input stored in MatrixRow1 & MatrixColumn1

		//user then enters characteristics for the second matrix
		printf("Please enter the number of rows and columns for the second matrix (seperated by a space)(Max 30 by 30); ");
		scanf_s("%d %d", &MatrixRow2, &MatrixColum2); //input stored in MatrixRow2 & MatrixColumn2

		printf("---------------------------------------------------------------------\n"); //Page break

		printf("\n"); //line skip

		//user enters elements for matrix 1
		printf("(Please enter elements of matrix 1:)\n");
		//for loop for user to input data for matrix based on characteristics of the matrix
		for (i = 0; i < MatrixRow1; ++i)
			for (j = 0; j < MatrixColum1; ++j) {
				printf("Enter element (location: %d,%d) for matrix 1: ", i + 1, j + 1);
				scanf_s("%d", &FirstMatrix[i][j]); //data values stored in FirstMatrix array
			}

		printf("\n"); //line skip

		//user enters elements for matrix 2
		printf("(PLease enter elements of matrix 2:)\n");
		//for loop for user to input data for matrix based on characteristics of the matrix
		for (i = 0; i < MatrixRow2; ++i)
			for (j = 0; j < MatrixColum2; ++j) {
				printf("Enter element (location: %d,%d) for matrix 2: ", i + 1, j + 1);
				scanf_s("%d", &SecondMatrix[i][j]); //data values stored in SecondMatrix array
			}

		printf("\n"); //line skip

		printf("---------------------------------------------------------------------\n"); //Page break
	}
	//if user selects Multiplication
	else if (UserSelection == 'M') {

		printf("---------------------------------------------------------------------\n"); //Page break

		//user enters characteristics for first matrix
		printf("Please enter the number of rows and colums for the first matrix (seperated by a space)(Max 30 by 30): ");
		scanf_s("%d %d", &MatrixRow1, &MatrixColum1);

		//user then enters characteristics for the second matrix
		printf("Please enter the number of rows and colums for the second matrix (seperated by a space)(Max 30 by 30): ");
		scanf_s("%d %d", &MatrixRow2, &MatrixColum2);

		//iterates until number of columns of matrix 1 is equal to the number of rows of matrix 2 (rules when multiplying matrices)
		while (MatrixColum1 != MatrixRow2) {
			printf("---------------------------------------------------------------------\n"); //Page break

			printf("\n"); //line skip

			printf("Bad input! Please check your values and try again!\n");
			printf("Please make sure the number of columns in (matrix 1) is equal to the number of rows in (matrix 2)!\n");
			printf("Attempting to get user input again...\n");

			printf("\n"); //line skip

			printf("Please enter the number of rows and columns for the first matrix (seperated by a space)(Max 30 by 30): "); //user enters characteristics for first matrix again
			scanf_s("%d%d", &MatrixRow1, &MatrixColum1); //input stored in MatrixRow1 & MatrixColumn1

			printf("Please enter the number of rows and columns for the second matrix (seperated by a space)(Max 30 by 30): "); //user then enters characteristics for the second matrix again
			scanf_s("%d%d", &MatrixRow2, &MatrixColum2); //input stored in MatrixRow2 & MatrixColumn2
		}

		printf("---------------------------------------------------------------------\n"); //Page break

		printf("\n"); //line skip

		//user enters elements for matrix 1
		printf("(Please enter elements of matrix 1:)\n");
		//for loop for user to input data for matrix based on characteristics of the matrix
		for (i = 0; i < MatrixRow1; ++i)
			for (j = 0; j < MatrixColum1; ++j) {
				printf("Enter element (location: %d,%d) for matrix 1: ", i + 1, j + 1);
				scanf_s("%d", &FirstMatrix[i][j]); //data values stored in FirstMatrix array
			}

		printf("\n"); //line skip

		//user enters elements for matrix 2
		printf("(Please enter elements of matrix 2:)\n");
		//for loop for user to input data for matrix based on characteristics of the matrix
		for (i = 0; i < MatrixRow2; ++i)
			for (j = 0; j < MatrixColum2; ++j) {
				printf("Enter element (location: %d,%d) for matrix 2: ", i + 1, j + 1);
				scanf_s("%d", &SecondMatrix[i][j]); //data values stored in SecondMatrix array
			}

		printf("\n"); //line skip

		printf("---------------------------------------------------------------------\n"); //Page break

	}
	else {
		printf("\n"); //line skip

		printf("Please check your inputs!\n");
		printf("An internal error has occured. Please restart the program and try again!\n");

		printf("\n"); //line skip

		printf("---------------------------------------------------------------------\n"); //Page break
	}

	//switch statement used to select which matrix operation was chosen by the user
	switch (UserSelection) {

	//addition operation
	case 'A':
		//for loop to perform addition arithmetic
		for (i = 0; i < MatrixRow1; ++i)
			for (j = 0; j < MatrixColum2; ++j) {
				ResultMatrix[i][j] = FirstMatrix[i][j] + SecondMatrix[i][j]; //sum stored in ResultMatrix array
			}

		printf("The sum of (Matrix 1) and (Matrix 2) yields: \n");
		//for loop to print results from addition arithmetic
		for (i = 0; i < MatrixRow1; ++i)
			for (j = 0; j < MatrixColum2; ++j) {
				printf("%d   ", ResultMatrix[i][j]); //prints value stored in ResultMatrix[i][j]
				if (j == MatrixColum2 - 1) {
					//seperates the top and bottom of the array when printing
					printf("\n\n"); //line skip
				}
			}
		
		printf("---------------------------------------------------------------------\n"); //Page break
		
		break;

	//subtraction operation
	case 'S':
		//for loop to perform subtraction arithmetic
		for (i = 0; i < MatrixRow1; ++i)
			for (j = 0; j < MatrixColum2; ++j) {
				ResultMatrix[i][j] = FirstMatrix[i][j] - SecondMatrix[i][j]; //subtraction stored in ResultMatrix array
			}

		printf("The subtraction of (Matrix 1) and (Matrix 2) yields: \n");
		//for loop to print results from subtraction arithmetic
		for (i = 0; i < MatrixRow1; ++i)
			for (j = 0; j < MatrixColum2; ++j) {
				printf("%d   ", ResultMatrix[i][j]); //prints value stored in ResultMatrix[i][j]
				if (j == MatrixColum2 - 1) {
					//seperates the top and bottom of the array when printing
					printf("\n\n"); //line skip
				}
			}
		
		printf("---------------------------------------------------------------------\n"); //Page break
		
		break;

	//multiplication operation
	case 'M':
		//for loop to initialize elements to 0 in ResultMatrix array
		for (i = 0; i < MatrixRow1; ++i) {
			for (j = 0; j < MatrixColum2; ++j) {
				ResultMatrix[i][j] = 0; //stored value of 0 in ResultMatrix array
			}
		}

		//for loop to perform multiplication arithmetic
		for (i = 0; i < MatrixRow1; ++i) {
			for (j = 0; j < MatrixColum2; ++j) {
				for (k = 0; k < MatrixColum1; ++k) {
					ResultMatrix[i][j] += FirstMatrix[i][k] * SecondMatrix[k][j]; //multiplication stored in ResultMatrix array
				}
			}
		}

		printf("The multiplication of (Matrix 1) and (Matrix 2) yields: \n");
		//for loop to print results from multiplication arithmetic
		for (int i = 0; i < MatrixRow1; ++i) {
			for (int j = 0; j < MatrixColum2; ++j) {
				printf("%d  ", ResultMatrix[i][j]); //prints value stored in ResultMatrix[i][j]
				//seperates the top and bottom of the array when printing
				if (j == MatrixColum2 - 1)
					printf("\n\n"); //line skip
			}
		}
		
		printf("---------------------------------------------------------------------\n"); //Page break
		
		break;

	default:
		printf("\n"); //line skip

		printf("An error has occured. Please check your inputs and try again!. Goodbye!");

		printf("\n"); //line skip

		printf("---------------------------------------------------------------------\n"); //Page break
	}
}