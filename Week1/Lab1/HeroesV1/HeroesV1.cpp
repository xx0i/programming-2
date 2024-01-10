#include <iostream>
#include "HeroesDB.h"
#include "Console.h"
#include "Input.h"
#include "Tester.h"


int main()
{
    Tester v1Test;
    /*
        NOTE: if you're having problems with the menu showing, it could be because you're using Windows Terminal.
        Go here to learn how to change Windows to use the Console window instead. 
        https://discord.com/channels/446669518593327105/1151952874012688384/1153398632763097212
    
    */
    Console::ResizeWindow(150, 30);

    HeroesDB heroDB;

    /*
        Here are some examples.
            - how to call methods
            - how to use the Console Write methods
            - how to access the data values of a Hero.
    */
    Hero theBest = heroDB.GetBestHero(); //how to call a non-static method
    Console::Write("The best hero is "); //how to call a static method
    Console::Write(theBest.Name(), ConsoleColor::Yellow);
    Console::Write("! (of course).\nThe Id of the hero is ");
    Console::Write(std::to_string(theBest.Id()), ConsoleColor::Green);
    Console::Write(".\nHis combat level is ");
    Console::Write(std::to_string(theBest.Powerstats().Intelligence), ConsoleColor::Red);
    Console::WriteLine("!");
    Input::PressEnter();


    int menuSelection = 0;
    std::vector<std::string> menuOptions { "1. Show Heroes", "2. Remove Hero", "3. Starts With", "4. Find Hero", "5. Remove All Heroes", "6. Show Top x", "7. Exit" };
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
                After creating the ShowHeroes method in HeroesDB, add code to case 1 of the switch in main to call the ShowHeroes method.
            */
            heroDB.ShowHeroes();
            break;
        }
        case 2:
        {
            /*
                After creating the RemoveHero method in HeroesDB, add code to case 2 of the switch in main.
                Using Input::GetString, ask the user to enter the name of the hero to remove.
                Call RemoveHero passing the string that the user enters.
                If the returned value is true, print that the hero was removed else print that the hero was not found.
            */
            std::string removeHero = Input::GetString("Enter the name of the hero to remove: ");
            heroDB.RemoveHero(removeHero);
            break;
        }
        case 3:
        {
            /*
                After creating the StartsWith method in HeroesDB, add code to case 3 of the switch in main.
                Using Input::GetString, ask the user to enter the first part of the names to find. 
                Call StartsWith passing the string that the user enters and assign the returned vector to a vector variable. 
                print out the number of heroes found AND loop over the vector and print the Id and Name for each hero found.
            */
            std::string startsWithPrefix = Input::GetString("Enter the start of the name to find: ");
            heroDB.StartsWith(startsWithPrefix);
            break;
        }
        case 4:
        {
            /*
                After creating the FindHero method in HeroesDB, add code to case 4 of the switch in main.
                Using Input::GetString, ask the user to enter the name of the hero to find. 
                Call FindHero passing the string that the user enters and a Hero variable. 
                if the returned value from FindHero is true, then call PrintHero passing the Hero variable else print out a message that the name was not found.
            */
            std::string look4hero = Input::GetString("Enter the name of the hero to find: ");
            Hero myHero;
            if (heroDB.FindHero(look4hero, myHero)) {
                heroDB.PrintHeroes(myHero);
            }
            else {
                Console::Write(look4hero + " was not found.\n");
            }
            break;
        }
        case 5:
        {
            /*
                After creating the RemoveAllHeroes method in HeroesDB, add code to case 5 of the switch in main.
                Using Input::GetString, ask the user to enter the first part of the names to remove. 
                Call RemoveAllHeroes passing the string that the user enters and a vector. 
                after calling the method, if the vector is empty, print that “No heroes found that start with <the StartsWith string the user entered>” 
                else print “The following heroes were removed: “ and loop over the vector calling PrintHero for each hero in the vector.
            */

            break;
        }
        case 6:
        {
            /*
                After updating the ShowHeroes method in HeroesDB, add code to case 6 of the switch in main.
                Using Input::GetInteger, ask the user to enter the number of heroes to show. 
                Use the HeroesDB.Count method to get the max value to pass to Input::GetInteger. 
                Call ShowHeroes and pass in the number that Input::GetInteger returns.
            */

            break;
        }
        default:
            break;
        }

        Input::PressEnter();

    } while (menuSelection != menuOptions.size());
}


