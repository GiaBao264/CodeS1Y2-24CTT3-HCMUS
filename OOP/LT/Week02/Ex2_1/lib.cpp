#include "lib.h"

// phân số mặc định = 0
Fraction::Fraction() {
	num = 0;
	denom = 1;
}

// phân số có tử mẫu
Fraction::Fraction(int n, int d) {
	num = n;
	denom = d;
}

// số nguyên
Fraction::Fraction(int value) {
	num = value;
	denom = 1;
}

// từ chuỗi "a/b"
Fraction::Fraction(string s) {
	char slash;
	stringstream ss(s);
	ss >> num >> slash >> denom;
}

// nhân bản từ phân số khác
Fraction::Fraction(const Fraction& f) {
	num = f.num;
	denom = f.denom;
}

// nhập vào tử mẫu
void Fraction::input() {
	string s;
	cin >> s;
	char slash;
	stringstream ss(s);
	ss >> num >> slash >> denom;
}

// xuất phân số
void Fraction::output() {
	cout << num << "/" << denom << endl;
}

// lấy tử
int Fraction::getNum() { return num; }

// lấy mẫu
int Fraction::getDenom() { return denom; }

// đặt tử
void Fraction::setNum(int n) { num = n; }

// đặt mẫu
void Fraction::setDenom(int d) { denom = d; }

// ước chung lớn nhất
int Fraction::ucln(int a, int b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a == 0 ? 1 : a;
}

// rút gọn phân số
Fraction Fraction::reduce() {
	int g = ucln(num, denom);
	Fraction r(num / g, denom / g);

	if (r.denom < 0) {
		r.denom *= -1;
		r.num *= -1;
	}
	return r;
}

// đảo ngược phân số
Fraction Fraction::inverse() {
	if (num == 0) {
		cout << "Mau so = 0";
		return *this;
	}
	Fraction inv(denom, num);
	return inv;
}

// cộng phân số
Fraction Fraction::add(Fraction p) {
	Fraction sum;

	sum.num = num * p.denom + denom * p.num;
	sum.denom = denom * p.denom;

	return sum;
}

// so sánh phân số
int Fraction::compare(Fraction p) {
	int left = num * p.denom;
	int right = p.num * denom;
	if (left == right) return 0;
	return (left < right) ? -1 : 1;
}