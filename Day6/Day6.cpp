#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>


int main()
{
    std::ifstream input(R"(C:\Users\Tibor\Desktop\drawer\gss\aoc2022\aoc2022_py\day6\day6.in)");
    std::string info;
    getline(input, info);

    /* PART 1 */

    for(int i = 4; i < info.size(); i++) {
        std::unordered_set<char> s;
        for(int j = i - 4; j < i; j++) {
            s.insert(info[j]);
        }
        if(s.size() == 4) {
            std::cout << i << '\n';
            break;
        }
    }

    /* PART 2 */

    int n = info.size();
    for(int i = 14; i < n; i++) {
        std::unordered_set<char> s(info.begin() + i - 14, info.begin() + i);
        if (s.size() == 14) {
            std::cout << i << '\n';
            break;
        }
    }

//    for(int i = 14; i < info.size(); i++) {
//        std::unordered_set<char> s;
//        for(int j = i - 14; j < i; j++) {
//            s.insert(info[j]);
//        }
//        if(s.size() == 14) {
//            std::cout << i << '\n';
//            break;
//        }
//    }


}