#pragma once
#include<iostream>
using namespace std;

class Polynomial
{
public:
	Polynomial(double = 0, double = 0, double = 0, double = 0, double = 0);
	~Polynomial();
	void setA0(double);
	void setA1(double);
	void setA2(double);
	void setA3(double);
	void setX(double);
	double getA0() const;
	double getA1() const;
	double getA2() const;
	double getA3() const;
	double getX() const;
	double computeValue();
	friend ostream &operator<<(ostream &, const Polynomial&);

private:
	double a0;
	double a1;
	double a2;
	double a3;
	double x;
};

