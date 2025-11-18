#include <iostream>
#include <string>

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
        Node* node = new Node{ value, nullptr };
        return node;
    };
public:
    class iterator;
    SLList();
    ~SLList();

    iterator Begin() {
        return iterator(_pHead);
    }

    iterator End() {
        return iterator(nullptr);
    }

    void push_back(const T&);
    void pop_back();
    void insert(iterator, const T&);
    void clear();
    int size() const;

    T& operator[](int index);
    const T& operator[](int index) const;

    SLList<T>& operator=(const SLList<T>& other);

public:
    class iterator {
    public:
        using iterator_category = forward_iterator_tag;
        using difference_type = ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

    private:
        Node* current_node;

        iterator(Node* node) : current_node(node) {}
        friend class SLList<T>;

    public:
        iterator() : current_node(nullptr) {}

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

        iterator& operator++() {
            if (current_node) {
                current_node = current_node->_pNext;
            }
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const iterator& other) const {
            return current_node == other.current_node;
        }

        bool operator!=(const iterator& other) const {
            return current_node != other.current_node;
        }
    };
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
    }
    else {
        _pTail->_pNext = node;
        _pTail = node;
    }
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
void SLList<T>::insert(iterator it, const T& value) {
    if (it.current_node == _pHead) {
        Node* node = CreateNode(value);
        if (!node) return;
        node->_pNext = _pHead;
        _pHead = node;
        if (_pTail == nullptr) {
            _pTail = node;
        }
        _n++;
        return;
    }
    
    if (it.current_node == nullptr) {
        push_back(value);
        return;
    }

    Node* prev = _pHead;
    while (prev != nullptr && prev->_pNext != it.current_node) {
        prev = prev->_pNext;
    }

    if (prev != nullptr) {
        Node* node = CreateNode(value);
        if (!node) return;
        node->_pNext = it.current_node;
        prev->_pNext = node;
        _n++;
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

class MyString {
private:
    char* _data;
    int _len;

    bool isDelimiter(char c, const SLList<char>& delimiters) const {
        for (int i = 0; i < delimiters.size(); ++i) {
            if (delimiters[i] == c) {
                return true;
            }
        }
        return false;
    }

public:
    MyString() {
        _len = 0;
        _data = new char[1];
        _data[0] = '\0';
    }

    MyString(const char* s) {
        if (!s) {
            _len = 0;
            _data = new char[1];
            _data[0] = '\0';
        } else {
            _len = strlen(s);
            _data = new char[_len + 1];
            strcpy(_data, s);
        }
    }

    MyString(const MyString& other) {
        _len = other._len;
        _data = new char[_len + 1];
        strcpy(_data, other._data);
    }

    ~MyString() {
        delete[] _data;
    }

    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] _data;
            _len = other._len;
            _data = new char[_len + 1];
            strcpy(_data, other._data);
        }
        return *this;
    }

    MyString& operator=(const char* s) {
        delete[] _data;
        if (!s) {
            _len = 0;
            _data = new char[1];
            _data[0] = '\0';
        } else {
            _len = strlen(s);
            _data = new char[_len + 1];
            strcpy(_data, s);
        }
        return *this;
    }

    int length() const {
        return _len;
    }

    void clear() {
        delete[] _data;
        _len = 0;
        _data = new char[1];
        _data[0] = '\0';
    }

    MyString operator+(const MyString& other) const {
        int newLen = _len + other._len;
        char* newData = new char[newLen + 1];
        
        strcpy(newData, _data);
        strcat(newData, other._data);

        MyString result(newData);
        delete[] newData;
        return result;
    }

    void operator+=(char c) {
        int newLen = _len + 1;
        char* newData = new char[newLen + 1];

        strcpy(newData, _data);
        newData[_len] = c;
        newData[newLen] = '\0';

        delete[] _data;
        _data = newData;
        _len = newLen;
    }

    friend ostream& operator<<(ostream& os, const MyString& ms) {
        os << ms._data;
        return os;
    }

    friend MyString operator+(const char* s, const MyString& ms) {
        int s_len = (s == nullptr) ? 0 : strlen(s);
        int newLen = s_len + ms._len;
        char* newData = new char[newLen + 1];

        if (s != nullptr) {
            strcpy(newData, s);
        } else {
            newData[0] = '\0';
        }
        strcat(newData, ms._data);

        MyString result(newData);
        delete[] newData;
        return result;
    }

    SLList<MyString> Split(const SLList<char>& delimiters, bool removeEmpty) const {
        SLList<MyString> result;
        MyString currentToken;

        for (int i = 0; i < _len; ++i) {
            char c = _data[i];

            if (isDelimiter(c, delimiters)) {
                if (!removeEmpty || currentToken.length() > 0) {
                    result.push_back(currentToken);
                }
                currentToken.clear();
            } else {
                currentToken += c;
            }
        }

        if (!removeEmpty || currentToken.length() > 0) {
            result.push_back(currentToken);
        }

        return result;
    }
};

int main(){
    MyString ms1("abcdsf");
    MyString ms2 = "____" + ms1;
    MyString ms3 = ms1 + ms2;
    cout << "ms1= " << ms1 << endl;
    cout << "ms2= " << ms2 << endl;
    cout << "ms3= " << ms3 << endl;
    MyString ms = "a,b,c;d.r;.,h;e,w__u,t.f;j_..";
    SLList<char> arrChar;
    arrChar.push_back(',');
    arrChar.push_back('.');
    arrChar.push_back(';');
    SLList<MyString> vMs = ms.Split(arrChar, false);
    cout << "Split: " << endl;
    for(SLList<MyString>::iterator itMS = vMs.Begin(); itMS != vMs.End(); itMS++){
        cout << *itMS << " ";
    }
    cout << endl << "size= " << vMs.size() << endl << endl;
    vMs = ms.Split(arrChar, true);
    cout << "Split co loai bo empty: " << endl;
    for(SLList<MyString>::iterator itMS = vMs.Begin(); itMS != vMs.End(); itMS++){
        cout << *itMS << " ";
    }
    cout << endl << "size= " << vMs.size() << endl;

    system("pause");
    return 0;
}