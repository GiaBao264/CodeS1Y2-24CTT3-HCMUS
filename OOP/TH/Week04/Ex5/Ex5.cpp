#include <cstring>
#include <iostream>

using namespace std;

class LinkedList {
private:
	struct Node {
		long long data;
		Node* next;
		Node(long long val) : data(val), next(nullptr) {
		}
	};
	Node* head;
	Node* tail;
	friend class SoNguyenLon;

	void copyFrom(const LinkedList& other) {
		Node* current = other.head;
		while (current != nullptr) {
			AddTail(current->data);
			current = current->next;
		}
	}

	bool printRecursive(ostream& os, Node* node) const {
		if (node == nullptr) {
			return true;
		}
		bool isZero = printRecursive(os, node->next);
		if (isZero && node->data == 0) {
			return true;
		}
		os << node->data;
		return false;
	}

public:
	LinkedList();
	~LinkedList();

	void AddHead(long long val);
	void AddTail(long long val);
	LinkedList(const LinkedList& other);
	LinkedList& operator=(const LinkedList& other);
	friend ostream& operator<<(ostream& os, const LinkedList& list);
};

class SoNguyenLon {
private:
	LinkedList digits;

public:
	SoNguyenLon();
	SoNguyenLon(const char* s);
	SoNguyenLon(int n, int maxDigit);
	SoNguyenLon(const SoNguyenLon& other);
	SoNguyenLon(long long val);

	SoNguyenLon operator-(const SoNguyenLon& other) const;
	SoNguyenLon operator+(const SoNguyenLon& other) const;
	SoNguyenLon operator*(const SoNguyenLon& other) const;
	friend ostream& operator<<(ostream& os, const SoNguyenLon& snl);
};

LinkedList::LinkedList() {
	head = nullptr;
	tail = nullptr;
}

LinkedList::~LinkedList() {
	Node* current = head;
	while (current != nullptr) {
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
}

LinkedList::LinkedList(const LinkedList& other) {
	head = nullptr;
	tail = nullptr;
	copyFrom(other);
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
	if (this != &other) {
		Node* current = head;
		while (current != nullptr) {
			Node* nextNode = current->next;
			delete current;
			current = nextNode;
		}
		head = nullptr;
		tail = nullptr;
		copyFrom(other);
	}
	return *this;
}

void LinkedList::AddHead(long long val) {
	Node* newNode = new Node(val);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	} else {
		newNode->next = head;
		head = newNode;
	}
}

void LinkedList::AddTail(long long val) {
	Node* newNode = new Node(val);
	if (tail == nullptr) {
		head = newNode;
		tail = newNode;
	} else {
		tail->next = newNode;
		tail = newNode;
	}
}

ostream& operator<<(ostream& os, const LinkedList& list) {
	LinkedList::Node* current = list.head;
	if (current == nullptr || (current->data == 0 && current->next == nullptr)) {
		os << "0";
		return os;
	}
	list.printRecursive(os, list.head);
	return os;
}

SoNguyenLon::SoNguyenLon() {
	digits.AddHead(0);
}

SoNguyenLon::SoNguyenLon(const char* s) {
	int len = strlen(s);
	if (len == 0) {
		digits.AddHead(0);
		return;
	}
	for (int i = len - 1; i >= 0; i--) {
		digits.AddTail(s[i] - '0');
	}
}

SoNguyenLon::SoNguyenLon(int n, int maxDigit) {
	for (int i = 0; i < maxDigit; i++) {
		digits.AddTail(n);
	}
}

SoNguyenLon::SoNguyenLon(const SoNguyenLon& other) {
	digits = other.digits;
}

SoNguyenLon::SoNguyenLon(long long val) {
	if (val == 0) {
		digits.AddHead(0);
	} else {
		while (val > 0) {
			digits.AddTail(val % 10);
			val /= 10;
		}
	}
}

SoNguyenLon SoNguyenLon::operator-(const SoNguyenLon& other) const {
	SoNguyenLon result;
	result.digits.~LinkedList();
	result.digits.head = nullptr;
	result.digits.tail = nullptr;

	LinkedList::Node* currentA = this->digits.head;
	LinkedList::Node* currentB = other.digits.head;
	int borrow = 0;

	while (currentA != nullptr) {
		int digitA = currentA->data;
		int digitB = (currentB != nullptr) ? currentB->data : 0;

		int sub = digitA - digitB - borrow;
		if (sub < 0) {
			sub += 10;
			borrow = 1;
		} else {
			borrow = 0;
		}

		result.digits.AddTail(sub);

		currentA = currentA->next;
		if (currentB != nullptr) currentB = currentB->next;
	}

	return result;
}

SoNguyenLon operator-(long long val, const SoNguyenLon& snl) {
	SoNguyenLon temp(val);
	return temp - snl;
}

SoNguyenLon SoNguyenLon::operator+(const SoNguyenLon& other) const {
	SoNguyenLon result;
	result.digits.~LinkedList();
	result.digits.head = nullptr;
	result.digits.tail = nullptr;

	LinkedList::Node* currentA = this->digits.head;
	LinkedList::Node* currentB = other.digits.head;
	int carry = 0;

	while (currentA != nullptr || currentB != nullptr || carry > 0) {
		int digitA = (currentA != nullptr) ? currentA->data : 0;
		int digitB = (currentB != nullptr) ? currentB->data : 0;

		int sum = digitA + digitB + carry;
		result.digits.AddTail(sum % 10);
		carry = sum / 10;

		if (currentA != nullptr) currentA = currentA->next;
		if (currentB != nullptr) currentB = currentB->next;
	}

	return result;
}

SoNguyenLon operator+(long long val, const SoNguyenLon& snl) {
	SoNguyenLon temp(val);
	return temp + snl;
}

SoNguyenLon SoNguyenLon::operator*(const SoNguyenLon& other) const {
	SoNguyenLon result;
	LinkedList::Node* currentB = other.digits.head;
	int pos = 0;
	while (currentB != nullptr) {
		int digitB = currentB->data;
		SoNguyenLon tempProduct;
		tempProduct.digits.~LinkedList();
		tempProduct.digits.head = nullptr;
		tempProduct.digits.tail = nullptr;

		for (int i = 0; i < pos; i++) {
			tempProduct.digits.AddTail(0);
		}

		LinkedList::Node* currentA = this->digits.head;
		int carry = 0;
		while (currentA != nullptr || carry > 0) {
			int digitA = (currentA != nullptr) ? currentA->data : 0;

			int product = (digitA * digitB) + carry;
			tempProduct.digits.AddTail(product % 10);
			carry = product / 10;

			if (currentA != nullptr) currentA = currentA->next;
		}
		result = result + tempProduct;
		currentB = currentB->next;
		pos++;
	}
	return result;
}

ostream& operator<<(ostream& os, const SoNguyenLon& snl) {
	os << snl.digits;
	return os;
}

int main() {
	SoNguyenLon snl1;
	SoNguyenLon snl2("44667733");
	SoNguyenLon snl3(5, 9);
	SoNguyenLon snl4(7, 30);
	SoNguyenLon snl5 = snl3 - snl2;
	SoNguyenLon snl6 = 1098765432 - snl2;
	SoNguyenLon snl7 = snl4 - snl3 + 123456789;
	SoNguyenLon snl8 = snl2 * snl3;
	cout << snl1 << endl << snl2 << endl << snl3 << endl;
	cout << snl4 << endl << snl5 << endl << snl6 << endl;
	cout << snl7 << endl << snl8 << endl << endl;

	system("pause");
	return 0;
}