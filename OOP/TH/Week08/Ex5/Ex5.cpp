#include <iostream>
#include <vector>
#include <string>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14
#endif

using namespace std;

class Hinh {
public:
    virtual ~Hinh() {}
    virtual void xuat(ostream& out) const = 0;

    friend ostream& operator<<(ostream& out, const Hinh& h) {
        h.xuat(out);
        return out;
    }
};

class HinhHocPhang : public Hinh {
public:
	virtual ~HinhHocPhang() {}
	virtual double tinhChuVi() const = 0;
	virtual double tinhDienTich() const = 0;
	virtual string getTen() const = 0;

    void xuat(ostream& out) const override {
        out << getTen() << " [P = " << tinhChuVi() << ", S = " << tinhDienTich() << "]";
    }
};

class HinhTron : public HinhHocPhang {
private:
	double banKinh;

public:
    HinhTron(double r) : banKinh(r) {}
	double tinhChuVi() const override { return 2 * M_PI * banKinh; }
	double tinhDienTich() const override { return M_PI * banKinh * banKinh; }
    string getTen() const override { return "Hinh Tron"; }
};

class HinhTamGiacDeu : public HinhHocPhang {
private:
	double canh;

public:
    HinhTamGiacDeu(double a) : canh(a) {}
	double tinhChuVi() const override { return 3 * canh; }
	double tinhDienTich() const override { return (sqrt(3) / 4) * canh * canh; }
    string getTen() const override { return "Hinh Tam Giac Deu"; }
};

class HinhChuNhat : public HinhHocPhang {
private:
	double dai, rong;

public:
    HinhChuNhat(double d, double r) : dai(d), rong(r) {}
	double tinhChuVi() const override { return 2 * (dai + rong); }
	double tinhDienTich() const override { return dai * rong; }
    string getTen() const override { return "Hinh Chu Nhat"; }
};

class HinhVuong : public HinhHocPhang {
private:
	double canh;

public:
    HinhVuong(double a) : canh(a) {}
	double tinhChuVi() const override { return 4 * canh; }
	double tinhDienTich() const override { return canh * canh; }
    string getTen() const override { return "Hinh Vuong"; }
};

class HinhHoc3D : public Hinh {
public:
	virtual ~HinhHoc3D() {}
	virtual double dienTichXungQuanh() const = 0;
	virtual double tinhTheTich() const = 0;
    virtual string getTen() const = 0;

    void xuat(ostream& out) const override {
        out << getTen() << " [Sxq = " << dienTichXungQuanh() << ", V = " << tinhTheTich() << "]";
    }
};

class HinhCau : public HinhHoc3D {
private:
	double banKinh;

public:
    HinhCau(double r) : banKinh(r) {}
	double dienTichXungQuanh() const override { return 4 * M_PI * banKinh * banKinh; }
	double tinhTheTich() const override { return (4.0 / 3) * M_PI * banKinh * banKinh * banKinh; }
    string getTen() const override { return "Hinh Cau"; }
};

class HinhLapPhuong : public HinhHoc3D {
private:
	double canh;

public:
    HinhLapPhuong(double a) : canh(a) {}
	double dienTichXungQuanh() const override { return 6 * canh * canh; }
	double tinhTheTich() const override { return canh * canh * canh; }
    string getTen() const override { return "Hinh Lap Phuong"; }
};

class HinhHop : public HinhHoc3D {
private:
	double dai, rong, cao;

public:
    HinhHop(double d, double r, double c) : dai(d), rong(r), cao(c) {}
	double dienTichXungQuanh() const override { return 2 * (dai * rong + dai * cao + rong * cao); }
	double tinhTheTich() const override { return dai * rong * cao; }
    string getTen() const override { return "Hinh Hop"; }
};

class HinhTru : public HinhHoc3D {
private:
	double banKinh, chieuCao;

public:
    HinhTru(double r, double c) : banKinh(r), chieuCao(c) {}
	double dienTichXungQuanh() const override { return 2 * M_PI * banKinh * (banKinh + chieuCao); }
	double tinhTheTich() const override { return M_PI * banKinh * banKinh * chieuCao; }
    string getTen() const override { return "Hinh Tru"; }
};

class HinhChop : public HinhHoc3D {
private:
	double canhDay, chieuCao;

public:
    HinhChop(double d, double c) : canhDay(d), chieuCao(c) {}
	double dienTichXungQuanh() const override {
		return canhDay * canhDay + 2 * canhDay * sqrt((canhDay / 2) * (canhDay / 2) + chieuCao * chieuCao);
	}
	double tinhTheTich() const override { return (1.0 / 3) * canhDay * canhDay * chieuCao; }
    string getTen() const override { return "Hinh Chop"; }
};

int main(){
    vector<Hinh*> dsHinh;
    dsHinh.push_back(new HinhTron(3.5));
    dsHinh.push_back(new HinhTamGiacDeu(8.5));
    dsHinh.push_back(new HinhChuNhat(3.7, 1.9));
    dsHinh.push_back(new HinhVuong(4.1));
    dsHinh.push_back(new HinhCau(13.5));
    dsHinh.push_back(new HinhLapPhuong(2.9));
    dsHinh.push_back(new HinhHop(1.2, 3.7, 6.3));
    dsHinh.push_back(new HinhTru(6.1, 4.9));
    dsHinh.push_back(new HinhChop(8.7, 3.2));

    for(int i = 0; i < dsHinh.size(); i++){
    cout << *dsHinh[i] << endl;
    }

    cout << endl << endl;
    system("pause");
    return 0;
}