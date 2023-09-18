//Quentin Epps
//  main.cpp
//  Project 1
//
// A program that prompts the user to enter the starting population, birth and death rates and the number of years to project. The program should then calculate and print the growth rate and the estimated population after each year.
//  Created by Quentin on 9/8/23.
//

#include <iostream>
using namespace std;

int popConvert(int);

#include <iostream>

// Function to calculate population growth rate
double GrowthRate(double birthRate, double deathRate) {
    return birthRate - deathRate;
}

// Function to calculate estimated population for the next year
double EstimatedPopulation(double currentPopulation, double birthRate, double deathRate) {
    // Check for invalid inputs
    if (birthRate < 0 || deathRate < 0 || currentPopulation < 2) {
        cout << "Invalid input. Birth rate, death rate, and population must be non-negative, and population should be at least 2." << endl;
        return -1;
    }

    // Calculate the estimated population for the next year
    return currentPopulation + (birthRate * currentPopulation) / 100 - (deathRate * currentPopulation) / 100;
}

int main() {
    double starting_Population, birthRate, deathRate;
    int years_Project;

    // Get user input
    cout << "Enter starting population: ";
    cin >> starting_Population;

    cout << "Enter birth rate: ";
    cin >> birthRate;

    cout << "Enter death rate: ";
    cin >> deathRate;

    cout << "Enter number of years to project: ";
    cin >> years_Project;

    // Calculate and print population growth rate
    double growthRate = GrowthRate(birthRate, deathRate);
    cout << "Population Growth Rate: " << growthRate << "%" << endl;

    // Project population for each year
    for (int i = 1; i<= years_Project; i++) {
        double estimatedPop = EstimatedPopulation(starting_Population, birthRate, deathRate);

        if (estimatedPop != -1) {
            cout << "Year " << i << ": Estimated Population = " << estimatedPop <<endl;
            starting_Population = estimatedPop; // Update the current population for the next iteration
        } else {
            break; // Exit the loop in case of invalid input
        }
    }

    return 0;
}
