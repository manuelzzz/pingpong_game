#include <iostream>
#include "ball.cpp"

using namespace std;

int main()
{
    cBall b(0, 0);
    cout << b << endl;
    b.RandomDirection();
    cout << b << endl;
    b.Move();
    cout << b << endl;
    b.RandomDirection();
    b.Move();
    cout << b << endl;

    return 0;
}