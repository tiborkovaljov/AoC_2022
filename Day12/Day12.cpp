#include <iostream>
#include <vector>
#include <fstream>


struct Coord {
    int x = 0;
    int y = 0;
};


int main()
{
    std::ifstream input("C:\\Users\\Tibor\\Desktop\\drawer\\gss\\AoC\\aoc2022\\aoc2022_cpp\\Day12\\day12.in");
    std::string line;
    std::vector<std::string> data;

    while(std::getline(input, line))
    {
        data.push_back(line);
    }

    int rows = data.size();
    int cols = data[0].size();

    std::vector<std::vector<char>> grid(rows, std::vector<char>(cols));

    Coord start;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            char c = data[i][j];
            if(c == 'S')
            {
                start = {
                    .x = i,
                    .y = j
                };
            }

            grid[i][j] = data[i][j];
        }
    }

    Coord player = start;
    int player_current_score = 'a';

    auto neighbour_score = [&](int x, int y) -> int {
        if(player.x+x < 0) { return 0; }
        if(player.y+y < 0) { return 0; }
        if(player.x+x > rows-1) { return 0; }
        if(player.y+y > cols-1) { return 0; }
        if(grid[player.x+x][player.y+y] == 'A') {return 0;}
        return grid[player.x+x][player.y+y];
    };

    int steps = 0;

    auto evaluate = [&]() {
        std::vector<std::pair<Coord, int>> dirs;
        dirs.push_back({{1, 0}, neighbour_score(1, 0)});
        dirs.push_back({{-1, 0}, neighbour_score(-1, 0)});
        dirs.push_back({{0, 1}, neighbour_score(0, 1)});
        dirs.push_back({{0, -1}, neighbour_score(0, -1)});

        for(auto& dir : dirs) {
            if(dir.second - 1 == player_current_score || (player_current_score == 'z' && grid[player.x + dir.first.x][player.y + dir.first.y] == 'E')) {
                grid[player.x][player.y] = 'A';
                player.x += dir.first.x;
                player.y += dir.first.y;
                player_current_score = dir.second;
                steps++;
                return;
            }
        }

        for(auto& dir : dirs) {
            if(dir.second == player_current_score) {
                grid[player.x][player.y] = 'A';
                player.x += dir.first.x;
                player.y += dir.first.y;
                steps++;
                return;
            }
        }
    };

    while(player_current_score != 'E') {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                std::cout << grid[i][j];
            }
            std::cout << std::endl;
        }

        if (player_current_score == 'A') { break; }
        evaluate();
        std::cout << '\n';
    }

    std::cout << steps << std::endl;

    return 0;
}
