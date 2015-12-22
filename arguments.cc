#include <iostream>
using namespace std;
int getData();
int main() {
	ios::sync_with_stdio(false);
	int count = getData();
	cout << "Count: " << count;
}
int getData() {
	int count = 0;
	char Name[15], Wage[15], Hours[15];
	char response;
	while (true) {
		cout << "Enter y to continue and n to exit\n";
		cin >> response;
		if (response == 'y') {
			cout << "Enter Name\n";
			cin >> Name;
			cout << "Enter Wage\n";
			cin >> Wage;
			cout << "Enter Hours\n";
			cin >> Hours;
			count++;

			cout << "Name: " << Name << "\nWage: " << Wage << "\nHours: " << Hours << endl;
		}
		else
			break;

	}
	return count;
}