#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Component {
protected:
	string name;

public:
	Component(string n) : name(n) {}
	virtual ~Component() {}

	virtual int getSize() = 0;
	virtual int countItems() = 0;

	virtual void Print(ostream& os, int level = 0) const {
		string indent(level * 4, ' ');
		os << indent << name;
	}

	friend ostream& operator<<(ostream& os, Component& c) {
		c.Print(os, 0);
		return os;
	}
};

class File : public Component {
private:
	string type;
	int size;

public:
	File(string n, int s) : Component(n), size(s) {}

	int getSize() override { return size; }
	int countItems() override { return 1; }

	void Print(ostream& os, int level = 0) const override {
		string indent(level * 4, ' ');
		os << indent << name << " (" << size << " B)" << endl;
	}
};

class Folder : public Component {
private:
	vector<Component*> children;

public:
	Folder(string n) : Component(n) {}

	void add(Component* c) { children.push_back(c); }

	int getSize() override {
		int totalSize = 0;
		for (size_t i = 0; i < children.size(); ++i) {
            totalSize += children[i]->getSize();
        }
		return totalSize;
	}

	int countItems() override {
        int total = 1;
        
        for (size_t i = 0; i < children.size(); ++i) {
            total += children[i]->countItems();
        }
        return total;
    }

	void Print(ostream& os, int level = 0) const override {
        string indent(level * 4, ' ');
        os << indent << "[" << name << "]" << endl;
        
        for (size_t i = 0; i < children.size(); ++i) {
            children[i]->Print(os, level + 1);
        }
    }
};

int main() {
	Folder* root = new Folder("C:");

	Folder* baiTap = new Folder("Bai tap");
	File* bt1 = new File("BT1.doc", 123456);
	baiTap->add(bt1);

	Folder* baiTapC = new Folder("Bai tap C");
	File* bt2cpp = new File("BT2.cpp", 1280);
	File* bt2xls = new File("BT2.xls", 23456);
	baiTapC->add(bt2cpp);
	baiTap->add(bt2xls);
	baiTap->add(baiTapC);
	root->add(baiTap);

	Folder* lyThuyet = new Folder("Ly thuyet");
	File* ch1 = new File("Ch1.ppt", 34567);
	lyThuyet->add(ch1);
	root->add(lyThuyet);

	cout << "--- CAY THU MUC ---" << endl;
    cout << *root;
    cout << "\n--- THONG TIN ---" << endl;
    cout << "So luong item trong [Bai tap]: " << baiTap->countItems() << endl;
    cout << "Kich thuoc [Bai tap C]: " << baiTapC->getSize() << " B" << endl;
    cout << "Tong kich thuoc [C:]: " << root->getSize() << " B" << endl;

	return 0;
}