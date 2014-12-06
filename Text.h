// File: Text.h
// Author: Timothy Kiyui (4316886)

#ifndef TEXT_H
#define TEXT_H

#include "Looks.h"
#include <string>
#include <vector>

using namespace std;

// Big splashy text that looks fancy when printed out.
class Text: public Looks
{
    private:
        // Non-fancy text value
        string _text;
    public:
        // Constructor
        Text(vector<string> looks, string text);
        // Returns the non-fancy text
        string str();
};
#endif
