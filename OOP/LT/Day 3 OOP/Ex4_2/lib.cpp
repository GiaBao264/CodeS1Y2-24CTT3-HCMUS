#include "lib.h"

Array::Array(int length) {
	this->length = length;
	data = new int[length];
}

Array::~Array() {
	delete[] this->data;
}

Array Array::operator+(const Array& a) const {
	Array result(this->length + a.length);
	for(int i = 0; i < this->length; i++) {
		result.data[i] = this->data[i];
	}
	for(int i = 0; i < a.length; i++) {
		result.data[this->length + i] = a.data[i];
	}
	return result;
}

Array& Array::operator=(const Array& a) {
	if(this != &a) {
		delete[] data;
		this->length = a.length;
		data = new int[this->length];
		for(int i = 0; i < this->length; i++) {
			data[i] = a.data[i];
		}
	}
	return *this;
}

Array& Array::operator+=(const Array& a) {
	int* newData = new int[this->length + a.length];
	for(int i = 0; i < this->length; i++) {
		newData[i] = this->data[i];
	}
	for(int i = 0; i < a.length; i++) {
		newData[this->length + i] = a.data[i];
	}
	delete[] this->data;
	this->data = newData;
	this->length += a.length;
	return *this;
}

int& Array::operator[](int index) {
	return data[index];
}

Array::operator int*() const {
    return data;
}

ostream& operator<<(ostream& os, const Array& a) {
	for(int i = 0; i < a.length; i++) {
		os << a.data[i] << " ";
	}
	return os;
}

istream& operator>>(istream& is, Array& a) {
	for(int i = 0; i < a.length; i++) {
		is >> a.data[i];
	}
	return is;
}