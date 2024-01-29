#include "HighScore.h"
#include <sstream>
#include <fstream>
#include "Console.h"
#include <iostream>
#include <iomanip>

//accessors
std::string HighScore::Name()const {
	return name_;
}

int HighScore::Score()const {
	return score_;
}

//mutators
void HighScore::Name(std::string& newName) {
	name_ = newName;
}

void HighScore::Score(int& newScore) {
	score_ = newScore;
}

//Deserialize method
void HighScore::Deserialize(std::string const& csvData, char const& delimiter) {
	{
		//data format: 1 high score object per line
		std::stringstream highScore(csvData);
		std::string scoreString;
		std::getline(highScore, name_, delimiter);
		std::getline(highScore, scoreString, delimiter);
		score_ = std::stoi(scoreString);
	}
}

//HighScore constructor
HighScore::HighScore(std::string const& csvData, char const& delimiter) {
	Deserialize(csvData, delimiter);  //calls the deserialize method
}

//LoadHighScores method
std::vector<HighScore> HighScore::LoadHighScores(std::string const& filePath) {
	std::vector<HighScore> highScores;  //vector to be returned
	std::ifstream inputFile(filePath);  //opens the file
	std::string line;
	//checks that the file is actually open (for security) and declares a string variable to hold the line
	if (inputFile.is_open()) {
		while (!inputFile.eof()) {  //loops until the end of the file
			std::getline(inputFile, line);

			std::string highScoreCSV;
			std::stringstream highScore(line);
			while (std::getline(highScore, highScoreCSV)) {
				//deserialize the high score and add to vector
				HighScore nextScore(highScoreCSV, '[');
				highScores.push_back(nextScore);
			}
		}
		inputFile.close();  //close the file
		return highScores;  //returns the high scores vector
	}
	else {
		Console::WriteLine("There was a problem loading the file. Please try again.");
	}
}

//ShowHighScores method
void HighScore::ShowHighScores(std::vector<HighScore> const& highScores) {
	//writes the scores with proper formatting
	Console::WriteLine("----HIGH SCORES----");
	for (auto& score : highScores) {
		std::cout << std::left << std::setw(17);
		Console::Write(score.name_);
		Console::WriteLine(std::to_string(score.score_), ConsoleColor::Yellow);
	}
}

//serialize method
void HighScore::serialize(std::ofstream& file, char const& objectDelimiter)const {
	file << name_ << objectDelimiter << score_;
}

//SaveHighScores method
void HighScore::SaveHighScores(std::string const& filePath, std::vector<HighScore>const& highScores) {
	char dataDelim = '|';//separates high scores
	char objDelim = ',';//separates the name and score inside the high score

	std::ofstream file(filePath);  //opens the file
	if (file.is_open()) {
		bool isFirst = true;
		for (auto& score : highScores)  //for each item in the passed vector
		{
			if (!isFirst)  //checks if the it is the first item
				file << dataDelim;
			score.serialize(file, objDelim);
			isFirst = false;
		}
		file.close();  //closes the file
	}
}