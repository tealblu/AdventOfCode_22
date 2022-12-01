#include "elf.h"

Elf::Elf() {
    totalCalories = 0;
    bag = {};
}

Elf::Elf(int totalCalories, vector<int> bag) {
    this->totalCalories = totalCalories;
    this->bag = bag;
}

void Elf::addToBag(int calories) {
    bag.push_back(calories);
    totalCalories += calories;
}