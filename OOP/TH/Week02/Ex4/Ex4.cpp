#include <iostream>
#include <string>

using namespace std;

class SoNguyenLon {
private:
	string _so;
public:
	SoNguyenLon();
	SoNguyenLon(const string& str);
	SoNguyenLon(const int& a, const int& b);
	~SoNguyenLon();
	
	static SoNguyenLon HieuVoiHangSo(const int& a, const SoNguyenLon& b);
	static SoNguyenLon SNLMax();
	SoNguyenLon Cong(const SoNguyenLon& snl) const;
	SoNguyenLon Tru(const SoNguyenLon& snl) const;
	SoNguyenLon Cong(const int& n) const;
	void In(ostream& os);
};

SoNguyenLon::SoNguyenLon() { _so = "0"; }

SoNguyenLon::SoNguyenLon(const string& str) { _so = str; }

SoNguyenLon::SoNguyenLon(const int& a, const int& b) {
	for(int i =0; i < b; i++) {
		_so += char('0' + a);
	}
}

SoNguyenLon::~SoNguyenLon() {}

SoNguyenLon SoNguyenLon::HieuVoiHangSo(const int& a, const SoNguyenLon& b) {
	SoNguyenLon snlA(to_string(a));
	return snlA.Tru(b);
}

SoNguyenLon SoNguyenLon::SNLMax() {
	return SoNguyenLon("99999999999999999999");
}

SoNguyenLon SoNguyenLon::Cong(const SoNguyenLon& snl) const {
	string a = _so;
	string b = snl._so;
	string kq = "";
	int lenA = a.length();
	int lenB = b.length();
	int maxLen = max(lenA, lenB);

	while (a.length() < maxLen) a = "0" + a;
	while (b.length() < maxLen) b = "0" + b;
	int carry = 0;
	for (int i = maxLen - 1; i >= 0; i--) {
		int sum = (a[i] - '0') + (b[i] - '0') + carry;
		carry = sum / 10;
		kq = to_string(sum % 10) + kq;
	}
	if (carry > 0) {
		kq = to_string(carry) + kq;
	}
	return SoNguyenLon(kq);
}

SoNguyenLon SoNguyenLon::Tru(const SoNguyenLon& snl) const {
	string a = _so;
	string b = snl._so;
	string kq = "";
	int lenA = a.length();
	int lenB = b.length();
	int maxLen = max(lenA, lenB);

	while (a.length() < maxLen) a = "0" + a;
	while (b.length() < maxLen) b = "0" + b;
	int borrow = 0;
	for (int i = maxLen - 1; i >= 0; i--) {
		int sub = (a[i] - '0') - (b[i] - '0') - borrow;
		if (sub < 0) {
			sub += 10;
			borrow = 1;
		} else {
			borrow = 0;
		}
		kq = to_string(sub) + kq;
	}

	size_t pos = kq.find_first_not_of('0');
	if (pos != string::npos) {
		return SoNguyenLon(kq.substr(pos));
	} else {
		return SoNguyenLon("0");
	}
}

SoNguyenLon SoNguyenLon::Cong(const int& n) const {
	SoNguyenLon snlN(to_string(n));
	return this->Cong(snlN);
}

void SoNguyenLon::In(ostream& os) {
	if (_so.empty()) {
		os << "0";
	} else {
		os << _so;
	}
}

int main() {
	SoNguyenLon snl1;
	SoNguyenLon snl2("1234567");
	SoNguyenLon snl3(3, 14);
	SoNguyenLon snl4(9, 20);
	SoNguyenLon snl5 = snl3.Tru(snl2);
	SoNguyenLon snl6 = SoNguyenLon::HieuVoiHangSo(45678910, snl2);
	SoNguyenLon snl7 = snl4.Tru(snl3).Cong(123456789);
	snl1.In(cout); cout << endl;
	snl2.In(cout); cout << endl;
	snl3.In(cout); cout << endl;
	snl4.In(cout); cout << endl;
	snl5.In(cout); cout << endl;
	snl6.In(cout); cout << endl;
	snl7.In(cout); cout << endl;
	cout << endl;

	cout << "SoNguyenLon Max: " << endl;
	SoNguyenLon::SNLMax().In(cout); cout << endl;
	return 0;
}