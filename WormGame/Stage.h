#pragma once

#include <vector>
#include <iostream>

#include "CObject.h"
#include "Worm.h"

using namespace std;

//불록 종류
enum class BLOCK : char
{
	NOMAL = ' ', //지나갈수 있는 길
	WALL = '#',
	HEAD = '@',
	BODY = 'O',
	APPLE = '+' //먹으면 지렁이 몸이 길어짐
};

class Stage
{
private:
	int xSize;
	int ySize;
	bool run = false;
	vector<vector<char>> map;
	vector<CObject*> obj;

public:
	bool isRun()
	{
		return run;
	}

	void start();

	void show();

public:
	Stage(int _xSize, int _ySize);
	
	~Stage();
};

