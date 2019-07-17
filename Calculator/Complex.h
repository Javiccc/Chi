#pragma once
#include<iostream>
using namespace std;

class Complex
{
public:
	Complex();
	Complex(double, double);
	~Complex();

	friend ostream &operator<< (ostream &, const Complex &);	//overloading output operator

	//overloading operators
	Complex operator+(const Complex&) const;
	Complex operator-(const Complex&) const;
	Complex operator*(const Complex&) const;
	Complex operator/(const Complex&) const;

	double model();	//������ģ
private:
	double real;
	double img;
};

