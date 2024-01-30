#include "WarGame.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Input.h"
#include "Console.h"
#include "player.h"


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
		std::move(suits.begin() + 4, suits.end(), std::back_inserter(faces));  //moves the faces from suits vector to faces vector
		suits.erase(suits.begin() + 4, suits.end());  //erases the faces from suits vector

		//making the card object and adding it to _cards
		for (int i = 0; i < suits.size(); i++) {  //loops through suits
			std::string currentSuit = suits[i];  //variable for current suits iteration
			for (int i = 0; i < faces.size(); i++) {  //loops through faces
				_cards.push_back(Card(currentSuit, faces[i]));  //creates a card object and adds it to the vector
			}

		}
		inputFile.close();  //close the file
	}
	else {
		Console::WriteLine("There was a problem loading the file. Please try again.");
	}
}

//ShowCards method
void WarGame::ShowCards() {
	//loops through _cards and prints each object and moves to the next line
	for (auto& card : _cards) {
		card.print();
		Console::Write("\n");
	}
}

//PlayGame
void WarGame::PlayGame(std::string const& name, std::vector<HighScore>& highScore, std::string const& file) {
	shuffle();

	//initializes the npc and player
	Player npc;
	npc.Name("NPC");
	Player player;
	player.Name(name);

	//halfs the _cards vector and gives half to the npc and the player
	std::size_t const half_size = _cards.size() / 2;
	std::vector<Card> half1(_cards.begin(), _cards.begin() + half_size);
	std::vector<Card> half2(_cards.begin() + half_size, _cards.end());

	for (int i = 0; i < half1.size(); i++) {
		npc.PushCard(half1[i]);
	}
	for (int i = 0; i < half2.size(); i++) {
		player.PushCard(half2[i]);
	}

	//loop for playing each round in a game
	std::vector<Card>unclaimedPile;

	while (player.HasCards()) {
		unclaimedPile.push_back(player.PopCard());
		unclaimedPile.push_back(npc.PopCard());
		int result = unclaimedPile[0].compare(unclaimedPile[1]);
		if (result == -1) {
			npc.WonCards(unclaimedPile);
			unclaimedPile[1].print();
			std::cout << std::left << std::setw(2);
			Console::Write(" vs. ");
			unclaimedPile[0].print();
			std::cout << std::left << std::setw(2);
			Console::WriteLine("  " + npc.Name() + " wins!");
			unclaimedPile.clear();
		}
		else if (result == 1) {
			player.WonCards(unclaimedPile);
			unclaimedPile[0].print();
			std::cout << std::left << std::setw(2);
			Console::Write(" vs. ");
			unclaimedPile[1].print();
			std::cout << std::left << std::setw(2);
			Console::WriteLine("  " + player.Name() + " wins!");
			unclaimedPile.clear();
		}
		else {
			unclaimedPile[1].print();
			std::cout << std::left << std::setw(2);
			Console::Write(" vs. ");
			unclaimedPile[0].print();
			Console::WriteLine("");
			unclaimedPile.clear();
		}
	}
	//checks who wins and prints (if player wins it checks for a new high score and inserts it if applicable)
	if (npc.Score() > player.Score()) {
		Console::WriteLine(npc.Name() + " WINS!  " + std::to_string(npc.Score()) + " to " + std::to_string(player.Score()));
	}
	else if (npc.Score() < player.Score()) {
		Console::WriteLine(player.Name() + " WINS!  " + std::to_string(player.Score()) + " to " + std::to_string(npc.Score()));
		if (player.Score() > highScore.back().Score()) {
			Console::WriteLine("_#_#_ NEW HIGHSCORE _#_#_", ConsoleColor::Cyan);
			for (int i = 0; i < highScore.size(); i++) {
				if (player.Score() >= highScore[i].Score()) {
					std::string fullPlayer = player.Name() + ';' + std::to_string(player.Score());
					HighScore newScore(fullPlayer, ';');
					highScore.insert(highScore.begin() + i, newScore);
					highScore.pop_back();
					HighScore::SaveHighScores("HighScores.csv", highScore);
					HighScore::ShowHighScores(highScore);
					break;
				}
			}
		}
	}
	else {
		Console::WriteLine("No winners, its a tie!");
	}
	//checks if the user wants to play again
	int again = Input::GetInteger("Do you want to play again? (1: yes, 2: no) ", 1, 2);
	if (again == 1) {
		PlayGame(name, highScore, file);
	}
}
