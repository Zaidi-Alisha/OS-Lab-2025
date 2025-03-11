#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include <iostream>
#include <fstream>
#include <sstream>

class WordCount {
public:
    int countWords(const std::string &filename);
};

#endif