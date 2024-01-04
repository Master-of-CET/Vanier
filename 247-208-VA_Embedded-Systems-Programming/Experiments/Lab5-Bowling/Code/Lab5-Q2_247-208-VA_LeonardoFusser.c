//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//This program calculates a quadratic formula where a, b and c are inputted by the user.                                                //
//Embedded Systems Programming																										    //
//Subash Handa																														    //
//Lab 5, Question 2																														//
//Program made by: Leonardo Fusser (1946995)																							//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <math.h>  //enable math library

int main()
{
    while (1)
    {
        //quadratic equation format
        printf("Quadratic Equation format: aX^2 + bX + c \n");

        //delcare inputs and outputs and their types
        float a, b, c, determinant, x1, x2, realSolution, imaginarySolution;

        //user input
        printf("Enter the coefficients a, b, c respectively seperated by a comma  \n");
        scanf_s("%f, %f, %f", &a, &b, &c);

        if (a == 0)
        {
            printf("This is not a quadratic equation \n");
            break;
        }

        //calculate the determinant to determine the number and the type of the solutions
        determinant = ((b * b) - (4 * a * c));
        printf(" Determinant = %f \n", determinant);

        if (determinant == 0)
        {
            // if the determinant is zero, then there will be one solution
            x1 = x2 = (-b) / (2 * a);
            printf("One real solution and it is %0.1f \n", x1);
        }
        else if (determinant > 0)
        {
            x1 = ((-b) + sqrtf(determinant)) / (2 * a);
            x2 = ((-b) - sqrtf(determinant)) / (2 * a);

            printf("Two distinct real solutions and they are %0.1f, and %0.1f \n", x1, x2);
        }
        else
        {
            //if the determinant is negative, then the solutions will contain an imaginary part
            realSolution = -b / (2 * a);
            imaginarySolution = sqrtf(-determinant) / (2 * a);

            printf(" Complex Solutions, and they are %0.1f + %0.1fi and %0.1f - %0.1fi \n", realSolution, imaginarySolution, realSolution, imaginarySolution);
        }
    }
}