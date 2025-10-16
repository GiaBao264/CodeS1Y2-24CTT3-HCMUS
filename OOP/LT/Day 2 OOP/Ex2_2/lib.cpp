#include "lib.h"

// mặc định
Array::Array() {
    size = 0;
    arr = nullptr;
}

// có kích thước và các phần tử = 0
Array::Array(int n) {
    size = n;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = 0;
}

// tạo từ mảng có sẵn
Array::Array(int a[], int n) {
    size = n;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = a[i];
}

// sao chép từ mảng khác
Array::Array(const Array& other) {
    size = other.size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = other.arr[i];
}

// tránh memory leak
Array::~Array() {
    delete[] arr;
}

// nhập mảng
void Array::input() {
    cout << "Nhap kich thuoc mang: ";
    cin >> size;
    delete[] arr; // xóa mảng cũ nếu có
    arr = new int[size];
    cout << "Nhap " << size << " phan tu: ";
    for (int i = 0; i < size; i++) cin >> arr[i];
}

// xuất mảng
void Array::output() {
    cout << "Mang: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// lấy kích thước
int Array::getSize() { return size; }

// đặt kích thước
void Array::setSize(int n) {
    delete[] arr;
    size = n;
    arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = 0;
}

// lấy phần tử
int Array::getElement(int index) {
    if (index < 0 || index >= size) {
        cout << "Vi tri khong hop le!\n";
        return -1;
    }
    return arr[index];
}

// đặt phần tử
void Array::setElement(int index, int value) {
    if (index < 0 || index >= size) {
        cout << "Vi tri khong hop le!\n";
        return;
    }
    arr[index] = value;
}

// tìm giá trị
int Array::find(int value) {
    for (int i = 0; i < size; i++)
        if (arr[i] == value)
            return i;
    return -1;
}

// sắp xếp mảng
void Array::sort() {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

