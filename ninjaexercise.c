#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int choice, calisthenics = 0, temp, climbDistance; // variables for storing different information
	do { // main menu
		printf("Ninja Calisthenics\n");
		printf("1. Practice Kung Fu\n");
		printf("2. Practice Bojustu\n");
		printf("3. Practice Rope Climbing\n");
		printf("4. Stop training for the day\n");
		printf("Choose your exercise!\n");
		scanf("%d", &choice);
		switch (choice) {
			case 1: // if option one is chose
			{
				printf("You go to the dojo and practice your Kung Fu!\n");
				calisthenics++; // adds one to calisthenics
				printf("You have done %d calisthenics and %d m distance in rope climbing.\n", calisthenics, climbDistance);
				break;				
			}

			case 2: // if option two is chose
			{
				printf("You go to the courtyard and practice your Bojustu!\n");
				calisthenics++; // adds one to calisthenics
				printf("You have done %d calisthenics and %d m distance in rope climbing.\n", calisthenics, climbDistance);
				break;
			}
 
			case 3: // if option three is chose
			{
				printf("You go to the rope climbing equipment inside the dojo.\n");
				printf("How much distance did you cover?\n");
				scanf("%d", &temp);
				climbDistance += temp; // adds rope climbing distance
				printf("You have done %d calisthenics and %d m distance in rope climbing.\n", calisthenics, climbDistance);
				break;
			}


		}
	}
	while (choice != 4); // if option four is chose
	printf("You have done %d calisthenics and %d m distance in rope climbing.\n", calisthenics, climbDistance);
	if (calisthenics > 0 && climbDistance > 0) { // if both are done

		printf("You are on the path to being a ninja!\n");
	}

	else { // if one or neither is done
		printf("You will need to train more if you want to be a ninja!\n");
	}
	return 0;
}