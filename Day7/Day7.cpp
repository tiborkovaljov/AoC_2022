#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>


int main()
{
    std::ifstream file("C:\\Users\\Tibor\\Desktop\\drawer\\gss\\aoc2022\\aoc2022_cpp\\Day7\\day7.in");
    std::vector<std::string> commands;
    std::string command_input;
    while (std::getline(file, command_input)) {
        commands.push_back(command_input);
    }

    std::string path = "/home";
    std::unordered_map<std::string, int> dirs;
    dirs["/home"] = 0;

    for(const auto& command : commands) {
        if(command[0] == '$') {
            if(command.substr(2, 2) == "ls") {
                // Do nothing when listing directories or files
            }
            else if(command.substr(2, 2) == "cd") {
                if(command.substr(5, 1) == "/") {
                    path = "/home";
                }
                else if(command.substr(5, 2) == "..") {
                    path = path.substr(0, path.rfind('/'));
                }
                else {
                    std::string dir_name = command.substr(5);
                    path = path + "/" + dir_name;
                    dirs[path] = 0;
                }
            }
        }
        else if(command.substr(0, 3) == "dir") {
            // Do nothing when listing directories available
        }
        else {
            int size = std::stoi(command.substr(0, command.find(' ')));
            std::string dir = path;
            for(int i = 0; i < std::count(path.begin(), path.end(), '/'); i++) {
                dirs[dir] += size;
                dir = dir.substr(0, dir.rfind('/'));
            }
        }
    }

    int total = 0;
    int limit = 30000000 - (70000000 - dirs["/home"]);

    std::vector<int> valid_dirs;

    for(const auto& dir : dirs) {
        if (dir.second <= 100000) {
            total += dir.second;
        }
        if(limit <= dir.second) {
            valid_dirs.push_back(dir.second);
        }
    }

    int smallest = *std::min_element(valid_dirs.begin(), valid_dirs.end());

    std::cout << "Part 1: " << total << '\n';
    std::cout << "Part 2: " << smallest << '\n';

    return 0;
}

