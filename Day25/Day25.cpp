#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>


int parse_snafu(const std::string& s, const std::unordered_map<std::string, int>& strToDigit);
std::string int_to_snafu(int n, const std::unordered_map<int, std::string>& digitToStr);


int main()
{
    std::ifstream file("C:\\Users\\Tibor\\Desktop\\drawer\\gss\\aoc2022\\aoc2022_cpp\\Day25\\day25.in");
    std::vector<std::string> lines;
    std::string line;
    while(std::getline(file, line)) {
        lines.push_back(line);
    }

    std::unordered_map<std::string, int> strToDigit = {
            {"0", 0},
            {"1", 1},
            {"2", 2},
            {"-", -1},
            {"=", -2}
    };

    std::unordered_map<int, std::string> digitToStr;
    for(const auto& pair : strToDigit) {
        int digit = pair.second;
        std::string str = pair.first;
        digitToStr[digit] = str;
    }

    int total = 0;
    for(const auto& line2 : lines) {
        total += parse_snafu(line2, strToDigit);
    }

    std::string snafuString = int_to_snafu(total, digitToStr);

    std::cout << snafuString;
}


int parse_snafu(const std::string& s, const std::unordered_map<std::string, int>& strToDigit)
{
    int total = 0;
    int d = s.length();
    int p = 1;
    std::string reversedStr(s.rbegin(), s.rend());
    for(int i = 0; i < d; i++) {
        total += p * strToDigit.at(std::string(1, reversedStr[i]));
        p *= 5;
    }
    return total;
}


std::string int_to_snafu(int n, const std::unordered_map<int, std::string>& digitToStr)
{
    std::string res = "";
    while(n > 0) {
        int d = ((n + 2) % 5) - 2;
        res += digitToStr.at(d);
        n -= d;
        n /= 5;
    }
    return std::string(res.rbegin(), res.rend());
}
