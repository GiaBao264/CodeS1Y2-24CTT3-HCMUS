#include <iostream>
#include <iomanip>

using namespace std;

class Ngay {
private:
	int _ng, _th, _n;
	void ChuanHoa();
public:
	Ngay();
	Ngay(const int&);
	Ngay(const int&, const int&, const int&);
	Ngay operator+(const int&) const;
	Ngay operator-(const int&) const;
	Ngay operator+(const Ngay&) const;
	Ngay operator-(const Ngay&) const;
	
	friend Ngay operator+(const int&, const Ngay&);
	friend Ngay operator-(const int&, const Ngay&);
	friend bool operator>(const Ngay&, const Ngay&);
	friend ostream& operator<<(ostream&, const Ngay&);
};

void Ngay::ChuanHoa() {
	int ngayTrongThang[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	while (_th > 12) {
		_th -= 12;
		_n++;
	}
	while (_th < 1) {
		_th += 12;
		_n--;
		if (_n < 1) _n = 1;
	}

	if (_n % 400 == 0 || (_n % 4 == 0 && _n % 100 != 0)) {
		ngayTrongThang[1] = 29;
	} 
	else {
		ngayTrongThang[1] = 28;
	}

	while (_ng > ngayTrongThang[_th - 1]) {
		_ng -= ngayTrongThang[_th - 1];
		_th++;
		if (_th > 12) {
			_th = 1;
			_n++;
		}
		if (_n % 400 == 0 || (_n % 4 == 0 && _n % 100 != 0)) {
			ngayTrongThang[1] = 29;
		}
		else {
			ngayTrongThang[1] = 28;
		}
	}

	while (_ng < 1) {
		_th--;
		if (_th < 1) {
			_th = 12;
			if (_n > 1) _n--;
		}
		if (_n % 400 == 0 || (_n % 4 == 0 && _n % 100 != 0)) {
			ngayTrongThang[1] = 29;
		}
		else {
			ngayTrongThang[1] = 28;
		}
		_ng += ngayTrongThang[_th - 1];
	}
}

Ngay::Ngay() {
	_ng = _th = _n = 1;
}

Ngay::Ngay(const int& ng) : Ngay() {
	_ng = abs(ng);
	this->ChuanHoa();
}

Ngay::Ngay(const int& ng, const int& th, const int& n) {
	_ng = abs(ng);
	_th = abs(th);
	_n = abs(n);
	this->ChuanHoa();
}

Ngay Ngay::operator+(const int& x) const {
	Ngay rt = *this;
	rt._ng += x;
	rt.ChuanHoa();
	return rt;
}

Ngay Ngay::operator-(const int& x) const {
	Ngay rt = *this;
	rt._ng -= x;
	rt.ChuanHoa();
	return rt;
}

Ngay Ngay::operator+(const Ngay& d) const {
	Ngay rt = *this;
	rt._ng += d._ng;
	rt._th += d._th;
	rt._n += d._n;
	rt.ChuanHoa();
	return rt;
}

Ngay Ngay::operator-(const Ngay& d) const {
	Ngay rt = *this;
	rt._ng -= d._ng;
	rt._th -= d._th;
	rt._n -= d._n;
	rt.ChuanHoa();
	return rt;
}

Ngay operator+(const int& x, const Ngay& d) {
	Ngay rt = d;
	rt._ng += x;
	rt.ChuanHoa();
	return rt;
}

Ngay operator-(const int& x, const Ngay& d) {
	Ngay rt = d;
	rt._ng -= x;
	rt.ChuanHoa();
	return rt;
}

bool operator>(const Ngay& d1, const Ngay& d2) {
	if (d1._n != d2._n) {
		return d1._n > d2._n;
	}
	if (d1._th != d2._th) {
		return d1._th > d2._th;
	}
	return d1._ng > d2._ng;
}

ostream& operator<<(ostream& os, const Ngay& d) {
	os << setfill('0') << setw(2) << d._ng << "/" << setfill('0') << setw(2) << d._th << "/" << setfill('0') << setw(2) << d._n;
	return os;
}

int main() {
	Ngay n1;
	Ngay n2(2, 10, 2014);
	Ngay n3(-10, 16, 2000);
	Ngay n4(1000);
	Ngay n5 = n2 + n3;
	Ngay n6 = n1 + 5000;
	Ngay n7 = 1234 + n4;
	Ngay n8 = 190 + n6 + n7;
	Ngay n9 = n8 - n6;
	Ngay n10 = 12000 - n9;
	if (n10 > n6) {
		n10 = n2 - 1000 + n6;
	}
	cout << n1 << endl << n2 << endl << n3 << endl << n4 << endl;
	cout << n5 << endl << n6 << endl << n7 << endl << n8 << endl;
	cout << n9 << endl << n10 << endl;

	system("pause");
	return 0;
}