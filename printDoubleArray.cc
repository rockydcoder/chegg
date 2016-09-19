#include <iostream>
using namespace std;

int main() {
	double myArr[] = {3.0, 4.5, 5.8, 9.5, 3.1, 10.0, 7.8, 9.9, 2.1, 4.4};
	double *ptr = myArr;
	for (int i = 0; i < 10; i++)
		cout << ptr[i] << endl;

}