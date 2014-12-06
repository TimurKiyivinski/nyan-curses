// File: Screen.cpp
// Author: Timothy Kiyui (4316886)

#include "Screen.h"
#include "curses.h"
#include <string>
#include <vector>

using namespace std;

Screen::Screen(int width):
    _width(width)
{}

// This print method makes use of the CURSES command line
// interface to print to the terminal.
void Screen::print(vector<string> gameView)
{
    clear();
    for (string viewLine: gameView)
    {
        if (viewLine.length() > _width)
            viewLine.substr(0, _width);
        printw("%s\n", viewLine.c_str());
    }
    refresh();
}
