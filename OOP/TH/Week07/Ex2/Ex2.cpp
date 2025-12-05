#include <math.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#ifndef M_PI
#define M_PI 3.14
#endif

using namespace std;

class HinhHocPhang {
public:
	virtual ~HinhHocPhang() {}

	virtual void napDuLieu(string params) = 0;
	virtual double tinhChuVi() const = 0;
	virtual double tinhDienTich() const = 0;
	virtual string getTenLoai() const = 0;

	string chuanHoaSo(string s) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ',') s[i] = ' ';
		}
		return s;
	}
};

class HinhChuNhat : public HinhHocPhang {
private:
	double dai, rong;

public:
	string getTenLoai() const override { return "Hinh Chu Nhat"; }

	void napDuLieu(string params) override {
		params = chuanHoaSo(params);
		sscanf(params.c_str(), "%lf %lf", &dai, &rong);
	}

	double tinhChuVi() const override { return 2 * (dai + rong); }

	double tinhDienTich() const override { return dai * rong; }
};

class HinhTron : public HinhHocPhang {
private:
	double banKinh;

public:
	string getTenLoai() const override { return "Hinh Tron"; }

	void napDuLieu(string params) override {
		params = chuanHoaSo(params);
		sscanf(params.c_str(), "%lf", &banKinh);
	}

	double tinhChuVi() const override { return 2 * M_PI * banKinh; }

	double tinhDienTich() const override { return M_PI * banKinh * banKinh; }
};

class HinhTamGiac : public HinhHocPhang {
private:
	double canhA, canhB, canhC;

public:
	string getTenLoai() const override { return "Hinh Tam Giac"; }

	void napDuLieu(string params) override {
		params = chuanHoaSo(params);
		sscanf(params.c_str(), "%lf %lf %lf", &canhA, &canhB, &canhC);
	}

	double tinhChuVi() const override { return canhA + canhB + canhC; }

	double tinhDienTich() const override {
		double p = tinhChuVi() / 2;
		return sqrt(p * (p - canhA) * (p - canhB) * (p - canhC));
	}
};

class HinhThangVuong : public HinhHocPhang {
private:
	double dayLon, dayNho, chieuCao;

public:
	string getTenLoai() const override { return "Hinh Thang Vuong"; }

	void napDuLieu(string params) override {
		params = chuanHoaSo(params);
		sscanf(params.c_str(), "%lf %lf %lf", &dayLon, &dayNho, &chieuCao);
	}

	double tinhChuVi() const override { return dayLon + dayNho + chieuCao + chieuCao; }

	double tinhDienTich() const override { return (dayLon + dayNho) * chieuCao / 2; }
};

class QuanLyHinhHocPhang {
private:
	HinhHocPhang** dsHinh;
	int soLuong;

public:
	QuanLyHinhHocPhang() : dsHinh(nullptr), soLuong(0) {}

	~QuanLyHinhHocPhang() {
		for (int i = 0; i < soLuong; i++) {
			delete dsHinh[i];
		}
		delete[] dsHinh;
	}

	void themHinh(HinhHocPhang* hinh) {
		HinhHocPhang** temp = new HinhHocPhang*[soLuong + 1];
		for (int i = 0; i < soLuong; i++) {
			temp[i] = dsHinh[i];
		}
		temp[soLuong] = hinh;
		delete[] dsHinh;
		dsHinh = temp;
		soLuong++;
	}

	void docFile(const string& filename) {
		ifstream f(filename.c_str());
		if (!f.is_open()) {
			cout << "Khong the mo file " << filename << endl;
			return;
		}

		string line;
		while (getline(f, line)) {
			if (line.empty()) continue;

			size_t pos = line.find(':');
			if (pos == string::npos) continue;

			string type = line.substr(0, pos);
			string params = line.substr(pos + 1);

			HinhHocPhang* h = NULL;

			if (type == "hcn")
				h = new HinhChuNhat();
			else if (type == "htr")
				h = new HinhTron();
			else if (type == "htg")
				h = new HinhTamGiac();
			else if (type == "hthv")
				h = new HinhThangVuong();

			if (h != NULL) {
				h->napDuLieu(params);
				themHinh(h);
			}
		}
		f.close();
	}

	void xuatDanhSachHinh(ostream& out) const {
		if (soLuong == 0) {
			cout << "Danh sach trong!" << endl;
			return;
		}

		double tongDienTich = 0;
		double tongChuVi = 0;

		int cntHCN = 0, cntHTR = 0, cntHTG = 0, cntHTV = 0;

		for (int i = 0; i < soLuong; i++) {
			string loai = dsHinh[i]->getTenLoai();
			double dt = dsHinh[i]->tinhDienTich();
			double cv = dsHinh[i]->tinhChuVi();

			cout << i + 1 << ". " << loai << " | Chu vi: " << cv << " | Dien tich: " << dt << endl;

			tongDienTich += dt;
			tongChuVi += cv;

			if (loai == "Hinh Chu Nhat")
				cntHCN++;
			else if (loai == "Hinh Tron")
				cntHTR++;
			else if (loai == "Hinh Tam Giac")
				cntHTG++;
			else if (loai == "Hinh Thang Vuong")
				cntHTV++;
		}

		cout << "-------------------------" << endl;
		cout << "Tong so luong hinh: " << soLuong << endl;
		cout << "Hinh Chu Nhat: " << cntHCN << endl;
		cout << "Hinh Tron: " << cntHTR << endl;
		cout << "Hinh Tam Giac: " << cntHTG << endl;
		cout << "Hinh Thang Vuong: " << cntHTV << endl;
		cout << "-------------------------" << endl;
		cout << "TONG DIEN TICH: " << tongDienTich << endl;
		cout << "TONG CHU VI:    " << tongChuVi << endl;
	}
};

int main() {
	QuanLyHinhHocPhang ql;

	ql.docFile("hhp.txt");
	ql.xuatDanhSachHinh(cout);
    
	return 0;
}