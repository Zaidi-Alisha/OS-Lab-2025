#ifndef LINECOUNT_H
#define LINECOUNT_H

#include <iostream>
#include <fstream>

class LineCount {
public:
    int countLines(const std::string &filename);
};

#endif