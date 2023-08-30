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

//�ҷ� ����
enum class BLOCK : char
{
	NOMAL = ' ', //�������� �ִ� ��
	WALL = '#',
	HEAD = '@',
	BODY = 'O',
	APPLE = '+' //������ ������ ���� �����
};

class Stage
{
private:
	int xSize;
	int ySize;
	bool run = false;
	vector<vector<char>> map;
	vector<CObject*> obj; //0��° ������Ʈ�� ������ �� ���ĺ��� ���

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

