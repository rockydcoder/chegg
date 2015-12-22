#include <stdio.h>
#include <string.h>

#define OK       0
#define NO_INPUT 1
#define TOO_LONG 2

int ReadFile(char fileLocation[20], int timestamps[300], float powerConsumed[300]);
static int getLine (char *prmpt, char *buff, size_t sz);
main()
{
    int timestamps[300],  numberOfSensors, st, et, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, count, rc, i, minPowerConsumedSensorId = 0, maxPowerConsumedSensorId = 0, minPowerConsumedTimeStamp = 0, maxPowerConsumedTimeStamp = 0;
    float powerConsumed[300], sampleRate = 0, minPowerConsumed = 0, maxPowerConsumed = 0;
    char choice, fileLocation[20];

    do
    {
        printf("\n\n\t a). - Enter the number of sensors\n");
        printf("\t b). - Enter file location\n");
        printf("\t c). - Time interval st and et\n");
        printf("\t d). - Sample rate\n");
        printf("\t e). - Get statistical valuea\n");
        printf("\t f). - Exit\n");
        scanf("%c",&choice);
        switch (choice)
        {
            case 'a': 
            		printf("\n\n\t a). - Enter the number of sensors\n");
            		scanf("%d", &numberOfSensors);
            		flag1 = 1;
                    break;
            case 'b': 
            		printf("\t b). - Enter file location\n"); // Enter name of text file for simplicity. Assumed that text file is in the same folder as source file
            		rc = getLine ("Enter string> ", fileLocation, sizeof(fileLocation));
				    if (rc == NO_INPUT) {
				        // Extra NL since my system doesn't output that on EOF.
				        printf ("\nNo input\n");
				        return 1;
				    }

				    if (rc == TOO_LONG) {
				        printf ("Input too long [%s]\n", fileLocation);
				        return 1;
				    }
            		flag2 = 1;
            		count = ReadFile(fileLocation, timestamps, powerConsumed);
                    break;
            case 'c': 
            		printf("\t c). - Time interval st and et\n");
            		scanf("%d%d", &st, &et);
            		flag3 = 1;
                    break;
            case 'd': 
            		printf("\t d). - Sample rate\n");
            		scanf("%f", &sampleRate);
            		flag4 = 1;
                    break;
            case 'e':
            		if (flag1 == 0) {
            			printf("Number of sensors has not been defined\n");
            			break;
            		}
            		if (flag2 == 0) {
            			printf("File location has not been defined\n");
            			break;
            		}
            		if (flag3 == 0) {
            			printf("Time interval has not been defined\n");
            			break;
            		}
            		if (flag4 == 0) {
            			printf("Sample rate has not been defined\n");
            			break;
            		}
            		printf("\tSensor ID \tAverage \tMin \t Max \tTotal\n");
            		printf("/t--------- \t--------\t----\t----\t------\n");
            		for	(i = 0; i < count; i++) {
            			if (timestamps[i] <= et && timestamps[i] >= st) {
            				printf("\t%d \t\t\t %f\n", &i, &powerConsumed[i]);
            				if (powerConsumed[i] < minPowerConsumed) {
            					minPowerConsumed = powerConsumed[i];
            					minPowerConsumedSensorId = i;
            					minPowerConsumedTimeStamp = timestamps[i];
            				}
            				if (powerConsumed[i] > maxPowerConsumed) {
            					maxPowerConsumed = powerConsumed[i];
            					maxPowerConsumedSensorId = i;
            					maxPowerConsumedTimeStamp = timestamps[i];
            				}
            			}
            			else continue;
            		}
            		printf("\t-----------------------------------------------------------------\n");
            		printf("\t The power consumed was minimum at time %d reported by sensor %d, and maximum at time %d reported by sensor %d\n ", &minPowerConsumedTimeStamp, &minPowerConsumedSensorId, &maxPowerConsumedTimeStamp, &maxPowerConsumedSensorId );
            		break;
        }
    }
    while (choice != 'f');
}

int ReadFile(char fileLocation[20], int timestamps[300], float powerConsumed[300])
{
    FILE *inFile;
    int i, count=0;
    char temp[2];
    inFile=fopen(fileLocation,"r");
    if (inFile == NULL)
    {
        printf("File cannot be opened.");
        fclose(inFile);
        return -1;
    }
    while (fscanf(inFile, "%d%f%s", timestamps[count], powerConsumed[count], temp)!= EOF)
    {
    	count++;
    }
    fclose(inFile);
    return count;
}

static int getLine (char *prmpt, char *buff, size_t sz) {
    int ch, extra;

    // Get line with buffer overrun protection.
    if (prmpt != NULL) {
        printf ("%s", prmpt);
        fflush (stdout);
    }
    if (fgets (buff, sz, stdin) == NULL)
        return NO_INPUT;

    // If it was too long, there'll be no newline. In that case, we flush
    // to end of line so that excess doesn't affect the next call.
    if (buff[strlen(buff)-1] != '\n') {
        extra = 0;
        while (((ch = getchar()) != '\n') && (ch != EOF))
            extra = 1;
        return (extra == 1) ? TOO_LONG : OK;
    }

    // Otherwise remove newline and give string back to caller.
    buff[strlen(buff)-1] = '\0';
    return OK;
}