#include "HighScore.h"

//accessors
std::string HighScore::Name() {
	return name_;
}

int HighScore::Score() {
	return score_;
}

//mutators
void HighScore::Name(std::string newName) {
	name_ = newName;
}

void HighScore::Score(int newScore) {
	score_ = newScore;
}