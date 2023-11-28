#ifndef FUNC_H
#define FUNC_H

#include <string>

void writeWordsToFile(const std::string& filename);
void filterAndWriteToFile(const std::string& inputFilename, const std::string& outputFilename);

#endif // FUNC_H