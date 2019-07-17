#pragma once
#include<iostream>
using namespace std;

class HugeInt
{
	friend ostream &operator<< (ostream &, const HugeInt &);
public:
	static const int digits = 30;	//maximum of number
	short* getInteger();	//to get private value

	HugeInt(long = 0);	//change value to array
	HugeInt(const string &);	//change string to array
	~HugeInt();

	HugeInt operator+(const HugeInt &) const;
	HugeInt operator-(const HugeInt &) const;
	HugeInt operator*(const HugeInt &) const;
	
	int getLength( ) const;	//to calculate the length of the number

private:
	short integer[digits];
	HugeInt productHelper(const HugeInt& , const HugeInt& ) const;	//help to calculate the product
};
