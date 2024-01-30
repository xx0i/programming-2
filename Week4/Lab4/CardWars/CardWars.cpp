#include <iostream>
#include "Console.h"
#include "Input.h"
#include "WarGame.h"
#include "Tester.h"
#include "HighScore.h"

int main()
{
	Tester cardWarsTest;
	Console::ResizeWindow(150, 30);

	int menuSelection = 0;
	std::vector<std::string> menuOptions{ "1. Show Cards", "2. Show High Scores", "3. Play Card Wars", "4. Exit" };
	std::string highScoreFile = "HighScores.csv";
	std::string cardsFile = "cards.csv";

	WarGame war(cardsFile);

	/*

		PART A

		Part A-1: Add a static LoadCards method to the WarGame class.
			It should have a string parameter for the file path.
			In the method, it should read the csv file and split the data to get each string. Store each card in the mCards vector field of the class.

			** Call the LoadCards method from the WarGame constructor.



		Part A-2: Add a static ShowCards method to the WarGame class.
			Loop over the vector and call the Print method on each card.

			** Call the ShowCards method from main in case 1 of the menu.



		Part A-3: Add a HighScore class with a name field and a score field both with getter/setter methods.


		Part A-4: Add a Player class with a name field, a score field, a pile field which is a vector of cards, and a won field which is a vector of cards.
			Add getter/setter methods for the score and name fields.
			Add the following methods: HasCards, PushCard, PopCard, and WonCards.
			HasCards will return true if there are cards in the pile vector.
			PushCard will take a card parameter and add it to the pile vector of cards.
			PopCard will remove a card from the pile vector of cards and return the card.
			WonCards will take a vector of cards and add it to the won vector of cards and update the score field.





		PART B

		Part B-1: Add a static LoadHighScores method to the HighScore class.
			It should have a string parameter for the file path.
			In the method, it should deserialize the CSV file into a vector<HighScore>.
			Return the vector.

			The file format: 1 high score object per line. On each line, is a csv string of “name,score”.


			** In the main method in CardWars.cpp, before the do-while loop, call LoadHighScores passing the highScoreFile variable and store the vector it returns into a variable to be used later.



		Part B-2: Add a static ShowHighScores method to the HighScore class.
			It should have a vector<HighScore> const ref parameter.
			It should print a “High Scores” title then loop over the high scores vector and print each item.
			Format the output so that the score has a color different than the name.
			See example screenshot in the lab document.

			** In case 2 of the menu switch in Main in CardWars.cpp, call the ShowHighScores method and pass the vector of highscores.



		 Part B-3: Add a static SaveHighScores method to the HighScore class.
			It should have a string parameter for the file path and a vector<HighScore> const ref parameter.
			In the method, it should serialize the vector of high scores to the file.
			Call this method in the game when a player gets a new high score.

			The file format: store 1 high score object per line. On each line, save a csv string of "name,score".



		Part B-4: Add a PlayGame method to the WarGame class.
			Declare your method in the WarGame.h file and define the method in the WarGame.cpp file.
			It should have 3 parameters: string for the player name, vector<HighScore> reference for the high scores, and a string for the name of the high score file.

			Here is the game logic to put in PlayGame:
			1.	Call the shuffle method to shuffle the vector of cards.
			2.	Create 2 instances of your Player class: npc and player.
				Give npc the name of “NPC”.
				Use Input::GetString in main to get the name. Pass the name as a parameter to PlayGame and use it to set the name of the player instance.
			3.	Take the shuffled vector and add half of the deck to npc and half of the deck to the player.
			4.	Create another vector called unclaimedPile.
			5.	Loop while the player instance has cards
				a.	Pop a card from the player instance and pop a card from the npc instance.
				b.	Add the 2 cards to the unclaimed pile.
				c.	Call the Compare method of the card class.
					i.	NOTE: Compare will return -1 if the card1 < card2, 0 if card1 = card2, 1 if card1 > card2
					ii.	Example of calling Compare: int compResult = card1.Compare(card2);
				d.	If Compare returns -1, add the unclaimed pile to the npc instance. Clear the unclaimed pile. Print NPC wins.
				e.	If Compare returns 1, add the unclaimed pile to the player instance. Clear the unclaimed pile. Print player wins. NOTE: use the player’s name.
			6.	After the loop, check who won. Print the scores from the npc and player instances.
				a.	If the npc has a higher score, print that the npc won the round.
				b.	If the npc has the same score as the player, print that it was a tie.
				c.	If the player has a higher score. Print out that the player won and check if it’s a new high score.
					i.	NOTE: the last score in the high score vector is the smallest high score. Therefore, if the player’s score is greater than the last score in the high score vector, the player has a new high score.
					ii.	If the player’s score is a new high score,
						1.	loop over high score vector to find the spot for the new high score.
							a.	insert a new high score object into the vector at that index
							b.	remove the last score in the vector
							c.	call SaveHighScores (see part B-3)
							d.	Call ShowHighScores to display the new top 10.
			7.	Ask the player if they want to play again. Use Input::GetInteger to get a number from the user: 1 for yes and 2 for no.
			8.	Continue playing while the user selects yes. Stop playing if they choose no.


			In case 3 of the menu switch in Main, call PlayGame to play a game of war!
	*/

	WarGame::LoadCards("cards.csv");  //calls LoadCards passing it cards.csv
	std::vector<HighScore> highScores = HighScore::LoadHighScores("HighScores.csv");  //calls LoadHighScores passing it HighScores.csv

	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			/*
				After creating the ShowCards method to the WarGame class, call the method here.
			*/
			WarGame::ShowCards();
			break;
		}
		case 2:
		{
			/*
				After creating the ShowHighScores method to the HighScore class, call the method here passing the highScores vector.
			*/
			HighScore::ShowHighScores(highScores);
			break;
		}
		case 3:
		{
			/*
				After creating the PlayGame method to the WarGame class, call the method here passing the highScoreFile string and the highScores vector.
			*/
			std::string name = Input::GetString("Please enter your name: ");
			WarGame::PlayGame(name, highScores, "HighScores.csv");
			break;
		}
		default:
			break;
		}

		Input::PressEnter();

	} while (menuSelection != menuOptions.size());

}