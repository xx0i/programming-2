#include "WarGame.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Input.h"
#include "Console.h"


std::vector<Card> WarGame::_cards;

WarGame::WarGame(std::string cardsFile)
{
}

void WarGame::shuffle()
{
	int ndx1, ndx2;
	srand((unsigned int)time(NULL));

	for (size_t i = 0; i < 52; i++)
	{
		ndx1 = rand() % 52;
		ndx2 = rand() % 52;

		Card temp = _cards[ndx1];
		_cards[ndx1] = _cards[ndx2];
		_cards[ndx2] = temp;
	}
}

//LoadCards method
void WarGame::LoadCards(std::string const& filePath) {
	std::ifstream inputFile(filePath);  //opens the file
	//checks that the file is actually open (for security) and declares a string variable to hold the line
	if (inputFile.is_open()) {

		//GETTING THE SUITS
		std::string inputLine; //variable for the line
		std::vector<std::string> suits; //vector to hold the suits, after split
		std::string index;  //placeholder
		while (std::getline(inputFile, inputLine)) {  //reads the file lines
			std::stringstream line(inputLine);
			while (std::getline(line, index, '?')) {
				suits.push_back(index);
			}
		}
		//separating the data into two vectors
		std::vector<std::string> faces; //vector to hold the faces
		std::move(suits.begin()+4, suits.end(), std::back_inserter(faces));  //moves the faces from suits vector to faces vector
		suits.erase(suits.begin() + 4, suits.end());  //erases the faces from suits vector

		//making the card object and adding it to _cards
		for (int i = 0; i < suits.size(); i++) {  //loops through suits
			std::string currentSuit = suits[i];  //variable for current suits iteration
			for (int i = 0; i < faces.size(); i++) {  //loops through faces
				_cards.push_back(Card(currentSuit, faces[i]));  //creates a card object and adds it to the vector
			}

		}
	}
	inputFile.close();  //close the file
}

//ShowCards method
void WarGame::ShowCards() {
	LoadCards("cards.csv");  //calls LoadCards passing it cards.csv
	//loops through _cards and prints each object and moves to the next line
	for (auto& card : _cards) {
		card.print();
		Console::Write("\n");
	}
}