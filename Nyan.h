// File: Nyan.h
// Author: Timothy Kiyui (4316886)

#ifndef NYAN_H
#define NYAN_H

#include "Looks.h"
#include "Coordinates.h"
#include <string>
#include <vector>

using namespace std;

// This class defines the annoying space cat creature that users
// will have to control.
class Nyan: public Looks, public Coordinates
{
    private:
        // Nyan's score
        int _score;
    public:
        // Constructor
        Nyan(vector<string> looks, int y, int Y);
        // Adds score
        void addScore();
        // Reduces score
        void popScore();
        // Gets current score
        int getScore();
};
#endif
