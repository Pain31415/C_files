#include "func.h"
#include <iostream>
#include <fstream>

void writeWordsToFile(const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string word;
    std::cout << "Enter words. Enter an empty line to finish." << std::endl;

    while (true) {
        std::getline(std::cin, word);

        if (word.empty()) {
            break;
        }

        file << word << std::endl;
    }

    std::cout << "Words have been written to " << filename << std::endl;
}

void filterAndWriteToFile(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    std::ofstream outputFile(outputFilename);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files: " << inputFilename << " or " << outputFilename << std::endl;
        return;
    }

    std::string word;

    while (inputFile >> word) {
        if (word.length() >= 7) {
            outputFile << word << std::endl;
        }
    }

    std::cout << "Filtered words have been written to " << outputFilename << std::endl;
}