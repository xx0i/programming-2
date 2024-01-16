#include "HeroesDB.h"
#include <iostream>
#include "Console.h"
#include <algorithm> 
#include <string_view>
#include <locale>
#include <cctype>


/*

	PART A

*/
//MergeSort method
std::vector<Hero> HeroesDB::MergeSort(std::vector<Hero>& heroes, SortBy selection) {
	if (heroes.size() <= 1) {
		return heroes;
	}
	// Recursive case. First, divide the vector into equal-sized sub vectors
	// consisting of the first half and second half of the vector.
	// This assumes vectors start at index 0.
	std::vector<Hero> left;
	std::vector<Hero> right;
	for (int i = 0; i < heroes.size(); i++) {
		if (i < (heroes.size()) / 2) {
			left.push_back(heroes[i]);
		}
		else {
			right.push_back(heroes[i]);
		}
	}
	// Recursively sort both sub vectors.
	left = MergeSort(left, selection);
	right = MergeSort(right, selection);
	// Then Merge the now-sorted sub vectors.
	return HeroesDB::Merge(left, right, selection);
}

//Merge method
std::vector<Hero> HeroesDB::Merge(std::vector<Hero> left, std::vector<Hero> right, SortBy selection) {
	std::vector<Hero> result;
	while (left.size() > 0 && right.size() > 0) {
		int compResult = Hero::Compare(left[0], right[0], selection);
		if (compResult == 1 || compResult == 0) {
			result.push_back(left[0]);
			left.erase(left.begin());
		}
		else {
			result.push_back(right[0]);
			right.erase(right.begin());
		}
	}
	// Either left or right may have elements left; consume them.
	// (Only one of the following loops will actually be entered.)
	while (left.size() > 0) {
		result.push_back(left[0]);
		left.erase(left.begin());
	}

	while (left.size() > 0) {
		result.push_back(right[0]);
		right.erase(right.begin());
	}
	return result;
}

/*

	PART B

*/




/*

	PART C

*/







HeroesDB::HeroesDB()
{
	DeserializeFromFile("heroes.json");
}

std::string HeroesDB::toUpper(const std::string& str)
{
	std::string copy = str;
	std::transform(copy.begin(),
		copy.end(),
		copy.begin(),
		[](unsigned char c) { return std::toupper(c); });
	return copy;
}

std::string HeroesDB::toUpper2(const std::string& str)
{
	std::string copy = str;
	for (auto& c : copy) c = toupper(c);
	return copy;
}

void HeroesDB::SortByNameDescending()
{
	std::vector<Hero> sorted(_heroes); //clone the list

	size_t n = sorted.size();
	bool swapped;
	do
	{
		swapped = false;
		for (size_t i = 1; i <= n - 1; i++)
		{
			int compResult = _stricmp(sorted[i - 1].Name().c_str(), sorted[i].Name().c_str());
			//int compResult = toUpper(sorted[i - 1].Name()).compare(toUpper(sorted[i].Name()));
			if (compResult < 0)
			{
				swapped = true;
				std::swap(sorted[i - 1], sorted[i]);

				//int temp = vec[i - 1];
				//vec[i - 1] = vec[i];
				//vec[i] = temp;
			}
		}
		--n;
	} while (swapped);

	for (auto& hero : sorted)
	{
		std::cout << hero.Id() << ": " << hero.Name() << std::endl;
	}
	std::cout << std::endl;
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