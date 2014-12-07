// File: main.cpp
// Author: Timothy Kiyui (4316886)

#include "Looks.h"
#include "Text.h"
#include "Nyan.h"
#include "Asteroid.h"
#include "Game.h"
#include "Screen.h"
#include <fstream>
#include <thread>
#include <chrono>

using namespace std;

// Converts files into a vector of strings.
vector<string> fromFile(string fileName)
{
    // Load the file as a stream
    ifstream vectorFile(fileName.c_str());
    vector<string> fileVector;
    string vectorLine("");
    if (vectorFile.is_open())
    {
        // Gets all lines of the stream and pushes it into
        // the vector
        while (getline(vectorFile, vectorLine))
            fileVector.push_back(vectorLine);
    }
    return fileVector;
}

// This is the main thread that will handle the main game loop and display it to the user.
void gameThread(Game *game, Screen *gameScreen, Nyan *_nyan, bool *gameLoop)
{
    while (*gameLoop)
    {
        // Sleep the thread for 50 miliseconds so that it is still playable
        this_thread::sleep_for(chrono::milliseconds(50));
        // Updates and prints the game
        gameScreen->print(game->print());
        // Game is over when the user scores -100
        if (_nyan->getScore() == -100)
            *gameLoop = false;
    }
}

// Game input thread, handles user input in order to move Nyan to get more points
void inputThread(Nyan *_nyan, bool *gameLoop)
{
    char userInput;
    while (*gameLoop)
    {
        // Get user input
        userInput = getch();
        switch (userInput)
        {
            case 'q': case 'Q': // Quit game by stopping the game loop
                *gameLoop = false;
                break;
            case 'w': case 'W': // Move up
                _nyan->goUp();
                break;
            case 's': case 'S': // Move down
                _nyan->goDown();
                break;
        }
    }
}

int main(void)
{
    // Create the Nyan
    Nyan *_nyan = new Nyan(fromFile("NYAN-CAT"), 5, 20);
    // Create the start splash text
    Text *_start = new Text(fromFile("NYAN-SPLASH"), "Nyan Curses");
    // Create the game over splash text
    Text *_end = new Text(fromFile("NYAN-OUT"), "Nyan Out");
    // Create the game with a window size of 80 * 25
    Game *game = new Game(80, 25, _nyan, _start, _end);
    // Create a screen with a width of 80
    Screen *gameScreen = new Screen(80);
#ifdef USES_CURSES_SCREEN
    initscr(); // Initialize CURSES screen
#endif
    // Shared game loop boolean
    bool gameLoop(true);
    // Game start splash
    gameScreen->print(game->splash());
    getch();
    // Create game threads
    thread _gameThread(gameThread, game, gameScreen, _nyan, &gameLoop);
    thread _inputThread(inputThread, _nyan, &gameLoop);
    // Begin both threads
    _gameThread.join();
    _inputThread.join();
    // Game over splash
    gameScreen->print(game->gameOver());
    getch();
#ifdef USES_CURSES_SCREEN
    endwin(); // Ends CURSES screen
#endif
    // Free memory
    delete game;
    delete gameScreen;
}
