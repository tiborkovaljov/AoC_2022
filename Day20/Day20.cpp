#include <iostream>
#include <vector>
#include <fstream>


int main()
{
    std::ifstream input("C:\\Users\\Tibor\\Desktop\\drawer\\gss\\AoC\\aoc2022\\aoc2022_cpp\\Day20\\day20.in");
    std::string line;
    std::vector<int> data;

    while(std::getline(input, line))
    {
        data.push_back(std::stoi(line));
    }

    for(int i = 0; i < data.size(); i++)
    {
        int steps = data[i];
        int currentIndex = i;

        if(steps >= 0)
        {
            while(steps > 0)
            {
                currentIndex = (currentIndex + 1) % data.size();
                steps--;
            }
        }
        else
        {
            while(steps < 0)
            {
                currentIndex = (currentIndex - 1 + data.size()) % data.size();
                steps++;
            }
        }

        data[currentIndex] = data[i];
    }

    int groveCoordinatesSum = 0;
    int currentIndex = 0;

    for(int i = 0; i < 3; i++)
    {
        currentIndex = (currentIndex + 1000) % data.size();
        groveCoordinatesSum += data[currentIndex];
    }

    std::cout << groveCoordinatesSum << '\n';

    return 0;
}
