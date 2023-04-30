#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    /* PART 1 */

    // 1. -> Bereme informace z inputu, tvorba vektoru, ve kterem budou nase informace

    std::ifstream input(R"(C:\Users\Tibor\Desktop\drawer\gss\aoc2022\aoc2022_py\day4\day4.in)");
    std::vector<std::string> info;
    std::string line;

    while (std::getline(input, line)) {
        info.push_back(line);
    }



    return 0;
}