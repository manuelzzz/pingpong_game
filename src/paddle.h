#pragma once
#include <iostream>

using namespace std;

class Paddle
{
private:
    int x, y;
    int originalX, originalY;

public:
    Paddle()
    {
        x = y = 0;
    };

    Paddle(int posX, int posY) : Paddle()
    {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
    };

    void Reset()
    {
        x = originalX;
        y = originalY;
    }

    int getX() { return x; };
    int getY() { return y; };
    void moveUp() { y--; };
    void moveDown() { y++; };

    friend ostream &operator<<(ostream &o, Paddle p)
    {
        o << "Paddle[" << p.x << ", " << p.y << "]" << endl;
        return o;
    };
};