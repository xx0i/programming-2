// Day11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Car.h"
#include <vector>
#include <fstream>
#include <sstream>

int main()
{
    std::cout << "Gone in 60 Seconds!\n";//https://carbuzz.com/features/beyond-eleanor-gone-in-60-seconds-car-names#:~:text=The%20Complete%20List%20Of%20Gone%20In%2060%20Seconds,8%201961%20Porsche%20Speedster%20-%20%22Natalie%22%20More%20items


    std::vector<Car> garage;
    garage.push_back(Car(1967, "Ford", "Shelby Mustang GT500"));
    garage.push_back(Car(1956, "Ford", "T Bird"));
    garage.push_back(Car(1961, "Porsche", "Speedster"));
    garage.push_back(Car(1965, "Pontiac", "GTO"));
    garage.push_back(Car(1969, "Plymouth", "Hemi Cuda"));



    /*
        ╔═════════════╗
        ║ Serializing ║
        ╚═════════════╝

        Saving the state (data) of objects

    */
    char dataDelim = '|';//separates cars. EX: car1|car2|car3
    char objDelim = ';';//separates data inside a car. EX: 1967;Ford;Shelby Mustang GT500


    std::ofstream file("myGarage.csv");
    bool isFirst = true;
    for (auto& car : garage)
    {
        if (!isFirst)
            file << dataDelim;
        car.serialize(file, objDelim);
        isFirst = false;
    }
    file.close();


    /*
        ╔═══════════════╗
        ║ Deserializing ║
        ╚═══════════════╝

        Recreating the objects from the saved state (data) of objects

    */
    std::vector<Car> newGarage;
    std::ifstream inFile("myGarage.csv");
    std::string line;
    while (!inFile.eof())
    {
        std::getline(inFile, line);

        std::string carCSV;
        std::stringstream carParts(line);
        while (std::getline(carParts, carCSV, dataDelim))
        {
            //deserialize the car
            Car nextCar(carCSV, objDelim);
            newGarage.push_back(nextCar);
        }
    }

    inFile.close();

    std::cout << "  NEW Garage  \n";
    for (auto& newCar : newGarage)
        std::cout << newCar.vehicleInformation() << "\n";
}