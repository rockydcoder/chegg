/*
 * Fraction.cpp
 *
 *  Created on: Feb 7, 2015
 *      Author: Rakesh Sarangi
 */

#include "Fraction.h"
#include<iostream>
#include<cmath>
using namespace std;


Fraction::Fraction(int p, int q) {
	// TODO Auto-generated constructor stub
	this->iNumerator_ = p;
	this->uiDenominator_ = q;
	Normalize();
}

Fraction::Fraction(double d) {
	double integer = (int) d;
	double decimal = d - integer;
	Fraction Frac1 = Fraction(integer,1);
	Fraction Frac2 = Fraction((int) decimal*Fraction::precision(), Fraction::precision());
	Fraction sum = Frac1 + Frac2;
	this->iNumerator_ = sum.iNumerator_;
	this->uiDenominator_ = sum.uiDenominator_;
	Normalize();
}

// DESTRUCTOR
Fraction::~Fraction() {
}

// Copy Constructor
Fraction::Fraction(const Fraction& Frac) {
	this->iNumerator_ = Frac.iNumerator_;
	this->uiDenominator_ = Frac.uiDenominator_;
}

// BASIC ASSIGNMENT OPERATOR
Fraction& Fraction::operator=(const Fraction& Frac) {
	this->iNumerator_ = Frac.iNumerator_;
	this->uiDenominator_ = Frac.uiDenominator_;
	return (*this);
}

// UNARY ARITHMETIC OPERATORS

// Pre-decrement. Dividendo. p/q <-- p/q - 1
Fraction& Fraction::operator--() {
	this->iNumerator_ -= this->uiDenominator_;
	return *this;
}

// Pre-increment. Componendo. p/q <-- p/q + 1
Fraction& Fraction::operator++() {
	this->iNumerator_ += this->uiDenominator_;
	return *this;
}

// Operand 'this' implicit
Fraction Fraction::operator-() {
	Fraction Frac;
	Frac.iNumerator_ = this->iNumerator_*(-1);
	Frac.uiDenominator_ = this->uiDenominator_;
	return Frac;
}

Fraction Fraction::operator+() {
	Fraction Frac;
	Frac.iNumerator_ = this->iNumerator_*1;
	Frac.uiDenominator_ = this->uiDenominator_;
	return Frac;
}

// Post-decrement. Lazy Dividendo. p/q <-- p/q - 1. Returns old p/q
Fraction Fraction::operator--(int i) {
	Fraction Frac(*this);
	this->iNumerator_ = this->iNumerator_ - this->uiDenominator_;
	return Frac;
}

// Post-increment. Lazy Componendo. p/q <-- p/q + 1. Returns old p/q
Fraction Fraction::operator++(int i) {
	Fraction Frac(*this);
	this->iNumerator_ = this->iNumerator_ + this->uiDenominator_;
	return Frac;
}

// BINARY ARITHMETIC OPERATORS USING FRIEND FUNCTIONS
Fraction operator+(const Fraction& Frac1, const Fraction& Frac2) {
	int lcm_denominator = Fraction::lcm(Frac1.uiDenominator_, Frac2.uiDenominator_);
	Fraction Frac;
	Frac.uiDenominator_ = lcm_denominator;
	Frac.iNumerator_ = Frac1.iNumerator_*(lcm_denominator/Frac1.uiDenominator_) + Frac2.iNumerator_*(lcm_denominator/Frac2.uiDenominator_);

	int gcd_frac = Fraction::gcd(Frac.iNumerator_, Frac.uiDenominator_);
	if(gcd_frac == 1)
		return Frac;

	else
	{
		Frac.iNumerator_ /= gcd_frac;
		Frac.uiDenominator_ /= gcd_frac;
		return Frac;
	}

}

Fraction operator-(const Fraction& Frac1, const Fraction& Frac2) {
	int lcm_denominator = Fraction::lcm(Frac1.uiDenominator_, Frac2.uiDenominator_);
		Fraction Frac;
		Frac.uiDenominator_ = lcm_denominator;
		Frac.iNumerator_ = Frac1.iNumerator_*(lcm_denominator/Frac1.uiDenominator_) - Frac2.iNumerator_*(lcm_denominator/Frac2.uiDenominator_);

		if(Frac.iNumerator_ == 0)
			return Frac;

		int gcd_frac = Fraction::gcd(abs(Frac.iNumerator_), Frac.uiDenominator_);
		if(gcd_frac == 1)
			return Frac;

		else
		{
			Frac.iNumerator_ /= gcd_frac;
			Frac.uiDenominator_ /= gcd_frac;
			return Frac;
		}
}

