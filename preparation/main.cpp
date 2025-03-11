#include <iostream>
#include "LetterCount.h"
#include "WordCount.h"
#include "LineCount.h"

int main() {
    std::string filename = "sample.txt"; // Change this to your file

    LetterCount lc;
    WordCount wc;
    LineCount lnc;

    int letterCount = lc.countLetters(filename);
    int wordCount = wc.countWords(filename);
    int lineCount = lnc.countLines(filename);

    std::cout << "File: " << filename << std::endl;
    std::cout << "Letter Count: " << letterCount << std::endl;
    std::cout << "Word Count: " << wordCount << std::endl;
    std::cout << "Line Count: " << lineCount << std::endl;

    return 0;
}