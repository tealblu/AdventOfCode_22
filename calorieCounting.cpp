/**
 * @file calorieCounting.cpp
 * @author Charles "Blue" Hartsell (GitHub: tealblu)
 * @brief Advent of Code 2022 Day 1: Calorie Counting
 * @version 0.1
 * @date 2022-12-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>

#include "elf.h"

using namespace std;

int main() {
    cout << "Advent of Code 2022 Day 1: Calorie Counting" << endl << endl;

    // Init variables
    vector<Elf> elves;

    // Take input line by line
    string line;
    while (getline(cin, line)) {
        // Print the line
        cout << line << endl;

        // Add first elf
        if (elves.size() == 0) {
            elves.push_back(Elf());
        }

        // Parse input:
        // Check if input is an empty line AND if line is not first line
        if (line == "" && elves.size() > 0) {
            // If so, add a new elf to the vector
            elves.push_back(Elf());
        } else {
            // If not, add the input to the last elf's bag
            elves.back().addToBag(stoi(line));
        }
    }

    // Find elf with the most calories
    int maxCalories = 0;
    int maxCaloriesIndex = 0;
    for (int i = 0; i < elves.size(); i++) {
        if (elves[i].totalCalories > maxCalories) {
            maxCalories = elves[i].totalCalories;
            maxCaloriesIndex = i;
        }
    }

    // Print the elf with the most calories
    cout << "Elf with the most calories: " << maxCaloriesIndex + 1 << endl;

    // Print the elf's bag
    cout << "Bag: ";
    for (int i = 0; i < elves[maxCaloriesIndex].bag.size(); i++) {
        cout << elves[maxCaloriesIndex].bag[i] << " ";
    }

    // Print the elf's total calories
    cout << endl << "Total calories: " << maxCalories << endl;

    return EXIT_SUCCESS;
}