#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class NhanVien {
protected:
	string hoTen, diaChi;

public:
	virtual void Nhap(string& line);
	virtual void Xuat(ostream& out) const;
	virtual bool laNhanVienXuatSac() const = 0;

	friend istream& operator>>(istream& in, NhanVien& nv);
	friend ostream& operator<<(ostream& out, const NhanVien& nv);
	virtual ~NhanVien() {}
};

class NhanVienKyThuat : public NhanVien {
private:
	string chungChiNganh;
	int soSangKien;

public:
	void Nhap(string& line) override;
	void Xuat(ostream& out) const override;
	bool laNhanVienXuatSac() const override;
};

class NhanVienThuKy : public NhanVien {
private:
	string chungChiNgoaiNgu;
	int soBaoCao;

public:
	void Nhap(string& line) override;
	void Xuat(ostream& out) const override;
	bool laNhanVienXuatSac() const override;
};

class CongTy {
private:
	NhanVien** dsNhanVien;
	int soLuong;

public:
	CongTy() : dsNhanVien(nullptr), soLuong(0) {}
	void themNhanVien(NhanVien* nv);
	void xuatNhanVien(ostream& out) const;
	void xuatNhanVienXuatSac(ostream& out) const;
	void docFile(const string& filename);
	~CongTy();
};

void NhanVien::Nhap(string& line) {
	size_t moNgoac = line.find('(');
	size_t dongNgoac = line.find(')');

	if (moNgoac != string::npos && dongNgoac != string::npos) {
		hoTen = line.substr(0, moNgoac);
		while (!hoTen.empty() && hoTen[hoTen.length() - 1] == ' ') hoTen.erase(hoTen.length() - 1);

		diaChi = line.substr(moNgoac + 1, dongNgoac - moNgoac - 1);
	}
}

void NhanVien::Xuat(ostream& out) const { out << "Ho ten: " << hoTen << " | Dia chi: " << diaChi; }

istream& operator>>(istream& in, NhanVien& nv) {
	string line;
	getline(in, line);
	nv.Nhap(line);
	return in;
}

ostream& operator<<(ostream& out, const NhanVien& nv) {
	nv.Xuat(out);
	return out;
}

void NhanVienKyThuat::Nhap(string& line) {
	NhanVien::Nhap(line);
	size_t moVuong = line.find('[');
	size_t dongVuong = line.find(']');
	if (moVuong != string::npos && dongVuong != string::npos) {
		chungChiNganh = line.substr(moVuong + 1, dongVuong - moVuong - 1);
	}

	size_t moNhon = line.find('<');
	size_t dongNhon = line.find('>');
	if (moNhon != string::npos && dongNhon != string::npos) {
		string soStr = line.substr(moNhon + 1, dongNhon - moNhon - 1);
		soSangKien = atoi(soStr.c_str());
	}
}

void NhanVienKyThuat::Xuat(ostream& out) const {
	NhanVien::Xuat(out);
	out << " | Nganh: " << chungChiNganh << " | Sang kien: " << soSangKien;
}

bool NhanVienKyThuat::laNhanVienXuatSac() const { return soSangKien >= 6; }

void NhanVienThuKy::Nhap(string& line) {
	NhanVien::Nhap(line);
	size_t moVuong = line.find('[');
	size_t dongVuong = line.find(']');
	if (moVuong != string::npos && dongVuong != string::npos) {
		chungChiNgoaiNgu = line.substr(moVuong + 1, dongVuong - moVuong - 1);
	}

	size_t moNhon = line.find('<');
	size_t dongNhon = line.find('>');
	if (moNhon != string::npos && dongNhon != string::npos) {
		string soStr = line.substr(moNhon + 1, dongNhon - moNhon - 1);
		soBaoCao = atoi(soStr.c_str());
	}
}

void NhanVienThuKy::Xuat(ostream& out) const {
	NhanVien::Xuat(out);
	out << " | Ngoai ngu: " << chungChiNgoaiNgu << " | Bao cao: " << soBaoCao;
}

bool NhanVienThuKy::laNhanVienXuatSac() const { return soBaoCao >= 12; }

void CongTy::themNhanVien(NhanVien* nv) {
	NhanVien** temp = new NhanVien*[soLuong + 1];
	for (int i = 0; i < soLuong; i++) {
		temp[i] = dsNhanVien[i];
	}
	temp[soLuong] = nv;
	delete[] dsNhanVien;
	dsNhanVien = temp;
	soLuong++;
}

void CongTy::xuatNhanVien(ostream& out) const {
	for (int i = 0; i < soLuong; i++) {
		out << *(dsNhanVien[i]) << endl;
	}
}

void CongTy::xuatNhanVienXuatSac(ostream& out) const {
	for (int i = 0; i < soLuong; i++) {
		if (dsNhanVien[i]->laNhanVienXuatSac()) {
			out << *(dsNhanVien[i]) << endl;
		}
	}
}

void CongTy::docFile(const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Khong the mo file: " << filename << endl;
		return;
	}

	string line;
	while (getline(file, line)) {
		if (line.empty()) continue;

		NhanVien* nv = NULL;
		string data;

		if (line.find("nvkt:") != string::npos) {
			nv = new NhanVienKyThuat();
			data = line.substr(5);
		} else if (line.find("nvtk:") != string::npos) {
			nv = new NhanVienThuKy();
			data = line.substr(5);
		}

		if (nv != NULL) {
			if (data.length() > 0 && data[0] == ' ') data.erase(0, 1);

			nv->Nhap(data);
			themNhanVien(nv);
		}
	}
	file.close();
}

CongTy::~CongTy() {
	for (int i = 0; i < soLuong; i++) {
		delete dsNhanVien[i];
	}
	delete[] dsNhanVien;
}

int main() {
	CongTy congTy;

	congTy.docFile("nhanvien.txt");
	cout << "\nDanh sach nhan vien:" << endl;
	congTy.xuatNhanVien(cout);
	cout << "\nDanh sach nhan vien xuat sac:" << endl;
	congTy.xuatNhanVienXuatSac(cout);

	return 0;
}