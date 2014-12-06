// File: Coordinates.h
// Author: Timothy Kiyui (4316886)

#ifndef COORDINATES_H
#define COORDINATES_H
// This is an abstract class to be used by any class with coordinates.
class Coordinates
{
    private:
        // Coordinates X & Y, flipped cartesion
        int _x;
        int _y;
        // Maximum X and Y value
        int _X;
        int _Y;
    public:
        Coordinates(int x, int y, int X, int Y);
        // Returns X coordinate
        int getX();
        // Returns Y coordinate
        int getY();
        // Sets X coordinate
        void setX(int x);
        // Sets Y coordinate
        void setY(int y);
        // Decreases Y coordinate
        void goUp();
        // Increases Y coordinate
        void goDown();
        // Shifts X to the left by 1
        void move();
};
#endif
