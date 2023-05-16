#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


int main()
{
    std::ifstream file("C:\\Users\\Tibor\\Desktop\\drawer\\gss\\aoc2022\\aoc2022_cpp\\Day8\\day8.in");
    std::vector<std::string> data;
    std::string line;

    while(std::getline(file, line)) {
        data.push_back(line);
    }

    int ROWS = data.size();
    int COLUMNS = data[0].size();

    int edges = (ROWS * 2) + ((COLUMNS - 2) * 2);
    int total = edges;
    std::vector<int> scores;

    // Iterate through trees not on edges
    for(int row = 1; row < ROWS - 1; row++) {
        for(int col = 1; col < COLUMNS - 1; col++) {
            char tree = data[row][col];
            // Get all horizontal and vertical trees
            std::vector<char> left, right, up, down;

            for(int i = 1; i <= col; i++) {
                left.push_back(data[row][col - i]);
            }

            for(int i = 1; i < COLUMNS - col; i++) {
                right.push_back(data[row][col + i]);
            }

            for(int i = 1; i <= row; i++) {
                up.push_back(data[row - i][col]);
            }

            for(int i = 1; i < ROWS - row; i++) {
                down.push_back(data[row + i][col]);
            }

            // === PART 1 ===
            // Check if tallest tree on all sides block out view
            if(*std::max_element(left.begin(), left.end()) < tree ||
                *std::max_element(right.begin(), right.end()) < tree ||
                *std::max_element(up.begin(), up.end()) < tree ||
                *std::max_element(down.begin(), down.end()) < tree) {
                total += 1;
            }

            // === PART 2 ===
            int score = 1;
            for(const auto& lst : {left, right, up, down}) {
                int tracker = 0;
                for(int i = 0; i < lst.size(); i++) {
                    if (lst[i] < tree) {
                        tracker += 1;
                    } else if (lst[i] == tree) {
                        tracker += 1;
                        break;
                    } else {
                        break;
                    }
                }
                score *= tracker;
            }
            scores.push_back(score);
        }
    }

    std::cout << "Part 1: " << total << std::endl;
    std::cout << "Part 2: " << *std::max_element(scores.begin(), scores.end()) << std::endl;

    return 0;
}