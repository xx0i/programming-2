#pragma once
#include <string>
class Pickaxe
{
public:
	//swing will tell you what object you hit
	std::string Swing(); //DECLARE the method

	//accessors provide access to the data
	std::string Label() { return label_;}

	//mutators allow you to modify the data
	void Label(std::string label) {
		if (label.size() > 0 && label != "steev") {
			label_ = label;
		}
	}

private:
	std::string label_;

public:
};

