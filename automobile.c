#include <stdio.h>
#include <string.h>
#define BUFSIZE 1000
struct auto_t scan_auto(char *);
void scan_date(char *, struct auto_t *);
struct date_t {
	char day[2];
	char month[2];
	char year[4];
};

struct tank_t {
	char tankCapacity[10];
	char currentFuelLevel[10];
};

struct auto_t {
	char make[50];
	char model[50];
	char odometerReading[10];
	struct date_t manufactureDate;
	struct date_t purchaseDate;
	struct tank_t gasTank;
};

int main(int argc, char *argv[]) {
    /* the first command-line parameter is in argv[1] 
       (arg[0] is the name of the program) */
    FILE *fp = fopen(argv[1], "r"); /* "r" = open for reading */

    char buff[BUFSIZE]; /* a buffer to hold what you read in */
    struct auto_t newAuto;

    /* read in one line, up to BUFSIZE-1 in length */
    while(fgets(buff, BUFSIZE - 1, fp) != NULL) 
    {
        /* buff has one line of the file, do with it what you will... */
    	newAuto = scan_auto(buff);
    	printf("%s\n", newAuto.make);
    	printf("%s\n", newAuto.model);
    	printf("%s\n", newAuto.odometerReading);
        
    }
    fclose(fp);  /* close the file */ 
}

struct auto_t scan_auto(char *line) {
	int spacesCount = 0;
	int i, endOfMake, endOfModel, endOfOdometer;
	char newLine[1000];
	for (i = 0; i < sizeof(line); i++) {
		if (line[i] == ' ') {
			spacesCount++;
			if (spacesCount == 1) {
				endOfMake = i;
			}
			else if (spacesCount == 2) {
				endOfModel = i;
			}
			else if (spacesCount == 3) {
				endOfOdometer = i;
			}
		}

	}
	struct auto_t newAuto;
	int count = 0;
	for (i = 0; i < endOfMake; i++) {
		newAuto.make[count++] = line[i];
	}
	newAuto.make[count] = '\0';
	count = 0;
	for (i = endOfMake+1; i < endOfModel; i++) {
		newAuto.model[count++] = line[i];
	}
	newAuto.model[count] = '\0';
	count = 0;
	for (i = endOfModel+1; i < endOfOdometer; i++) {
		newAuto.odometerReading[count++] = line[i];
	}
	newAuto.odometerReading[count] = '\0';
	count = 0;
	for (i = endOfOdometer+1; i < sizeof(line); i++) {
		newLine[count++] = line[i];
	}
	newLine[count] = '\0';
	scan_date(newLine, &newAuto);
	return newAuto;

}

void scan_date(char *line, struct auto_t *newAuto) {
	int i, endOfMDay, endOfMMonth, endOfMYear, endOfPDay, endOfPMonth, endOfPYear, spacesCount = 0;
	for (i = 0; i < sizeof(line); i++) {
		if (line[i] == ' ') {
			spacesCount++;
			switch(spacesCount) {
				case 1:
					endOfMDay = i;
					break;
				case 2:
					endOfMMonth = i;
					break;
				case 3:
					endOfMYear = i;
					break;
				case 4:
					endOfPDay = i;
					break;
				case 5:
					endOfPMonth = i;
					break;
				case 6:
					endOfMYear = i;
					break;

			}
		}
	}
}

