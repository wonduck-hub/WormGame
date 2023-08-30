#pragma once

#include <vector>

using std::vector;

#include "Struct.h"

class CObject
{
private:
	Vec2 index;

public:
	int getX()
	{
		return index.x;
	}
	int getY()
	{
		return index.y;
	}
	void setX(int _x)
	{
		index.x = _x;
	}
	void setY(int _y)
	{
		index.y = _y;
	}

public:
	virtual void show(vector<vector<char>>& _map, const int _sizeX, const int _sizeY) = 0;

public:
	CObject();
	~CObject();
};