#pragma once

#include <vector>

#include "CObject.h"
#include "Stage.h"
#include "Struct.h"
#include "Apple.h"

using std::vector;

class Worm : public CObject
{
private:
	int length;
	vector<Vec2> body;
	Vec2 prevPos;

public:
	virtual void show(vector<vector<char>>& _map, const int _sizeX, const int _sizeY);

public:
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

public:
	void eatApple();

public:
	Worm(int _headX, int _headY);
	~Worm();
};

