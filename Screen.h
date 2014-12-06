// File: Screen.h
// Author: Timothy Kiyui (4316886)

#ifndef SCREEN_H
#define SCREEN_H

#include "curses.h"
#include <string>
#include <vector>

// Makes main more modular, and as such removes unnecessary methods
// if the Screen implementation is modified without editing main.
#define USES_CURSES_SCREEN

using namespace std;

// Screen is divided into it's own implementation such that it may be
// reimplemented into different interfaces such as simple stdio by 
// providing a similar print method.
class Screen
{
    private:
        int _width;
    public:
        Screen(int width);
        void print(vector<string> gameView);
};
#endif
