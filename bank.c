#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct CUSTOMER {
	int Account;
	double Balance;
	char Name[20];
};
int main(int argc, char const *argv[])
{
	struct CUSTOMER customers[MAX];
	int choice, i, numberOfAccounts = 0;
	do {
		printf("1-Display all customers\n");
		printf("2-Display customer w/ balance greater than a value\n");
		printf("3-Search\n");
		printf("4-Sort\n");
		printf("5-Delete an account\n");
		printf("6-Add a new account\n");
		printf("7-Exit\n");
		printf("Your option here: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
			{
				printf("1-Display all customers\n");
				for (i = 0; i < numberOfAccounts; i++) {
					printf("%d\t%f\t%s\n", customers[i].Account, customers[i].Balance, customers[i].Name);
				}
				break;
			}
			case 2:
			{
				printf("2-Display customer w/ balance greater than a value\n");
				printf("Enter the threshold value: ");
				double thresholdBalance;
				scanf("%lf", &thresholdBalance);
				for (i = 0; i < numberOfAccounts; i++) {
					if (customers[i].Balance > thresholdBalance)
						printf("%d\t%f\t%s\n", customers[i].Account, customers[i].Balance, customers[i].Name);
				}
				break;
			}
			case 3:
			{
				printf("3-Search\n");
				int accountSearch;
				int flag = 0;
				printf("Enter the account # to search: ");
				scanf("%d", &accountSearch);
				for (i = 0; i < numberOfAccounts; i++) {
					if (customers[i].Account == accountSearch) {
						flag = 1;
						printf("%d\t%f\t%s\n", customers[i].Account, customers[i].Balance, customers[i].Name);
						break;
					}
				}
				if (!flag)
					printf("No such account found\n");
				break;
			}
			case 4:
			{
				printf("4-Sort\n");
				printf("a-sort by name\n");
				printf("b-sort by account number\n");
				printf("c-sort by balance\n");
				printf("x-return main menu\n");
				char c;
				printf("Your option here: ");
				scanf("%c", &c);
				switch (c) {
					case 'a':
					break;
					case 'b':
					break;
					case 'c':
					break;
				}
				break;
			}
			case 5:
			{
				printf("5-Delete an account\n");
				int accountSearch, flag = 0;
				printf("Enter the account # to delete: ");
				scanf("%d", &accountSearch);
				for (i = 0; i < numberOfAccounts; i++) {
					if (customers[i].Account == accountSearch) {
						flag = 1;
						int j;
						for (j = i; j < numberOfAccounts-1; j++) {
							customers[j] = customers[j+1];
						}
						numberOfAccounts--;
						break;
					}
				}
				if (!flag)
					printf("No such account found\n");
				break;
			}
			case 6:
			{
				printf("6-Add a new account\n");
				if (numberOfAccounts < 100) {
					struct CUSTOMER newCustomer;
					printf("Enter account # of new customer: ");
					scanf("%d", &newCustomer.Account);
					printf("Enter ac balance of new customer: ");
					scanf("%lf *[^\n]", &newCustomer.Balance);
					printf("Enter name of new customer: ");
					fgets(newCustomer.Name, sizeof(newCustomer.Name), stdin);
					customers[numberOfAccounts++] = newCustomer;
					printf("Customer added to database\n");
				}
				else {
					printf("Max limit of database reached\n");
				}

			}




		}
	} while (choice != 7);
	return 0;
}