Fraction operator*(const Fraction& Frac1, const Fraction& Frac2) {
	Fraction Frac;
	Frac.iNumerator_ = Frac1.iNumerator_ * Frac2.iNumerator_;
	Frac.uiDenominator_ = Frac1.uiDenominator_ * Frac2.uiDenominator_;
	int gcd_frac = Fraction::gcd(Frac.iNumerator_, Frac.uiDenominator_);
	if(gcd_frac == 1)
		return Frac;

	else
	{
		Frac.iNumerator_ /= gcd_frac;
		Frac.uiDenominator_ /= gcd_frac;
		return Frac;
	}

}

Fraction operator/(const Fraction& Frac1, const Fraction& Frac2) {
	Fraction Frac;
	Frac.iNumerator_ = Frac1.iNumerator_ * Frac2.uiDenominator_;
	Frac.uiDenominator_ = Frac1.uiDenominator_ * Frac2.iNumerator_;
	int gcd_frac = Fraction::gcd(Frac.iNumerator_, Frac.uiDenominator_);
	if(gcd_frac == 1)
		return Frac;

	else
	{
		Frac.iNumerator_ /= gcd_frac;
		Frac.uiDenominator_ /= gcd_frac;
		return Frac;
	}
}

Fraction operator%(const Fraction& Frac1, const Fraction& Frac2) {
	Fraction Frac;
	Frac.iNumerator_ = Frac2.iNumerator_;
	Frac.uiDenominator_ = Frac2.uiDenominator_;
	while(Frac < Frac1) {
		Frac = Frac + Frac2;

	}

	return (Frac2 + Frac1 - Frac);
}

bool Fraction::operator==(const Fraction& Frac) {
	return((this->iNumerator_ == Frac.iNumerator_) && (this->uiDenominator_ == Frac.uiDenominator_));
}

bool Fraction::operator!=(const Fraction& Frac) {
	return ((this->iNumerator_ != Frac.iNumerator_) || (this->uiDenominator_ != Frac.uiDenominator_));
}

bool Fraction::operator<(const Fraction& Frac) {
	int lcm_denominator = Fraction::lcm(this->uiDenominator_, Frac.uiDenominator_);
	return ((this->iNumerator_*(lcm_denominator/this->uiDenominator_)) < (Frac.iNumerator_*(lcm_denominator/Frac.uiDenominator_)));
}

bool Fraction::operator<=(const Fraction& Frac) {
	int lcm_denominator = Fraction::lcm(this->uiDenominator_, Frac.uiDenominator_);
	return ((this->iNumerator_*(lcm_denominator/this->uiDenominator_)) <= (Frac.iNumerator_*(lcm_denominator/Frac.uiDenominator_)));
}

bool Fraction::operator>(const Fraction& Frac) {
	int lcm_denominator = Fraction::lcm(this->uiDenominator_, Frac.uiDenominator_);
	return ((this->iNumerator_*(lcm_denominator/this->uiDenominator_)) > (Frac.iNumerator_*(lcm_denominator/Frac.uiDenominator_)));
}

bool Fraction::operator>=(const Fraction& Frac) {
	int lcm_denominator = Fraction::lcm(this->uiDenominator_, Frac.uiDenominator_);
	return ((this->iNumerator_*(lcm_denominator/this->uiDenominator_)) >= (Frac.iNumerator_*(lcm_denominator/Frac.uiDenominator_)));
}

// ADVANCED ASSIGNEMENT OPERATORS
Fraction& Fraction::operator+=(const Fraction& Frac) {
	*this = *this + Frac;
	return (*this);
}

Fraction& Fraction::operator-=(const Fraction& Frac) {
	*this = *this - Frac;
	return (*this);
}

Fraction& Fraction::operator*=(const Fraction& Frac) {
	*this = *this * Frac;
	return (*this);
}

