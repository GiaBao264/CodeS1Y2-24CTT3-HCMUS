#include <iostream>

using namespace std;

class HocSinh {
private:
	string hoTen;
	int mssv;
	double d1, d2, d3;
	static const int MAX_HS = 100;
	static HocSinh danhSach[MAX_HS];
	static int soLuong;
public:
	HocSinh();
	HocSinh(const string& ht, const double& di1, const double& di2, const double& di3);
	~HocSinh();

	void DatHoTen(const string& ht);
	void GanDiem(const double& di1, const double& di2, const double& di3);
	double TinhDiemTB() const;

	static void ThemHocSinh(const HocSinh& hs);
	static HocSinh HSDiemTBCaoNhat();
	void In(ostream& os);
};

HocSinh::HocSinh() {
	hoTen = "";
	mssv = 0;
	d1 = d2 = d3 = 0.0;
}

HocSinh::HocSinh(const string& ht, const double& di1, const double& di2, const double& di3) {
	hoTen = ht;
	mssv = 0;
	d1 = di1 < 0 ? 0 : di1;
	d2 = di2 < 0 ? 0 : di2;
	d3 = di3 < 0 ? 0 : di3;

	ThemHocSinh(*this);
}

HocSinh::~HocSinh() {}

void HocSinh::DatHoTen(const string& ht) {
	hoTen = ht;
}

void HocSinh::GanDiem(const double& di1, const double& di2, const double& di3) {
	d1 = di1 < 0 ? 0 : di1;
	d2 = di2 < 0 ? 0 : di2;
	d3 = di3 < 0 ? 0 : di3;
}

double HocSinh::TinhDiemTB() const {
	return (d1 + d2 + d3) / 3.0;
}

void HocSinh::ThemHocSinh(const HocSinh& hs) {
	if (soLuong < MAX_HS) {
		danhSach[soLuong] = hs;
		soLuong++;
	}
}

HocSinh HocSinh::HSDiemTBCaoNhat() {
	if (soLuong == 0) return HocSinh();

	HocSinh hsMax = danhSach[0];
	for (int i = 1; i < soLuong; i++) {
		if (danhSach[i].TinhDiemTB() > hsMax.TinhDiemTB()) {
			hsMax = danhSach[i];
		}
	}
	return hsMax;
}

void HocSinh::In(ostream& os) {
	os << "Ho ten: " << hoTen << endl << "Diem 1: " << d1 << endl << "Diem 2: " << d2 << endl << "Diem 3: " << d3 << endl << "Diem TB: " << TinhDiemTB() << endl;
}

HocSinh HocSinh::danhSach[MAX_HS];
int HocSinh::soLuong = 0;
int main() {
	HocSinh hs1;
	hs1.DatHoTen("Nguyen Van A");
	hs1.GanDiem(7, 8, 10);
	HocSinh hs2("Tran Thi B", 5, 8, 4.5);
	HocSinh hs3("Hoang Thi C", -9.5, 8.5, 4.5);
	HocSinh hs4("Le Van D", 7.5, 9, -10);
	hs1.In(cout); cout << endl;
	hs2.In(cout); cout << endl;
	hs3.In(cout); cout << endl;
	hs4.In(cout); cout << endl;
	cout << "Hoc sinh co diem TB cao nhat: " << endl;
	HocSinh::HSDiemTBCaoNhat().In(cout);
	cout << endl;

	return 0;
}