/**
 * @file rockPaperScissors.cpp
 * @author Charles "Blue" Hartsell (GitHub: @tealblu)
 * @brief 
 * @version 0.1
 * @date 2022-12-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

int main() {
    vector<pair<char, char>> strategyGuide;
    int total = 0;
    map<char, int> scores;

    // Insert score values
    scores.insert(pair<char, int>('R', 1));
    scores.insert(pair<char, int>('P', 2));
    scores.insert(pair<char, int>('S', 3));
    scores.insert(pair<char,int>('L', 0));
    scores.insert(pair<char, int>('T', 3));
    scores.insert(pair<char, int>('W', 6));

    // Open file
    ifstream strategyFile("strategyGuide.txt");

    // Check if file is open
    if (strategyFile.is_open()) {
        // Read file
        string line;
        while (getline(strategyFile, line)) {
            // Add to vector
            strategyGuide.push_back(make_pair(line[0], line[2]));
            cout << "Added " << line[0] << " " << line[2] << endl;
        }
    }

    // Close file
    strategyFile.close();

    // Iterate through vector, totaling scores
    // Rock: A, X; Paper: B, Y; Scissors: C, Z
    // Points: Rock: 1, Paper: 2, Scissors: 3, Lose: 0, Tie: 3, Win: 6
    for (int i = 0; i < strategyGuide.size(); i++) {
        int roundScore = 0;
        if (strategyGuide[i].first == 'A' && strategyGuide[i].second == 'X') { // Rock vs Rock (tie)
            roundScore += scores.at('R') + scores.at('T');

        } else if (strategyGuide[i].first == 'B' && strategyGuide[i].second == 'Y') { // Paper vs Paper (tie)
            roundScore += scores.at('P') + scores.at('T');

        } else if (strategyGuide[i].first == 'C' && strategyGuide[i].second == 'Z') { // Scissors vs Scissors (tie)
            roundScore += scores.at('S') + scores.at('T');

        } else if (strategyGuide[i].first == 'X' && strategyGuide[i].second == 'B') { // Rock vs Paper (lose)
            roundScore += scores.at('R') + scores.at('L');

        } else if (strategyGuide[i].first == 'Y' && strategyGuide[i].second == 'C') { // Paper vs Scissors (lose)
            roundScore += scores.at('P') + scores.at('L');

        } else if (strategyGuide[i].first == 'Z' && strategyGuide[i].second == 'A') { // Scissors vs Rock (lose)
            roundScore += scores.at('S') + scores.at('L');

        } else if(strategyGuide[i].first == 'X' && strategyGuide[i].second == 'C') { // Rock vs Scissors (win)
            roundScore += scores.at('R') + scores.at('W');
            
        } else if (strategyGuide[i].first == 'Y' && strategyGuide[i].second == 'A') { // Paper vs Rock (win)
            roundScore += scores.at('P') + scores.at('W');
            
        } else if (strategyGuide[i].first == 'Z' && strategyGuide[i].second == 'B') { // Scissors vs Paper (win)
            roundScore += scores.at('S') + scores.at('W');
        }

        total += roundScore;
    }

    cout << "total score: " << total << endl;
}