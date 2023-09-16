#include <time.h>
#include <conio.h>

#include "ball.h"
#include "paddle.h"

class GameManager
{
private:
    int width, height;
    int score1, score2;
    char up1, down1, up2, down2;
    bool quit;
    Ball *ball;
    Paddle *player1;
    Paddle *player2;

public:
    GameManager(int w, int h)
    {
        // srand(time(NULL));
        quit = false;
        up1 = 'w';
        down1 = 's';
        up2 = 'i';
        down2 = 'k';
        score1 = score2 = 0;
        width = w;
        height = h;

        ball = new Ball(w / 2, h / 2);

        player1 = new Paddle(1, h / 2 - 3);
        player2 = new Paddle(w - 2, w / 2);
    }

    ~GameManager()
    {}

    void scoreUp(Paddle *player)
    {
        if (player == player1)
            score1++;
        else if (player == player2)
            score2++;

        ball->Reset();
        player1->Reset();
        player2->Reset();
    }

    void Draw()
    {
        system("clear");
        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;

        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;
    }
};