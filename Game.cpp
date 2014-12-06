// File: Game.cpp
// Author: Timothy Kiyui (4316886)

#include "Game.h"
#include "Nyan.h"
#include "Asteroid.h"
#include "Text.h"
#include <string>
#include <vector>

using namespace std;

Game::Game(int width, int height, Nyan *nyan, Text *start, Text *end)
{
    // Initialize game values
    if (nyan != NULL)
        _nyan = nyan;
    if (start != NULL)
        _start = start;
    if (end != NULL)
        _end = end;
    // Minimum width for the game is 80 characters, the typical
    // Windows terminal size
    width < 80 ?
        (_width = 80):
        (_width = width);
    // Minimum height for the game is 25 characters, the typical
    // Windows terminal size
    height < 25 ?
        (_height = 25):
        (_height = height);
    // Create asteroids
    char asteroid_icons[8] = {'*', '+', '@', '.', 'X', 'O', '~', '-'};
    for (int i(0); i < 8; i++)
    {
        Asteroid *_asteroid = new Asteroid(asteroid_icons[i],
                0,
                0);
    }
}

Game::~Game()
{
    if (_nyan != NULL)
        delete _nyan;
    if (_start != NULL)
        delete _start;
    if (_end != NULL)
        delete _end;
    for (Asteroid *asteroid: _asteroids)
        delete asteroid;
}

// Update the game and return the printable string vector
vector<string> Game::print()
{
    vector<string> toPrint;
    // Status bar
    string statusBar("Score: " + _nyan->getScore());
    toPrint.push_back(statusBar);
    // Create empty white lines
    string whiteLine("");
    for (int x(0); x < _width; x++) whiteLine += " ";
    // Add white lines until Nyan
    for (int y(1); y < _nyan->getY(); y++)
        toPrint.push_back(whiteLine);
    vector<string> nyanVector = _nyan->getLooks();
    toPrint.insert(toPrint.end(),
            nyanVector.begin(),
            nyanVector.end());
    return nyanVector;
    while (toPrint.size() < _height)
        toPrint.push_back(whiteLine);
    return toPrint;
}
