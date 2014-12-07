// File: Asteroid.cpp
// Author: Timothy Kiyui (4316886)

#include "Asteroid.h"
#include "Nyan.h"
#include <string>
#include <vector>

using namespace std;

// Asteroids have just one icon so Looks it ini
Asteroid::Asteroid(char icon, int x, int y, int X, int Y):
    Coordinates(x, y, X, Y), _icon(icon)
{
}

// Collides with Nyan, collision is handled Game
void Asteroid::collide(Nyan *nyan)
{
    // Add points for stars
    if (_icon == '*' || _icon == '+')
        nyan->addScore();
    // Otherwise, take points
    else nyan->popScore();
}

// Get Asteroid icon
char Asteroid::getLooks() { return _icon; }
