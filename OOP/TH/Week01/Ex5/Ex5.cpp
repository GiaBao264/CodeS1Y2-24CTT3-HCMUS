#include <iostream>

using namespace std;

class MangSoNguyen {
private:
	int* arr;
	int size;
public:
	MangSoNguyen();
	MangSoNguyen(int size);
	MangSoNguyen(int arr[], int size);
	MangSoNguyen(const MangSoNguyen& ms);
	~MangSoNguyen();
	void Xuat();
};

MangSoNguyen::MangSoNguyen() {
	size = 0;
	arr = nullptr;
}

MangSoNguyen::MangSoNguyen(int size) {
	this->size = size > 0 ? size : 0;
	if (this->size > 0) {
		arr = new int[this->size];
		for (int i = 0; i < this->size; i++) {
			arr[i] = 0;
		}
	}
	else {
		arr = nullptr;
	}
}

MangSoNguyen::MangSoNguyen(int arr[], int size) {
	this->size = size > 0 ? size : 0;
	if (this->size > 0) {
		this->arr = new int[this->size];
		for (int i = 0; i < this->size; i++) {
			this->arr[i] = arr[i];
		}
	}
	else {
		this->arr = nullptr;
	}
}

MangSoNguyen::MangSoNguyen(const MangSoNguyen& ms) {
	size = ms.size;
	if (size > 0) {
		arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = ms.arr[i];
		}
	}
	else {
		arr = nullptr;
	}
}

MangSoNguyen::~MangSoNguyen() {
	delete[] arr;
}

void MangSoNguyen::Xuat() {
	cout << "Mang gom " << size << " phan tu: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void main() {
	MangSoNguyen msn1;
	msn1.Xuat();
	MangSoNguyen msn2(5);
	msn2.Xuat();
	int arr[10];
	for (int i = 0; i < 8; i++) {
		arr[i] = i * i;
	}
	MangSoNguyen msn3(arr, 8);
	msn3.Xuat();
	MangSoNguyen msn4(msn3);
	msn4.Xuat();
}