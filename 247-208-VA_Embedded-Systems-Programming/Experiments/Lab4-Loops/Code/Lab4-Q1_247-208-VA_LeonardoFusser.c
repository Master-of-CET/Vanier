/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//This program is desinged to calculate the LCM (lowest common multiple) from two values. The values are inputted by the user.     //
//Embedded Systems Programming (Lab 4)(Question 1)                                                                                 //
//Subash Handa                                                                                                                     //
//Program made by: Leonardo Fusser (1946995)                                                                                       //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>

int main()
{
    //variable declaration
    int usr_num1;
    int usr_num2;
    
    printf("Enter your 1st Number: ");
    scanf_s("%d", &usr_num1); //receive 1st number
    printf("Enter your 2nd number: ");
    scanf_s("%d", &usr_num2); //receive 2nd number
    printf("-----------------------------------------------\n"); //page break
    printf("The lowest common multiple of %d and %d is: %d.\n", usr_num1, usr_num2, lcm(usr_num1, usr_num2)); //print result of LCM
    printf("-----------------------------------------------\n"); //page break
}
//call to function (for greatest common denominator)
int gcd(int usr_num1, int usr_num2)
{
    if (usr_num1 == 0)
        return usr_num2;
    return gcd(usr_num2 % usr_num1, usr_num1);
}

//call to function (for lowest common denominator)
int lcm(int usr_num1, int usr_num2)
{
    return ((usr_num1 * usr_num2) / gcd(usr_num1, usr_num2));
}