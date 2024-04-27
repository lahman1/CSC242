#include <iostream>
#include <vector>
#include <array>

int main() {
    // Example of an array
    std::array<int, 5> arr = { 1, 2, 3, 4, 5 };

    // Example of a vector
    std::vector<int> vec = { 10, 20, 30, 40, 50 };

    // Printing array elements
    std::cout << "Array elements:" << std::endl;
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Printing vector elements
    std::cout << "Vector elements:" << std::endl;
    for (const auto& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}