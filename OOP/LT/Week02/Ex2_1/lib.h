#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Fraction {
private:
	// tử
	int num;
	// mẫu
	int denom;

	// ước chung lớn nhất
	int ucln(int a, int b);

public:
	// mặc định = 0
	Fraction();
	// phân số có tử mẫu
	Fraction(int n, int d);
	// số nguyên
	Fraction(int value);
	// từ chuỗi "a/b"
	Fraction(string s);
	// nhân bản từ phân số khác
	Fraction(const Fraction& f);

	// nhập vào tử mẫu
	void input();
	// xuất phân số
	void output();

	// lấy tử
	int getNum();
	// lấy mẫu
	int getDenom();
	void setNum(int n);
	void setDenom(int d);

	// rút gọn phân số
	Fraction reduce();
	// đảo ngược phân số
	Fraction inverse();
	// cộng phân số
	Fraction add(Fraction p);
	// so sánh phân số
	int compare(Fraction p);
};