#include <iostream>

using namespace std;

template <typename T>
class SLList {
private:
	struct Node {
		T _info;
		Node* _pNext;
	};

	Node *_pHead, *_pTail;
	int _n;

	static Node* CreateNode(const T& value) {
		Node* node = new Node{value, nullptr};
		return node;
	};

public:
	class Iterator;
	SLList();
	~SLList();

	void AddHead(const T&);
	void AddTail(const T&);
	void RemoveHead();
	void RemoveTail();
	void Clear();

	Iterator Begin() {
		return Iterator(nullptr);
	}

	Iterator End() {
		return Iterator(nullptr);
	}

	template <typename T>
	friend ostream& operator<<(ostream& os, const SLList<T>& ll) {
		SLList<T>::Node* node = ll._pHead;
		while (node != nullptr) {
			os << node->_info << ", ";
			node = node->_pNext;
		}
		return os;
	}
};

template <typename T>
SLList<T>::SLList() {
	_pHead = _pTail = nullptr;
	_n = 0;
}

template <typename T>
SLList<T>::~SLList() {
	Clear();
}

template <typename T>
void SLList<T>::Clear() {
	while (_pHead != nullptr) {
		RemoveHead();
	}
}

template <typename T>
void SLList<T>::AddTail(const T& value) {
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
void SLList<T>::AddHead(const T& value) {
	Node* node = CreateNode(value);
	if (node == nullptr) {
		return;
	}
	if (_pHead == nullptr) {
		_pHead = _pTail = node;
		_n++;
		return;
	}
	node->_pNext = _pHead;
	_pHead = node;
	_n++;
}

template <typename T>
void SLList<T>::RemoveHead() {
	if (_pHead == nullptr) {
		return;
	}
	Node* temp = _pHead;
	_pHead = _pHead->_pNext;
	delete temp;
	_n--;
	if (_pHead == nullptr) {
		_pTail = nullptr;
	}
}

template <typename T>
void SLList<T>::RemoveTail() {
	if (_pHead == nullptr) {
		return;
	}
	if (_pHead == _pTail) {
		delete _pHead;
		_pHead = _pTail = nullptr;
		_n--;
		return;
	}
	Node* current = _pHead;
	while (current->_pNext != _pTail) {
		current = current->_pNext;
	}
	delete _pTail;
	_pTail = current;
	_pTail->_pNext = nullptr;
	_n--;
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

#include <algorithm>

void fnAction(int val) {
    cout << val << ", ";
}

void fnAction2(int& val) {
    val *= 2;
}

bool fnPredict(int val) {
    const int threshold = 3;
    return val > threshold;
}

int main(){
    SLList<int> l;
    l.AddTail(1);
    l.AddTail(1);
    l.AddTail(0);
    l.AddTail(4);
    l.AddTail(2);
    l.AddTail(5);

    for(SLList<int>::Iterator it = l.Begin(); it != l.End(); ++it){
        cout << *it << ", ";
    }
    cout << endl;
    for_each(l.Begin(), l.End(), fnAction2);
    for_each(l.Begin(), l.End(), fnAction);
    cout << endl;

    replace_if(l.Begin(), l.End(), fnPredict, 100);
    cout << l << endl;

    fill(l.Begin(), l.End(), 123);
    cout << l << endl;
    l.Clear();

    system("pause");
    return 0;
}