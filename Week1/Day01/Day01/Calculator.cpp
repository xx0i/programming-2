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

float Calculator::average(std::vector<float>nums) {
	float avg = 0;
	for (int i = 0; i < nums.size(); i++) {
		avg += nums[i];
	}
	avg /= nums.size();
	return avg;
}