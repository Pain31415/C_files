#include "func.h"
#include <iostream>

int main() {
    const std::string filename1 = "file1.txt";
    const std::string filename2 = "file2.txt";

    std::cout << "Enter lines for file 1:" << std::endl;
    writeStringsToFile(filename1);

    std::cout << "\nEnter lines for file 2:" << std::endl;
    writeStringsToFile(filename2);

    compareFiles(filename1, filename2);

    return 0;
}