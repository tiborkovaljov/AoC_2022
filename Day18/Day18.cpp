#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>
#include <tuple>


int main()
{
    std::ifstream file("C:\\Users\\Tibor\\Desktop\\drawer\\gss\\aoc2022\\aoc2022_cpp\\Day18\\day18.in");
    std::vector<std::string> lines;
    std::string line2;

    while(std::getline(file, line2)) {
        lines.push_back(line2);
    }

    file.close();

    std::set<std::tuple<int, int, int>> rocks;
    for(const auto& line : lines) {
        std::stringstream ss(line);
        int x, y, z;
        char comma;
        ss >> x >> comma >> y >> comma >> z;
        rocks.insert(std::make_tuple(x, y, z));
    }

    int total = 0;

    for(const auto& rock : rocks) {
        int x, y, z;
        std::tie(x, y, z) = rock;

        for(const auto& delta : std::vector<std::tuple<int, int, int>>{
                std::make_tuple(1, 0, 0), std::make_tuple(-1, 0, 0),
                std::make_tuple(0, 1, 0), std::make_tuple(0, -1, 0),
                std::make_tuple(0, 0, 1), std::make_tuple(0, 0, -1)}) {
            int dx, dy, dz;
            std::tie(dx, dy, dz) = delta;

            if(rocks.find(std::make_tuple(x + dx, y + dy, z + dz)) == rocks.end()) {
                total += 1;
            }
        }
    }

    std::cout << total << '\n';

    return 0;
}
