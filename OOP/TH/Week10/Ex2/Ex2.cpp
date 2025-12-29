#include <iostream>
#include <exception>
#include <cmath>

using namespace std;

class CA {
private:
	double _value;

public:
	CA(const double& v) { _value = v; }
	double GetTest() { return this->_value; }
};

class Level1 {
public:
	static double RunTest3(CA* pCA) {
		if (pCA == nullptr) {
			throw exception("Argument must not be null");
		}
		double rs = pCA->GetTest();
		return sqrt(rs);
	}
};

class Level2 {
public:
	static double RunTest2() {
		CA* pCA = nullptr;
		double dRS = Level1::RunTest3(pCA);
		return sqrt(dRS);
	}
};

int main() {
    try {
        cout << "Vi du 4: " << Level1::RunTest3(nullptr) << endl;
    } catch (const exception& ex) {
        cout << "Loi Vi du 4: " << ex.what() << endl;
    }

    cout << endl;

    try {
        cout << "Vi du 5: " << Level2::RunTest2() << endl;
    } catch (const exception& ex) {
        cout << "Loi Vi du 5: " << ex.what() << endl;
    }

    system("pause");
    return 0;
}