#include"Calculator.h"

int main()
{
	Calculator *myCalculator = Calculator::getInstance();
	myCalculator->compute();
	return 0;
}