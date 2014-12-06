// File: Text.cpp
// Author: Timothy Kiyui (4316886)

#include "Text.h"
#include <string>
#include <vector>

using namespace std;

// Constructor
Text::Text(vector<string> looks, string text):
    Looks(looks), _text(text)
{}

// Returns the non-fancy text
string Text::str() { return _text; }
