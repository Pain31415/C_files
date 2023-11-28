#include "functions.h"
#include <iostream>
#include <fstream>

void writeStringsToFile(const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    std::cout << "Enter lines. Enter an empty line to finish." << std::endl;

    while (true) {
        std::getline(std::cin, line);

        if (line.empty()) {
            break;
        }

        file << line << std::endl;
    }

    std::cout << "Lines have been written to " << filename << std::endl;
}

void copyFileContent(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    std::ofstream outputFile(outputFilename);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files: " << inputFilename << " or " << outputFilename << std::endl;
        return;
    }

    std::string line;

    while (std::getline(inputFile, line)) {
        outputFile << line << std::endl;
    }

    std::cout << "File content has been copied to " << outputFilename << std::endl;
}