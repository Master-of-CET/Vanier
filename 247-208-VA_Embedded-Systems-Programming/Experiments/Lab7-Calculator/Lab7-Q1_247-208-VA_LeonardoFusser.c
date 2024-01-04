////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//This program is a sales calculator where the number of months of sales and sales for each month are inputted by the user.                                       //
//                                                                                                                                                                //
//Program made by: Leonardo Fusser (1946995)                                                                                                                       //
//                                                                                                                                                                //
//For: Subash Handa                                                                                                                                               //
//Embedded Systems Programming                                                                                                                                    //
//                                                                                                                                                                //
//Lab 1 online, Question 1                                                                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//***Note: this might not run in Visual Studio due to it's particular settings.
//         Instead, use this online compiler that will work:
//         https://www.onlinegdb.com/

#include <stdio.h>

void main()
{
    float TotalSales; //stores the amount of total sales (all months)
    float SalesAverage; //stores the sales average
    float HighestSales; //stores the highest amount of sales
    float LowestSales; //stores the lowest amount of sales
    int NumMonths; //stores the number of months of sales
    int i; //loop iterator

    //user input number of months of sales
    printf("Enter the number of months for your sales: ");
    scanf("%d", &NumMonths);
    float userVals[NumMonths];

    //repeat of what the user has inputed above
    printf("Enter %d months of sales data...\n", NumMonths);

    //page break
    printf("------------------------------------------------\n");

    //loop that asks the user to input the amount of sales for month x up to NumMonths
    for (i = 0; i < NumMonths; ++i) {
        printf("Sales for month %d: ", i + 1);
        scanf("%f", &(userVals[i])); //stores sales in array under element i
        TotalSales = TotalSales + userVals[i]; //calaculates total sales
    }

    //loop that determines highest sales
    HighestSales = userVals[0];
    for (i = 1; i < NumMonths; i++) {
        if (HighestSales < userVals[i]) {
            HighestSales = userVals[i];
        }
    }

    //loop that deteremines lowest sales (opposite from above)
    LowestSales = userVals[0];
    for (i = 1; i < NumMonths; i++) {
        if (LowestSales > userVals[i]) {
            LowestSales = userVals[i];
        }
    }
    //page break
    printf("------------------------------------------------\n");

    //loop that prints out sales values that is stored in userVals[] array to user
    printf("Entered sales values: ");
    for (i = 0; i < NumMonths; ++i) {
        printf("%4.2f $ (Month %d) / ", userVals[i], i + 1);
    }
    printf("\n");
    //page break
    printf("------------------------------------------------\n");

    //prints TotalSales, SalesAverage, HighestSales and LowestSales to user
    printf("Total amount of sales: %4.2f $\n", TotalSales); //print TotalSales
    SalesAverage = TotalSales / NumMonths; //calculate SalesAverage
    printf("Average sales: %4.2f $\n", SalesAverage); //print SalesAverage
    printf("Highest sales: %4.2f $\n", HighestSales); //print HighestSales
    printf("Lowest sales: %4.2f $\n", LowestSales); //print LowestSales
    //page break
    printf("------------------------------------------------\n");
}