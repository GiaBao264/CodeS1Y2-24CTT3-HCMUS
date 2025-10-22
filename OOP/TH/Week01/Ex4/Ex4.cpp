#include <iostream>

using namespace std;

class NgaySinh {
private:
	int _ng, _th, _n;
	void ChuanHoa();
public:
	NgaySinh(const int& = 1, const int& = 1, const int& = 1);
	~NgaySinh();
	void Xuat();
};

class SinhVien {
private:
	string mssv, HoTen;
	NgaySinh ns;
	float DLT, DTH;
public:
	SinhVien();
	SinhVien(string mssv);
	SinhVien(string mssv, string HoTen, float DLT, float DTH);
	SinhVien(string mssv, string HoTen, float DLT, float DTH, int ng, int th, int n);
	SinhVien(string mssv, string HoTen, float DLT, float DTH, NgaySinh n);
	SinhVien(const SinhVien& sv);
	~SinhVien();
	void Xuat();
};

void NgaySinh::ChuanHoa() {
	_ng = abs(_ng);
	_th = abs(_th);
	_n = abs(_n);
	int thangDu = (_ng - 1) / 30;
	_ng = (_ng - 1) % 30 + 1;
	_th += thangDu;
	int namDu = (_th - 1) / 12;
	_th = (_th - 1) % 12 + 1;
	_n += namDu;
}

NgaySinh::NgaySinh(const int& ng, const int& th, const int& n) {
	_ng = abs(ng);
	_th = abs(th);
	_n = abs(n);
	ChuanHoa();
}

NgaySinh::~NgaySinh() {}

void NgaySinh::Xuat() {
	cout << _ng << "/" << _th << "/" << _n << endl;
}

SinhVien::SinhVien() : ns(1, 1, 1) {
	mssv = "0000000";
	HoTen = "Empty";
	DLT = DTH = 0;
}

SinhVien::SinhVien(string mssv) : ns(1, 1, 1) {
	this->mssv = mssv;
	HoTen = "Empty";
	DLT = DTH = 0;
}

SinhVien::SinhVien(string mssv, string HoTen, float DLT, float DTH)
	: ns(1, 1, 1) {
	this->mssv = mssv;
	this->HoTen = HoTen;
	this->DLT = DLT;
	this->DTH = DTH;
}

SinhVien::SinhVien(string mssv, string HoTen, float DLT, float DTH, int ng, int th, int n)
	: ns(ng, th, n) {
	this->mssv = mssv;
	this->HoTen = HoTen;
	this->DLT = DLT;
	this->DTH = DTH;
}

SinhVien::SinhVien(string mssv, string HoTen, float DLT, float DTH, NgaySinh n)
	: ns(n) {
	this->mssv = mssv;
	this->HoTen = HoTen;
	this->DLT = DLT;
	this->DTH = DTH;
}

SinhVien::SinhVien(const SinhVien& sv)
	: ns(sv.ns) {
	mssv = sv.mssv;
	HoTen = sv.HoTen;
	DLT = sv.DLT;
	DTH = sv.DTH;
}

SinhVien::~SinhVien() {}

void SinhVien::Xuat() {
	cout << "MSSV: " << mssv << endl;
	cout << "Ho Ten: " << HoTen << endl;
	cout << "Ngay Sinh: "; ns.Xuat();
	cout << "Diem LT: " << DLT << endl;
	cout << "Diem TH: " << DTH << endl;
	cout << "------------------------" << endl;
}

void main() {
	SinhVien sv1;
	sv1.Xuat();
	SinhVien sv2("1363001");
	sv2.Xuat();
	SinhVien sv3("1363002", "Nguyen Van A", 7, 8.5);
	sv3.Xuat();
	SinhVien sv4("1363003", "Tran Thi B", 8, 9.5, 12, 3, 1996);
	sv4.Xuat();
	NgaySinh n(30, 2, 1996);
	SinhVien sv5("1363004", "Ngo Van C", 5, 6, n);
	sv5.Xuat();
	SinhVien sv6(sv5);
	sv6.Xuat();
}