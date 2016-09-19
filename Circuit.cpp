#include<iostream>
using namespace std;

class Circuit {
public:
	Circuit(const double, const double, const double);
	virtual double getCurrent() = 0;
	virtual void printAttributes() = 0;
	virtual void computeEfficiency() = 0;
private:
	double resistance;
	double inputVoltage;
	double current;
};

Circuit::Circuit(const double r, const double i, const double c) {
	resistance = r;
	inputVoltage = i;
	current = c;
}

double Circuit::getCurrent() {
	current = inputVoltage/resistance;
	return current;
}

void Circuit::printAttributes() {
	cout << "Resistance = " << resistance << endl;
	cout << "Input voltage = " << inputVoltage << endl;
	cout << "Current = " << current << endl;
}

class Amplifier:public Circuit {
private:
	double gain;
public:
	Amplifier(const double r, const double i, const double c, const double g) {
		resistance = r;
		inputVoltage = i;
		current = c;
		gain = g;
	}

	double getOutputVoltage() {
		return inputVoltage * gain;
	}

	double getGain() {
		return gain;
	}

	void computeEfficiency() {
		double inputPower = inputVoltage * current;
		double outputPower = getOutputVoltage() * current;
		double efficiency = 100*outputPower / inputPower;
	}

};

int main() {
	Amplifier amplifier = Amplifier(10, 10, 5, 2);
	amplifier.getOutputVoltage();
	amplifier.getGain();
	amplifier.computeEfficiency();
}
