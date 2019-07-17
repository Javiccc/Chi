#include"HugeInt.h"
#include<cmath>
#include<algorithm>

//overloading output operator
ostream &operator<< (ostream &output, const HugeInt &num)
{
	int i;
	for (i = 0; (num.integer[i] == 0) && (i <= HugeInt::digits); i++)
	{ }	//skip leading zeros
	if (i == HugeInt::digits)
		output << 0;
	else
	{//print the number
		for (; i < HugeInt::digits; ++i)
			output << num.integer[i];
	}
	return output;
}

short* HugeInt::getInteger()
{
	return integer;
}

HugeInt::HugeInt(long value)
{
	//initializing with zeros
	for (int i = 0; i < digits; ++i)
		integer[i] = 0;

	//change digits to array
	for (int j = digits - 1; value != 0 && j >= 0; j--)
	{
		integer[j] = value % 10;
		value /= 10;
	}
}

HugeInt::HugeInt(const string &number)
{
	//initializing with zeros
	for (int i = 0; i < digits; ++i)
		integer[i] = 0;

	//change into array
	int length = number.size();
	for (int j = digits - length, k = 0; j < digits; ++j, ++k)
	{
		if (isdigit(number[k]))
			integer[j] = number[k] - '0';	//char's ASCII substract 0's ASCII
	}
}


HugeInt::~HugeInt()
{
	//Destructor
}

HugeInt HugeInt::operator+(const HugeInt &op2) const
{//overloading +operator
	HugeInt temp;	//temporary value
	int carry = 0;	//carry tag
	
	for (int i = digits - 1; i >= 0; i--)
	{
		temp.integer[i] = integer[i] + op2.integer[i] + carry;
		//detect if it is carried
		if (temp.integer[i] > 9)
		{
			temp.integer[i] %= 10;
			carry = 1;
		}
		else
			carry = 0;
	}
	return temp;
}

HugeInt HugeInt::operator-(const HugeInt &op2) const
{
	HugeInt temp;
	int borrow = 0;

	for (int i = digits - 1; i >= 0; i--)
	{
		temp.integer[i] = integer[i] - op2.integer[i] - borrow;
		//detect if it borrow a bit
		if (temp.integer[i] < 0)
		{
			temp.integer[i] += 10;
			borrow = 1;
		}
		else
		{
			borrow = 0;
		}
	}
	return temp;
}

HugeInt HugeInt::operator*(const HugeInt &op2) const
{// the method to calculate product is encapsulated in the productHelper
	return productHelper(*this, op2);
}

HugeInt HugeInt::productHelper(const HugeInt& op1, const HugeInt& op2) const
{
	HugeInt temp;
	int op1Length = getLength();
	int op2Length = op2.getLength();
	int totalLength = op1Length + op2Length;
	if (totalLength > 30) cerr << "The product is out of range." << endl;
	//用分治法来进行计算，提高程序的运行效率
	int halfN = max(op1Length, op2Length) / 2;
	//something
	return temp;
}

int HugeInt::getLength( ) const
{
	int i;
	int length = 0;
	for(i = 0; (integer[i] == 0) && (i <= HugeInt::digits - 1); i++)
	{ }	//skip leading zeros
	if (i == HugeInt::digits)
	{
		return length;
	}
	for (i = 0; i <= HugeInt::digits - 1; i++)
	{//detect the length
		length++;
	}
	return length;
}