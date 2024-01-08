#include "HeroesDB.h"
#include <iostream>
#include "Console.h"
#include <algorithm> 
#include <locale>



/*

	PART A

*/
//show heroes method
void HeroesDB::ShowHeroes(){
	//for each loop to go through the _heroes vector
	for (Hero hero : _heroes)
		//prints id number and hero to console
		Console::Write(std::to_string(hero.Id()) + ". " + hero.Name()+ "\n");
}
//remove heroes method
//If the hero is found, remove the hero from the heroes vector.
//Return true if the hero was found and removed.
//Return false if the hero was not found.
//
//When checking for a match, make sure to ignore the case of the name and the parameter.
//Use the _stricmp method to compare strings.Note: you’ll need to call c_str() on the std::string when calling the method.
bool HeroesDB::RemoveHero(std::string heroRemove) {
	bool result = false;
	//for each loop to go through the _heroes vector
	for (int i = 0; i < _heroes.size(); i++) {

		//variables to be used in comparison
		std::string s1 = _heroes[i].Name();
		std::string s2 = heroRemove;

		//_stricmp method to compare s1 and s2
		int compResult = _stricmp(s1.c_str(), s2.c_str());

		//if the two strings are the same the hero is removed and result is set to true
		if(compResult == 0) {
			_heroes.erase(_heroes.begin() + i);
			result = true;
			Console::Write(heroRemove + " was removed.\n");
			break;
		}
		else {
			result = false;
		}
	}
	//else result is set to false
	if (result == false) {
		Console::Write(heroRemove + " was not found.\n");
			}

	return result;
}
/*
Loop over the heroes vector and add every hero whose name starts with the string parameter to a vector.Return the vector.
When checking for a match, make sure to ignore the case of the name and the parameter.
Use the isPrefix method of the HeroesDB class to check for a prefix.*/
//starts with method
std::vector<Hero> HeroesDB::StartsWith(std::string heroPrefix) {

	std::vector<Hero>samePrefix;

	for (int i = 0; i < _heroes.size(); i++) {
		bool prefix1 = isPrefix(heroPrefix, _heroes[i].Name());
		if (prefix1 == true) {
				samePrefix.push_back(_heroes[i]);
		}
	}
	for (Hero hero : samePrefix)
		Console::Write(std::to_string(hero.Id()) + ". " + hero.Name() + "\n");

	return samePrefix;
}

/*

	PART B

*/




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