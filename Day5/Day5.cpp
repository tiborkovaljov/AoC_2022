#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


int main()
{
    // 1.
    std::fstream input(R"(C:\Users\Tibor\Desktop\drawer\gss\aoc2022\aoc2022_cpp\Day5\day5.in)");
    std::vector<std::string> info;
    std::string line;
    while(std::getline(input, line)) {
        info.push_back(line);
    }

    input.close();

    //2.
    auto blankLine = -1;
    for(auto i = 0; i < info.size(); i++) {
        if(info[i].empty()) {
            blankLine = i;
            break;
        }
    }

    cout << blankLine << '\n';

}