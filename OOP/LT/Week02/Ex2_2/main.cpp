#include "lib.h"

int main() {
    Array a1;

    // nhập mảng
    a1.input(); cout << endl;

    // xuất mảng
    a1.output(); cout << endl;

    // lấy kích thước
    cout << "Kich thuoc mang: " << a1.getSize() << endl;

    // tìm phần tử
    int x;
    cout << "Nhap gia tri can tim: ";
    cin >> x;
    int pos = a1.find(x);
    if (pos == -1) cout << "Khong tim thay!\n";
    else cout << "Gia tri o vi tri: " << pos << endl;

    // sao chép mảng
    Array a2(a1);
    cout << "Mang sao chep: ";
    a2.output();

    // sắp xếp
    cout << "Mang sau khi sap xep: ";
    a1.sort();
    a1.output();
    
	a1.~Array();
	a2.~Array();

    return 0;
}