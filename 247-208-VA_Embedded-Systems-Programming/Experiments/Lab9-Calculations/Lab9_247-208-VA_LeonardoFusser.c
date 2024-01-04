/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//This program is designed to calculate the max, min, mean, median, variance and standard-deviation of a certain number of measurements entered by a user.			   //
//																																									   //
//Program made by: Leonardo Fusser (1946995)																														   //
//For: Subash Handa																																					   //
//Embedded Systems Programming																																		   //
//Lab3Online																																						   //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <math.h>

/*Start of functions*/

//function to find the MAX & MIN
void MaxMinFunction(double ArrayMeasurements[], int NumElements) {
	
	//new variable declarations
	double Max;
	double Min;
	
	
	Max = ArrayMeasurements[0]; //temp
	//for loop to determine MAX
	for (int i = 1; i < NumElements; ++i) {
		if (Max < ArrayMeasurements[i]) {
			Max = ArrayMeasurements[i];
		}
	}
	printf("The MAX is: %.2lf\n", Max); //print MAX

	Min = ArrayMeasurements[0]; //temp
	//for loop to determine MIN
	for (int i = 1; i < NumElements; ++i) {
		if (Min > ArrayMeasurements[i]) {
			Min = ArrayMeasurements[i];
		}
	}
	printf("The MIN is: %.2lf\n", Min); //print MIN
}

//function to find the MEAN, VARIANCE & STANDARD-DEVIATION
void MeanVarianceDeviationFunction(double ArraySum, int NumElements, double ArrayMeasurements[]) {
	
	//new variable declarations
	double Mean;
	double VarianceSum = 0;
	double Variance;
	double StdDeviation;

	Mean = ArraySum / NumElements;         //MEAN calculation
	printf("The MEAN is: %.2lf\n", Mean);  //print MEAN

	//for loop to calculate variance sum
	for (int i = 0; i < NumElements; i++) {
		VarianceSum = VarianceSum + pow((ArrayMeasurements[i] - Mean), 2);
	}
	Variance = VarianceSum / (float)NumElements;  //VARIANCE calculation
	printf("The VARIANCE is: %.2lf\n", Variance); //print VARIANCE

	StdDeviation = sqrt(Variance);							    //STANDARD-DEVIATION calculation
	printf("The STANDARD DEVIATION is: %.2lf\n", StdDeviation); //print STANDARD-DEVIATION
}

//function to find the MEDIAN
void MedianFunction(double ArrayMeasurements[], int NumElements) {
	
	//new variable declarations
	int temp = 0;
	double Median = 0;

	//(in order to find MEDIAN, we must sort measurements in ascending order first)
	//for loop to sort array
	for (int i = 0; i < NumElements; i++) {
		for (int j = 0; j < NumElements - 1; j++) {
			if (ArrayMeasurements[j] > ArrayMeasurements[j + 1]) {
				temp = ArrayMeasurements[j];
				ArrayMeasurements[j] = ArrayMeasurements[j + 1];
				ArrayMeasurements[j + 1] = temp;
			}
		}
	}

	//if even # of measurements...
	if (NumElements % 2 == 0) {
		Median = (ArrayMeasurements[(NumElements - 1) / 2] + ArrayMeasurements[NumElements / 2]) / 2; //formula to find MEDIAN (even)
	}

	//or if odd # of measuremnets...
	else {
		Median = ArrayMeasurements[NumElements / 2]; //formula to find MEDIAN (odd)
	}

	printf("The MEDIAN is: %.2lf\n", Median); //print MEDIAN
}

/*End of functions*/

//main
void main() {

	//variable definitions
	int UsrInput_NumMeasurements;     //# of measurements
	double ArrayMeasurements[20];	  //measurements stored in array (max 20 measurements)
	double ArrayMeasurementsSum = 0;  //sum of measurements
	
	//user input (number of measurements)
	printf("Enter the number of measurements in total (max 20): ");
	scanf_s("%d", &UsrInput_NumMeasurements);

	printf("--------------------------------------------------------\n"); //page break

	//for loop to get measurements from user
	for (int i = 0; i < UsrInput_NumMeasurements; ++i) {
		printf("Enter measurement (%d): ", i + 1);
		scanf_s("%lf", &(ArrayMeasurements[i])); //measurements stored in array
		ArrayMeasurementsSum = ArrayMeasurementsSum + ArrayMeasurements[i]; //sum of measurements calculation
	}
	printf("--------------------------------------------------------\n"); //page break

	//function calls (& passing certain arguments)
	MaxMinFunction(ArrayMeasurements, UsrInput_NumMeasurements);										//function call to MAX & MIN arithemetic operation
	MeanVarianceDeviationFunction(ArrayMeasurementsSum, UsrInput_NumMeasurements, ArrayMeasurements);   //function call to MEAN, VARIANCE, DEVIATION arithemetic operation
	MedianFunction(ArrayMeasurements, UsrInput_NumMeasurements);										//function call to MEDIAN arithemetic operation

	printf("--------------------------------------------------------\n"); //page break
}