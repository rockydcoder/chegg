#include <iostream>
#include <cmath>
using namespace std;

bool double_is_int(double x) {
	double intpart;
	return modf(x, &intpart) == 0.0;
}

bool is_even(int x) {
	return x % 2 == 0;
}

int main() {
	ios::sync_with_stdio(false);
	cout << "Enter two numbers" << endl;
	double a, b;
	cin >> a >> b;
	if (double_is_int(a)) {

		cout << "First value is an integer" << endl;
		if (is_even(a))
			cout << "First value is even" << endl;
		else
			cout << "First value is odd" << endl;
	}
	else
		cout << "First value is a floating point" << endl;

	if (double_is_int(b)) {
		cout << "Second value is an integer" << endl;
		if (is_even(b))
			cout << "Second value is even" << endl;
		else
			cout << "Second value is odd" << endl;
	}
	else
		cout << "Second value is a floating point" << endl;

	if (double_is_int(a) && double_is_int(b)) {
		cout << "Integer Division Result is: " << ((int) a / (int) b) << " with remaindar: " << ((int) a% (int) b) << endl;
	}

	else {
		cout << "Floating division result is: " << a/b << endl;
	}

}