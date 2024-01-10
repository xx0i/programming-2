#include "HeroesDB.h"
#include <iostream>
#include "Console.h"
#include <algorithm> 
#include <locale>



/*

	PART A

*/
//ShowHeroes method
void HeroesDB::ShowHeroes(){
	//for each loop to go through the _heroes vector
	for (Hero hero : _heroes)
		//prints id number and hero to console
		Console::Write(std::to_string(hero.Id()) + ". " + hero.Name()+ "\n");
}
//RemoveHeroes method
//Use the _stricmp method to compare strings.Note: you’ll need to call c_str() on the std::string when calling the method.
bool HeroesDB::RemoveHero(std::string heroRemove) {
	bool result = false;
	//for loop to go through the _heroes vector
	for (int i = 0; i < _heroes.size(); i++) {

		//variables to be used in comparison
		std::string s1 = _heroes[i].Name();
		std::string s2 = heroRemove;

		//_stricmp method to compare s1 and s2
		int compResult = _stricmp(s1.c_str(), s2.c_str());

		//if the two strings are the same the hero is removed and result is set to true and the loop exits
		if(compResult == 0) {
			_heroes.erase(_heroes.begin() + i);
			result = true;
			Console::Write(heroRemove + " was removed.\n");
			break;
		}
		//else result = false
		else {
			result = false;
		}
	}
	//if result equals false the console prints the value was not found
	if (result == false) {
		Console::Write(heroRemove + " was not found.\n");
			}
	//return result
	return result;
}

//StartsWith method
std::vector<Hero> HeroesDB::StartsWith(std::string heroPrefix) {
	//initialize empty vector
	std::vector<Hero>samePrefix;
	
	//for loop to check each variable in the _heroes vector
	for (int i = 0; i < _heroes.size(); i++) {

		//checks if the current index is equal to the value of prefix and if so adds it to the samePrefix vector
		bool prefix1 = isPrefix(heroPrefix, _heroes[i].Name());
		if (prefix1 == true) {
				samePrefix.push_back(_heroes[i]);
		}
	}
	//a for each loop is used to go through the samePrefix vector and print to the console
	Console::Write("Found " + std::to_string(samePrefix.size()) + " heroes that start with " + heroPrefix +".\n");
	for (Hero hero : samePrefix)
		Console::Write(std::to_string(hero.Id()) + ". " + hero.Name() + "\n");

	//return samePrefix
	return samePrefix;
}

/*

	PART B

*/
//PrintHero method
void HeroesDB::PrintHeroes(Hero& hero) {

	//prints hero id and name in yellow
	Console::WriteLine(std::to_string(hero.Id()) + ". " + hero.Name() + "\n", ConsoleColor::Yellow);
	
	//prints stats header in blue
	Console::WriteLine("\tSTATS:", ConsoleColor::Blue);
	//prints stats in white
	Console::WriteLine("\t\tIntelligence: " + std::to_string(hero.Powerstats().Intelligence), ConsoleColor::White);
	Console::WriteLine("\t\tStrength: " + std::to_string(hero.Powerstats().Strength));
	Console::WriteLine("\t\tSpeed: " + std::to_string(hero.Powerstats().Speed));
	Console::WriteLine("\t\tDurability: " + std::to_string(hero.Powerstats().Durability));
	Console::WriteLine("\t\tPower: " + std::to_string(hero.Powerstats().Power));
	Console::WriteLine("\t\tCombat: " + std::to_string(hero.Powerstats().Combat));
	
	//prints appearance header in blue
	Console::WriteLine("\tAPPEARANCE:", ConsoleColor::Blue);
	//prints appearance in white
	Console::WriteLine("\t\tRace: " + hero.Appearance().Race, ConsoleColor::White);
	for (int i = 0; i < hero.Appearance().Height.size(); i++) {
		Console::WriteLine("\t\tHeight: " + hero.Appearance().Height[i]);
	}
	for (int i = 0; i < hero.Appearance().Weight.size(); i++) {
		Console::WriteLine("\t\tWeight: " + hero.Appearance().Weight[i]);
		break;
	}
	Console::WriteLine("\t\tEye Colour: " + hero.Appearance().EyeColor);
	Console::WriteLine("\t\tHair Colour: " + hero.Appearance().HairColor);

	//prints bio header in blue
	Console::WriteLine("\tBIO:", ConsoleColor::Blue);
	//prints bio in white
	Console::WriteLine("\t\tFull Name: " + hero.Biography().FullName, ConsoleColor::White);
	Console::WriteLine("\t\tAlter Egos: " + hero.Biography().AlterEgos);
	for (int i = 0; i < hero.Biography().Aliases.size(); i++) {
		if (i == 0) {
			Console::Write("\t\tAliases: " + hero.Biography().Aliases[i] + ", ");
		}
		else if (i > 0 && i < hero.Biography().Aliases.size()-1){
			Console::Write(hero.Biography().Aliases[i] + ", ");
		}
		else if (i == hero.Biography().Aliases.size() - 1) {
			Console::Write(hero.Biography().Aliases[i]);
		}
	}
	Console::WriteLine("\n\t\tPlace Of Birth: " + hero.Biography().PlaceOfBirth);
	Console::WriteLine("\t\tFirst Appearance: " + hero.Biography().FirstAppearance);
	Console::WriteLine("\t\tPublisher: " + hero.Biography().Publisher);
	Console::WriteLine("\t\tAlignment: " + hero.Biography().Alignment);

	//prints work header in blue
	Console::WriteLine("\tWORK:", ConsoleColor::Blue);
	//prints work in white
	Console::WriteLine("\t\tOccupation: " + hero.Work().Occupation, ConsoleColor::White);
	Console::WriteLine("\t\tBase: " + hero.Work().Base);

	//prints connections header in blue
	Console::WriteLine("\tCONNECTIONS:", ConsoleColor::Blue);
	//prints connections in white
	Console::WriteLine("\t\tGroup Affiliations: " + hero.Connections().GroupAffiliation, ConsoleColor::White);
	Console::WriteLine("\t\tRelatives: " + hero.Connections().Relatives);
}

