#include <iostream>
#include <vector>
#include <fstream>



int main()
{
    std::vector<int> encryptedFile = {1, 2, -3, 3, -2, 0, 4};

    // Perform the mixing operation on the encrypted file
    for(int i = 0; i < encryptedFile.size(); i++)
    {
        int steps = encryptedFile[i];
        int currentIndex = i;

        // Move the number forward or backward in the circular list
        if(steps >= 0)
        {
            while(steps > 0)
            {
                currentIndex = (currentIndex + 1) % encryptedFile.size();
                steps--;
            }
        }
        else
        {
            while(steps < 0)
            {
                currentIndex = (currentIndex - 1 + encryptedFile.size()) % encryptedFile.size();
                steps++;
            }
        }

        // Update the value at the current index in the encrypted file
        encryptedFile[currentIndex] = encryptedFile[i];
    }

    // Find the grove coordinates
    int groveCoordinatesSum = 0;
    int currentIndex = 0;

    for(int i = 0; i < 3; i++)
    {
        currentIndex = (currentIndex + 1000) % encryptedFile.size();
        groveCoordinatesSum += encryptedFile[currentIndex];
    }

    // Output the sum of the grove coordinates
    std::cout << "Sum of the grove coordinates: " << groveCoordinatesSum << '\n';

    return 0;
}