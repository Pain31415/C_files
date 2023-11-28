#include "func.h"
#include <iostream>
#include <fstream>

void writeStringToFile(const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    std::cout << "Enter a string. Press Enter to finish." << std::endl;

    std::getline(std::cin, line);
    file << line;

    std::cout << "String has been written to " << filename << std::endl;
}

void caesarCipherEncrypt(const std::string& inputFilename, const std::string& outputFilename, int key) {
    std::ifstream inputFile(inputFilename);
    std::ofstream outputFile(outputFilename);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files: " << inputFilename << " or " << outputFilename << std::endl;
        return;
    }

    char ch;
    while (inputFile.get(ch)) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = static_cast<char>((ch - base + key) % 26 + base);
        }
        outputFile << ch;
    }

    std::cout << "String has been encrypted using Caesar Cipher with key " << key << std::endl;
}