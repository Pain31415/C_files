#include "func.h"

int main() {
    const std::string inputFilename = "input.txt";
    const std::string outputFilename = "output.txt";

    writeStringToFile(inputFilename);
    generateStatistics(inputFilename, outputFilename);

    return 0;
}