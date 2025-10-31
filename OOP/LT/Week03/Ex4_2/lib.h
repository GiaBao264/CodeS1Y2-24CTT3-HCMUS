#include <iostream>

using namespace std;

class Array {
private:
	int length;
	int* data;
public:
	Array(int legth);
	~Array();

	Array operator+(const Array& a) const;
	Array& operator=(const Array& a);
	Array& operator+=(const Array& a);
	int& operator[](int index);

	operator int*() const;

	friend ostream& operator<<(ostream& os, const Array& a);
	friend istream& operator>>(istream& is, Array& a);
};