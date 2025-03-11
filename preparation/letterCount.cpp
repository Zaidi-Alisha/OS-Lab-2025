#include "LetterCount.h"

int LetterCount::countLetters(const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return -1;
    }

    char ch;
    int letterCount = 0;

    while (file.get(ch)) {
        if (isalpha(ch)) { // Check if character is a letter
            letterCount++;
        }
    }

    file.close();
    return letterCount;
}