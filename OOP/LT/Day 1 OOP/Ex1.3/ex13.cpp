#include <iostream>

using namespace std;

//Sort tăng dần.
template <typename T>
bool Ascending(T x, T y) {
    return x > y;
}

//Sort giảm dần.
template <typename T>
bool Descending(T x, T y) {
    return x < y;
}

//Sort mảng theo yêu cầu (tăng dầu hoặc giảm dần).
template <typename T>
void sortArray(T a[], int n, bool(*p)(T, T)) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (p(a[i], a[j])) {
                T temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

//Hàm in mảng.
template <typename T>
void printArray(T a[], int n) {
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
}

int main() {
    //Khai báo mảng.
    double a[] = { 2.5, 1.1, 4.3, 0.9 };

    //Kích thước mảng.
    int n = sizeof(a) / sizeof(a[0]);

    //In ra mảng ban đầu.
    cout << "Array ban dau: ";
    printArray(a, n);
    cout << endl;

    //Lựa chọn kiểu sắp xếp.
    int choice;
    cout << "Chon kieu sap xep (1 = Tang dan, 2 = Giam dan): ";
    cin >> choice;

    //Sắp xếp theo lựa chọn.
    if (choice == 1) {
        sortArray(a, n, Ascending);
        cout << "Array sap xep tang dan: ";
    }
    else if (choice == 2) {
        sortArray(a, n, Descending);
        cout << "Array sap xep giam dan: ";
    }
    else {
        cout << "Lua chon khong hop le!";
        return 0;
    }

    //In ra mảng đã sắp xếp.
    printArray(a, n);

    return 0;
}