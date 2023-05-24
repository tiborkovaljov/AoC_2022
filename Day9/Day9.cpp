#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>


std::vector<std::string> splitString(const std::string& str, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while(std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}


bool touching(int x1, int y1, int x2, int y2)
{
    return std::abs(x1 - x2) <= 1 && std::abs(y1 - y2) <= 1;
}


void move(int dx, int dy, int& hx, int& hy, int& tx, int& ty, std::set<std::pair<int, int>>& tail_visited)
{
    hx += dx;
    hy += dy;

    if(!touching(hx, hy, tx, ty)) {
        int sign_x = (hx == tx) ? 0 : (hx - tx) / std::abs(hx - tx);
        int sign_y = (hy == ty) ? 0 : (hy - ty) / std::abs(hy - ty);

        tx += sign_x;
        ty += sign_y;
    }

    tail_visited.insert(std::make_pair(tx, ty));
}


int main()
{
    std::ifstream file("C:\\Users\\Tibor\\Desktop\\drawer\\gss\\aoc2022\\aoc2022_cpp\\Day9\\day9.in");
    std::string line2;
    std::vector<std::string> lines;

    while(std::getline(file, line2)) {
        lines.push_back(line2);
    }

    int hx = 0, hy = 0;
    int tx = 0, ty = 0;
    std::set<std::pair<int, int>> tail_visited;
    tail_visited.insert(std::make_pair(tx, ty));

    std::map<std::string, std::pair<int, int>> direction_map = {
            {"R", {1, 0}},
            {"U", {0, 1}},
            {"L", {-1, 0}},
            {"D", {0, -1}}
    };

    for(const std::string& line : lines) {
        std::vector<std::string> parts = splitString(line, ' ');
        std::string op = parts[0];
        int amount = std::stoi(parts[1]);
        std::pair<int, int> direction = direction_map[op];
        int dx = direction.first;
        int dy = direction.second;

        for(int i = 0; i < amount; i++) {
            move(dx, dy, hx, hy, tx, ty, tail_visited);
        }
    }

    std::cout << tail_visited.size() << std::endl;

    return 0;
}