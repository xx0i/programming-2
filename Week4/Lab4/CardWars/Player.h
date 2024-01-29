#pragma once
#include <string>
#include <vector>
#include "Card.h"

class Player
{
public:
	//accessors
	std::string Name();
	int Score();

	//mutators
	void Name(std::string newName);
	void Score(int newScore);

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

//HasCards will return true if there are cards in the pile vector.
//PushCard will take a card parameter and add it to the pile vector of cards.
//PopCard will remove a card from the pile vector of cards and return the card.
//WonCards will take a vector of cards and add it to the won vector of cards and update the score field