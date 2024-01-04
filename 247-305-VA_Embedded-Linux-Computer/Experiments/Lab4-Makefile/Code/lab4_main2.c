#include <stdio.h>

int test_grades[35];
int nu_students = 0;


int read_grades(int *r_grades,int number)
{
  int i;
  for(i = 0; i < number; i++, r_grades++)
  {
    printf("Enter a grade: ");
    scanf("%d",r_grades);
  }
  return 0;
}

int print_grades(int *p_grades, int numb)
{
  int i;
  for(i = 0; i < numb; ++i, p_grades++)
  {
    printf("%d\n",*p_grades);
  }
}

float average(int *ave_grades, int number)
{
  int i;
  float sum = 0;
  for(i = 0; i < number; i++, ave_grades++)
  {
    sum += *ave_grades;
  }
  return (sum/number);
}


void main()
{
  printf("How many students do you have?: ");
  scanf("%d", &nu_students);
  read_grades(test_grades,nu_students);
  print_grades(test_grades,nu_students);

  printf("You have %d students. \nThe average grade is %5.2f\n", nu_students, average(test_grades,nu_students));
  
}

