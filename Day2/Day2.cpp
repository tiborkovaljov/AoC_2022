#include <iostream>
#include <fstream>
#include <vector>
#include <map>


int main()
{
    /* PART 1 */

    /* OUTCOMES */
    // A vs X = DRAW = (1 + 3) = 4
    // A vs Y = WIN  = (2 + 6) = 8
    // A vs Z = LOSS = (3 + 0) = 3
    // B vs X = LOSS = (1 + 0) = 1
    // B vs Y = DRAW = (2 + 3) = 5
    // B vs Z = WIN  = (3 + 6) = 9
    // C vs X = WIN  = (1 + 6) = 7
    // C vs Y = LOSS = (2 + 0) = 2
    // C vs Z = DRAW = (3 + 3) = 6

    // 1.
    std::fstream input(R"(C:\Users\Tibor\Desktop\drawer\gss\aoc2022\aoc2022_cpp\Day2\day2.in)");
    std::vector<std::string> info;
    std::string line;
    while(std::getline(input, line)) {
        info.push_back(line);
    }

    input.close();

    // 2.
    std::map<std::string, int> posibilities;

    posibilities["A X"] = 4;
    posibilities["A Y"] = 8;
    posibilities["A Z"] = 3;
    posibilities["B X"] = 1;
    posibilities["B Y"] = 5;
    posibilities["B Z"] = 9;
    posibilities["C X"] = 7;
    posibilities["C Y"] = 2;
    posibilities["C Z"] = 6;

    // 3.
    int points = 0;

    // 4.
    for(const std::string& game : info) {
        points += posibilities[game];
    }

    // 5.
    std::cout << points << '\n';


    /* PART 2 */


    std::map<std::string, int> posibilities2;

    // lost - 0, draw - 3, won - 6 points
    // X - lose, Y - draw, Z - win

    posibilities["A X"] = 3;
    posibilities["A Y"] = 4;
    posibilities["A Z"] = 8;
    posibilities["B X"] = 1;
    posibilities["B Y"] = 5;
    posibilities["B Z"] = 9;
    posibilities["C X"] = 2;
    posibilities["C Y"] = 6;
    posibilities["C Z"] = 7;

    // 2.
    int points2 = 0;

    // 3.
    for(const std::string& game : info) {
        points2 += posibilities[game];
    }

    // 4.
    std::cout << points2 << '\n';
}
