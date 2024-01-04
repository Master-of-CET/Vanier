//include header files
#include "Functions_1.h"
#include "Functions_2.h"


int test_grades[35]; //array to store grades
int nu_students = 0; //number of students

//main program
void main()
{
  printf("How many students do you have?: ");
  scanf("%d", &nu_students);
  read_grades(test_grades,nu_students); //call read_grades function
  print_grades(test_grades,nu_students); //call print_grades function

  //print results to console
  printf("You have %d students! \nThe average grade is %5.2f\n", nu_students, average(test_grades,nu_students));
}

