#include <iostream>

using namespace std;

class cPaddle
{
private:
    int x, y;
    int originalX, originalY;

public:
    cPaddle()
    {
        x = y = 0;
    };

    cPaddle(int posX, int posY) : cPaddle()
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
    void moveDown() { x--; };

    friend ostream &operator<<(ostream &o, cPaddle p)
    {
        o << "Paddle[" << p.x << ", " << p.y << "]" << endl;
        return o;
    };
};