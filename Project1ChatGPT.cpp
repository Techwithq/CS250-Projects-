#include <iostream>

// Function to calculate population growth rate
double GrowthRate(double birthRate, double deathRate) {
    return birthRate - deathRate;
}

// Function to calculate estimated population for the next year
double EstimatedPopulation(double currentPopulation, double growthRate) {
    return currentPopulation + (growthRate * currentPopulation) / 100;
}

int main() {
    double startingPopulation, birthRate, deathRate;
    int yearsToProject;

    // Get user input
    std::cout << "Enter the starting population: ";
    std::cin >> startingPopulation;

    std::cout << "Enter the birth rate (as a percentage): ";
    std::cin >> birthRate;

    std::cout << "Enter the death rate (as a percentage): ";
    std::cin >> deathRate;

    std::cout << "Enter the number of years to project: ";
    std::cin >> yearsToProject;

    // Calculate and print population growth rate
    double growthRate = GrowthRate(birthRate, deathRate);
    std::cout << "Population Growth Rate: " << growthRate << "%" << std::endl;

    // Project population for each year
    for (int year = 1; year <= yearsToProject; year++) {
        double estimatedPop = EstimatedPopulation(startingPopulation, growthRate);
        std::cout << "Year " << year << ": Estimated Population = " << estimatedPop << std::endl;
        startingPopulation = estimatedPop; // Update the current population for the next iteration
    }

    return 0;
}
