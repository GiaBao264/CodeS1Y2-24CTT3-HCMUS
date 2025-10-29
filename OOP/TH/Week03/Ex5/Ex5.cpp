#include <iostream>
#include <cstring>

using namespace std;

class SoNguyenLon {
private:
	char* value;
public:
	SoNguyenLon();
	SoNguyenLon(const int&);
	SoNguyenLon(const char*);
	SoNguyenLon(const int&, const int&);
	SoNguyenLon operator+(const SoNguyenLon&) const;
	SoNguyenLon operator-(const SoNguyenLon&) const;
	~SoNguyenLon();
	
	friend SoNguyenLon operator+(const int&, const SoNguyenLon&);
	friend SoNguyenLon operator-(const int&, const SoNguyenLon&);
	friend ostream& operator<<(ostream&, const SoNguyenLon&);
};

SoNguyenLon::SoNguyenLon() {
	value = new char[2];
	value[0] = '0';
	value[1] = '\0';
}

SoNguyenLon::SoNguyenLon(const int& n) : SoNguyenLon() {
	int len = 0;
	int temp = n;
	if (temp == 0) {
		len = 1;
	} else {
		while (temp != 0) {
			len++;
			temp /= 10;
		}
	}
	value = new char[len + 1];
	value[len] = '\0';
	temp = n;
	for (int i = len - 1; i >= 0; i--) {
		value[i] = (temp % 10) + '0';
		temp /= 10;
	}
}

SoNguyenLon::SoNguyenLon(const char* val) {
	int len = strlen(val);
	value = new char[len + 1];
	strcpy(value, val);
}

SoNguyenLon::SoNguyenLon(const int& n, const int& m) {
	value = new char[m + 1];
	for (int i = 0; i < m; i++) {
		value[i] = n + '0';
	}
	value[m] = '\0';
}

SoNguyenLon SoNguyenLon::operator+(const SoNguyenLon& snl) const {
	int len1 = strlen(value);
	int len2 = strlen(snl.value);
	int maxLen = max(len1, len2);

	char* result = new char[maxLen + 2];
	result[maxLen + 1] = '\0';

	int i = len1 - 1;
	int j = len2 - 1;
	int k = maxLen;
	int carry = 0;
	while (k > 0) {
		int d1 = (i >= 0) ? (value[i] - '0') : 0;
		int d2 = (j >= 0) ? (snl.value[j] - '0') : 0;
		int sum = d1 + d2 + carry;
		result[k] = char((sum % 10) + '0');
		carry = sum / 10;
		i--; j--; k--;
	}
	if (carry > 0) {
		result[0] = char(carry + '0');
		return SoNguyenLon(result);
	} else {
		return SoNguyenLon(result + 1);
	}
}

SoNguyenLon SoNguyenLon::operator-(const SoNguyenLon& snl) const {
	int len1 = strlen(value);
	int len2 = strlen(snl.value);

	char* result = new char[len1 + 1];
	result[len1] = '\0';

	int i = len1 - 1;
	int j = len2 - 1;
	int k = len1 - 1;
	int borrow = 0;
	while (k >= 0) {
		int d1 = (i >= 0) ? (value[i] - '0') : 0;
		int d2 = (j >= 0) ? (snl.value[j] - '0') : 0;
		d1 -= borrow;
		if (d1 < d2) {
			d1 += 10;
			borrow = 1;
		} else {
			borrow = 0;
		}
		int diff = d1 - d2;
		result[k] = char(diff + '0');
		i--; j--; k--;
	}
	int start = 0;
	while (result[start] == '0' && start < len1 - 1) {
		start++;
	}
	return SoNguyenLon(result + start);
}