//FindHero method
bool HeroesDB::FindHero(std::string heroFind, Hero& hero) {
	//bool variable to be returned
	bool result = false;
	//for loop to go through the _heroes vector
	for (int i = 0; i < _heroes.size(); i++) {

		//variables to be used in comparison
		std::string s1 = _heroes[i].Name();
		std::string s2 = heroFind;

		//_stricmp method to compare s1 and s2
		int compResult = _stricmp(s1.c_str(), s2.c_str());
		
		//if the strings are the same result = true and the hero ref is set to the value at the current index
		if (compResult == 0) {
			result = true;
			hero = _heroes[i];
			break;
		}
		//else result = false
		else {
			result = false;
		}
	}
	//return result
	return result;
}


//RemoveAllHeroes method
void HeroesDB::RemoveAllHeroes(std::string removeHero, std::vector<Hero>& heroes) {
	//for loop to check each variable in the _heroes vector
	for (int i = 0; i < _heroes.size();) {

		//checks if the current index is equal to the value of prefix and if so adds it to the removedHeroes vector and removes it from _heroes vector
		bool prefix1 = isPrefix(removeHero, _heroes[i].Name());
		if (prefix1 == true) {
			heroes.push_back(_heroes[i]);
			_heroes.erase(_heroes.begin() + i);
		}
		else {
			++i;
		}
	}
}

//DEFINE the method in CPP file
//  *** don't forget the "HeroesDB::" in front of the method name.
Hero HeroesDB::GetBestHero()
{
	return _heroes[51];
}

HeroesDB::HeroesDB()
{
	DeserializeFromFile("heroes.json");
}

bool HeroesDB::charComparer(char c1, char c2)
{
	return std::tolower(c1, std::locale()) == std::tolower(c2, std::locale());
}
bool HeroesDB::isPrefix(const std::string& prefix, const std::string& word)
{
	return  (std::mismatch(prefix.begin(), prefix.end(),
		word.begin(), word.end(),
		charComparer)).first == prefix.end();
}


bool HeroesDB::Deserialize(const std::string& s)
{
	rapidjson::Document doc;
	if (!InitDocument(s, doc))
		return false;

	if (!doc.IsArray())
		return false;


	_heroes.reserve(doc.Size());

	for (rapidjson::SizeType i = 0; i < doc.Size(); ++i)
	{
		rapidjson::Value& node = doc[i];
		Hero myHero(node);
		_heroes.push_back(myHero);
	}

	//JsonNodePrinter::PrintNode(doc, 4);


	return true;
}


bool HeroesDB::Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const
{
	//writer->StartArray();

	//for (std::list<Product>::const_iterator it = _products.begin(); it != _products.end(); it++)
	//{
	//	(*it).Serialize(writer);
	//}
	//writer->EndArray();

	return true;
}