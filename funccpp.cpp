#include "func.h"
#include <iostream>
#include <fstream>

void writeStringsToFile(const std::string & filename) {
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

void copyFileContentInReverse(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    std::ofstream outputFile(outputFilename);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files: " << inputFilename << " or " << outputFilename << std::endl;
        return;
    }

    std::string* lines = nullptr;
    int size = 0;
    std::string line;

    while (std::getline(inputFile, line)) {
        size++;
    }

    lines = new std::string[size];

    inputFile.clear();
    inputFile.seekg(0, std::ios::beg);

    int i = 0;
    while (std::getline(inputFile, line)) {
        lines[i++] = line;
    }

    for (int j = size - 1; j >= 0; j--) {
        outputFile << lines[j] << std::endl;
    }

    delete[] lines;

    std::cout << "File content has been copied to " << outputFilename << " in reverse order." << std::endl;
}