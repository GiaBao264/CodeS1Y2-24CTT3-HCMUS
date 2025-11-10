#include <cstring>
#include <iostream>

using namespace std;

template <typename T>
class LinkedList;

template <typename T>
ostream& operator<<(ostream& os, const LinkedList<T>&);

template <typename T>
class LinkedList {
private:
	struct Node {
		T data;
		Node* next;
		Node(T val) : data(val), next(nullptr) {
		}
	};
	Node* head;
	Node* tail;

public:
	LinkedList<T>();
	~LinkedList<T>();
	void AddHead(T val);
	void AddTail(T val);
	void RemoveHead();
	void RemoveTail();
	T& operator[](int index);
	friend ostream& operator<< <T>(ostream& os, const LinkedList<T>&);
};

class CString {
private:
	char* str;

public:
	CString(const char* s = "");
	CString(const CString& other);
	~CString();
	CString& operator=(const CString& other);
	friend ostream& operator<<(ostream& os, const CString& cstr);
};

template <typename T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	tail = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
	Node* current = head;
	while (current != nullptr) {
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
}

template <typename T>
void LinkedList<T>::AddHead(T val) {
	Node* newNode = new Node(val);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	} else {
		newNode->next = head;
		head = newNode;
	}
}

template <typename T>
void LinkedList<T>::AddTail(T val) {
	Node* newNode = new Node(val);
	if (tail == nullptr) {
		head = newNode;
		tail = newNode;
	} else {
		tail->next = newNode;
		tail = newNode;
	}
}

template <typename T>
void LinkedList<T>::RemoveHead() {
	if (head == nullptr) return;
	Node* temp = head;
	head = head->next;
	delete temp;
	if (head == nullptr) tail = nullptr;
}

template <typename T>
void LinkedList<T>::RemoveTail() {
	if (tail == nullptr) return;
	if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}
	Node* current = head;
	while (current->next != tail) {
		current = current->next;
	}
	delete tail;
	tail = current;
	tail->next = nullptr;
}

template <typename T>
T& LinkedList<T>::operator[](int index) {
	Node* current = head;
	int count = 0;
	while (current != nullptr) {
		if (count == index) {
			return current->data;
		}
		current = current->next;
		count++;
	}
	throw out_of_range("Index out of range");
}

template <typename T>
ostream& operator<<(ostream& os, const LinkedList<T>& list) {
	typename LinkedList<T>::Node* current = list.head;
	while (current != nullptr) {
		os << current->data << " ";
		current = current->next;
	}
	return os;
}

CString::CString(const char* s) {
	if (s == nullptr) {
		str = new char[1];
		str[0] = '\0';
	} else {
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
}

CString::CString(const CString& other) {
	str = new char[strlen(other.str) + 1];
	strcpy(str, other.str);
}

CString::~CString() {
	delete[] str;
}

CString& CString::operator=(const CString& other) {
	if (this != &other) {
		delete[] str;
		str = new char[strlen(other.str) + 1];
		strcpy(str, other.str);
	}
	return *this;
}

ostream& operator<<(ostream& os, const CString& cstr) {
	os << cstr.str << ", ";
	return os;
}

int main() {
	srand((unsigned int)time(NULL));
	const int maxV = 1000, iTest = 2;
	int n = 5 + rand() % 10;
	LinkedList<int> ll;
	for (int i = 0; i < n; i++) {
		if (rand() % 2 == 0) {
			ll.AddHead(rand() % maxV);
		} else {
			ll.AddTail(rand() % maxV + maxV);
		}
	}
	cout << ll << endl;
	ll[iTest] = -123;
	ll[iTest + 2] = 9876;
	ll.RemoveHead();
	ll.RemoveTail();
	cout << "Sau thay doi: " << endl;
	cout << ll << endl;

	LinkedList<CString> llCS;
	llCS.AddTail(CString("cstring-1"));
	llCS.AddTail(CString("cstring-2"));
	llCS.AddTail(CString("cstring-3"));
	cout << "List CString: " << llCS << endl;
	llCS[iTest] = CString("new CString");
	cout << "List Cstring changed: " << endl << llCS << endl;
	system("pause");
	return 0;
}