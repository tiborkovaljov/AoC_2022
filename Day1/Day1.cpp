#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


int main()
{
    /* PART 1 */

    // 1.
    std::fstream input(R"(C:\Users\Tibor\Desktop\drawer\gss\aoc2022\aoc2022_cpp\Day1\day1.in)");
    std::vector<std::string> info;
    std::string line;
    while(std::getline(input, line)) {
        info.push_back(line);
    }

    input.close();

    // 2.
    int max = 0;
    int elf = 0;

    // 3.
    for(const std::string& item : info) {
        if(item.empty()) {
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

    // 4.
    std::cout << max << '\n';


    /* PART 2 */

    // 1.
    std::vector<int> elfs2;

    // 2.
    int elf2 = 0;
    for(const std::string& item : info) {
        if(item.empty()) {
            elf2 = 0;
        }
        else {
            int num = stoi(item);
            elf2 += num;
        }
        elfs2.emplace_back(elf2);
    }


    // 3.
    std::sort(elfs2.begin(), elfs2.end());

    // 4.
    int top_three = elfs2[elfs2.size() - 1] + elfs2[elfs2.size() - 2] + elfs2[elfs2.size() - 3];

    std::cout << top_three << '\n';
}
