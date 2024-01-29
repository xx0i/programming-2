#pragma once
#include "string"
#include <vector>
class HighScore
{
public:
	//accessors
	std::string Name();
	int Score();

	//mutators
	void Name(std::string newName);
	void Score(int newScore);

	//HighScore constructor
	HighScore(std::string const& csvData, char const& delimiter);

	//LoadHighScores method
	static std::vector<HighScore> LoadHighScores(std::string const& filePath);

private:
	//member fields string name and int score
	std::string name_;
	int score_;
	//Deserialize method
	void Deserialize(std::string csvData, char delimiter);
};