#include <time.h>
#include <conio.h>

#include "ball.h"
#include "paddle.h"

class GameManager
{
private:
    int width, height;
    int score1, score2;
    int moveBallLogic;
    char up1, down1, up2, down2;
    bool quit;
    Ball *ball;
    Paddle *player1;
    Paddle *player2;

public:
    GameManager(int w, int h)
    {
        srand((unsigned int)time(NULL));
        quit = false;
        up1 = 'w';
        down1 = 's';
        up2 = 'i';
        down2 = 'k';
        score1 = score2 = 0;
        moveBallLogic = 0;
        width = w;
        height = h;

        ball = new Ball(w / 2, h / 2);

        player1 = new Paddle(1, h / 2 - 1);
        player2 = new Paddle(w - 2, h / 2 - 1);
    }

    ~GameManager()
    {
        delete ball;
        delete player1;
        delete player2;
    }

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
            cout << "\u2501";
        cout << endl;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int ballx = ball->getX();
                int bally = ball->getY();
                int player1x = player1->getX();
                int player1y = player1->getY();
                int player2x = player2->getX();
                int player2y = player2->getY();

                if (j == 0)
                    cout << "\u2503";

                if (ballx == j && bally == i)
                    cout << "\u25C9";
                else if (player1x == j && (player1y == i || player1y + 1 == i))
                    cout << "\u250B";
                else if (player2x == j && (player2y == i || player2y + 1 == i))
                    cout << "\u250B";
                else
                    cout << " ";

                if (j == width - 1)
                    cout << "\u2503";
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; i++)
            cout << "\u2501";
        cout << endl;

        cout << "Score 1: " << score1 << endl
             << "Score 2: " << score2 << endl;
    }

    void Input()
    {
        int player1y = player1->getY();
        int player2y = player2->getY();

        if (_kbhit())
        {
            char current = (char)getchar();

            if (current == up1)
                if (player1y > 0)
                    player1->moveUp();

            if (current == up2)
                if (player2y > 0)
                    player2->moveUp();

            if (current == down1)
                if (player1y + 2 < height)
                    player1->moveDown();

            if (current == down2)
                if (player2y + 2 < height)
                    player2->moveDown();

            if (ball->getDirection() == STOP)
                ball->RandomDirection();

            if (current == 'q')
                quit = true;
        }
    }

    void Logic()
    {
        int ballx = ball->getX();
        int bally = ball->getY();
        int player1x = player1->getX();
        int player2x = player2->getX();
        int player1y = player1->getY();
        int player2y = player2->getY();

        for (int i = 0; i < 4; i++)
            if (ballx == player1x + 1)
                if (bally == player1y + i)
                    ball->ChangeDirection((Direction)((rand() % 3) + 4));

        for (int i = 0; i < 4; i++)
            if (ballx == player2x - 1)
                if (bally == player2y + i)
                    ball->ChangeDirection((Direction)((rand() % 3) + 1));

        if (bally == height - 1)
            ball->ChangeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
        if (bally == 0)
            ball->ChangeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
        if (ballx == width - 1)
            scoreUp(player1);
        if (ballx == 0)
            scoreUp(player2);

        moveBallLogic++;
        if (moveBallLogic >= 30)
        {
            moveBallLogic = 0;
            ball->Move();
        }
    }

    void Run()
    {
        while (!quit)
        {
            Draw();
            Input();
            Logic();
        }
    }
};