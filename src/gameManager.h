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
        player2 = new Paddle(w - 2, h / 2 - 3);
    }

    ~GameManager()
    {
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
                else if (player1x == j && player1y == i)
                    cout << "\u250B";
                else if (player2x == j && player2y == i)
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
    }
};