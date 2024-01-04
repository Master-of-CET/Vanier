/*
Name:Massimo Valentini
Online Lab : 6
Objective: Using structures and functions, add two
           fractions and display the result as a fraction.
Date Due: 14 / 5 / 2020
Question : 1
Note:
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma warning(disable : 4996)

struct StudentInfo
{
    int ID;
    char name[100];
    float QuizzesGrades1, QuizzesGrades2, MidtermGrade, FinalExamGrade, TotalGrade;
}student[19];

int MenuAnswer, tally = 0, i = 0;

int main()
{
    char answer;
    printf("\nWould you like to go to the menu? Enter Y or N:");
    scanf(" %c", &answer);
    answer = toupper(answer);
    while (answer == 'Y') {
        menu();

        printf("\nDo you want to return to the menu? (Y or N): ");
        scanf(" %c", &answer);
        answer = toupper(answer);

    }
    printf("GoodBye!");
    return 0;

}
int menu()
{
    for (int i = 0; i < 18; ++i)
    {
        printf("==");
    }
    printf("\n\t\tMENU\n");
    for (int i = 0; i < 18; ++i)
    {
        printf("==");
    }
    printf("\n1. Add student records?\n2. Delete student records\n3. View all student records\n4. Calculate an average of the class scores.\n");
    printf("Enter your choice(1-4):");
    i = tally;
    scanf("%d", &MenuAnswer);
    switch (MenuAnswer)
    {
    case 1:
        AddStudents(i);
        break;
    case 2:
        DeleteStudents(i);
        break;
    case 3:
        DisplayRecords();
        break;
    case 4:
        average(i);
        break;
    default:
        menu();

    }
}
float AddStudents(int i)
{
    FILE* fd;
    fd = fopen("Info.txt", "a+");
    printf("Input Student ID: ");
    scanf("%d", &student[i].ID);
    printf("Input the students Name: ");
    scanf("%s", &student[i].name);
    printf("Input the students first quiz grade: ");
    scanf("%f", &student[i].QuizzesGrades1);
    printf("Input the students second quiz grade: ");
    scanf("%f", &student[i].QuizzesGrades2);
    printf("Input the students midterm grades: ");
    scanf("%f", &student[i].MidtermGrade);
    printf("Input the students Final ExamGrade: ");
    scanf("%f", &student[i].FinalExamGrade);
    printf("Input the students Total Grade: ");
    scanf("%f", &student[i].TotalGrade);
    fprintf(fd, "ID:%d / Name:%s / First-Quiz:%.1f%% / Second-QuizL:%.1f%% / Mid-Term:%.1f%% / Final Exam:%.1f%% / Overall:%.1f%%\n", student[i].ID, student[i].name, student[i].QuizzesGrades1, student[i].QuizzesGrades2, student[i].MidtermGrade, student[i].FinalExamGrade, student[i].TotalGrade);
    printf("\nID:%d\nName:%s\nFirst-Quiz:%.1f%%\nSecond-Quiz:%.1f%%\nMid-Term:%.1f%%\nFinal Exam%.1f%%\nTotal Grade:%.1f%%\n", student[i].ID, student[i].name, student[i].QuizzesGrades1, student[i].QuizzesGrades2, student[i].MidtermGrade, student[i].FinalExamGrade, student[i].TotalGrade);
    printf("Counter:%d", i);
    tally += 1;
    fclose(fd);
    return(tally);
}
float DeleteStudents()
{
    FILE* fileptr1, * fileptr2;
    char filename[40] = "Info.txt";
    char ch;
    int delete_line, temp = 1;

    fileptr1 = fopen(filename, "r"); //open file in read mode
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    rewind(fileptr1); //rewind
    printf(" \n Enter line number of the line to be deleted:");
    scanf("%d", &delete_line);
    fileptr2 = fopen("replica.c", "w");  //open new file in write mode
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        ch = getc(fileptr1);
        if (ch == '\n')
        {
            temp++;
        }
        if (temp != delete_line)//except the line to be deleted
        {

            putc(ch, fileptr2);  //copy all lines in file replica.c
        }
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove(filename);
    rename("replica.c", filename); //rename the file replica.c to original name
    printf("\n The contents of file after being modified are as follows:\n");
    fileptr1 = fopen(filename, "r");
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    tally -= 1;
    fclose(fileptr1);
    return 0;

}
float DisplayRecords()
{
    char ch;
    FILE* fd;
    fd = fopen("Info.txt", "r");
    ch = getc(fd);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fd);
    }
    rewind(fd);
    fclose(fd);
    return(0);

}
float average(int tally)
{
    float avg = 0;
    for (int i = 0; i < tally; ++i)
    {
        avg += student[i].TotalGrade;
        printf("\nStudents[%d]:%f.1%%", i, student[i].TotalGrade);
    }
    avg = avg / tally;
    printf("\nAverage:%.1f%%", avg);
    return(0);
}