#pragma once
#include "string"
#include <vector>
class HighScore
{
public:
	//accessors
	std::string Name()const;
	int Score()const;

	//mutators
	void Name(std::string& newName);
	void Score(int& newScore);

	//HighScore constructor
	HighScore(std::string const& csvData, char const& delimiter);

	//LoadHighScores method
	static std::vector<HighScore> LoadHighScores(std::string const& filePath);

	//ShowHighScores method
	static void ShowHighScores(std::vector<HighScore> const& highScores);

	//SaveHighScores method
	static void SaveHighScores(std::string const& filePath, std::vector<HighScore> const& highScores);

private:
	//member fields string name and int score
	std::string name_;
	int score_;

	//Deserialize method
	void Deserialize(std::string const& csvData, char const& delimiter);

	//serialize method
	void serialize(std::ofstream& file, char const& objectDelimiter)const;
};