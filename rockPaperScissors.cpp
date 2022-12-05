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

class PointConverter {
    public:
        PointConverter() {
            points['A'] = 1;
            points['B'] = 2;
            points['C'] = 3;

            points['X'] = 1;
            points['Y'] = 2;
            points['Z'] = 3;

            points['W'] = 6;
            points['L'] = 0;
            points['D'] = 3;
        }
        int getPoints(char c) {
            return points[c];
        }
        int getPoints(pair<char, char> p) {
            char me = p.second;
            char them = p.first;

            // Catch draw
            if ((me == 'X' && them == 'A') || (me == 'Y' && them == 'B') || (me == 'Z' && them == 'C')) {
                return getPoints('D') + getPoints(me);
            }

            // Figure out who won
            if (me == 'X' && them == 'B') { // X (Rock) loses to B (Paper)
                return getPoints('L') + getPoints(me);

            } else if (me == 'X' && them == 'C') { // X (Rock) beats C (Scissors)
                return getPoints('W') + getPoints(me);

            } else if (me == 'Y' && them == 'A') { // Y (Paper) beats to A (Rock)
                return getPoints('W') + getPoints(me);

            } else if (me == 'Y' && them == 'C') { // Y (Paper) loses to C (Scissors)
                return getPoints('L') + getPoints(me);

            } else if (me == 'Z' && them == 'A') { // Z (Scissors) loses to A (Rock)
                return getPoints('L') + getPoints(me);

            } else if (me == 'Z' && them == 'B') { // Z (Scissors) beats B (Paper)
                return getPoints('W') + getPoints(me);

            } else {
                cout << "Error: " << me << " vs " << them << endl;
                exit(EXIT_FAILURE);
            }
        }

        pair<char, char> decode(pair<char, char> next) {
            // Decode the next move
            char me;
            char them = next.first;
            char result = next.second;

            if (result == 'Z') { // I won
                if (them == 'A') { // They played Rock
                    me = 'Y'; // I played Paper
                } else if (them == 'B') { // They played Paper
                    me = 'Z'; // I played Scissors
                } else if (them == 'C') { // They played Scissors
                    me = 'X'; // I played Rock
                }
            } else if (result == 'X') { // I lost
                if (them == 'A') { // They played Rock
                    me = 'Z';
                } else if (them == 'B') { // They played Paper
                    me = 'X';
                } else if (them == 'C') { // They played Scissors
                    me = 'Y';
                }
            } else if (result == 'Y') { // Draw
                if (them == 'A') { // They played Rock
                    me = 'X';
                } else if (them == 'B') { // They played Paper
                    me = 'Y';
                } else if (them == 'C') { // They played Scissors
                    me = 'Z';
                }
            } else {
                cout << "Error: " << them << " vs " << result << endl;
                exit(EXIT_FAILURE);
            }

            return(make_pair(them, me));
        }
        
    private:
        map<char, int> points;
};

class StrategyGuide {
    public:
        StrategyGuide() {
            // Open file
            ifstream file("strategyGuide.txt");

            // Read file
            string line;
            while (getline(file, line)) {
                strat.push_back(make_pair(line[0], line[2]));
            }

            // Close file
            file.close();

            current = 0;
        }

        pair<char, char> getNext() {
            pair<char, char> next = strat[current];
            current++;
            return next;
        }

        bool hasNext() {
            return current < strat.size();
        }

        void restart() {
            current = 0;
        }
    private:
        vector<pair<char, char>> strat;
        int current;
};

int main() {
    // Initalize variables
    PointConverter pc;
    StrategyGuide sg;\
    int total = 0;

    // Loop through strategy guide
    while (sg.hasNext()) {
        // Get next move
        pair<char, char> next = sg.getNext();

        // Decode move
        next = pc.decode(next);
        cout << "I played " << next.second << " and they played " << next.first << endl;

        // Get points
        int p = pc.getPoints(make_pair(next.first, next.second));
        cout << "I got " << p << " points" << endl;

        // Add round points to total
        total += p;
    }

    cout << "Total points: " << total << endl;
}