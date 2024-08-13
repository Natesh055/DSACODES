#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <conio/conio.h>
using namespace std;

bool gameover;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum edirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
edirection dir;

void setup()
{
    gameover = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void draw()
{
    system("clear");
    for (int i = 0; i < width; i++)
    {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1)
            {
                cout << "#";
            }

            if (i == y && j == x)
            {
                cout << "O";
            }
            else if (i == fruitY && j == fruitX)
            {
                cout << "F";
            }

            else
                cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < width; i++)
    {
        cout << "#";
    }
    cout << endl;
}

void logic()
{
}

void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        }
    }
}

int main()
{
    setup();
    while (!gameover)
    {
        draw();
        input();
        logic();
    }
    return 0;
}