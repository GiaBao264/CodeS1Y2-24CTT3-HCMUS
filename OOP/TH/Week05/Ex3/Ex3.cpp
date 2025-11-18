#include <iostream>

using namespace std;

template <typename T>
class SLList {
private:
	struct Node {
		T _info;
		Node* _pNext;
	};

	Node* _pHead;
	Node* _pTail;
	int _n;

	static Node* CreateNode(const T& value) {
		Node* node = new Node{value, nullptr};
		return node;
	};

public:
	class Iterator;
	SLList();
	~SLList();

	Iterator Begin() {
		return Iterator(_pHead);
	}

	Iterator End() {
		return Iterator(nullptr);
	}

	void push_back(const T&);
	void pop_back();
	void insert(Iterator, const T&);
	void clear();
	int size() const;
	T& operator[](int index);
	const T& operator[](int index) const;
	SLList<T>& operator=(const SLList<T>& other);
};

template <typename T>
SLList<T>::SLList() {
	_pHead = _pTail = nullptr;
	_n = 0;
}

template <typename T>
SLList<T>::~SLList() {
	clear();
}

template <typename T>
void SLList<T>::push_back(const T& value) {
	Node* node = CreateNode(value);
	if (node == nullptr) {
		return;
	}
	if (_pHead == nullptr) {
		_pHead = _pTail = node;
		_n++;
		return;
	}
	_pTail->_pNext = node;
	_pTail = node;
	_n++;
}

template <typename T>
void SLList<T>::pop_back() {
	if (_pHead == nullptr) {
		return;
	}
	if (_pHead == _pTail) {
		delete _pHead;
		_pHead = _pTail = nullptr;
		_n = 0;
		return;
	}
	Node* prev = _pHead;
	while (prev->_pNext != _pTail) {
		prev = prev->_pNext;
	}
	delete _pTail;
	_pTail = prev;
	_pTail->_pNext = nullptr;
	_n--;
}

template <typename T>
void SLList<T>::insert(Iterator it, const T& value) {
	if (it.current_node == nullptr) {
		push_back(value);
		return;
	}
	Node* node = CreateNode(value);
	if (node == nullptr) {
		return;
	}
	if (it.current_node == _pHead) {
		node->_pNext = _pHead;
		_pHead = node;
		_n++;
		return;
	}
	Node* prev = _pHead;
	while (prev != nullptr && prev->_pNext != it.current_node) {
		prev = prev->_pNext;
	}
	if (prev != nullptr) {
		node->_pNext = it.current_node;
		prev->_pNext = node;
		_n++;
	} else {
		delete node;
	}
}

template <typename T>
void SLList<T>::clear() {
	while (_pHead != nullptr) {
		Node* temp = _pHead;
		_pHead = _pHead->_pNext;
		delete temp;
	}
	_pTail = nullptr;
	_n = 0;
}

template <typename T>
int SLList<T>::size() const {
	return _n;
}

template <typename T>
T& SLList<T>::operator[](int index) {
	if (index < 0 || index >= _n) {
		throw out_of_range("Index out of range");
	}
	Node* current = _pHead;
	for (int i = 0; i < index; ++i) {
		current = current->_pNext;
	}
	return current->_info;
}

template <typename T>
const T& SLList<T>::operator[](int index) const {
	if (index < 0 || index >= _n) {
		throw out_of_range("Index out of range");
	}
	Node* current = _pHead;
	for (int i = 0; i < index; ++i) {
		current = current->_pNext;
	}
	return current->_info;
}

template <typename T>
SLList<T>& SLList<T>::operator=(const SLList<T>& other) {
	if (this != &other) {
		clear();
		Node* current = other._pHead;
		while (current != nullptr) {
			push_back(current->_info);
			current = current->_pNext;
		}
	}
	return *this;
}

template <typename T>
class SLList<T>::Iterator {
public:
	using iterator_category = forward_iterator_tag;
	using difference_type = ptrdiff_t;
	using value_type = T;
	using pointer = T*;
	using reference = T&;

private:
	Node* current_node;

	Iterator(Node* node) : current_node(node) {}
	friend class SLList<T>;

public:
	Iterator() : current_node(nullptr) {}

	reference operator*() const {
		if (!current_node) {
			throw out_of_range("Dereferencing end() or null iterator");
		}
		return current_node->_info;
	}

