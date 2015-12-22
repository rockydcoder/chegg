#include <iostream>
#include <random>
using namespace std;
struct Customer
{
	int customerId;
	char firstInitial;
	char lastInitial;
	char state;
	int zip;
	
};
int main() {
	ios::sync_with_stdio(false);
	int N, stateCode, countTexasCustomers = 0, countOklahomacustomers = 0;
	bool flag = true;
	while (flag) {
		cout << "Enter number of customers. (Must be an integer between 10 and 1000" << endl;
		cin >> N;
		if (N >= 10 && N <= 1000)
			flag = false;
		else
			cout << "Number of customers is out of range" << endl;

	}
	Customer **main ;
	main = new Customer *[N];
	random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator
    uniform_int_distribution<> generateId(5000, 10000); // define the range for customer id
    uniform_int_distribution<> generateFirstInitial(1, 26); // define the range for first initial name
    uniform_int_distribution<> generateLastInitial(1, 26); // define the range for last initial name
    uniform_int_distribution<> generateState(1, 2); // define the range for state
    uniform_int_distribution<> generateTZip(70000, 74999); // define the range for texas zip
    uniform_int_distribution<> generateOZip(75000, 79999); // define the range for oklahoma zip


    for(int i = 0; i < N; ++i) {
    	main[i] = new Customer;
    	main[i]->customerId = generateId(eng);
    	main[i]->firstInitial = generateFirstInitial(eng) + 64;
    	main[i]->lastInitial = generateLastInitial(eng) + 64;
    	stateCode = generateState(eng);
    	if (stateCode == 1) {
    		countTexasCustomers++;
    		main[i]->state = 'T';
    		main[i]->zip = generateTZip(eng);
    	}
    	else if (stateCode == 2) {
    		countOklahomacustomers++;
    		main[i]->state = 'O';
    		main[i]->zip = generateOZip(eng);
    	}
    }
    Customer **texas, **oklahoma;
    texas = new Customer *[countTexasCustomers];
    oklahoma = new Customer *[countOklahomacustomers];

    int countT = 0, countO = 0;
    for (int i = 0; i < N; i++) {
    	if (main[i]->state == 'T') {
    		texas[countT] = new Customer;
    		texas[countT++] = main[i];
    	}
    	else if (main[i]->state == 'O') {
    		oklahoma[countO] = new Customer;
    		oklahoma[countO++] = main[i];
    	}
    }

    cout << "Information of Texas customers" << endl;
    for (int i = 0; i < countTexasCustomers; i++) {
    	cout << texas[i]->customerId << "\t" << texas[i]->firstInitial << "\t" << texas[i]->lastInitial << "\t" << texas[i]->state << "\t" << texas[i]->zip << endl;
    }

    cout << "Information of Oklahoma customers" << endl;
    for (int i = 0; i < countOklahomacustomers; i++) {
    	cout << oklahoma[i]->customerId << "\t" << oklahoma[i]->firstInitial << "\t" << oklahoma[i]->lastInitial << "\t" << oklahoma[i]->state << "\t" << oklahoma[i]->zip << endl;
    }
        
}