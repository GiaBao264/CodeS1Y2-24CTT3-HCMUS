#include "lib.h"

int main() {
    cout << "---- Basic Array ----" << endl;
	int arr[6] = {0, 1, 0, 2, 3, 4};
	Array a1(6, arr);
    a1.display();
	a1[3] = 4;
    a1.display();
 
    cout << endl << "---- Histogram Array ----" << endl;

	HistogramArray a2(6, arr, 5);
	a2.computeHistogram();
	a2.displayHistogram();
	a2[3] = 4;
	a2.computeHistogram();
	a2.displayHistogram();
}