	pointer operator->() const {
		if (!current_node) {
			throw out_of_range("Accessing member via end() or null iterator");
		}
		return &(current_node->_info);
	}

	Iterator& operator++() {
		if (current_node) {
			current_node = current_node->_pNext;
		} else {
			throw out_of_range("Incrementing end() or null iterator");
		}
		return *this;
	}

	Iterator operator++(int) {
		if (!current_node) {
			throw out_of_range("Incrementing end() or null iterator");
		}
		Iterator temp = *this;
		current_node = current_node->_pNext;
		return temp;
	}

	bool operator==(const Iterator& other) const {
		return current_node == other.current_node;
	}

	bool operator!=(const Iterator& other) const {
		return current_node != other.current_node;
	}
};

class SoNguyenLon {
private:
	SLList<unsigned int> lCS;
	void Pow10(const int& n);

public:
	SoNguyenLon(void);
	SoNguyenLon(const int& cs, const int& scs);
	SoNguyenLon(const unsigned long& n);
	SoNguyenLon(const SoNguyenLon& snl);
	SoNguyenLon(const char* s);
	~SoNguyenLon(void);

	int SoCS();
	SoNguyenLon operator+(SoNguyenLon snl);
	SoNguyenLon operator-(SoNguyenLon snl);
	SoNguyenLon operator*(SoNguyenLon snl);
	bool operator>(SoNguyenLon& snl);
	const SoNguyenLon& operator=(const SoNguyenLon& snl);
	SoNguyenLon& operator+=(SoNguyenLon snl);
	friend SoNguyenLon operator+(const unsigned long& n, const SoNguyenLon& snl);
	friend SoNguyenLon operator-(const unsigned long& n, const SoNguyenLon& snl);
	friend ostream& operator<<(ostream& os, const SoNguyenLon& snl);
};

void SoNguyenLon::Pow10(const int& n) {
	for (int i = 0; i < n; ++i) {
		lCS.insert(lCS.Begin(), 0);
	}
}

SoNguyenLon::SoNguyenLon(void) {
	lCS.push_back(0);
}

SoNguyenLon::SoNguyenLon(const int& cs, const int& scs) {
	int csR = cs;
	if (csR < 1) {
		csR = 1;
	}
	if (csR > 9) {
		csR = 9;
	}
	int soCS = abs(scs);
	if (soCS < 1) {
		soCS = 1;
	}
	for (int i = 0; i < soCS; ++i) {
		lCS.push_back(csR);
	}
}

SoNguyenLon::SoNguyenLon(const unsigned long& n) {
	unsigned long temp = n;
	while (temp > 0) {
		lCS.push_back(temp % 10);
		temp /= 10;
	}
}

SoNguyenLon::SoNguyenLon(const SoNguyenLon& snl) {
	lCS = snl.lCS;
}

SoNguyenLon::SoNguyenLon(const char* s) {
	int len = strlen(s);
	for (int i = len - 1; i >= 0; --i) {
		if (s[i] < '0' || s[i] > '9') {
			lCS.clear();
			lCS.push_back(0);
			return;
		}
		lCS.push_back(s[i] - '0');
	}
}

SoNguyenLon::~SoNguyenLon(void) {
	lCS.clear();
}

int SoNguyenLon::SoCS() {
	return lCS.size();
}

bool SoNguyenLon::operator>(SoNguyenLon& snl) {
	if (lCS.size() > snl.lCS.size()) {
		return true;
	}
	if (lCS.size() < snl.lCS.size()) {
		return false;
	}
	for (int i = lCS.size() - 1; i >= 0; --i) {
		if (lCS[i] == snl.lCS[i]) {
			continue;
		}
		if (lCS[i] > snl.lCS[i]) {
			return true;
		}
		return false;
	}
	return false;
}

const SoNguyenLon& SoNguyenLon::operator=(const SoNguyenLon& snl) {
	lCS = snl.lCS;
	return *this;
}

SoNguyenLon& SoNguyenLon::operator+=(SoNguyenLon snl) {
	*this = *this + snl;
	return *this;
}

