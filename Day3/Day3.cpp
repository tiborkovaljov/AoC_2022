#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;


int main()
{
    /* PART 1 */

    // 1.
    ifstream input(R"(C:\Users\Tibor\Desktop\drawer\gss\aoc2022\aoc2022_cpp\Day3\day3.in)");
    string line;
    unordered_map<char, int> letter_priority;
    vector<string> info;

    while (getline(input, line)) {
        info.push_back(line);
    }

    // 2.
    int total_sum = 0;

    // 3.
    int priority = 1;
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(char c : alphabet) {
        letter_priority[c] = priority;
        ++priority;
    }

    // 4.
    for(const auto& rucksack : info) {
        auto half = rucksack.length() / 2;
        string left = rucksack.substr(0, half);
        string right = rucksack.substr(half);
        // 5.
        for(char c : "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") {
            if(left.find(c) != string::npos && right.find(c) != string::npos) {
                total_sum += letter_priority[c];
            }
        }
    }

    cout << total_sum << '\n';


    /* PART 2 */

    total_sum = 0;

    int j = 3;
    for(int i = 0; i < info.size(); i += 3) {
        vector<string> rucksacks;
        for(int k = i; k < j; k++) {
            if(k < info.size()) {
                rucksacks.push_back(info[k]);
            }
        }
        j += 3;

        for(char c : "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") {
            bool found_in_all_rucksacks = true;
            for(const string& rucksack : rucksacks) {
                if(rucksack.find(c) == string::npos) {
                    found_in_all_rucksacks = false;
                    break;
                }
            }
            if(found_in_all_rucksacks) {
                total_sum += letter_priority[c];
            }
        }
    }

    cout << total_sum;

    return 0;
}

