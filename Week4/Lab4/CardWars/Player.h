#pragma once
#include <string>
#include <vector>
#include "Card.h"

class Player
{
public:
	//accessors
	std::string Name()const;
	int Score()const;

	//mutators
	void Name(std::string newName);
	void Score(int& newScore);

	//HasCards method
	bool HasCards();

	//PushCard method
	void PushCard(Card const& card);

	//PopCard method
	Card PopCard();

	//WonCards method
	void WonCards(std::vector<Card> const& cards);

private:
	//member fields string name, int score, vector of Card pile, vector of Card won
	std::string name_;
	int score_;
	std::vector<Card> pile_;
	std::vector<Card> won_;
};