SoNguyenLon SoNguyenLon::operator+(SoNguyenLon snl) {
	SoNguyenLon snlKQ;
	snlKQ.lCS.clear();
	SoNguyenLon* snlSCSMax = (SoCS() > snl.SoCS()) ? this : &snl;
	SoNguyenLon* snlSCSMin = (SoCS() < snl.SoCS()) ? this : &snl;

	int nho = 0, temp;
	for (int i = 0; i < snlSCSMin->SoCS(); ++i) {
		temp = lCS[i] + snl.lCS[i] + nho;
		snlKQ.lCS.push_back(temp % 10);
		nho = temp / 10;
	}
	for (int i = snlSCSMin->SoCS(); i < snlSCSMax->SoCS(); ++i) {
		temp = snlSCSMax->lCS[i] + nho;
		snlKQ.lCS.push_back(temp % 10);
		nho = temp / 10;
	}
	if (nho > 0) {
		snlKQ.lCS.push_back(1);
	}
	return snlKQ;
}

SoNguyenLon SoNguyenLon::operator-(SoNguyenLon snl) {
	SoNguyenLon snlKQ;
	snlKQ.lCS.clear();
	SoNguyenLon* snlSCSMax = (SoCS() > snl.SoCS()) ? this : &snl;
	SoNguyenLon* snlSCSMin = (SoCS() < snl.SoCS()) ? this : &snl;

	SoNguyenLon* snlSCSMax;
	SoNguyenLon* snlSCSMin;

	int nho = 0, temp;
	for (int i = 0; i < snlSCSMin->SoCS(); ++i) {
		temp = snlSCSMax->lCS[i] - snlSCSMin->lCS[i] - nho;
		if (temp < 0) {
			temp += 10;
			nho = 1;
		} else {
			nho = 0;
		}
		snlKQ.lCS.push_back(temp);
	}
	for (int i = snlSCSMin->SoCS(); i < snlSCSMax->SoCS(); ++i) {
		temp = snlSCSMax->lCS[i] - nho;
		if (temp < 0) {
			temp += 10;
			nho = 1;
		} else {
			nho = 0;
		}
		snlKQ.lCS.push_back(temp);
	}
	while (snlKQ.lCS.size() > 1 && snlKQ.lCS[snlKQ.lCS.size() - 1] == 0) {
		snlKQ.lCS.pop_back();
	}
	return snlKQ;
}

SoNguyenLon SoNguyenLon::operator*(SoNguyenLon snl) {
	SoNguyenLon snlKQ, *psnlTemp;
	SoNguyenLon* snlSCSMax = (SoCS() > snl.SoCS()) ? this : &snl;
	SoNguyenLon* snlSCSMin = (SoCS() < snl.SoCS()) ? this : &snl;
	int nho = 0, temp;
	for (int i = 0; i < snlSCSMin->SoCS(); ++i) {
		psnlTemp = new SoNguyenLon();
		psnlTemp->lCS.clear();
		nho = 0;
		for (int j = 0; j < snlSCSMax->SoCS(); ++j) {
			temp = snlSCSMin->lCS[i] * snlSCSMax->lCS[j] + nho;
			psnlTemp->lCS.push_back(temp % 10);
			nho = temp / 10;
		}
		if (nho > 0) {
			psnlTemp->lCS.push_back(nho);
		}
		psnlTemp->Pow10(i);
		snlKQ += *psnlTemp;
		delete psnlTemp;
	}
	return snlKQ;
}

SoNguyenLon operator+(const unsigned long& n, const SoNguyenLon& snl) {
	SoNguyenLon snlN(n);
	return snlN + snl;
}

SoNguyenLon operator-(const unsigned long& n, const SoNguyenLon& snl) {
	SoNguyenLon snlN(n);
	return snlN - snl;
}

ostream& operator<<(ostream& os, const SoNguyenLon& snl) {
	for (int i = snl.lCS.size() - 1; i >= 0; --i) {
		os << (int)snl.lCS[i];
	}
	return os;
}

int main() {
	const int iTest = 78912;
	SoNguyenLon snl1(123);
	SoNguyenLon snl2(40000);
	cout << snl1 << " + " << snl2 << " = ";
	cout << (snl1 + snl2) << endl;
	cout << snl1 << " * " << snl2 << " = ";
	cout << (snl1 * snl2) << endl;
	cout << snl1 << " - " << snl2 << " = ";
	cout << (snl1 - snl2) << endl;
	cout << snl2 << " - " << snl1 << " = ";
	cout << (snl2 - snl1) << endl;
	cout << iTest << " - " << snl2 << " = ";
	cout << (iTest - snl2) << endl;

	system("pause");
	return 0;
}