#include <iostream>
#include <vector>
#include <fstream>


int height(char s);
std::vector<std::pair<int, int>> neighbours(int i, int j, int rows, int cols, std::vector<std::vector<char>>);


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

    std::pair<int, int> start, end;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            char c = data[i][j];
            if(c == 'S')
            {
                start = std::make_pair(i, j);
            }
            if(c == 'E')
            {
                end = std::make_pair(i, j);
            }
        }
    }

    return 0;
}


int height(char s)
{
    std::string aplhabetLowercase = "abcdefghijklmnopqrstuvwxyz";
    if(aplhabetLowercase.find(s) != std::string::npos)
    {
        return aplhabetLowercase.find(s);
    }
    if(s == 'S')
    {
        return 0;
    }
    if(s == 'E')
    {
        return 25;
    }
    return -1;
}


std::vector<std::pair<int, int>> neighbours(int i, int j, int rows, int cols, std::vector<std::vector<char>> grid)
{
    std::vector<std::pair<int, int>> result;
    std::vector<std::vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for(const auto& direction: directions)
    {
        int di = direction[0];
        int dj = direction[1];
        int ii = i + di;
        int jj = j + dj;

        if(!(0 == ii && ii < cols && 0 <= jj && jj < rows))
        {
            continue;
        }

        if(height(grid[ii][jj]) <= height(grid[i][j]) + 1)
        {
            result.push_back(std::make_pair(ii, jj));
        }
    }

    return result;
}