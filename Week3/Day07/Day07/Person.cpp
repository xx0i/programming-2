#include "Person.h"
#include <iostream>
void Person::ItsMyBirthday(int age)
{
	age++;
	std::cout << "Happy Birthday! Today you are " << age << " years old!" << std::endl;
}
//accessors
int Person::Age() {
	return age_;
}
std::string Person::Name() {
	return name_;
}

//mutators
void Person::Age(int age) {
	if (age > 0) {
		age_ = age;
	}
}
void Person::Name(std::string name) {
	if (name.size() > 0) {
		name_ = name;
	}
}