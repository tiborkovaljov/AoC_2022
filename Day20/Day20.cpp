#include <iostream>
#include <vector>


template <typename T>
void enumerate(const std::vector<T>& container)
{
    for (auto it = container.begin(); it != container.end(); ++it) {
        std::cout << std::distance(container.begin(), it) << " " << *it << '\n';
    }
}


int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    

    return 0;
}