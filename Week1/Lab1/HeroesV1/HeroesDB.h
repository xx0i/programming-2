#pragma once
#include <string>
#include "Hero.h"

#include <iostream>

class HeroesDB : public JSONBase
{
public:
    HeroesDB();
	virtual ~HeroesDB() {};
    size_t Count() { return _heroes.size(); }
    Hero GetBestHero(); //DECLARE the method in the header (.h) file

    /*
    
        PART A


    
        Part A-1: Add a method called ShowHeroes to the HeroesDB class. 
        The method should loop over the _heroes vector and print the hero ID and the hero Name.
        
    */
    
    void ShowHeroes();

    /*
    
        Part A-2:  Add a method called RemoveHero to the HeroesDB class. 
        The method should have a string parameter for the name of the hero to remove. 
        The method should loop over the heroes vector. 
        If the hero is found, remove the hero from the heroes vector. 
        Return true if the hero was found and removed. 
        Return false if the hero was not found. 
        
        When checking for a match, make sure to ignore the case of the name and the parameter.
        Use the _stricmp method to compare strings. Note: you’ll need to call c_str() on the std::string when calling the method.
    
    */
    bool RemoveHero(std::string heroRemove);

    /*
    
        Part A-3: Add a method called StartsWith to the HeroesDB class. 
        The method should have a string parameter for the name of the hero to match. 
        Loop over the heroes vector and add every hero whose name starts with the string parameter to a vector. Return the vector.
        When checking for a match, make sure to ignore the case of the name and the parameter. 
        Use the isPrefix method of the HeroesDB class to check for a prefix.
    
    */
    std::vector<Hero> StartsWith(std::string heroPrefix);


    /*

        PART B


        Part B-1: Add a method called PrintHero to the HeroesDB class. 
        The method should have a Hero parameter passed to it. 
        Print the details of the Hero parameter. (see the screenshot in part B-2) Make sure to match the formatting (color and indention).
    */
    void PrintHeroes(Hero hero);

    /*

        Part B-2: Add a method called FindHero to the HeroesDB class. 
        The method should have a string parameter for the name to search and a Hero reference parameter. 
        The method needs to loop over the heroes vector to try to find the hero. 
        Check if each hero name matches the parameter. 
        If so, set the Hero parameter to the found hero, break out of the loop and return true. 
        When checking for a match, make sure to ignore the case of the name and the parameter. 
        If the hero is not found, return false.

    */



    /*

        Part B-3: Add a method called RemoveAllHeroes to the HeroesDB class. 
        The method should have a string parameter for the name of the hero to match and a reference parameter for the vector of heroes that were found and removed. 
        Loop over the heroes vector and add every hero whose name starts with the string parameter to the vector parameter. 
        Make sure to remove the hero from the heroes vector.

    */




    /*

        PART C

        Part C-1: MODIFY the ShowHeroes method -- add an optional parameter to the ShowHeroes method. 
        Default it to 0. In the method, if the parameter has the default value, show all the heroes else show the number of heroes that match the parameter. 
        Example, if 10 is passed in, only show the first 10 heroes.

    */

private:
    std::vector<Hero> _heroes;

    static bool charComparer(char c1, char c2);
    static bool isPrefix(const std::string& prefix, const std::string& word);

    virtual bool Deserialize(const std::string& s);
    virtual bool Deserialize(const rapidjson::Value& obj) { return false; };
    virtual bool Serialize(rapidjson::Writer<rapidjson::StringBuffer>* writer) const;
};