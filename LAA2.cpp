#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    while (true) {
        int number;
        std::cout << "Enter a non-negative number (or -1 to exit): ";
        std::cin >> number;

        // Checks if user wants to exit program.
        if (number == -1) {
            break;
        }

        // Checks for invalid input
        if (number < 0) {
            std::cout << "Invalid input. Please enter a non-negative integer." << std::endl;
            continue; // Skip the rest of the loop and prompt again
        }

        std::vector<int> binaryDigits;

        // Special case for 0
        if (number == 0) {
            binaryDigits.push_back(0);
        }

        // Collect binary digits in reverse order
        while (number > 0) {
            binaryDigits.push_back(number % 2);
            number /= 2;
        }

        // Reverse the digits to display them in the correct order
        std::reverse(binaryDigits.begin(), binaryDigits.end());

        std::cout << "Binary representation: ";
        for (int bit : binaryDigits) {
            std::cout << bit;
        }
        std::cout << std::endl;
    }

    std::cout << "Exiting program." << std::endl;
    return 0;
}
