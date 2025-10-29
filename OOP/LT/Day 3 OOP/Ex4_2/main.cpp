#include "lib.h"

int main() {
	Array a1(3);
	Array a2(2);

	cout << "Enter 3 elements for array a1: ";
	cin >> a1;

	cout << "Enter 2 elements for array a2: ";
	cin >> a2;

	cout << "Array a1: " << a1 << endl;
	cout << "Array a2: " << a2 << endl;

	Array a3 = a1 + a2;
	cout << "Array a3 = a1 + a2 -> a3 = " << a3 << endl;

	Array a4(1);
	cout << "Array a4 ban dau (1 phan tu): " << a4 << endl;
	a4 = a3;
	cout << "Array a4 sau khi a4 = a3 -> a4 = " << a4 << endl;

	a1 += a2;
	cout << "Array a1 += a2 -> a1 = " << a1 << endl;

	int* p = a2;
	cout << "Pointer p points to array a2: ";
	for(int i = 0; i < 2; i++) {
		cout << p[i] << " ";
	}
	cout << endl;

	return 0;
}