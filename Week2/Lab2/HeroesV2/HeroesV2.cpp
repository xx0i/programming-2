#include <iostream>
#include "HeroesDB.h"
#include "Console.h"
#include "Input.h"
#include <locale>
#include "Tester.h"

int main()
{
	Tester v2Test;
	Console::ResizeWindow(150, 30);

	HeroesDB heroDB;

	int menuSelection = 0;
	std::vector<std::string> menuOptions{ "1. Sort by Name (descending)", "2. Sort By", "3. Find Hero (Binary Search)", "4. Print Group Counts", "5. Find All Heroes by first letter", "6. Remove Hero", "7. Exit" };
	std::vector<std::string> sortByOptions{ "1. Intelligence", "2. Strength", "3. Speed", "4. Durability", "5. Power", "6. Combat" };

	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			heroDB.SortByNameDescending();
			break;
		}
		case 2:
		{
			/*
				After creating the SortByAttribute method in HeroesDB (part A-2), add code to case 2 of the switch.
				Call the SortByAttribute method and pass the sortByChoice variable to it.
			*/
			int sortBySelection = Input::GetMenuSelection(sortByOptions);
			SortBy sortByChoice = (SortBy)sortBySelection;
			heroDB.SortByAttribute(sortByChoice);
			break;
		}
		case 3:
		{
			/*
				After creating the FindHero method in HeroesDB (part B-2), add code to case 3 of the switch.
				Using Input.getString, ask the user to enter the name to find.
				Call the FindHero method and pass the string the user entered.
			*/
			std::string hero2find = Input::GetString("Please enter the name of the hero to find: ");
			heroDB.FindHero(hero2find);
			break;
		}
		case 4:
		{
			/*
				After creating the PrintGroupCounts method in HeroesDB (part B-4), add code to case 4 to call the PrintGroupCounts method.
			*/
			heroDB.PrintGroupCounts();
			break;
		}
		case 5:
		{
			/*
				After creating the FindHeroesByLetter method in HeroesDB (part C-1), add code to case 5 of the switch.
				Using Input.getString, ask the user to enter the letter to find.
				Call FindHeroesByLetter passing the string that the user enters.
			*/
			std::string letter2find = Input::GetString("Please enter the first letter of the heroes to find: ");
			heroDB.FindHeroesByLetter(letter2find);
			break;
		}
		case 6:
		{
			/*
				After creating the RemoveHero method in HeroesDB (part C-2), add code to case 6 of the switch.
				Using Input.getString, ask the user to enter the letter to find.
				Call RemoveHero passing the string that the user enters.
			*/

			break;
		}
		default:
			break;
		}

		Input::PressEnter();

	} while (menuSelection != menuOptions.size());
}