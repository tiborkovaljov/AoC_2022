#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>

using namespace std;


int main()
{
    // 1. -> bereme info z inputu
    // 2. ->

    ifstream input(R"(C:\Users\Tibor\Desktop\drawer\gss\aoc2022\aoc2022_py\day6\day6.in)");
    string info;
    getline(input, info);

    /* PART 1 */

    for(int i = 4; i < info.size(); i++) {
        unordered_set<char> s;
        for(int j = i - 4; j < i; j++) {
            s.insert(info[j]);
        }
        if(s.size() == 4) {
            cout << i << '\n';
            break;
        }
    }

    /* PART 2 */

    for(int i = 14; i < info.size(); i++) {
        unordered_set<char> s;
        for(int j = i - 14; j < i; j++) {
            s.insert(info[j]);
        }
        if(s.size() == 14) {
            cout << i << '\n';
            break;
        }
    }
}