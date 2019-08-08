#include"Polynomial.h"

void Polynomial::setA0(double p0)
{
	a0 = p0;
}

void Polynomial::setA1(double p1)
{
	a1 = p1;
}

void Polynomial::setA2(double p2)
{
	a2 = p2;
}

void Polynomial::setA3(double p3)
{
	a3 = p3;
}

void Polynomial::setX(double tempx)
{
	x = tempx;
}

double Polynomial::getA0() const
{
	return a0;
}

double Polynomial::getA1() const
{
	return a1;
}

double Polynomial::getA2() const
{
	return a2;
}

double Polynomial::getA3() const
{
	return a3;
}


Polynomial::Polynomial(double p0, double p1, double p2, double p3, double x)
{
	a0 = p0;
	a1 = p1; 
	a2 = p2;
	a3 = p3;
}

Polynomial::~Polynomial()
{
}

double Polynomial::computeValue()
{
	double result;
	result = getA0() + getA1() * x + getA2() * x*x + getA3() * x*x*x;
	return result;
}


ostream &operator<<(ostream &output, const Polynomial & para)
{
	output << "f(x) = " << para.getA0() << " + " << para.getA1() << " * x + "
		<< para.getA2() << " * x*x + " << para.getA3() << " * x*x*x ";
	return output;
}