#include <iostream>
using namespace std;

double celsius_to_fahrenheit(double c) {
	return (c+32)*9/5;
}

double foot_to_meter(double f) {
	return f*0.3048;
}

double calculate_bmi_kg_m(double w, double m) {
	return w/(m*m);
}

double calculate_bmi_lb_in(double lb, double in) {
	return (lb/(in*in))*703;
}

double pound_to_kg(double pound) {
	return pound*0.453;
}

int main() {
	cout << celsius_to_fahrenheit(0) << endl;
	cout << foot_to_meter(1) << endl;
	cout << calculate_bmi_kg_m(1,1) << endl;
	cout << calculate_bmi_lb_in(1, 1) << endl;
	cout << pound_to_kg(1) << endl;
}