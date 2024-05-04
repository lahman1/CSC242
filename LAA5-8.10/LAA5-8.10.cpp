#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <map>

// Function to create a 5x5 matrix from a given keyword
std::vector<std::string> createCipherMatrix(const std::string& key) {
    std::unordered_set<char> used;
    std::vector<std::string> matrix;
    std::string currentRow;
    for (char c : key) {
        if (c == 'J') c = 'I';  // Treat J as I
        if (used.insert(c).second) {
            if (currentRow.size() == 5) {
                matrix.push_back(currentRow);
                currentRow.clear();
            }
            currentRow.push_back(c);
        }
    }

    // Add remaining letters to the matrix
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c != 'J' && used.insert(c).second) {
            if (currentRow.size() == 5) {
                matrix.push_back(currentRow);
                currentRow.clear();
            }
            currentRow.push_back(c);
        }
    }
    if (!currentRow.empty()) matrix.push_back(currentRow);

    return matrix;
}

// Function to prepare text by removing non-alphabet characters, replacing J with I, and making pairs
std::vector<std::string> prepareText(const std::string& input, bool forEncryption) {
    std::string filtered;
    for (char c : input) {
        if (std::isalpha(c)) {
            filtered += std::toupper(c == 'J' ? 'I' : c);
        }
    }

    std::vector<std::string> pairs;
    for (size_t i = 0; i < filtered.size(); i++) {
        char first = filtered[i];
        char second = ((i + 1 < filtered.size()) && filtered[i + 1] != first) ? filtered[i + 1] : 'X';

        pairs.push_back(std::string() + first + second);

        // If we added an 'X' or if second was a valid different character, increment i
        i += (second != 'X' || filtered[i + 1] == first) ? 1 : 0;
    }
    return pairs;
}

// Function to encrypt or decrypt a pair
std::string processPair(const std::string& pair, const std::vector<std::string>& matrix, bool decrypt) {
    int row1, col1, row2, col2;
    row1 = col1 = row2 = col2 = -1;

    // Locate the letters in the matrix
    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 5; ++col) {
            if (matrix[row][col] == pair[0]) {
                row1 = row;
                col1 = col;
            }
            if (matrix[row][col] == pair[1]) {
                row2 = row;
                col2 = col;
            }
        }
    }

    // Apply Playfair rules
    if (row1 == row2) {
        // Same row
        if (!decrypt) {
            col1 = (col1 + 1) % 5;
            col2 = (col2 + 1) % 5;
        }
        else {
            col1 = (col1 - 1 + 5) % 5;
            col2 = (col2 - 1 + 5) % 5;
        }
    }
    else if (col1 == col2) {
        // Same column
        if (!decrypt) {
            row1 = (row1 + 1) % 5;
            row2 = (row2 + 1) % 5;
        }
        else {
            row1 = (row1 - 1 + 5) % 5;
            row2 = (row2 - 1 + 5) % 5;
        }
    }
    else {
        // Rectangle
        std::swap(col1, col2);
    }

    // Construct the resulting pair
    return std::string() + matrix[row1][col1] + matrix[row2][col2];
}

// Main encryption/decryption function
std::string encryptDecrypt(const std::string& text, const std::string& keyword, bool decrypt) {
    std::vector<std::string> matrix = createCipherMatrix(keyword);
    std::vector<std::string> pairs = prepareText(text, !decrypt);
    std::string result;

    for (const std::string& pair : pairs) {
        result += processPair(pair, matrix, decrypt);
    }

    return result;
}

int main() {
    std::string keyword, text;
    std::cout << "Enter keyword: ";
    std::cin >> keyword;
    std::cin.ignore(); // Ignore newline after the keyword input
    std::cout << "Enter text: ";
    std::getline(std::cin, text);

    std::string encrypted = encryptDecrypt(text, keyword, false);
    std::string decrypted = encryptDecrypt(encrypted, keyword, true);

    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}
