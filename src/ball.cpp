#include <iostream>

using namespace std;

enum eDirection
{
    STOP = 0,
    LEFT = 1,
    UPLEFT = 2,
    DOWNLEFT = 3,
    RIGHT = 4,
    UPRIGHT = 5,
    DOWNRIGHT = 6,
};

class cBall
{
private:
    int x, y;
    int originalX, originalY;
    eDirection direction;

public:
    cBall(int posX, int poxY)
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

    void ChangeDirection(eDirection d)
    {
        direction = d;
    };

    void RandomDirection()
    {
        direction = (eDirection)((rand() % 2) + 1);
    }

    int getX() { return x; }
    int getY() { return y; }
    eDirection getDirection() { return direction; }

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

    friend ostream &operator<<(ostream &o, cBall c)
    {
        o << "Ball[" << c.x << ", " << c.y << "][" << c.direction << "]" << endl;
        return o;
    };
};