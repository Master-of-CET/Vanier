//////////////////////////////////////////////////////////////////////////////////////////////////
//This program is designed to add two fractions, where the fractions are inputed by the user.   //
//                                                                                              //
//Program made by: Leonardo Fusser (1946995)                                                    //
//For: Subash Handa                                                                             //
//Embedded Systems Programming                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

//struct to store function characteristics
typedef struct Fraction_struct {

    //struct variables
    int Numerator;
    int Denominator;

}Fraction;

//function to calculate summation of fractions while passing arguements from struct
Fraction summation(Fraction F1, Fraction F2){
    
    //performing result arithemetic
    Fraction result = { (F1.Numerator * F2.Denominator) + (F2.Numerator * F1.Denominator), F1.Denominator * F2.Denominator };
    
    return result; //return result to user
}

//main function
void main(){

    //variable declations
    int Numerator1;     //Fraction1 - numerator
    int Denominator1;   //Fraction1 - denominator
    int Numerator2;     //Fraction2 - numerator
    int Denominator2;   //Fraction2 - denominator

    printf("------------------------------------------------------\n"); //page break
    printf("\n"); //line skip
    
    printf("Enter fraction 1 (numerator/denominator - seperated by a space): ");
    scanf_s("%d %d", &Numerator1, &Denominator1);                                  //input from user for fraction 1
    printf("Enter fraction 2 (numerator/denominator - seperated by a space): ");
    scanf_s("%d %d", &Numerator2, &Denominator2);                                  //input from user for fraction 2
    
    printf("\n"); //line skip
    printf("------------------------------------------------------\n"); //page break

    Fraction F1 = { Numerator1, Denominator2 };                         //fraction 1
    Fraction F2 = { Numerator2, Denominator2 };                         //fraction 2
    Fraction summation(Fraction, Fraction);                             //call to summation function
    Fraction result = summation(F1, F2);                                //fraction summation
                                  
    printf("\n"); //line skip
    
    printf("Result: %d / %d\n", result.Numerator, result.Denominator);  //print result of summation to user
    
    printf("\n"); //line skip
    printf("------------------------------------------------------\n"); //page break
}
