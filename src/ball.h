#pragma once
#include <iostream>
#define DIRECTION_H_

enum Direction
{
    STOP = 0,
    LEFT = 1,
    UPLEFT = 2,
    DOWNLEFT = 3,
    RIGHT = 4,
    UPRIGHT = 5,
    DOWNRIGHT = 6,
};

using namespace std;

class Ball
{
private:
    int x, y;
    int originalX, originalY;
    Direction direction;

public:
    Ball(int posX, int poxY)
    {
        originalX = posX;
        originalY = poxY;
        x = posX;
        y = poxY;
        direction = STOP;
    }

    void Reset()
    {
        x = originalX;
        y = originalY;
        direction = STOP;
    };

    void ChangDirection(Direction d)
    {
        direction = d;
    };

    void RandomDirection()
    {
        direction = (Direction)((rand() % 2) + 1);
    }

    int getX() { return x; }
    int getY() { return y; }
    Direction getDirection() { return direction; }

    void Move()
    {
        switch (direction)
        {
        case STOP:
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UPLEFT:
            x--;
            y--;
            break;
        case DOWNLEFT:
            x--;
            y++;
            break;
        case UPRIGHT:
            x++;
            y--;
            break;
        case DOWNRIGHT:
            x++;
            y++;
            break;
        default:
            break;
        }
    }

    friend ostream &operator<<(ostream &o, Ball c)
    {
        o << "Ball[" << c.x << ", " << c.y << "][" << c.direction << "]" << endl;
        return o;
    };
};