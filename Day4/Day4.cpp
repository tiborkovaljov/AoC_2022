#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main()
{
    /* PART 1 */

    // 1.
    std::ifstream input(R"(C:\Users\Tibor\Desktop\drawer\gss\aoc2022\aoc2022_cpp\Day4\day4.in)");
    std::vector<std::string> info;
    std::string line;
    while(getline(input, line)) {
        info.push_back(line);
    }

    // 2.
    int ans = 0;
    int ans2 = 0;

    // 3.
    for(std::string& elves : info) {
        std::string one, two;
        size_t position = elves.find(',');
        one = elves.substr(0, position);
        two = elves.substr(position + 1);
        int a1, b1, a2, b2;
        position = one.find('-');
        a1 = stoi(one.substr(0, position));
        a2 = stoi(one.substr(position + 1));
        position = two.find('-');
        b1 = stoi(two.substr(0, position));
        b2 = stoi(two.substr(position + 1));
        // 4.
        if ((a1 <= b1 && b2 <= a2) || (b1 <= a1 && a2 <= b2)) {
            ans += 1;
        }

        /* PART 2 */

        // 1.
        if(!(a2 < b1 || a1 > b2)) {
            ans2 += 1;
        }

    }

    std::cout << ans << '\n';
    std::cout << ans2 << '\n';

    return 0;
}
