#pragma once
#include "CObject.h"


class Apple :public CObject
{

public:
	virtual void show(vector<vector<char>>& _map, const int _sizeX, const int _sizeY);

	void setPos(vector<vector<char>>& _map);
	Vec2 getPos()
	{
		return Vec2{ getX(), getY() };
	}
public:
	Apple();
	~Apple();
};

