#include <iostream>
#include <unordered_map>
#include <vector>
#include <stdexcept>

// Function to find the most frequently occurring value in an array
int findMostFrequentValue(const std::vector<int>& array) {
    if (array.empty()) {
        throw std::invalid_argument("Input array must not be empty.");
    }

    // Initialize a map to store frequency counts
    std::unordered_map<int, int> frequencyMap;

    // Iterate through the array to count frequencies
    for (int num : array) {
        frequencyMap[num]++;
    }

    // Find the number with the highest frequency count
    int maxFrequency = 0;
    int mostFrequentValue = 0; // Initialize with any value
    for (const auto& pair : frequencyMap) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
            mostFrequentValue = pair.first;
        }
    }

    // Return the most frequently occurring value
    return mostFrequentValue;
}

int main() {
    // Example array
    std::vector<int> array = { 1, 2, 3, 2, 2, 4, 5, 2, 3, 3 };

    // Find the most frequently occurring value
    const int mostFrequent = findMostFrequentValue(array);

    // Output the result
    std::cout << "The most frequently occurring value is: " << mostFrequent << std::endl;

    return 0;
}