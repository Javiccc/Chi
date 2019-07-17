#include"Complex.h"

Complex::Complex() {}	// default constructor

Complex::Complex(double a , double b )
{
	real = a; 
	img = b;
}

Complex::~Complex()
{
}

ostream &operator<< (ostream & output, const Complex & complex)
{
	if (complex.img >= 0)
	{
		output << complex.real << " + " << complex.img << "i ";
	}
	if (complex.img < 0)
	{
		output << complex.real << " - " << abs(complex.img) << "i ";
	}
	return output;
}

Complex Complex::operator+(const Complex& op2) const
{
	Complex temp = Complex();
	temp.real = real + op2.real;
	temp.img = img + op2.img;
	return temp;
}

Complex Complex::operator-(const Complex& op2) const
{
	Complex temp = Complex();
	temp.real = real - op2.real;
	temp.img = img - op2.img;
	return temp;
}

Complex Complex::operator*(const Complex& op2) const
{
	Complex temp = Complex();
	temp.real = real * op2.real - img * op2.img;
	temp.img = real * op2.img + op2.real * img;
	return temp;
}

Complex Complex::operator/(const Complex& op2) const
{
	Complex temp = Complex();
	Complex helpnum = Complex();
	helpnum.real = op2.real;
	helpnum.img = -op2.img;

	temp = (*this) * helpnum;
	double factor;	//compute the ·ÖÄ¸
	factor = pow(op2.real, 2) + pow(op2.img, 2);
	temp.real /= factor;
	temp.img /= factor;
	return temp;
}

double Complex::model()
{
	double temp = 0;
	temp = sqrt(pow(real, 2) + pow(img, 2));
	return temp;
}