#include <iostream>
#include <vector>

using namespace std;

class ChiTietMay {
protected:
	string _maSo;

public:
	ChiTietMay(string maSo) : _maSo(maSo) {}
	virtual ~ChiTietMay() {}

	virtual double TrongLuong() = 0;
	virtual double GiaThanh() = 0;
	virtual void Print(ostream& os, int level = 0) const {
		string indent(level * 4, ' ');
		string hienThiMa = _maSo;
		os << indent << "Ma so: " << hienThiMa;
	}

	friend ostream& operator<<(ostream& os, ChiTietMay& ct) {
		ct.Print(os, 0);
		return os;
	}
};
class ChiTietDon : public ChiTietMay {
private:
	double _trongLuong, _donGia;

public:
	ChiTietDon(const string& maSo, const double& trongLuong, const double& donGia)
		: ChiTietMay(maSo), _trongLuong(trongLuong), _donGia(donGia) {}

	double TrongLuong() override { return _trongLuong; }
	double GiaThanh() override { return _donGia; }

	void Print(ostream& os, int level = 0) const override {
		ChiTietMay::Print(os, level);
		os << " | Weight: " << _trongLuong << " | Price: " << (long long)_donGia << " VND" << endl;
	}
};

class ChiTietPhuc : public ChiTietMay {
private:
	vector<ChiTietMay*> dschiTiet;

public:
	ChiTietPhuc() : ChiTietMay("") {}
	ChiTietPhuc(const string& maSo) : ChiTietMay(maSo) {}

	void ThemChiTiet(ChiTietMay* ct) { dschiTiet.push_back(ct); }

	void ThemChiTietMay(ChiTietMay* ct) { ThemChiTiet(ct); }

	double TrongLuong() override {
		double totalWeight = 0;
		for (int i = 0; i < dschiTiet.size(); ++i) {
			totalWeight += dschiTiet[i]->TrongLuong();
			totalWeight *= 1.1;
		}
		return totalWeight;
	}

	double GiaThanh() override {
		double totalCost = 0;
		for (int i = 0; i < dschiTiet.size(); ++i) {
			totalCost += dschiTiet[i]->GiaThanh();
			totalCost *= 1.2;
		}
		return totalCost;
	}

	void Print(ostream& os, int level = 0) const override {
		ChiTietMay::Print(os, level);
		os << " Chi Tiet Phuc:" << endl;
		for (size_t i = 0; i < dschiTiet.size(); ++i) {
			dschiTiet[i]->Print(os, level + 1);
		}
	}
};

typedef ChiTietPhuc CoMay;

int main() {
	CoMay* pcm = new CoMay();

	pcm->ThemChiTietMay(new ChiTietDon("CTD001", 120, 350000));

	ChiTietMay* pctm = new ChiTietPhuc("CTP001");
	((ChiTietPhuc*)pctm)->ThemChiTiet(new ChiTietDon("CTD002", 50, 1280000));
	((ChiTietPhuc*)pctm)->ThemChiTiet(new ChiTietDon("CTD003", 20, 10000));

	ChiTietMay* pctm1 = new ChiTietPhuc("CTP002");
	((ChiTietPhuc*)pctm1)->ThemChiTiet(new ChiTietDon("CTD004", 80, 170000));
	((ChiTietPhuc*)pctm)->ThemChiTiet(pctm1);

	pcm->ThemChiTietMay(pctm);
	pcm->ThemChiTietMay(new ChiTietDon("CTD005", 210, 2350000));
	pcm->ThemChiTietMay(new ChiTietDon("CTD006", 40, 50000));

	cout << "Thong tin co may: " << endl << *pcm << endl;

	cout << "Trong luong: " << pcm->TrongLuong() << endl;

	cout << "Gia thanh: " << pcm->GiaThanh() << endl;

	cout << endl << endl;
	system("pause");
	return 0;
}