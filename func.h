#ifndef FUNC_H
#define FUNC_H

#include <string>

void writeStringToFile(const std::string& filename);
void caesarCipherEncrypt(const std::string& inputFilename, const std::string& outputFilename, int key);

#endif // FUNC_H