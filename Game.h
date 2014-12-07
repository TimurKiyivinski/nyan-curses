// File: Game.h
// Author: Timothy Kiyui (4316886)

#ifndef GAME_H
#define GAME_H

#include "Nyan.h"
#include "Text.h"
#include "Asteroid.h"
#include <string>
#include <vector>

using namespace std;

class Game
{
    private:
        int _width;
        int _height;
        Nyan *_nyan;
        Text *_start;
        Text *_end;
        vector<Asteroid*> _asteroids;
    public:
        // Game constrcutor with Asteroids
        // and game screen width and height,
        // minimum is 80 by 25
        Game(int width, int height, Nyan *nyan, Text *start, Text *end);
        // Game destructor to free memory
        ~Game();
        // Splash screen for game start and end
        vector<string> splash();
        vector<string> gameOver();
        // The whole game is updated and returned as a printable
        // string vector by this one method that is to be used by
        // Screen to draw to any implemented interface.
        vector<string> print();
};
#endif
