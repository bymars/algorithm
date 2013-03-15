#ifndef BIGINT_H
#define BIGINT_H
#include <iostream>
class BigInt {

friend const BigInt& operator+(const BigInt&, const BigInt&);
public:
	BigInt(const std::string&);
private:
	int value[20];
	int pointer;
	int length;
};
#endif
