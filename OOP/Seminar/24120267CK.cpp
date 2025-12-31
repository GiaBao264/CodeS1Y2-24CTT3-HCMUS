/*
Ho va ten : Tran Huynh Gia Bao
MSSV : 24120267
*/

#include <math.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MachDien {
protected:
	string maso;

public:
	MachDien() : maso(maso) {}
	~MachDien() {}
};

class MachDon : public MachDien {
private:
	vector<MachDien*> md;
	double dientro, trigia;

public:
	MachDon() : MachDien(), dientro(dientro), trigia(trigia) {}
	~MachDon() {}

	double getDT() { return dientro; }
	double getTG() { return trigia; }
};

class MachPhuc : public MachDon {
private:
	vector<MachDien*> mp;

public:
	MachPhuc() : MachDon() {}
};

class MachNT : public MachPhuc {
private:
	vector<MachPhuc*> mnt;

public:
	MachNT() {}
	~MachNT() {}

	double tongR() {
		double tR;
		for (int i = 0; i <= mnt.size(); ++i) {
			tR += mnt[i]->getDT();
		}
		return tR;
	}

	double tongTG() {
		double tTG;
		for (int i = 0; i <= mnt.size(); ++i) {
			tTG += mnt[i]->getTG();
		}
		return tTG;
	}
};

class MachSS : public MachPhuc {
private:
	vector<MachPhuc*> mnt;

public:
	MachSS() {}
	~MachSS() {}

	double tongR() {
		double tR = 0;
		for (int i = 0; i <= mnt.size(); ++i) {
			tR += 1 / mnt[i]->getDT();
		}
		return 1 / tR;
	}

	double tongTG() {
		double tTG;
		for (int i = 0; i <= mnt.size(); ++i) {
			tTG += mnt[i]->getTG();
		}
		tTG += tTG * 0.15;
		return tTG;
	}
};

class BoMach : public MachDien {
private:
	bool tontaiMD;

public:
	BoMach() { tontaiMD = false; }
	~BoMach() {}

	void docFile(const string& filename) {
		ifstream file(filename);
		if (!file.is_open()) {
			cerr << "Khong the mo file: " << filename << endl;
			return;
		}

		string line;
		while (getline(file, line)) {
			if (line.empty()) continue;

			MachDon* md = NULL;
			MachPhuc* mp = NULL;
			string mS;
			double triGia, dienTro;

			if (line.find("MachDon") != string::npos) {
				md = new MachDon();
				mS = line.substr(10);
			} else if (line.find("MachNoiTiep") != string::npos) {
				mp = new MachNT();
				mS = line.substr(14);
			} else if (line.find("MachSongSong") != string::npos) {
				mp = new MachSS();
				mS = line.substr(15);
			}
		}
		file.close();
	}
};

int main() {
	BoMach bm;

	bm.docFile("data.txt");

	return 0;
}