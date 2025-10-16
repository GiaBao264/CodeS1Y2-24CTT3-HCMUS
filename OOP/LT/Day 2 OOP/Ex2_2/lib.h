#pragma once
#include <iostream>

using namespace std;

class Array {
private:
	int* arr;
	int size;

public:
	// mặc định
	Array();
	// có kích thước và các phần tử = 0
	Array(int n);
	// tạo từ mảng có sẵn
	Array(int a[], int n);
	// sao chép từ mảng khác
	Array(const Array& other);
	// tránh memory leak
	~Array();

	// nhập mảng
	void input();
	// in mảng
	void output();

	// lấy kích thước
	int getSize();
	// thay đổi kích thước
	void setSize(int n);

	// lấy phần tử
	int getElement(int index);
	//đặt phần tử
	void setElement(int index, int value);

	// tìm giá trị
	int find(int value);
	// sắp xếp
	void sort();
};