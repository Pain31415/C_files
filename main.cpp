#include "func.h"

int main() {
    const std::string inputFilename = "input.txt";
    const std::string outputFilename = "output.txt";

    writeStringsToFile(inputFilename);
    copyFileContentInReverse(inputFilename, outputFilename);

    return 0;
}