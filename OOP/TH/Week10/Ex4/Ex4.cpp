#include <iostream>
#include <vector>

using namespace std;

class CItem {
protected:
	string name;
	bool isHidden;

public:
	CItem(string n) : name(n), isHidden(false) {}
	virtual ~CItem() {}
	string getName() const { return name; }
	virtual void Print(bool isPrintHiddenItems = 0);
	virtual CItem* FindByName(string n) {
		if (this->name == n) return this;
		return NULL;
	}
	virtual void SetHidden(bool hidden, bool applyToChild) { this->isHidden = hidden; }
};

class CFile : public CItem {
private:
	double size;

public:
	CFile(string n, double s) : CItem(n), size(s) {}
	void Print(bool isPrintHiddenItems) override {
		if (isHidden && !isPrintHiddenItems) return;
		cout << "File: " << name << ", Size: " << size << endl;
	}
	void SetHidden(bool hidden, bool applyToChild) { this->isHidden = hidden; }
};

class CFolder : public CItem{
private:
    vector<CItem*> items;

public:
    CFolder(string n) : CItem(n){}

    void Add(CItem* item){
        items.push_back(item);
    }
    CItem* RemoveByName(string n){
        for(auto it = items.begin(); it != items.end(); ++it){
            if((*it)->getName() == n){
                CItem* removeItem = *it;
                items.erase(it);
                return removeItem;
            }
        }
        return NULL;
    }

    CItem* FindByName(string n) override{
        if (this->name == n) return this;

        for (auto item : items) {
            CItem* found = item->FindByName(n);
            if (found != NULL) return found;
        }
        return NULL;
    }

    void Print(bool isPrintHiddenItems) override {
        if (isHidden && !isPrintHiddenItems) return;

        cout << "Folder: " << name << endl;
        for (auto item : items) {
            item->Print(isPrintHiddenItems);
        }
    }

    void SetHidden(bool hidden, bool applyToChildren) override {
        this->isHidden = hidden;
        
        if (applyToChildren) {
            for (auto item : items) {
                item->SetHidden(hidden, applyToChildren);
            }
        }
    }
};

int main() {
	CFolder C("C");	 // (1)
	CFolder System("System");
	CFolder Windows("Windows");
	CFile a_txt("a.txt", 123);	// (2)
	CFile b_doc("b.doc", 456);
	System.Add(&a_txt);	 // (3)
	Windows.Add(&b_doc);
	C.Add(&System);	 // (4)
	C.Add(&Windows);
	cout << "Content of folder C ->" << endl;
	bool isPrintHiddenItems = false;
	C.Print(isPrintHiddenItems);		  // print hidden items or not? 1/0 (5)
	CItem* p = C.RemoveByName("System");  // (6)
	cout << "Content of folder C afer removing folder System ->" << endl;
	C.Print(false);
	p = C.FindByName("b.doc");	// (7)
	if (p != NULL) {
		cout << "b.doc is found in folder C" << endl;
	} else {
		cout << "b.doc is not found" << endl;
	}
	p = C.FindByName("a.txt");
	if (p != NULL) {
		cout << "a.txt is found" << endl;
	} else {
		cout << "a.txt is not found" << endl;
	}
	p = C.FindByName("Windows");  // (8)
	bool isHidden;
	bool isAlsoApplyToChildren;
	if (p != NULL) {
		cout << "Folder Windows is folder. Content of folder Windows ->" << endl;

		isHidden = true;
		isAlsoApplyToChildren = false;
		// set HIDDEN to folder p and do not change hidden attributes of its sub-items

		p->SetHidden(isHidden, isAlsoApplyToChildren);	// (9)
		p->Print(false);
		// set HIDDEN to folder p and all its items
		isHidden = true;
		isAlsoApplyToChildren = true;
		p->SetHidden(isHidden, isAlsoApplyToChildren);	// (10)
		p->Print(false);
	} else {
		cout << "Folder Windows is not found" << endl;
	}
	return 0;
}