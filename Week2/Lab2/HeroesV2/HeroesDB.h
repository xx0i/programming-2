#pragma once

#include <iostream>
#include <string>
#include <map>
#include "Hero.h"
#include "enums.h"


class HeroesDB : public JSONBase
{
public:
	HeroesDB();
	virtual ~HeroesDB() {};
	size_t Count() { return _heroes.size(); }

	void SortByNameDescending();


	/*

		PART A


		Part A-1: Implement the MergeSort and Merge methods in the HeroesDB class.
		Your code must follow the pseudo-code.

		NOTE: you must add a parameter of type SortBy to both methods.
		You will get the user’s sort by selection in part A-2 and pass it to MergeSort.

	*/
	//MergeSort
	std::vector<Hero> MergeSort(const std::vector<Hero>& heroes, const SortBy selection);

	//Merge
	std::vector<Hero> Merge(std::vector<Hero>& left, std::vector<Hero>& right, const SortBy selection);

	//SortByAttribute
	void SortByAttribute(SortBy selection);
	/*

		Part A-2: Add a method called SortByAttribute to the HeroesDB class.
		The method should have a SortBy parameter passed to it.

		Call the MergeSort method from part A-1.
		Pass to it the _heroes vector of the class and the SortBy parameter.
		Print the items in the sorted vector that is returned from MergeSort.

		NOTE: print the hero ID, selected attribute, and name (see screenshot).
		To get the selected attribute, call the GetSortByAttribute on each hero.


	*/



	/*

		PART B


		Part B-1: Implement the BinarySearch method in the HeroesDB class.
		Your code must follow the pseudo-code.

	*/


	/*

		Part B-2:  Add a method called FindHero to the HeroesDB class.

		The method should have a string parameter for the name of the hero to find.
		Call the BinarySearch method from part B-1.

		Print the result.
		If the found index is -1, print “<insert heroName> is not found” otherwise print “<insert heroName> was found at index <insert found index>”.


	*/



	/*

		Part B-3: Add a method called GroupHeroes to the HeroesDB class.

		The method should initialize the _groupedHeroes map.
		Make sure to make the keys case insensitive (ignore the case).

		You want to create a map where the keys are the first letters of the heroes and the value for each key is a vector of the heroes whose names start with that letter.
		EX: for the key “B”, the value would contain a vector of all the heroes whose names start with B.
		Loop over the heroes vector.
		Check if the first letter of each hero name is in the _groupedHeroes map.
		If not, then create a new vector, add the hero to the vector, then add the vector to the map as the value for that initial letter.
		If it is in the map already, then add the hero to the vector that is stored for that key.
		Example:
		When you start, the map will be empty.
		•	Start looping over the _heroes vector.
			o	Get the first letter of the hero’s name. (EX: “A” if the hero’s name is “Aquaman”)
			o	Using the letter as a key, add the hero to vector for the key in the map. Remember that the value for the key in the map is a vector.
				So, you can’t add the hero directly as value for the key because the value is defined as a vector. Add the hero to the vector using push_back.


	*/


	/*

		Part B-4:  Add a method called PrintGroupCounts to the HeroesDB class.

		In the method, if _groupedHeroes is empty, call the GroupHeroes method from part B-1.
		Loop over the map and print each key and the count of the vector for each key.

	*/



	/*

		PART C


		Part C-1: Add a method called FindHeroesByLetter to the HeroesDB class.

		The method should take a parameter for the first letter.
		In the method, if _groupedHeroes is empty, call the GroupHeroes method from part B-1.
		Check if the letter parameter is in the map.
		If it is not, then print a message that no heroes were found that start with the letter.
		Else, loop over the vector of heroes for the key and print the ID and name.

	*/


	/*

		Part C-2:  Add a method called RemoveHero to the HeroesDB class.

		The method should take a string parameter that is the name of the hero to remove.
		In the method, if _groupedHeroes is empty, call the GroupHeroes method from part B-1.
		Check if the _groupedHeroes map contains a key with the first letter of the name.
		•	If the key is not found, print a message saying the hero was not found.
		•	If the key is found, then get the vector for the key. The vector is the value stored in the map for the key.
			o	call the BinarySearch method to get the index of the hero to remove for the vector.
					If BinarySearch returns the index, then remove the hero from the vector AND from the _heroes vector. Print that the hero was removed.
					•	NOTE: if removing the hero makes the vector empty for the letter, then remove the letter (which is the key) from the map.
					If BinarySearch returns -1 (meaning the hero is not in the vector), print a message that the hero was not found.


	*/


private:
	std::vector<Hero> _heroes;
	std::map<char, std::vector<Hero>> _groupedHeroes;

	static std::string toUpper(const std::string& str);
	static std::string toUpper2(const std::string& str);
	static bool charComparer(char c1, char c2);
	static bool isPrefix(const std::string& prefix, const std::string& word);

	virtual bool Deserialize(const std::string& s);
	virtual bool Deserialize(const rapidjson::Value& obj) { return false; };
	virtual bool Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const;
};
