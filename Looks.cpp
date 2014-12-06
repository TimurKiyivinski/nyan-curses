// File: Looks.cpp
// Author: Timothy Kiyui (4316886)

#include "Looks.h"
#include <string>
#include <vector>

using namespace std;

// Constructor
Looks::Looks(vector<string> looks)
{
    // All lines of the string must match this
    int length = looks[0].length();
    // Test all lines of the vector
    for (string line: looks)
        if (line.length() != length)
            // Throw an error if any line doesn't match
            throw "Line lengths must be matching!";
    _looks = looks;
}

// Simply return the looks vector as is
vector<string> Looks::getLooks() { return _looks; }
