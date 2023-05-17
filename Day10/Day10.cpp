#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>


int main()
{
    std::ifstream file("C:\\Users\\Tibor\\Desktop\\drawer\\gss\\aoc2022\\aoc2022_cpp\\Day10\\day10.in");
    std::string line2;
    std::vector<std::string> lines;

    // Read lines from the file
    while(std::getline(file, line2)) {
        lines.push_back(line2);
    }
    file.close();

    int value = 1;
    int cycle_time = 0;
    int answer = 0;
    std::vector<int> wanted = {20, 60, 100, 140, 180, 220};

    for(const auto& line : lines) {
        std::istringstream iss(line);
        std::vector<std::string> parts;

        // Split the line into parts
        std::string part;
        while(iss >> part) {
            parts.push_back(part);
        }

        if(parts[0] == "noop") {
            cycle_time += 1;
            if(std::find(wanted.begin(), wanted.end(), cycle_time) != wanted.end()) {
                answer += cycle_time * value;
            }
        }

        else if(parts[0] == "addx") {
            int num = std::stoi(parts[1]);
            value += num;
            cycle_time += 1;
            if(std::find(wanted.begin(), wanted.end(), cycle_time) != wanted.end()) {
                answer += cycle_time * (value - num);
            }
            cycle_time += 1;
            if(std::find(wanted.begin(), wanted.end(), cycle_time) != wanted.end()) {
                answer += cycle_time * (value - num);
            }
        }
    }

    std::cout << answer << std::endl;

    return 0;
}
