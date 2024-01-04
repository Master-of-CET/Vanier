//header file
#include "Functions_1.h"

//average function
float average(int *ave_grades, int number)
{
  int i;
  float sum = 0;
  for(i = 0; i < number; i++, ave_grades++)
  {
    sum += *ave_grades; //save grades to array
  }
  return (sum/number); //return average
}
