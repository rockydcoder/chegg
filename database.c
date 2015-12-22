#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct EMPLOYEE {
	char first[7];
	char initial [1];
	char last[9];
	char street [16];
	char city[11];
	char state[2];
	char zip[5];
	int age;
	char sex[1];
	int tenure;
	double salary;
};
void strsub(char buf[], char sub[], int start, int end);
int main(int argc, char const *argv[])
{
	FILE *fp = fopen("payfile.txt", "r"); /* "r" = open for reading */
	struct EMPLOYEE workers[MAX];
	int i = 0, j, k, index, counter1, counter2;
	double max = 0, min = 500, sumOfSalaries = 0, avgSalary = 0;
	char buf[MAX];
	char cAge[2];
	char cTenure[1];
	char cSalary[6];
	while (!feof(fp)) {
		fgets(buf, MAX, fp);
		strsub(buf, workers[i].first, 0, 6);
		strsub(buf, workers[i].initial, 8, 8);
		strsub(buf, workers[i].last, 10, 18);
		strsub(buf, workers[i].street, 20, 35);
		strsub(buf, workers[i].city, 37, 47);
		strsub(buf, workers[i].state, 49, 50);
		strsub(buf, workers[i].zip, 52, 56);
		strsub(buf, cAge, 58, 59);
		strsub(buf, workers[i].sex, 61,61);
		strsub(buf, cTenure, 63, 63);
		strsub(buf, cSalary, 65, 70);
		workers[i].age = atoi(cAge);
		workers[i].tenure = atoi(cTenure);
		workers[i].salary = atof(cSalary);
		i++;
	}

	fclose(fp); /* close the file */

	printf("***ALL INFORMATION OF WORKERS***\n");
	for (j = 0; j < i; j++) {
		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%s\t%d\t%f\n", workers[j].first, workers[j].initial, workers[j].last, 
			workers[j].street, workers[j].city, workers[j].state, workers[j].zip, workers[j].age, workers[j].sex, 
			workers[j].tenure, workers[j].salary);
		sumOfSalaries += workers[j].salary;
	}
	avgSalary = sumOfSalaries/i;
	printf("********************************\n");

	printf("***First and Last Name***\n");
	for (j = 0; j < i; j++) {
		printf("%s\t%s\n", workers[j].first, workers[j].last);
	}
	printf("********************************\n");

	printf("***First and Last Name of highest paid woman***\n");
	for (j = 0; j < i; j++) {
		if (workers[j].sex == 'F') {
			if (workers[j].salary > max) {
				max = workers[j].salary;
				index = j;
			}
		}
	}
	printf("%s\t%s\n", workers[index].first, workers[index].last);
	printf("********************************\n");

	printf("***First and Last Name of lowest paid man***\n");
	for (j = 0; j < i; j++) {
		if (workers[j].sex == 'M') {
			if (workers[j].salary < min) {
				min = workers[j].salary;
				index = j;
			}
		}
	}
	printf("%s\t%s\n", workers[index].first, workers[index].last);
	printf("********************************\n");

	printf("***Average Salary***\n");
	printf("%f\n", avgSalary);
	printf("********************************\n");

	printf("***First and Last Name of all women earning less than the average salary***\n");
	for (j = 0; j < i; j++) {
		if (workers[j].sex == 'F') {
			if (workers[j].salary < avgSalary) {
				printf("%s\t%s\n", workers[j].first, workers[j].last);
			}
		}
	}
	printf("********************************\n");

	printf("***Ratio of number of men earning more than average salary to number of men earning less than average salary***\n");
	for (j = 0; j < i; j++) {
		if (workers[j].sex == 'M') {
			if (workers[j].salary > avgSalary) {
				counter1++;
			}
			else {
				counter2++;
			}
		}
	}
	printf("%d:%d\n", counter1, counter2);
	printf("********************************\n");

	printf("***First and Last Name of all employees who earn more than $35000 per year, have been with the company for at least 5 years and are more than 30 years old***\n");
	for (j = 0; j < i; j++) {
		if (workers[j].salary*52 > 35000 && workers[j].age > 30 && workers[j].tenure >= 5) {
			printf("%s\t%s\n", workers[j].first, workers[j].last);
		}
	}
	printf("********************************\n");

	printf("***First and Last Name of all employees who received the raise***\n");
	for (j = 0; j < i; j++) {
		if (workers[j].salary < 350) {
			workers[j].salary *= 1.1;
			printf("%s\t%s\t%f\n", workers[j].first, workers[j].last, workers[j].salary);
		}
	}
	printf("********************************\n");

	struct EMPLOYEE temp;
	for (j = 0; j < i; j++) {
		for (k = 0; k < i-1; k++) {
			if (strcmp(workers[k].zip, workers[k+1].zip) > 0) {
				temp = workers[k];
				workers[k] = workers[k+1];
				workers[k+1] = temp;
			}
		}
	}
	printf("***First and Last Name of employees sorted according to zip***\n");
	for (j = 0; j < i; j++) {
		printf("%s\t%s\t%s\n", workers[j].first, workers[j].last, workers[j].zip);
	}

	return 0;
}

void strsub(char buf[], char sub[], int start, int end) {
    int i, j;

    for (j = 0, i = start; i <= end; i++, j++) {
    	sub[j] = buf[i];
    }
    sub[j] = '\0';
}