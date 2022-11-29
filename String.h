#pragma once
#include <iostream>
using namespace std;


class String {
private:
	char* str;
	int L;
	int len(const char* str) {
		int i = 0;
		while (str[i] != '\0') {
			i++;
		}
		return i;
	}

public:

	String() { this->str = nullptr; L = 0; }

	String(const char* str) {
		L = len(str);
		this->str = new char[L + 1];
		for (int i = 0; i < L; i++) {
			this->str[i] = str[i];
		}
		this->str[L] = '\0';
	}

	String(char* str) {
		L = len(str);
		this->str = new char[L + 1];
		for (int i = 0; i < L; i++) {
			this->str[i] = str[i];
		}
		this->str[L] = '\0';
	}

	int length() {
		return L;
	}

	char operator[](int i) {
		return this->str[i];
	}

	void operator=(String obj) {
		if (str != nullptr) { delete[] str; }
		L = obj.length();
		str = new char[L + 1];
		for (int i = 0; i < L; i++) {
			str[i] = obj[i];
		}
		str[L] = '\0';
	}

	void operator=(const char* obj) {
		if (str != nullptr) { delete[] str; }
		L = len(obj);
		str = new char[L + 1];
		for (int i = 0; i < L; i++) {
			str[i] = obj[i];
		}
		str[L] = '\0';
	}

	char* getstr() {
		return this->str;
	}

	long double to() {
		int i;
		long double t = 0, s = 0.1, flag = 0;
		int begin = 0, sign = 1;
		if (str[begin] == '-') { sign *= -1; begin++; }
		for (int i = begin; i < L; i++) {
			if (str[i] != '.') {
				t = t * 10 + (str[i] - '0');
			}
			else { flag = 1; }
			if (flag == 1) { s *= 10; }
		}

		if (flag == 1) { return t / s * sign; }
		return t * sign;
	}

	String operator+(String obj) {
		char* string = new char[L + obj.length() + 1];
		int i;
		for (i = 0; i < L; i++) {
			string[i] = str[i];
		}
		for (i = L; i < L + obj.length(); i++) {
			string[i] = obj[i - L];
		}
		string[L + obj.length()] = '\0';
		return String(string);
	}

	String operator+(const char* obj) {
		char* string = new char[L + len(obj) + 1];
		int i;
		for (i = 0; i < L; i++) {
			string[i] = str[i];
		}
		for (i = L; i < L + len(obj); i++) {
			string[i] = obj[i - L];
		}
		string[L + len(obj)] = '\0';
		return String(string);
	}

	void operator+=(String obj) {
		char* string = new char[L + obj.length() + 1];
		int i;
		for (i = 0; i < L; i++) {
			string[i] = str[i];
		}
		for (i = L; i < L + obj.length(); i++) {
			string[i] = obj[i - L];
		}
		string[L + obj.length()] = '\0';
		if (this->str != nullptr) { delete this->str; }
		L += obj.length();
		this->str = string;
	}

	void operator+=(const char* obj) {
		char* string = new char[L + len(obj) + 1];
		int i;
		for (i = 0; i < L; i++) {
			string[i] = str[i];
		}
		for (i = L; i < L + len(obj); i++) {
			string[i] = obj[i - L];
		}
		string[L + len(obj)] = '\0';
		if (this->str != nullptr) { delete this->str; }
		L += len(obj);
		this->str = string;
	}

	void operator+=(char obj) {
		char* string = new char[L + 2];
		int i;
		for (i = 0; i < L; i++) {
			string[i] = str[i];
		}

		string[L] = obj;
		string[L + 1] = '\0';
		if (this->str != nullptr) { delete this->str; }
		L += 1;
		this->str = string;
	}

	String operator-(int j) {
		if (L - j > 0) {
			char* string = new char[L - j + 1];
			int i;
			for (i = 0; i < L - j; i++) {
				string[i] = str[i];
			}
			string[L - j] = '\0';
			return String(string);
		}
		return String("");
	}

	void operator-=(int j) {
		if (L - j > 0) {
			char* string = new char[L - j + 1];
			int i;
			for (i = 0; i < L - j; i++) {
				string[i] = str[i];
			}
			string[L - j] = '\0';
			if (this->str != nullptr) { delete this->str; }
			L -= j;
			this->str = string;
		}
		else { str = new char[0]; L = 0; }
	}

	String operator*(int k) {
		char* string = new char[L * k + 1];
		for (int i = 0; i < L; i++) {
			for (int j = i; j < k * L; j += L) {
				string[j] = str[i];
			}
		}
		string[L * k] = '\0';
		return String(string);
	}

	bool operator==(String obj) {
		bool rezult = true;
		if (this->L == obj.length()) {
			int i;
			for (i = 0; i < this->L; i++) {
				if (str[i] != obj[i]) {
					rezult = false;
				}
			}
		}
		else { rezult = false; }
		return rezult;
	}

	bool operator==(const char* obj) {
		bool rezult = true;
		if (this->L == len(obj)) {
			int i;
			for (i = 0; i < this->L; i++) {
				if (str[i] != obj[i]) {
					rezult = false;
				}
			}
		}
		else { rezult = false; }
		return rezult;
	}

	friend ostream& operator<<(ostream& out, String obj) {
		for (int i = 0; i < obj.length(); i++) {
			out << obj[i];
		}
		return out;
	}

	friend istream& operator>>(istream& in, String& obj) {
		char* buff = new char[99999]{ '\0' };
		in >> buff;
		obj.L = obj.len(buff);
		if (obj.str != nullptr) { delete[] obj.str; }
		obj.str = new char[obj.L + 1];
		for (int i = 0; i < obj.L; i++) {
			obj.str[i] = buff[i];
		}
		obj.str[obj.L] = '\0';
		delete[] buff;
		return in;
	}

};


String to_String(double a, int accuracy) {
	char str[100];
	int i = 0, sign = 0;

	for (int j = 0; j < accuracy; j++) a *= 10;

	if (a < 0) { sign = -1; a *= sign; }
	long long b = (long long)a;

	while (b > 0 || i < accuracy) {
		str[i++] = (b % 10 + '0');
		b /= 10;
		if (i == accuracy) { str[i++] = '.'; }
	}
	if (i == accuracy + 1) str[i++] = '0';
	if (sign == -1) str[i++] = '-';

	char* str2 = new char[i + 1];

	for (int j = i - 1; j >= 0; j--) {
		str2[i - j - 1] = str[j];
	}
	str2[i] = '\0';
	return String(str2);
}