#pragma once
#include<iostream>
using namespace std;

class Matrix
{
private:
	int row;	//# of row
	int column;	//# of column
	double *matrixPtr;	//A point to the matrix
	void resize(int, int);

public:
	int getRow() const { return row; }
	int getColumn() const { return column; }
	Matrix() {}//default constructor
	Matrix(int r, int c);	//constructor
	Matrix(const Matrix& tmp);	//copy constructor
	~Matrix();	//destructor
	void setMember();	//set members to intialize
	void print() const;	//to show every element

	//compute the inverse
	//Matrix inverse(const Matrix &);
	//operator overloading
	Matrix operator=(const Matrix &);
	Matrix operator+(const Matrix &);
	Matrix operator-(const Matrix &);
	Matrix operator*(const Matrix &);
	Matrix operator*(double realNumber);
	friend ostream &operator<<(ostream &, const Matrix&);
};