/*
Ho va ten : Tran Huynh Gia Bao
MSSV : 24120267
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class DongHoTT;

class ListDHTT
{
private:
    struct Node
    {
        string _info;
        Node *_pNext;
    };

    Node *_pHead, *_pTail;
    int _n;

    static Node *CreateNode(const string &value)
    {
        Node *node = new Node{value, nullptr};
        return node;
    };

public:
    using DongHoTT = ::DongHoTT;
    class Iterator;
    ListDHTT();
    ~ListDHTT();

    void AddTail(const int &);
    void AddTail(const string &);
    void AddTail(const DongHoTT &);

    Iterator begin() const
    {
        return Iterator(_pHead);
    }

    Iterator end() const
    {
        return Iterator(nullptr);
    }

    friend ostream &operator<<(ostream &os, const ListDHTT &ll)
    {
        ListDHTT::Node *node = ll._pHead;
        while (node != nullptr)
        {
            os << node->_info << ":";
            node = node->_pNext;
        }
        return os;
    }

public:
    class Iterator
    {
    public:
        using Iterator_category = forward_iterator_tag;
        using difference_type = ptrdiff_t;
        using value_type = DongHoTT;
        using pointer = DongHoTT *;
        using reference = DongHoTT;

    private:
        Node *current_node;

        Iterator(Node *node) : current_node(node) {}
        friend class ListDHTT;

    public:
        Iterator() : current_node(nullptr) {}

        value_type operator*() const
        {
            if (!current_node)
                throw out_of_range("Dereferencing end() or null Iterator");
            return DongHoTT(current_node->_info);
        }

        Iterator &operator++()
        {
            if (current_node)
            {
                current_node = current_node->_pNext;
            }
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const Iterator &other) const { return current_node == other.current_node; }
        bool operator!=(const Iterator &other) const { return !(*this == other); }
    };
};

class DongHoTT
{
    friend class ListDHTT;

private:
    int phut, giay, nghinGiay;
    void ChuanHoa();

public:
    DongHoTT();
    DongHoTT(int ks);
    DongHoTT(int s, int ks);
    DongHoTT(int min, int s, int ks);
    DongHoTT(const string &);

    DongHoTT operator+(const DongHoTT &a) const;
    DongHoTT &operator++();
    DongHoTT operator++(int);

    int GetPhut() const { return phut; }
    bool operator>(const DongHoTT &other) const;

    friend DongHoTT operator+(int giay, const DongHoTT &dhtt);
    friend ostream &operator<<(ostream &os, const DongHoTT &dhtt);
};

ListDHTT::ListDHTT()
{
    _pHead = _pTail = nullptr;
    _n = 0;
}

ListDHTT::~ListDHTT()
{
    while (_pHead != nullptr)
    {
        Node *temp = _pHead;
        _pHead = _pHead->_pNext;
        delete temp;
    }
    _pTail = nullptr;
    _n = 0;
}

void ListDHTT::AddTail(const int &value)
{
    DongHoTT dhtt(value);
    Node *node = CreateNode(to_string(dhtt.phut) + ":" + to_string(dhtt.giay) + ":" + to_string(dhtt.nghinGiay));
    if (node == nullptr)
    {
        return;
    }
    if (_pHead == nullptr)
    {
        _pHead = _pTail = node;
        _n++;
        return;
    }
    _pTail->_pNext = node;
    _pTail = node;
    _n++;
}

void ListDHTT::AddTail(const string &value)
{
    DongHoTT dhtt(value);
    Node *node = CreateNode(to_string(dhtt.phut) + ":" + to_string(dhtt.giay) + ":" + to_string(dhtt.nghinGiay));
    if (node == nullptr)
    {
        return;
    }
    if (_pHead == nullptr)
    {
        _pHead = _pTail = node;
        _n++;
        return;
    }
    _pTail->_pNext = node;
    _pTail = node;
    _n++;
}

void ListDHTT::AddTail(const DongHoTT &dhtt)
{
    Node *node = CreateNode(to_string(dhtt.phut) + ":" + to_string(dhtt.giay) + ":" + to_string(dhtt.nghinGiay));
    if (node == nullptr)
    {
        return;
    }
    if (_pHead == nullptr)
    {
        _pHead = _pTail = node;
        _n++;
        return;
    }
    _pTail->_pNext = node;
    _pTail = node;
    _n++;
}

void DongHoTT::ChuanHoa()
{
    phut = abs(phut);
    giay = abs(giay);
    nghinGiay = abs(nghinGiay);
    int nghinGiayDu = giay / 1000;
    giay = giay % 1000;
    giay += nghinGiayDu;
    int phutDu = giay / 60;
    giay = giay % 60;
    phut += phutDu;
}

DongHoTT::DongHoTT()
{
    phut = giay = nghinGiay = 0;
}

DongHoTT::DongHoTT(int ks)
{
    phut = giay = 0;
    nghinGiay = abs(ks);
    ChuanHoa();
}

DongHoTT::DongHoTT(int s, int ks)
{
    phut = 0;
    giay = abs(s);
    nghinGiay = abs(ks);
    ChuanHoa();
}

DongHoTT::DongHoTT(int min, int s, int ks)
{
    phut = abs(min);
    giay = abs(s);
    nghinGiay = abs(ks);
    ChuanHoa();
}

DongHoTT::DongHoTT(const string &str)
{
    size_t pos1 = str.find(":");
    size_t pos2 = str.find(":", pos1 + 1);
    phut = stoi(str.substr(0, pos1));
    giay = stoi(str.substr(pos1 + 1, pos2 - pos1 - 1));
    nghinGiay = stoi(str.substr(pos2 + 1));
    ChuanHoa();
}

DongHoTT DongHoTT::operator+(const DongHoTT &a) const
{
    DongHoTT temp;
    temp.phut = this->phut + a.phut;
    temp.giay = this->giay + a.giay;
    temp.nghinGiay = this->nghinGiay + a.nghinGiay;
    temp.ChuanHoa();
    return temp;
}

DongHoTT &DongHoTT::operator++()
{
    this->giay++;
    this->ChuanHoa();
    return *this;
}

DongHoTT DongHoTT::operator++(int)
{
    DongHoTT old = *this;
    this->giay++;
    this->ChuanHoa();
    return old;
}

bool DongHoTT::operator>(const DongHoTT &other) const
{
    if (phut != other.phut)
        return phut > other.phut;
    if (giay != other.giay)
        return giay > other.giay;
    return nghinGiay > other.nghinGiay;
}

DongHoTT operator+(int giay, const DongHoTT &dhtt)
{
    DongHoTT temp;
    temp.phut = dhtt.phut;
    temp.giay = dhtt.giay + giay;
    temp.nghinGiay = dhtt.nghinGiay;
    temp.ChuanHoa();
    return temp;
}

ostream &operator<<(ostream &os, const DongHoTT &dhtt)
{
    os << dhtt.phut << ":" << dhtt.giay << ":" << dhtt.nghinGiay;
    return os;
}

bool funcCountIf(ListDHTT::DongHoTT dhtt)
{
    return dhtt.GetPhut() >= 60;
}

int main()
{
    ListDHTT list;
    ListDHTT::DongHoTT dhtt1(20, 70, -2076), dhtt2("37:87:194"), dhtt3(200, 8060), dhtt4(40001);

    cout << "dhtt1: " << dhtt1 << endl;
    cout << "dhtt2: " << dhtt2 << endl;

    list.AddTail("1:2:3");

    list.AddTail(dhtt3 + dhtt2);
    list.AddTail(10000 + dhtt4);

    list.AddTail(10000 + ++dhtt1++ + dhtt2++);
    cout << "ListL\n"
         << list << endl;

    int nCI = count_if(list.begin(), list.end(), funcCountIf);
    cout << "So DHTT co phut >= 60: " << nCI << endl;

    ListDHTT::DongHoTT dhttMax = *list.begin();
    for_each(list.begin(), list.end(), [&dhttMax](ListDHTT::DongHoTT dhtt)
             {
        if(dhtt > dhttMax){
            dhttMax = dhtt;
        } });
    cout << "DHTT lon nhat: " << dhttMax << endl;

    return 0;
}
