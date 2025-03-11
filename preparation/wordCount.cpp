#include "WordCount.h"

int WordCount::countWords(const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return -1;
    }

    std::string word;
    int wordCount = 0;

    while (file >> word) { // Reads word by word
        wordCount++;
    }

    file.close();
    return wordCount;
}