#include "Calculator.h"

int Calculator::minus(int number1, int number2)
{
	return number1 - number2;
}

double Calculator::mult(double num, double factor)
{
	return num * factor;
}

bool Calculator::isEven(int number){
	bool result = false;
	
	if (number % 2 == 0) {
		result = true;
	}
	else {
		result = false;
	}
	return result;
}