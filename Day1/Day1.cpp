#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

/* COMPLETED */

int main()
{
    std::fstream input(R"(C:\Users\Tibor\Desktop\drawer\gss\aoc2022\aoc2022_cpp\Day1\day1.in)");
    std::vector<std::string> info;
    std::string line;

    while(std::getline(input, line))
    {
        info.push_back(line);
    }

    input.close();

    int max = 0;
    int elf = 0;

    for(const std::string& item : info)
    {
        if(item.empty())
        {
            elf = 0;
        }
        else
        {
            int num = stoi(item);
            elf += num;
        }
        if(elf > max)
        {
            max = elf;
        }
    }

    std::cout << max << '\n';


    std::vector<int> elfs2;

    int elf2 = 0;

    for(const std::string& item : info)
    {
        if(item.empty())
        {
            elf2 = 0;
        }
        else
        {
            int num = stoi(item);
            elf2 += num;
        }
        elfs2.emplace_back(elf2);
    }

    std::sort(elfs2.begin(), elfs2.end());

    int top_three = elfs2[elfs2.size() - 1] + elfs2[elfs2.size() - 2] + elfs2[elfs2.size() - 3];

    std::cout << top_three << '\n';
}
