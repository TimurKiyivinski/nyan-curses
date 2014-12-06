// File: Looks.cpp
// Author: Timothy Kiyui (4316886)

#include "Looks.h"
#include <string>
#include <vector>

using namespace std;

// Constructor
Looks::Looks(vector<string> looks):
    _looks(looks)
{
}

// Simply return the looks vector as is
vector<string> Looks::getLooks() { return _looks; }
