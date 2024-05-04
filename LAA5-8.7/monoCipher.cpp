#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>

// Function to create the cipher alphabet
std::string createCipherAlphabet(const std::string& key) {
    std::unordered_set<char> seen;
    std::string result;
    for (char c : key) {
        if (seen.insert(c).second) {
            result.push_back(c);
        }
    }

    // Append the rest of the alphabet in reverse order
    for (char c = 'Z'; c >= 'A'; c--) {
        if (seen.insert(c).second) {
            result.push_back(c);
        }
    }
    return result;
}

// Function to encrypt or decrypt based on the cipher alphabet
std::string translate(const std::string& text, const std::string& cipher, bool decrypt) {
    std::string normal = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string result;
    for (char c : text) {
        if (isalpha(c)) {
            char base = (c >= 'a' && c <= 'z') ? 'a' : 'A';
            size_t index = normal.find(toupper(c));
            if (decrypt) {
                // Decrypt mode
                index = cipher.find(toupper(c));
                result += normal[index] - 'A' + base;
            }
            else {
                // Encrypt mode
                result += cipher[index] - 'A' + base;
            }
        }
        else {
            result += c;  // Non-alphabetical characters are not encrypted
        }
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " -d|-e -k<KEYWORD> <inputfile> <outputfile>\n";
        return 1;
    }

    std::string mode = argv[1];
    std::string keyword = argv[2];
    std::string inputFile = argv[3];
    std::string outputFile = argv[4];

    // Remove the -k from the keyword
    if (keyword.size() < 3 || keyword.substr(0, 2) != "-k") {
        std::cerr << "Keyword must start with -k.\n";
        return 1;
    }
    keyword = keyword.substr(2);

    // Create the cipher alphabet
    std::string cipherAlphabet = createCipherAlphabet(keyword);
    bool decrypt = (mode == "-d");

    std::ifstream input(inputFile);
    std::ofstream output(outputFile);
    if (!input || !output) {
        std::cerr << "Error opening files.\n";
        return 1;
    }

    std::string line;
    while (getline(input, line)) {
        output << translate(line, cipherAlphabet, decrypt) << '\n';
    }

    input.close();
    output.close();

    return 0;
}
