#include "func.h"
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

void addSeparatorAfterLastNonSpaceLine(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    std::ofstream outputFile(outputFilename);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files: " << inputFilename << " or " << outputFilename << std::endl;
        return;
    }

    std::string line;
    std::string lastNonSpaceLine;

    while (std::getline(inputFile, line)) {
        if (!line.empty() && line.find_first_not_of(' ') != std::string::npos) {
            lastNonSpaceLine = line;
        }

        outputFile << line << std::endl;
    }

    if (!lastNonSpaceLine.empty()) {
        outputFile << "------------" << std::endl;
    }
    else {
        outputFile << std::endl << "------------" << std::endl;
    }

    std::cout << "Separator has been added to " << outputFilename << std::endl;
}