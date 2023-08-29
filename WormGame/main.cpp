#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>

#include "Stage.h"
#include "Worm.h"

//커서 위치 변경 함수
void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

//커서 깜빡임 숨기는 함수
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

const int RIGHT_ARROW = 77;
const int LEFT_ARROW = 75;
const int UP_ARROW = 72;
const int DOWN_ARROW = 80;

int main()
{
    ShowConsoleCursor(false);

    clock_t startT, finishT;

    Worm w(25, 10);

    Stage s(50, 20);

    s.start();

    startT = clock();
    int input;

    while (s.isRun())
    {
        setCursorPosition(0, 0);


        if (_kbhit())
        {
            input = _getch();

            switch (input)
            {
            case RIGHT_ARROW:
                break;
            case LEFT_ARROW:
                break;
            default:
                break;
            }
        }

        finishT = clock();
        if ((double)(finishT - startT) > 1000)
        {
            startT = finishT;
        }

        s.show();
    }

	return 0;
}