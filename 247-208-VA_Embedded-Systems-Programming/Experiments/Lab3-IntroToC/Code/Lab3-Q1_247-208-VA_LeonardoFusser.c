//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//This program calculates the time it takes for sound to travel through a certain medium. The type of medium and distance (in feet) the sound will travel, will be inputted by the user.//
//Embedded Systems Programming (Lab 3)(Question 1)																																		//
//Subash Handa																																											//			
//Program made by: Leonardo fusser (1946995)																																			//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>

void main() {
	//variable definitions
	const int time_air = 1100;
	const int time_water = 4900;
	const int time_steel = 16400;
	double dist_air;
	double dist_water;
	double dist_steel;
	int usr_input;
	double usr_distance;

	//print menu to user
	printf("Medium:         Speed (feet per second): \n");
	printf("Air             1'100\n");
	printf("Water           4'900\n");
	printf("Steel           16'400\n");
	printf("------------------------------------------------------------\n"); //line break 
	
	//user selection from menu
	printf("Select 1 (for Air), 2 (for Water) or 3 (for Steel): ");
	scanf_s("%d", &usr_input);
	printf("------------------------------------------------------------\n");//line break
	
	//user distance input
	printf("Enter the number of feet for the distance: ");
	scanf_s("%lf", &usr_distance);
	printf("------------------------------------------------------------\n");//line break

	//input validation & calculations
	if (usr_input >= 1 && usr_input <= 3 && usr_distance > 0) {
		
		//if user selects 1st option
		if (usr_input == 1) {
			dist_air = usr_distance / time_air;
			printf("Time for sound to travel through 'air' as a medium: %lf seconds.\n", dist_air);//print distance in seconds (air)
			printf("------------------------------------------------------------\n");//line break
		}
		//if user selects 2nd option
		else if (usr_input == 2) {
			dist_water = usr_distance / time_water;
			printf("Time for sound to travel through 'water' as a medium: %lf seconds.\n", dist_water);//print distance in seconds (water)
			printf("------------------------------------------------------------\n");//line break
		}
		//if user selects 3rd option
		else if (usr_input == 3) {
			dist_steel = usr_distance / time_steel;
			printf("Time for sound to travel through 'steel' as a medium: %lf seconds.\n", dist_steel);//print distance in seconds (steel)
			printf("------------------------------------------------------------\n");//line break
		}

	}
	//if (IF statement) above fails
	else {
		printf("Please check you inputs and try again!\n");
		printf("-------------------------------------------------\n");//line break
	}
}