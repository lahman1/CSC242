#include <iostream>

double calculateAverage(int arr[], int size) {
    double sum = 0.0;
    
    // Caluculate the sum of all the elments in the array
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    // Calculate the avergae
    double average = sum / size;
    
    std::cout << "The average is: " << average << std::endl;

    return average;
    }

    int main() {
        int numbers[] = {1, 10, 13, 17, 21, 30, 50};
        int size = sizeof(numbers) / sizeof(numbers[0])

        double avg = calculateAverage(numbers, size);

        return 0;
    }