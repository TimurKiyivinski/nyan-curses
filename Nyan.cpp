// File: Nyan.cpp
// Author: Timothy Kiyui (4316886)

#include "Nyan.h"
#include <string>
#include <vector>

using namespace std;

// Constructor
Nyan::Nyan(vector<string> looks, int y, int Y):
    Looks(looks), _score(0), Coordinates(1, y, 1, Y)
{}

// Adds score
void Nyan::addScore() { _score++; }

// Reduces score
void Nyan::popScore() { _score--; }

// Gets current score
int Nyan::getScore() { return _score; }
