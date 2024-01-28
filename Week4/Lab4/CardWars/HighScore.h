#pragma once
#include "string"
class HighScore
{
public:
	//accessors
	std::string Name();
	int Score();

	//mutators
	void Name(std::string newName);
	void Score(int newScore);

private:
	//member fields string name and int score
	std::string name_;
	int score_;

};

