#include"Matrix.h"

Matrix::Matrix(int r, int c)
{//Constructor
	this->row = r;
	this->column = c;
	this->matrixPtr = new double[r * c];
}

void Matrix::setMember()
{
	cout << "请逐个输入行列元素" << endl;
	for (int i = 0; i < row * column; i++)
		cin >> matrixPtr[i];
}

Matrix::Matrix(const Matrix& tmp)
{//Copy constructor
	this->row = tmp.row;
	this->column = tmp.column;

	//apply a new allocation and assign the matrix
	this->matrixPtr = new double[tmp.row * tmp.column];
	if (row * column != 0)
	{
		for (int i = 0; i < row * column; i++)
		{
			this->matrixPtr[i] = tmp.matrixPtr[i];
		}
	}
	else matrixPtr = NULL;
}

Matrix::~Matrix() 
{//destructor
	this->row = 0;
	this->column = 0;
	delete[] this->matrixPtr;
}


//Matrix Matrix::inverse(const Matrix &tmp){}

Matrix Matrix::operator=(const Matrix &tmp)
{//overloading assignment function
	if (this == &tmp)
		return *this;

	this->resize(tmp.row, tmp.column);
	if (row * column != 0)
	{
		for (int i = 0; i < row * column; i++)
		{
			this->matrixPtr[i] = tmp.matrixPtr[i];
		}
	}
	else matrixPtr = NULL;
	return *this;
}

void Matrix::resize(int a, int b)
{//to resize the matrix
	row = a;
	column = b;
	delete[]matrixPtr;
	matrixPtr = new double[row * column];
}

Matrix Matrix::operator+(const Matrix &a)
{
	Matrix tmp = *this;
	if (a.matrixPtr == NULL) return tmp;
	if ((a.row != tmp.row) || (a.column != tmp.column))
	{
		throw logic_error("They are not the same size.");
	}
	for (int i = 0; i < this->row * this->column; i++)
	{
		tmp.matrixPtr[i] = tmp.matrixPtr[i] + a.matrixPtr[i];
	}
	return tmp;
}

Matrix Matrix::operator-(const Matrix &a)
{
	Matrix tmp = *this;
	if (a.matrixPtr == NULL) return tmp;
	if ((a.row != tmp.row) || (a.column != tmp.column))
	{
		throw logic_error("They are not the same size.");
	}
	for (int i = 0; i < this->row * this->column; i++)
	{
		tmp.matrixPtr[i] = tmp.matrixPtr[i] - a.matrixPtr[i];
	}
	return tmp;
}

Matrix Matrix::operator*(const Matrix &a)
{
	Matrix *tmp = new Matrix(this->row, a.column);
	if (a.matrixPtr == NULL)
	{
		tmp = NULL;
		return *tmp;
	}
	if (a.row != tmp->column)
	{
		clog << "They cannot be producted." << endl;
	}

	for (int i = 0; i < tmp->getRow() * a.getColumn(); i++)
	{//对应行列元素相乘相加
		double number = 0;
		for (int j = 0; j < this->row; j++)
		{//counting the row
			number = 0;
			for (int k = 0; k < this->column; k++)
			{//counting the column
				number += this->matrixPtr[j * column + k] * a.matrixPtr[k + j * row];
			}
			tmp->matrixPtr[i] = number;
		}
	}
	return *tmp;
}

Matrix Matrix::operator*(double realNumber)
{
	Matrix tmp = *this;
	for (int i = 0; i < this->row * this->column; i++)
	{
		tmp.matrixPtr[i] = tmp.matrixPtr[i] * realNumber;
	}
	return tmp;
}

ostream &operator<<(ostream &output, const Matrix& tmp)
{
	if(tmp.matrixPtr != NULL)
		for (int i = 0; i < tmp.row; i++)
		{
			for (int j = 0; j < tmp.column; j++)
			{
				cout << tmp.matrixPtr[i * tmp.column + j] << " ";
			}
			cout << endl;
		}
	else cout << "It is a null matrix." << endl;
	return output;
}

void Matrix::print() const
{
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->column; j++)
		{
			cout << this->matrixPtr[i * this->column + j] << " ";
		}
		cout << endl;
	}
}