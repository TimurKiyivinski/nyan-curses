// File: main.cpp
// Author: Timothy Kiyui (4316886)

#include "Looks.h"
#include "Text.h"
#include "Nyan.h"
#include "Asteroid.h"
#include "Game.h"
#include "Screen.h"
#include <fstream>

using namespace std;

vector<string> fromFile(string fileName)
{
    ifstream vectorFile(fileName.c_str());
    vector<string> fileVector;
    string vectorLine("");
    if (vectorFile.is_open())
    {
        while (getline(vectorFile, vectorLine))
            fileVector.push_back(vectorLine);
    }
    return fileVector;
}

int main(void)
{
    Nyan *_nyan = new Nyan(fromFile("NYAN-SPLASH"), 5, 5);
    Text *_start = new Text(fromFile("NYAN-SPLASH"), "Nyan Curses");
    Text *_end = new Text(fromFile("NYAN-SPLASH"), "Nyan Curses");
    Game *game = new Game(80, 25, _nyan, _start, _end);
    Screen *gameScreen = new Screen(80);
    if (gameScreen == NULL) return 1;
#ifdef USES_CURSES_SCREEN
    initscr();
#endif
    gameScreen->print(game->print());
    getch();
#ifdef USES_CURSES_SCREEN
    endwin();
#endif
    delete game;
    delete gameScreen;
}
