#include <stdio.h>
#include <stdlib.h>
double array[1000];
int counter = 0;
void readFile();
void performance(int counter);
int main(int argc, char const *argv[])
{
	readFile();
	performance(counter);
	return 0;
}

void readFile() {
	FILE *fp = fopen("data.txt", "r");
	int i = 0, retval;

	if(fp == NULL) {
	    printf("Error in opening file\n");
	}

	while(i < 1000 && (retval = fscanf(fp, "%lf", &array[i++])) == 1) {
		counter++;
	} 

	if(i == 1000) {
	    printf("Cannot take in more processors\n");
	}

	if(retval == 0) {
	   	printf("Read value not an integer. matching failure\n");
	}

	if(retval == EOF) {
	    // end of file reached or a read error occurred
	    if(ferror(fp)) {
	        // read error occurred in the stream fp
	        // clear it
	        clearerr(fp);
	    }
	}

	// after being done with fp
	fclose(fp);
}

void performance(int counter) {
	int i;
	double executionTime;
	for (i = 0; i < counter; i+=3) {
		executionTime = array[i]*array[i+1]*array[i+2];
		printf("Execution time = %lf\n", executionTime);
	}

}

