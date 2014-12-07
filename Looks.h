// File: Looks.h
// Author: Timothy Kiyui (4316886)

#ifndef LOOKS_H
#define LOOKS_H

#include <string>
#include <vector>

using namespace std;

// The looks class is an abstract class that will be shared by all
// objects that have a look or a shape in ascii to be printed. The
// Screen class collaborates with this class in order to print Looks
// out to the interface
class Looks
{
    private:
        // Vector of how an object
        // should look like
        vector<string> _looks;
    public:
        // Constructor
        Looks(vector<string> looks);
        // Returns the looks vector
        vector<string> getLooks();
};
#endif
