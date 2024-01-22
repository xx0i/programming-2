#include "Person.h"
#include <iostream>
void Person::ItsMyBirthday(int age)
{
	age++;
	std::cout << "Happy Birthday! Today you are " << age << " years old!" << std::endl;
}
