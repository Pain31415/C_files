#include "func.h"
#include <iostream>
#include <fstream>
#include <cctype>

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

void generateStatistics(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    std::ofstream outputFile(outputFilename);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files: " << inputFilename << " or " << outputFilename << std::endl;
        return;
    }

    int charCount = 0;
    int lineCount = 0;
    int vowelCount = 0;
    int consonantCount = 0;
    int digitCount = 0;

    char ch;

    while (inputFile.get(ch)) {
        charCount++;

        if (ch == '\n') {
            lineCount++;
        }

        if (isalpha(ch)) {
            ch = tolower(ch);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelCount++;
            }
            else {
                consonantCount++;
            }
        }

        if (isdigit(ch)) {
            digitCount++;
        }
    }

    outputFile << "Statistics for " << inputFilename << ":\n";
    outputFile << "Character count: " << charCount << "\n";
    outputFile << "Line count: " << lineCount << "\n";
    outputFile << "Vowel count: " << vowelCount << "\n";
    outputFile << "Consonant count: " << consonantCount << "\n";
    outputFile << "Digit count: " << digitCount << "\n";

    std::cout << "Statistics have been written to " << outputFilename << std::endl;
}