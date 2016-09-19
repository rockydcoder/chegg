#include "Circuit.cpp"
#include <iostream>
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
}