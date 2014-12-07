// File: Asteroid.h
// Author: Timothy Kiyui (4316886)

#ifndef ASTEROID_H
#define ASTEROID_H
#include "Nyan.h"
#include "Coordinates.h"
#include <string>
#include <vector>

using namespace std;

class Asteroid: public Coordinates
{
    private:
        // Asteroid icon
        char _icon;
        // Location
        int _x;
        int _y;
    public:
        // Constructor
        Asteroid(char icon, int x, int y, int X, int Y);
        // Collides with Nyan
        void collide(Nyan *nyan);
        // Looks
        char getLooks();
};
#endif
