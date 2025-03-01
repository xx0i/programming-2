﻿// Day02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

bool postFix(std::string& hero)
{
    srand((unsigned int)time(NULL));
    int postFixNumber = rand() % 1000;
    hero = hero + "-" + std::to_string(postFixNumber);
    return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
    //scores.push_back(5); //not allowed because it is marked as const
    float sum = 0;
    for (auto score : scores)
        sum += score;

    return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
    std::cout << "----SCORES----\n";
    int index = 1;
    for (int score : scores)
        std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
    std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}

void GetUserInfo(std::string& firstName, std::string& lastName, int& age) {
    firstName = "Bruce";
    lastName = "Wayne";
    age = 35;
}

void AddGrades(std::vector<float>& courseGrades) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++) {
        courseGrades.push_back(rand()%10001 / 100.0F);
    }
}

void PrintBalance(const float& bankBalance) {
    //bankBalance = 0;
    std::cout << "Your balance is " << bankBalance << "\n";
}

void CalculateStats(const std::vector<float>& courseGrades, float& min, float& max) {
    min = courseGrades[0];
    max = courseGrades[0];
    for (size_t i = 1; i < courseGrades.size(); i++)
    {
        if (min > courseGrades[i]) {
            min = courseGrades[i];
        }
        if (max < courseGrades[i]) {
            max = courseGrades[i];
        }
    }
}


int main()
{
    std::string fName, lName;
    int myAge;
    GetUserInfo(fName, lName, myAge);
    std::cout << "I am " + fName + " " + lName + " and I am " + std::to_string(myAge) + " years old.\n";

    float balance = 1000;
    PrintBalance(balance);
    std::cout << "My balance is " << balance << "\n";



    /*
        ╔══════════════════════════════╗
        ║Parameters: Pass by Reference.║
        ╚══════════════════════════════╝
        Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

        NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
            This is because the parameter is actually just a new name for the other variable.
    */
    std::string spider = "Spiderman";
    bool isEven = postFix(spider);
    std::string evenResult = (isEven) ? "TRUE" : "FALSE";
    std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


    /*
        CHALLENGE 1:

            Write a method to fill the vector of floats with grades.
            1) pass it in by reference
            2) add 10 grades to the vector

    */
    std::vector<float> grades;
    AddGrades(grades);
    std::cout << "----GRADES-----\n";
    for (auto& grade : grades)
        std::cout << grade << std::endl;


    /*
        ╔══════════════════╗
        ║ const parameters ║
        ╚══════════════════╝
        const is short for constant. It prevents the variable from being changed in the method.

        This is the way you pass by reference and prevent the method from changing the variable.
    */
    std::vector<int> highScores;
    for (int i = 0; i < 10; ++i)
        highScores.push_back(rand());
    float avg = average(highScores);



    /*
        CHALLENGE 2:

            Write a method to calculate the stats on a vector of grades
            1) create a method to calculate the min, max. 
                pass the grades vector as a const reference. Use ref parameters for min and max.
            2) call the method in main and print out the min, max.

    */
    float min, max;
    std::cout << "----GRADE STATS-----\n";
    CalculateStats(grades, min, max);
    std::cout << "Min grade: " << min << "\tMax grade: " << max << std::endl;




    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    print(highScores);

    for (size_t i = 0; i < highScores.size();)
    {
        if (highScores[i] < 2500)
            highScores.erase(highScores.begin() + i);
        else
            ++i;
    }


    /*
        INTERMEDIATE LEVEL...
        a way using std::remove_if and a lambda
    
    highScores.erase(
        std::remove_if(highScores.begin(),
                       highScores.end(),
                       [](int score) { return score < 2500; }),
        highScores.end());


    print(highScores);
    */


    print(highScores);
 


    /*
        CHALLENGE 3:

            Using the vector of grades you created.
            Remove all the failing grades (grades < 59.5).
            Print the grades.
    */
    std::cout << "----GRADES-----\n";
    for (auto& grade : grades)
    {
        std::cout << grade << "\n";
    }

    for (size_t i = 0; i < grades.size();)
    {
        if (grades[i] < 59.5)
            grades.erase(grades.begin() + i);
        else
            ++i;
    }

    std::cout << "----GRADES-----\n";
    for (auto& grade : grades)
    {
        std::cout << grade << "\n";
    }




    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        
        size(): # of items that have been ADDED
        capacity(): length of the internal array
        reserve(n): presizes the internal array
    */
    std::vector<int> scores;
    scores.reserve(10); //makes the internal array to hold 10 items.

    printInfo(scores);
}