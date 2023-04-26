#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


void part1_day1()
{
    // 1. -> Bereme informace z inputu + tvorba vektoru, ve kterem budou ulozeny informace z inputu
    // 2. -> Hledani elfa, ktery nese nejvice kalorii (int max)
    // 3. -> Vyspani souctu kalorii tohoto elfa

    // 1.
    std::fstream input("C:\\Users\\Tibor\\Desktop\\drawer\\gss\\aoc2022\\aoc2022_cpp\\Day1\\day1.in");
    std::vector<std::string> info;
    std::string line;
    while(std::getline(input, line)) {
        info.push_back(line);
    }

    input.close();

    // 2.
    int max = 0;
    int elf = 0;

    for(std::string item : info) {
        if(item == "") {
            elf = 0;
        }
        else {
            int num = stoi(item);
            elf += num;
        }
        if(elf > max) {
            max = elf;
        }
    }

    // 3.
    std::cout << max << '\n';
}


void part2_day1()
{
    // 1. -> Bereme informace z inputu + tvorba vektoru, ve kterem budou ulozeny informace z inputu
    // 2. -> Tvorba vektoru k drzeni poscitanych kalorii elfu
    // 3. -> Projdeme info, poscitame kalorie elfu a pushneme kazdeho elfa do naseho vektoru
    // 4. -> sortneme vektor od nejmensiho po nejvetsi
    // 5. -> Tyto vysledky poscitame a toto je nas vysledek

    // 1.
    std::fstream input("C:\\Users\\Tibor\\Desktop\\drawer\\gss\\aoc2022\\aoc2022_cpp\\Day1\\day1.in");
    std::vector<std::string> info;
    std::string line;
    while(std::getline(input, line)) {
        info.push_back(line);
    }

    input.close();

    // 2.
    std::vector<int> elfs;

    // 3.
    int elf = 0;
    for(std::string item : info) {
        if(item == "") {
            elf = 0;
        }
        else {
            int num = stoi(item);
            elf += num;
        }
        elfs.emplace_back(elf);
    }

    // 4.
    std::sort(elfs.begin(), elfs.end());

    // 5.
    int top_three = elfs[elfs.size() - 1] + elfs[elfs.size() - 2] + elfs[elfs.size() - 3];

    std::cout << top_three << '\n';
}


int main()
{
    part1_day1();
    part2_day1();
}
