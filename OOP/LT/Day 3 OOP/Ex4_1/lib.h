#include <iostream>

using namespace std;

class Fraction {
private:
	int num;
	int denom;

	void simplify();
public:
	Fraction();
	Fraction(int num);
	Fraction(int num, int denom);

	// Operator
	Fraction operator+(const Fraction& Frac) const;
	Fraction operator-(const Fraction& Frac) const;
	Fraction operator*(const Fraction& Frac) const;
	Fraction operator/(const Fraction& Frac) const;

	// Comparison operators
	bool operator<(const Fraction& Frac) const;
	bool operator>(const Fraction& Frac) const;
	bool operator==(const Fraction& Frac) const;
	bool operator>=(const Fraction& Frac) const;
	bool operator<=(const Fraction& Frac) const;
	bool operator!=(const Fraction& Frac) const;

	// Assignment operators
	Fraction& operator=(const Fraction& Frac);
	Fraction& operator+=(const Fraction& Frac);
	Fraction& operator*=(const Fraction& Frac);

	// Increment and Decrement
	Fraction& operator++();
	Fraction& operator--();
	Fraction operator++(int);
	Fraction operator--(int);

	// Type conversion
	operator int() const;
	operator float() const;

	// Stream operators
	friend ostream& operator<<(ostream& os, const Fraction& f);
	friend istream& operator>>(istream& is, Fraction& f);
};