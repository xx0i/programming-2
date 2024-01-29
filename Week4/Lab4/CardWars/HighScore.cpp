#include "HighScore.h"
#include <sstream>
#include <fstream>
#include "Console.h"

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

//Deserialize method
void HighScore::Deserialize(std::string csvData, char delimiter) {
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