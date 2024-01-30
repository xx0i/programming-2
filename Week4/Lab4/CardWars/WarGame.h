#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "HighScore.h"

class WarGame
{

public:
	WarGame(std::string cardsFile);

	//LoadCards method with a string parameter
	static void LoadCards(std::string const& filePath);

	//ShowCards method
	static void ShowCards();

	//PlayGame
	static void PlayGame(std::string const& name, std::vector<HighScore>& highScore, std::string const& file);

private:
	static std::vector<Card> _cards;
	static void shuffle();
};

