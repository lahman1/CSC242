#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <cctype>


int main() {
    std::unordered_set<std::string> dictionary;
    std::string word;

    // Load the dictionary
    std::ifstream dictFile("words.txt");
    if (!dictFile) {
        std::cerr << "Failed to open the dictionary file." << std::endl;
        return 1;
    }

    while (dictFile >> word) {
        dictionary.insert(word);
    }
    dictFile.close();

    // Open the file to be checked
    std::ifstream checkFile("checkFile.txt");
    if (!checkFile) {
        std::cerr << "Failed to open the file to be checked." << std::endl;
        return 1;
    }

    // Check each word in the file against the dictionary
    while (checkFile >> word) {
        word = word;
        if (dictionary.find(word) == dictionary.end()) {
            std::cout << "Misspelled or unknown word: " << word << std::endl;
        }
    }
    checkFile.close();

    return 0;
}
