#include <stdlib.h>

#include "Apple.h"
#include "Stage.h"
#include "Define.h"

void Apple::show(vector<vector<char>>& _map, const int _sizeX, const int _sizeY)
{
	_map[getY()][getX()] = (char)BLOCK::APPLE;
}

void Apple::setPos(vector<vector<char>>& _map)
{
	srand((unsigned)time(NULL));
	int rX = rand() % X;
	int rY = rand() % Y;

	while (true)
	{
		if (_map[rY][rX] != (char)BLOCK::NOMAL)
		{
			rX = rand() % X;
			rY = rand() % Y;
		}
		else
		{
			setX(rX);
			setY(rY);
			break;
		}
	}

}


Apple::Apple()
{
	setX(1);
	setY(1);
}

Apple::~Apple()
{
}
