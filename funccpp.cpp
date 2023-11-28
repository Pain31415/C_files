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

bool compareFiles(const std::string& filename1, const std::string& filename2) {
    std::ifstream file1(filename1);
    std::ifstream file2(filename2);

    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "Error opening files: " << filename1 << " or " << filename2 << std::endl;
        return false;
    }

    std::string line1, line2;
    int lineNum = 1;
    bool filesMatch = true;

    while (std::getline(file1, line1) && std::getline(file2, line2)) {
        if (line1 != line2) {
            std::cout << "Mismatch at line " << lineNum << ":" << std::endl;
            std::cout << "File 1: " << line1 << std::endl;
            std::cout << "File 2: " << line2 << std::endl;
            filesMatch = false;
        }

        lineNum++;
    }

    while (std::getline(file1, line1)) {
        std::cout << "File 1 has extra line: " << line1 << std::endl;
        filesMatch = false;
        lineNum++;
    }

    while (std::getline(file2, line2)) {
        std::cout << "File 2 has extra line: " << line2 << std::endl;
        filesMatch = false;
        lineNum++;
    }

    if (filesMatch) {
        std::cout << "Files match." << std::endl;
    }
    else {
        std::cout << "Files do not match." << std::endl;
    }

    return filesMatch;
}