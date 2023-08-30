#pragma once

#include <vector>
#include <iostream>

#include "CObject.h"
#include "Worm.h"

using namespace std;

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
	void update();

public:
	Stage(int _xSize, int _ySize);
	
	~Stage();
};

