#pragma once
#include<iostream>
using namespace std;
//Using singleton
class Calculator
{
public:
	//Singleton
	static Calculator *getInstance();
	static void destroyInstance();
	void compute();	//to encapsulate compute manipulation

private:
	static Calculator* myInstance;

	Calculator();
	Calculator(const Calculator&);
	Calculator operator=(const Calculator &){ }	//to protect assignment
	~Calculator();
};
