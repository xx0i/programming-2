﻿// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

enum class Weapon
{
	Sword, Axe, Spear, Mace
};

int LinearSearch(std::vector<int>nums, int findNumber) {
	int found = -1;
	for (size_t i = 0; i < nums.size(); i++) {
		if (findNumber == nums[i]) {
			found = i;
			break;
		}
	}
	return found;
}

int main()
{
	/*
		╔═════════╗
		║Searching║
		╚═════════╝

		There are 2 ways to search a vector: linear search or binary search

		CHALLENGE 1:

			write a method to linear search the numbers list.
				The method should take 2 parameters: vector of ints to search, int to search for.
				The method should return -1 if NOT found or the index if found.

			The algorithm:
				1) start at the beginning of the vector
				2) compare each item in the vector to the search item
				3) if found, return the index
				4) if reach the end of the vector, return -1 which means not found

	*/
	std::vector<int> numbers = { 0,1,2,3,4,5,6 };
	int searchNumber = 15;
	int index = LinearSearch(numbers, searchNumber);
	std::cout << searchNumber << " was" << ((index == -1) ? " NOT " : " ") << "found.\n";




	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Creating a map  ]

		map<TKey, TValue>  - an associative collection.
			TKey is a placeholder for the type of the keys.
			TValue is a placeholder for the type of the values.

		When you want to create a map variable,
			1) replace TKey with whatever type of data you want to use for the keys
			2) replace TValue with the type you want to use for the values


		[  Adding items to a map  ]

		There are 2 ways to add items to a Dictionary:
		1) using the insert method.
		3) using [key] = value
	*/
	std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

	//returns an iterator and a bool. 
	//if the key is already in the map, it will NOT insert it -- the bool will be false.
	auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
	if (inserted.second == false) //meaning not inserted
		std::cout << "The key was already in the map. It was not inserted.\n";
	else
		std::cout << "The key was inserted in the map.\n";

	dorasBackpack[Weapon::Axe] = 3;
	dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map


	/*
		CHALLENGE 2:

			Create a map that stores names (string) and grades. Call the variable grades.
			Add students and grades to your map.

	*/
	std::map<std::string, double>grades;
	auto gradesInserted = grades.insert(std::make_pair("Jennifer", rand() % 101));
	if (gradesInserted.second == false)
		std::cout << "The student was already in the course. \n";
	else
		std::cout << "The student was added.\n";
	grades["Rebecca"] = rand() % 101;
	grades["Michelle"] = rand() % 101;
	grades["Elle"] = rand() % 101;
	grades["Ariel"] = rand() % 101;

	//LECTURE NOTES
	std::map<std::string, float>menu; //type of key is string (name of item), type of value is float(price of item)

	std::string key = "veggie burger";
	float value = 1.99F;
	menu[key] = value;
	menu["cheese burger"] = 1.99F;
	menu["hamburger"] = 1.99F;

	auto result = menu.insert(std::make_pair("turkey burger", 1.99F));
	if (result.second) {
		std::cout << "turkey burger was added to the menu \n";
	}


	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Looping over a map  ]

		You should use a ranged-based for loop when needing to loop over the entire map.

	*/
	for (auto const& [key, val] : dorasBackpack) //requires C++ 20
	{
		switch (key)
		{
		case Weapon::Sword:
			std::cout << "Sword: ";
			break;
		case Weapon::Axe:
			std::cout << "Axe: ";
			break;
		case Weapon::Spear:
			std::cout << "Spear: ";
			break;
		case Weapon::Mace:
			std::cout << "Mace: ";
			break;
		default:
			break;
		}
		std::cout << val << "\n";
	}


	/*
		CHALLENGE 4:

			Loop over your grades map and print each student name and grade.

	*/
	for (const auto& [student, grade] : grades)
	{
		std::cout << student + ": " + std::to_string(grade) + "\n";
	}


	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Checking for a key in a map  ]

		use the find method to check if the key is in the map

		will return map.end() if NOT found.

	*/
	std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
	if (foundIter == dorasBackpack.end()) //meaning it was NOT found
	{
		std::cout << "Dora did not find any maces.\n";
	}
	else
	{
		//can safely grab the value for the key
		std::cout << "Dora found " << foundIter->second << " Maces\n";
	}



	/*
		CHALLENGE 5:

			look for a specific student in the map.
			If the student is found, print out the student's grade
			else print out a message that the student was not found

	*/
	std::string studentName = "Ariel";
	auto studentFound = grades.find(studentName);
	if (studentFound != grades.end())
		std::cout << studentName << " has a grade of " << studentFound->second << ".\n";
	else
		std::cout << studentName << " was not in the course.\n";




	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Updating a value for a key in a map  ]

		To update an existing value in the map, use the [ ]


	*/
	dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



	/*
		CHALLENGE 6:

			Pick any student and curve the grade (add 5) that is stored in the grades map

	*/
	grades[studentName] = std::min<double>(100, grades[studentName] + 5);
	std::cout << "The grade for " << studentName << " is now " << grades[studentName] << ".\n";
}