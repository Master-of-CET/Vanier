//include header file
#include "Functions_2.h"

//take grades from user function
int read_grades(int *r_grades,int number)
{
  int i;
  for(i = 0; i < number; i++, r_grades++)
  {
    printf("Enter a grade: ");
    scanf("%d",r_grades); //store grades in array
  }
  return 0;
}

//print grades user inputed to console
int print_grades(int *p_grades, int numb)
{
  int i;
  for(i = 0; i < numb; ++i, p_grades++)
  {
    printf("%d\n",*p_grades); //prints grades stored in array
  }
}