Fraction& Fraction::operator/=(const Fraction& Frac) {
	*this = *this / Frac;
	return (*this);
}

Fraction& Fraction::operator%=(const Fraction& Frac) {
	*this = *this % Frac;
	return (*this);
}

// SPECIAL OPERATORS
Fraction Fraction::operator!() {
	Fraction Frac;
	Frac.iNumerator_ = this->uiDenominator_;
	Frac.uiDenominator_ = this->iNumerator_;

	return Frac;
}

// BASIC I/O using FRIEND FUNCTIONS
ostream& operator<<(ostream& out, const Fraction& Frac) {
	out << Frac.iNumerator_ << "/" << Frac.uiDenominator_;
	return out;
}

istream& operator>>(istream& in, Fraction& Frac) {
	in >> Frac.iNumerator_ >> Frac.uiDenominator_;
	return in;
}

// CONSTANTS OF DATATYPE
const Fraction Fraction::sc_fUnity = Fraction(1,1);


const Fraction Fraction::sc_fZero = Fraction(0,1);


// STATIC UTILITY FUNCTIONS

int Fraction::gcd(int a, int b) {
	int c;

	if(a == 0 || b == 0)
		return 0;

	else if(a < 0 || b < 0)
		return -1;

	do
	{
		c = a % b;
		if(c == 0)
			return b;

		a = b;
		b = c;

	}
	while(true);
}

int Fraction::lcm(int a, int b) {
	int gcd = Fraction::gcd(a, b);
	return (a*b/gcd);
}

Fraction& Fraction::Normalize() {

	if (this->iNumerator_ == 0)
		return (*this);
	int gcd_frac = Fraction::gcd(abs(this->iNumerator_), this->uiDenominator_);
	if(gcd_frac == 1)
		return (*this);

	else
	{
		this->iNumerator_ /= gcd_frac;
		this->uiDenominator_ /= gcd_frac;
		return (*this);
	}
}

/*int main() {

	int i, j;
	char c;
	Fraction f1, f2, result;

	cout << "\t+++ Rational number Calculator\n" << endl;
	cout << "Enter 1st fraction - A" << endl;
	cout << "enter p then q: ";
	cin >> f1;
	cout << "Enter 2nd fraction - B" << endl;
	cout << "enter p then q: ";
	cin >> f2;

	while(1) {
		cout << "What do you want to do with these numbers?\n"
		     << "1. Re-enter these numbers\n"
		     << "2. Perform arithmetic operations\n"
		     << "3. Special operators\n"
		     << "4. exit\n"
		     << "Your response: ";
		cin >> i;

	switch(i) {


	case 1: {
	    cout << "Which rational number do you want to change.\n Enter 1 for A, 2 for B\nYour response: ";
	    cin >> j;
	    if(j == 1) {cout << "Enter A: "; cin >> f1;}
	    if(j == 2) {cout << "Enter B: "; cin >> f2;}
	    break;
	}

	case 2: {
	    cout << "Which operator will you perform on these two complexes? (+, -, *, /)" << endl;
	    cin >> c;
	    if(c == '+') cout << "The answer is " << f1 + f2 << "\n\n";
	    else if(c == '-') cout << "The answer is " << f1 - f2 << "\n\n";
	    else if(c == '*') cout << "The answer is " << f1 * f2 << "\n\n";
	    else if(c == '/') cout << "The answer is " << f1 / f2 << "\n\n";
	    else cout << "Wrong operator entered. Please try again\n\n";
	    break;

	}

	case 3: {
	    cout << "1. Check equality\n2. Give Invert\nYour response: ";
	    cin >> j;
	    if(j == 1) {
		if(f1 == f2) cout << "The complex numbers are equal\n" << endl;
		else if(f1 != f2) cout << "The complex numbers are not equal\n" << endl;
	    }
	    else if(j == 2) cout << "\nThe invert of " << f1 << " is " << !f1 << "\nThe invert of " << f2 << " is " << !f2 << "\n\n";
	    else cout << "Wrong number entered. Please try again\n\n";
	    break;
	}

	case 4: {
	    return 0;
	    break;
	}

	default: {
	    cout << "Wrong value entered. Please try again\n" << endl;
	    break;
	}
	}
	}


		return 0;

}

*/






