#include <iostream>
#include <iomanip>

using namespace std;

class ThoiGian {
private:
	int gio;
	int phut;
	int giay;
	void ChuanHoa();
public:
	ThoiGian();
	ThoiGian(int giay);
	ThoiGian(int phut, int giay);
	ThoiGian(int gio, int phut, int giay);
	void Xuat();
};

void ThoiGian::ChuanHoa() {
	giay = abs(giay);
	phut = abs(phut);
	gio = abs(gio);
	int phutDu = giay / 60;
	giay = giay % 60;
	phut += phutDu;
	int gioDu = phut / 60;
	phut = phut % 60;
	gio += gioDu;
}

ThoiGian::ThoiGian() {
	gio = phut = giay = 0;
}

ThoiGian::ThoiGian(int x) {
	if (x < 0) x = 0;
	giay = x;
	phut = gio = 0;
	ChuanHoa();
}

ThoiGian::ThoiGian(int p, int s) {
	if (p < 0) p = 0;
	phut = p;
	if (s < 0) s = 0;
	giay = s;
	gio = 0;
	ChuanHoa();
}

ThoiGian::ThoiGian(int h, int p, int s) {
	if (h < 0) h = 0;
	gio = h;
	if (p < 0) p = 0;
	phut = p;
	if (s < 0) s = 0;
	giay = s;
	ChuanHoa();
}

void ThoiGian::Xuat() {
	cout << setfill('0') << setw(2) << gio << ":"
		<< setfill('0') << setw(2) << phut << ":"
		<< setfill('0') << setw(2) << giay << endl;
}

void main() {
	ThoiGian tg1;
	tg1.Xuat();

	ThoiGian tg2(1212);
	tg2.Xuat();

	ThoiGian tg3(125, 45);
	tg3.Xuat();

	ThoiGian tg4(12, 239, -78);
	tg4.Xuat();
}