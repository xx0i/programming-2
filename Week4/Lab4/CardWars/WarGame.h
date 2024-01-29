#pragma once
#include <string>
#include <vector>
#include "Card.h"

class WarGame
{

public:
	WarGame(std::string cardsFile);

	//LoadCards method with a string parameter
	static void LoadCards(std::string const& filePath);

	//ShowCards method
	static void ShowCards();

private:
	static std::vector<Card> _cards;
	static void shuffle();
};

