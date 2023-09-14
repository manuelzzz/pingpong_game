#include <iostream>
#include "ball.cpp"
#include "paddle.cpp"

using namespace std;

int main()
{
    cPaddle p1(0, 0), p2(10, 0);
    cout << p1 << endl;
    cout << p2 << endl;
    p1.moveUp();
    p2.moveDown();
    cout << p1 << endl;
    cout << p2 << endl;

    return 0;
}