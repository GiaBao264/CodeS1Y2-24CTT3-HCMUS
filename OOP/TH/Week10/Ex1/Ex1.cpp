#include <iostream>

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
	static double RunTest1(CA* pCA) {
		double rs = pCA->GetTest();
		return sqrt(rs);
	}

	static double RunTest2(CA* pCA) {
		if (pCA == nullptr) {
			return -1;
		}
		double rs = pCA->GetTest();
		return sqrt(rs);
	}
};

class Level2 {
public:
	static double RunTest1() {
		CA* pCA = nullptr;
		double dRS = Level1::RunTest2(pCA);
		if (dRS == -1) {
			return -1;
		}
		return sqrt(dRS);
	}
};

int main() {
	cout << "Vi du 1: " << endl;
	cout << Level1::RunTest1(nullptr) << endl;

	cout << "Vi du 2: " << endl;
	cout << Level1::RunTest2(nullptr) << endl;

	cout << "Vi du 3: " << endl;
	cout << Level2::RunTest1() << endl;

	system("pause");
	return 0;
}