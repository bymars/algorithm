#include <iostream>
#include <sstream>
#include <string>
#include "bigint.h"
using namespace std;

const BigInt& operator+ (const BigInt& l, const BigInt& r) {
	int i, up = 0;
	BigInt big_int("0");
	for (i = 0; i < l.length && i < r.length; i++) {
		int value = l.value[i] + r.value[i] + up;
		up = value / 1000000000;
		big_int.value[i] = value % 1000000000;
	}
}

BigInt::BigInt(const string& s) : length(0), pointer(0) {

	string::const_iterator begin = s.begin();
	string::const_iterator end = s.end() - 1;
	if (*begin == '-' || *begin == '+') {
		begin++;
	}
	while (*begin == '0') begin++;

	int p = s.find('.');
	pointer = s.size() - p - 1;
	if (p == s.size)
	if (p != -1) {
		while (*end == '0') {
			end--;
			pointer--;
		}
	}

	string ss(begin, end + 1);
	cout << ss << endl;
	ss.erase(ss.size() - pointer - 1, 1);
	cout << ss << " " << pointer << endl;
}
int main(int argc, char** argv) {
	BigInt("000000010000200000000300000000.400000000");
}
