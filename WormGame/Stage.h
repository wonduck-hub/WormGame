#pragma once

#include <vector>
#include <iostream>

#include "CObject.h"
#include "Worm.h"

using namespace std;

const int RIGHT_ARROW = 77;
const int LEFT_ARROW = 75;
const int UP_ARROW = 72;
const int DOWN_ARROW = 80;

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
	vector<CObject*> obj; //0번째 오브젝트는 지렁이 그 이후부턴 사과

public:
	bool isRun()
	{
		return run;
	}

	void start();

	void show();
	void update(const int _input);

public:
	Stage(int _xSize, int _ySize);
	
	~Stage();
};

