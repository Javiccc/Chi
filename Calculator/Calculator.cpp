#include"Calculator.h"

Calculator* Calculator::myInstance = NULL;

Calculator::Calculator()
{//Constructor
}

Calculator::~Calculator()
{//Destructor
}

Calculator* Calculator::getInstance()
{
	if (myInstance == NULL)
	{
		myInstance = new Calculator();
	}
	return myInstance;
}

void Calculator::destroyInstance()
{
	if (myInstance != NULL)
	{
		delete myInstance;
		myInstance = NULL;
	}
}
