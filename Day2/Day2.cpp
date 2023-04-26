#include <iostream>
#include <fstream>
#include <vector>
#include <map>


void part1_day2()
{
    // 1. -> Bereme informace z inputu + tvorba vektoru, ve kterem budou ulozeny informace z inputu
    // 2. -> Tvorba slovniku, ktery bude drzet informace o bodovani
    // 3. -> Tvorba promenne pro scitani bodu
    // 4. -> For cyklem projdeme info z inputu a dle toho, co tam bude, pricteme dane body k promenne
    // 5. -> Vypsani vysledku

    // 1.
    std::fstream input("C:\\Users\\Tibor\\Desktop\\drawer\\gss\\aoc2022\\aoc2022_cpp\\Day2\\day2.in");
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
    for(std::string game : info) {
        points += posibilities[game];
    }

    // 5.
    std::cout << points << '\n';
}


void part2_day2()
{
    // 1. -> Bereme informace z inputu + tvorba vektoru, ve kterem budou ulozeny informace z inputu
    // 2. -> Tvorba predelaneho slovniku, ktery bude drzet informace o bodovani
    // 3. -> Tvorba promenne pro scitani bodu
    // 4. -> For cyklem projdeme info z inputu a dle toho, co tam bude, pricteme dane body k promenne
    // 5. -> Vypsani vusledku

    // 1.
    std::fstream input("C:\\Users\\Tibor\\Desktop\\drawer\\gss\\aoc2022\\aoc2022_cpp\\Day2\\day2.in");
    std::vector<std::string> info;
    std::string line;
    while(std::getline(input, line)) {
        info.push_back(line);
    }

    input.close();

    // 2.
    std::map<std::string, int> posibilities;

    // lost - 0, draw - 3, won - 6 points

    posibilities["A X"] = 3;
    posibilities["A Y"] = 4;
    posibilities["A Z"] = 8;
    posibilities["B X"] = 1;
    posibilities["B Y"] = 5;
    posibilities["B Z"] = 9;
    posibilities["C X"] = 2;
    posibilities["C Y"] = 6;
    posibilities["C Z"] = 7;

    // 3.
    int points2 = 0;

    // 4.
    for(std::string game : info) {
        points2 += posibilities[game];
    }

    // 5.
    std::cout << points2 << '\n';
}


int main()
{
    part1_day2();
    part2_day2();
}