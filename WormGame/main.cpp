#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>

#include "Stage.h"
#include "Worm.h"
#include "Define.h"

//Ŀ�� ��ġ ���� �Լ�
void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

//Ŀ�� ������ ����� �Լ�
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

int main()
{
    ShowConsoleCursor(false);

    clock_t startT, finishT;

    Stage s(X, Y);

    s.start();

    startT = clock();
    

    while (s.isRun())
    {
        setCursorPosition(0, 0);

        

        /*finishT = clock();
        if ((double)(finishT - startT) > 1000)
        {
            startT = finishT;
        }*/
        s.update();
        s.show();
    }

	return 0;
}