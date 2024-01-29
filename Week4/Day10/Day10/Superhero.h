#pragma once
#include <string>
class Superhero
{
public:
	Superhero(std::string name, std::string secret, int age) : name_(name), secret_(secret), age_(age) {}

	std::string Name() { return name_; }
	std::string Secret() { return secret_; }
	int Age() { return age_; }

private:
	std::string name_, secret_;
	int age_;
};

