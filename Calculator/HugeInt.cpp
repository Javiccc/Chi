#include"HugeInt.h"


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
{
	HugeInt temp;
	int carry = 0;

	for (int i = digits - 1; i >= 0; i--)
	{
		temp.integer[i] = integer[i] * op2.integer[i] + carry;
		//detect the carry
		if (temp.integer[i] > 9)
		{
			carry = temp.integer[i] / 10;
			temp.integer[i] %= 10;
		}
		else
			carry = 0;

	}
	return temp;
}
