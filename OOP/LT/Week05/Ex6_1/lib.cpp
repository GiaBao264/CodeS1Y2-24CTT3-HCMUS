#include "lib.h"

Array::Array() {
	size = 0;
	data = nullptr;
}

Array::Array(int s, int arr[]) {
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = arr[i];
	}
}

Array::Array(const Array& other) {
	size = other.size;
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}

Array::~Array() {
	delete[] data;
}

Array& Array::operator=(const Array& other) {
	if (this != &other) {
		delete[] data;
		size = other.size;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
	}
	return *this;
}

int& Array::operator[](int index) {
	return data[index];
}

void Array::setElement(int index, int value) {
	data[index] = value;
}

int Array::getElement(int index) const {
	return data[index];
}

void Array::getSize(int& s) const {
	s = size;
}

void Array::display() const {
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

HistogramArray::HistogramArray(int size) {
	histSize = size;
	histogram = new int[histSize];
	for (int i = 0; i < histSize; i++) {
		histogram[i] = 0;
	}
}

HistogramArray::HistogramArray(int s, int arr[], int hSize) : Array(s, arr) {
	histSize = hSize;
	histogram = new int[histSize];
	for (int i = 0; i < histSize; i++) {
		histogram[i] = 0;
	}
}

HistogramArray::~HistogramArray() {
	delete[] histogram;
}

void HistogramArray::computeHist() const {
	for (int i = 0; i < histSize; i++) {
		histogram[i] = 0;
	}

	int arrSize;
	getSize(arrSize);
	for (int i = 0; i < arrSize; i++) {
		int value = getElement(i);
		if (value >= 0 && value < histSize) {
			histogram[value]++;
		}
	}
}

void HistogramArray::displayHist() const {
    cout << "| ";
	for (int i = 0; i < histSize; i++) {
		cout << i << " -> " << histogram[i] << " | ";
	}
    cout << endl;
}