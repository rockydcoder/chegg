#include <iostream>
using namespace std;
void longDivision(int dividend, int divisor, int number_of_decimal_places);
int main() {
	longDivision(100, 3, 20);

}

void longDivision(int dividend, int divisor, int number_of_decimal_places) {
	if (number_of_decimal_places == 0)
		return;
	int q = dividend / divisor;
	cout << q;
	dividend = dividend - divisor*q;
	dividend*=10;
	longDivision(dividend, divisor, --number_of_decimal_places);
}
