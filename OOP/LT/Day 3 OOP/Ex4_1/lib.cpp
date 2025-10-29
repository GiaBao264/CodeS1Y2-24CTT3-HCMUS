#include "lib.h"

// Simplify Fraction
void Fraction::simplify() {
	int a = num;
	int b = denom;
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	num /= a;
	denom /= a;
	if (denom < 0) {
		num = -num;
		denom = -denom;
	}
}

// Constructors
Fraction::Fraction() : num(0), denom(1) {}
Fraction::Fraction(int num) : num(num), denom(1) {}

Fraction::Fraction(int num, int denom) : num(num), denom(denom) {
	simplify();
}

// Operator
Fraction Fraction::operator+(const Fraction& Frac) const {
	return Fraction(num * Frac.denom + Frac.num * denom, denom * Frac.denom);
}

Fraction Fraction::operator-(const Fraction& Frac) const {
	return Fraction(num * Frac.denom - Frac.num * denom, denom * Frac.denom);
}

Fraction Fraction::operator*(const Fraction& Frac) const {
	return Fraction(num * Frac.num, denom * Frac.denom);
}

Fraction Fraction::operator/(const Fraction& Frac) const {
	return Fraction(num * Frac.denom, denom * Frac.num);
}

// Comparison operators
bool Fraction::operator<(const Fraction& Frac) const {
	return num * Frac.denom < Frac.num * denom;
}

bool Fraction::operator>(const Fraction& Frac) const {
	return num * Frac.denom > Frac.num * denom;
}

bool Fraction::operator==(const Fraction& Frac) const {
	return num == Frac.num && denom == Frac.denom;
}

bool Fraction::operator>=(const Fraction& Frac) const {
	return !(*this < Frac);
}

bool Fraction::operator<=(const Fraction& Frac) const {
	return !(*this > Frac);
}

bool Fraction::operator!=(const Fraction& Frac) const {
	return !(*this == Frac);
}

// Assignment operators
Fraction& Fraction::operator=(const Fraction& Frac) {
	num = Frac.num;
	denom = Frac.denom;
	simplify();
	return *this;
}

Fraction& Fraction::operator+=(const Fraction& Frac) {
	num = num * Frac.denom + Frac.num * denom;
	denom = denom * Frac.denom;
	simplify();
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& Frac) {
	num *= Frac.num;
	denom *= Frac.denom;
	simplify();
	return *this;
}

// Increment and Decrement
Fraction& Fraction::operator++() {
	num += denom;
	return *this;
}

Fraction& Fraction::operator--() {
	num -= denom;
	return *this;
}

Fraction Fraction::operator++(int) {
	Fraction temp = *this;
	num += denom;
	return temp;
}

Fraction Fraction::operator--(int) {
	Fraction temp = *this;
	num -= denom;
	return temp;
}

// Type conversion
Fraction::operator int() const {
	return num / denom;
}

Fraction::operator float() const {
	return static_cast<float>(num) / denom;
}

// Stream operators
ostream& operator<<(ostream& os, const Fraction& f) {
	os << f.num << "/" << f.denom;
	return os;
}

istream& operator>>(istream& is, Fraction& f) {
	char slash;
	is >> f.num >> slash >> f.denom;
	f.simplify();
	return is;
}