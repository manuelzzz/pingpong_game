#include <time.h>
#include <conio.h>

#include "ball.cpp"
#include "paddle.cpp"

class cGameManager
{
private:
    int width, height;
    int score1, score2;
    char up1, down1, up2, down2;
    bool quit;
    cBall *ball;
    cPaddle *player1;
    cPaddle *player2;

public:
    cGameManager(int w, int h)
    {
        srand(time(NULL));
        quit = false;
        up1 = 'w'; down1 = 's';
        up2 = 'i'; down2 = 'k';
        score1 = score2 = 0;
        width = w; height = h;

        ball = new cBall(w / 2, h / 2);

        player1 = new cPaddle(1, h / 2 - 3);
        player2 = new cPaddle(w - 2, w / 2);
    }

    ~cGameManager() { delete ball, player1, player2; }

    void scoreUp(cPaddle *player)
    {
        if (player == player1)
            score1++;
        else if (player == player2)
            score2++;

        ball->Reset();
        player1->Reset();
        player2->Reset();
    }
};