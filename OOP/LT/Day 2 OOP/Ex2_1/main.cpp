#include "lib.h"

int main() {
    Fraction ps1, ps2;

    // Nhập phân số 1
    while (true) {
        cout << "Nhap phan so thu nhat (a/b): ";
        ps1.input();
        if (ps1.getDenom() == 0) {
            cout << "Mau phai khac 0. Vui long nhap lai!\n";
            continue;
        }
        break;
    }

    // Nhập phân số 2
    while (true) {
        cout << "Nhap phan so thu hai (a/b): ";
        ps2.input();
        if (ps2.getDenom() == 0) {
            cout << "Mau phai khac 0. Vui long nhap lai!\n";
            continue;
        }
        break;
    }
    cout << endl;

	// Xuất 2 phân số vừa nhập
    cout << "Phan so thu nhat: ";
    ps1.output();
    cout << "Phan so thu hai: ";
    ps2.output();
	cout << endl;

    // Cộng 2 phân số
    Fraction sum = ps1.add(ps2);
    cout << "Tong hai phan so: ";
    sum.output();
    cout << endl;

    // Rút gọn kết quả
    Fraction reduced = sum.reduce();
    cout << "Rut gon: ";
    reduced.output();
	cout << endl;

    // Nghịch đảo phân số 1
    cout << "Nghich dao cua phan so thu nhat: ";
    Fraction inv = ps1.inverse();
    inv.output();

	// Nghich đảo phân số 2
	cout << "Nghich dao cua phan so thu hai: ";
	inv = ps2.inverse();
	inv.output();
	cout << endl;

    // So sánh 2 phân số
    cout << "So sanh ps1 va ps2: ";
    int cmp = ps1.compare(ps2);
    if (cmp == 0) cout << "Hai phan so bang nhau";
    else if (cmp < 0) cout << "ps1 < ps2";
    else cout << "ps1 > ps2";
	cout << endl;

    return 0;
}
