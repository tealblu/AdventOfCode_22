#ifndef ELF_H
#define ELF_H

#include <vector>

using namespace std;

class Elf {
    public:
        int totalCalories;
        vector<int> bag;

        Elf();
        Elf(int totalCalories, vector<int> bag);

        void addToBag(int calories);
};

#endif