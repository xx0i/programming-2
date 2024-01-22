#pragma once
#include <string>
class Person
{
	int age_;
	std::string name_;

public:
	void ItsMyBirthday(int age);

	//accessors
	int Age();
	std::string Name();

	//mutators
	void Age(int age);
	void Name(std::string name);
};

