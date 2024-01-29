#include "Player.h"
#include <iostream>

//accessors
std::string Player::Name()const {
	return name_;
}

int Player::Score()const {
	return score_;
}

//mutators
void Player::Name(std::string& newName) {
	name_ = newName;
}

void Player::Score(int& newScore) {
	score_ = newScore;
}

//HasCards method
bool Player::HasCards() {
	bool result = false; //bool result set to default, false
	//checks if pile_ has data, if so updates result to be true
	if (pile_.size() > 0) {
		result = true;
	}
	return result;  //returns result
}

//PushCard method
void Player::PushCard(Card const& card) {
	pile_.push_back(card);  //inserts the card being passed into the pile_ vector
}

//PopCard method
Card Player::PopCard() {
	int toRemove = (rand() % pile_.size());  //gets a random number to represent a card in the pile_ vector
	Card cardRemoval = pile_.at(toRemove);  //gets the random card from the pile_ vector
	return cardRemoval;  //returns the card
	pile_.erase(pile_.begin() + toRemove);  //removes the card
}

//WonCards method
void Player::WonCards(std::vector<Card> const& cards) {
	std::move(cards.begin(), cards.end(), std::back_inserter(won_));  //moves the cards from the passed vector to the won_ vector
	score_ = won_.size();  //sets score equal to the size of won_ vector, to show how many cards were won
}