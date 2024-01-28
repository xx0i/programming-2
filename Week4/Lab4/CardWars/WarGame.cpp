#include "WarGame.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Input.h"


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
		std::string inputLine1; //variable for the first line (suits)
		std::vector<std::string> suits; //vector to hold the suits
		std::string suit;  //placeholder
		std::getline(inputFile, inputLine1);  //reads line 1
		while (std::getline(inputFile, suit, '?')) {
			suits.push_back(suit);
		}

		//GETTING THE FACES
		std::string inputLine2; //variable for the second line (faces)
		std::vector<std::string> faces; //vector to hold the faces
		std::string face;  //placeholder
		std::getline(inputFile, inputLine2);  //reads line 2
		while (std::getline(inputFile, face, '?')) {
			faces.push_back(face);
		}

		//making the card object and adding it to _cards
		for (int i = 0; i < suits.size(); i++) {  //loops through suits
			std::string currentSuit = suits[i];  //variable for current suits iteration
			for (int i = 0; i < faces.size(); i++) {  //loops through faces
				_cards.push_back(Card(currentSuit, faces[i]));  //creats a card object and adds it to the vector
			}

		}
	}
	inputFile.close();  //close the file
}