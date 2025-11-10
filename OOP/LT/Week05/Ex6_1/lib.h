#include <iostream>

using namespace std;

class Array {
private:
	int* data;
	int size;

public:
	Array();
	Array(int s, int arr[]);
	Array(const Array& other);
	~Array();

	Array& operator=(const Array& other);
    int& operator[](int index);
	void setElement(int index, int value);
	int getElement(int index) const;
    void getSize(int& s) const;
	void display() const;
};

class HistogramArray : public Array {
private:
	int* histogram;
	int histSize;

public:
	HistogramArray(int size);
    HistogramArray(int s, int arr[], int hSize);
	~HistogramArray();

	void computeHistogram() const;
	void displayHistogram() const;
};