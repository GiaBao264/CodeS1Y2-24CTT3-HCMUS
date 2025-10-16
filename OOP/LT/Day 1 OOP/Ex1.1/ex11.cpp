#include <iostream>

using namespace std;

//Hàm sort mảng a theo kiểu dữ liệu của các phần tử trong a.
template <typename T>
void sortArray(T a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] < a[j]) {
                auto temp = a[i];
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
    //Khai báo các mảng.
    int arrInt[] = { 5, 2, 9, 1, 7 };
    float arrFloat[] = { 2.5, 1.1f, 4.3f, 0.9f };
    char arrChar[] = { 'd', 'a', 'c', 'b' };

    //Kích thước các mảng.
    int n1 = sizeof(arrInt) / sizeof(arrInt[0]);
    int n2 = sizeof(arrFloat) / sizeof(arrFloat[0]);
    int n3 = sizeof(arrChar) / sizeof(arrChar[0]);
    
    //Sort từng mảng.
    sortArray(arrInt, n1);
    sortArray(arrFloat, n2);
    sortArray(arrChar, n3);

    //In ra các mảng.
    cout << "Array 1:";
    printArray(arrInt, n1);
    cout << endl;

    cout << "Array 2:";
    printArray(arrFloat, n2);
    cout << endl;

    cout << "Array 3:";
    printArray(arrChar, n3);
    cout << endl;

    return 0;
}