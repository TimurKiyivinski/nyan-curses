// File: Coordinates.cpp
// Author: Timothy Kiyui (4316886)

#include "Coordinates.h"

// Constructor
Coordinates::Coordinates(int x, int y, int X, int Y):
    _x(x), _y(y), _X(X), _Y(Y)
{
}

// Gets the current X position
int Coordinates::getX() { return _x; }

// Gets the current Y position
int Coordinates::getY() { return _y; }

// Sets the current X condition if it is in the right range
void Coordinates::setX(int x) { if (x < _X && x > 0) _x = x; }

// Sets the current Y condition if it is in the right range
void Coordinates::setY(int y) { if (y < _Y && y > 0) _y = y; }

// Go up
void Coordinates::goUp() { if (_y < _Y) _y++; }

// Go down
void Coordinates::goDown() { if (_y > 0) _y--; }

// Moves X by 1
void Coordinates::move()
{
    _x == 0 ?
        (_x = _X):
        (_x--);
}
