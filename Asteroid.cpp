// File: Asteroid.cpp
// Author: Timothy Kiyui (4316886)

#include "Asteroid.h"
#include "Nyan.h"
#include <string>
#include <vector>

using namespace std;

// Asteroids have just one icon so Looks it ini
Asteroid::Asteroid(char icon, int x, int y):
    _icon(icon), _x(x), _y(y)
{
}

// Collides with Nyan, collision is handled Game
void Asteroid::collide(Nyan *nyan)
{
    // Skip non dangerous asteroid or stars
    if (_icon == '*' || _icon == '+') return;
    // Otherwise, hurt Nyan
    nyan->popScore();
}

// Get Asteroid icon
char Asteroid::getLooks() { return _icon; }
