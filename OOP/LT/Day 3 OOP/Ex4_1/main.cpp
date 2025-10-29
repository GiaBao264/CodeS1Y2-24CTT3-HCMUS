#include "lib.h"

int main() {
	//Fraction
	Fraction f1(3, 4);
	Fraction f2(2, 5);
	Fraction f3;

	cout << "f1 = " << f1 << endl;
	cout << "f2 = " << f2 << endl;
	cout << endl;

	//Operator
	Fraction f4 = f1 + f2;
	cout << "f1 + f2 = " << f4 << endl;
	Fraction f5 = f1 - f2;
	cout << "f1 - f2 = " << f5 << endl;
	Fraction f6 = f1 * f2;
	cout << "f1 * f2 = " << f6 << endl;
	Fraction f7 = f1 / f2;
	cout << "f1 / f2 = " << f7 << endl;
	cout << endl;

	// Comparison operators
	cout << f1 << ((f1 > f2) ? " > " : " < ") << f2 << endl;
	cout << f1 << ((f1 >= f2) ? " >= " : " < ") << f2 << endl;
	cout << f1 << ((f1 == f2) ? " == " : " != ") << f2 << endl;
	/*cout << f1 << ((f1 < f2) ? " < " : " > ") << f2 << endl;
	cout << f1 << ((f1 <= f2) ? " <= " : " > ") << f2 << endl;
	cout << f1 << ((f1 != f2) ? " != " : " == ") << f2 << endl;*/
	cout << endl;

	// Assignment operators
	f3 = f1;
	cout << "f3 = f1 -> f3 = " << f3 << endl;
	f3 += f2;
	cout << "f3 += f2 -> f3 = " << f3 << endl;
	f3 *= f1;
	cout << "f3 *= f1 -> f3 = " << f3 << endl;
	cout << endl;

	// Increment and Decrement
	cout << "++f1 = " << ++f1 << endl;
	cout << "f1++ = " << f1++ << endl;
	cout << "f1 = " << f1 << endl;
	cout << endl;
	cout << "--f2 = " << --f2 << endl;
	cout << "f2-- = " << f2-- << endl;
	cout << "f2 = " << f2 << endl;
	cout << endl;

	// Tupe conversion
	cout << "int(f1) = " << int(f1) << endl;
	cout << "float(f2) = " << float(f2) << endl;

	return 0;
}