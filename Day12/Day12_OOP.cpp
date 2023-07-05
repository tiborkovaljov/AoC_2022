#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <fstream>

enum struct Solution: int {
    part1, part2
};

struct Coords {
    int x;
    int y;
    int steps;
};

class Day12 {
public:
    Solution solution = {};
    Day12(Solution sol) : solution{sol} {};

    int solve()
    {
        /* 1 */
        std::ifstream input("C:\\Users\\Tibor\\Desktop\\drawer\\gss\\AoC\\aoc2022\\aoc2022_cpp\\Day12\\day12.in");
        std::string line;
        std::vector<std::string> data = {};

        while (std::getline(input, line))
        {
            data.push_back(line);
        }

        /* 2 */
        Coords start;
        Coords end;

        for (int i = 0; i < data.size(); i++)
        {
            for (int j = 0; j < data[i].size(); j++)
            {
                if (data[i][j] == 'S')
                {
                    data[i][j] = 'a';
                    if (solution == Solution::part1)
                    {
                        start.x = i;
                        start.y = j;
                        start.steps = 0;
                    }
                }
                if (data[i][j] == 'E')
                {
                    data[i][j] = 'z';
                    end.x = i;
                    end.y = j;
                    end.steps = 0;
                }
            }
        }

        /* 3 */
        std::vector<Coords> directions = {
            Coords{1, 0, 0},
            Coords{0, 1, 0},
            Coords{-1, 0, 0},
            Coords{0, -1, 0}
        };

        /* 4 */
        std::vector<std::vector<bool>> visited (
            data.size(),
            std::vector<bool> (data[0].size(), false)
        );

        /* 5 */
        std::queue<Coords> coords = {};

        if (solution == Solution::part1)
        {
            coords.push(start);
        }
        else
        {
            coords.push(end);
        }

        /* 6 */
        auto inBounds = [&](const Coords& point) -> bool {
            return point.x >= 0 && point.y >= 0 && point.x < data.size() && point.y < data[0].size();
        };

        /* 7 */
        while(!coords.empty())
        {
            Coords currentCoord = coords.front();
            coords.pop();

            if (visited[currentCoord.x][currentCoord.y]) { continue; }

            visited[currentCoord.x][currentCoord.y] = true;

            if (solution == Solution::part1)
            {
                if (currentCoord.x == end.x && currentCoord.y == end.y)
                { return currentCoord.steps; }
            }
            else
            {
                if(data[currentCoord.x][currentCoord.y] == 'a')
                {
                    return currentCoord.steps;
                }
            }

            for (const Coords& dir: directions)
            {
                const Coords newPoint = Coords {
                    .x = currentCoord.x + dir.x,
                    .y = currentCoord.y + dir.y,
                    .steps = currentCoord.steps + 1
                };

                if(!inBounds(newPoint)) { continue; }
                if(visited[newPoint.x][newPoint.y]) { continue; }
                if (solution == Solution::part1)
                {
                    if ((data[currentCoord.x][currentCoord.y] + 1) < (data[newPoint.x][newPoint.y])) { continue; }
                }
                else
                {
                    if ((data[currentCoord.x][currentCoord.y]) > (data[newPoint.x][newPoint.y]) + 1) { continue; }
                }


                coords.push(newPoint);
            }

        }

        return 0;
    }
};

int main()
{
    Day12 solver(Solution::part1);

    std::cout << solver.solve() << '\n';

    solver.solution = Solution::part2;

    std::cout << solver.solve() << '\n';

    return 0;
}

