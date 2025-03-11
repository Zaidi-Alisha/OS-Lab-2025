#include "LineCount.h"

int LineCount::countLines(const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return -1;
    }

    std::string line;
    int lineCount = 0;

    while (getline(file, line)) { // Reads line by line
        lineCount++;
    }

    file.close();
    return lineCount;
}