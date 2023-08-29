#pragma once

#include <vector>

#include "CObject.h"
#include "Stage.h"

using std::vector;

class Worm : public CObject
{
private:
	int length;
	vector<char> body;

public:


public:
	Worm(int _headX, int _headY) : length(1)
	{
		setX(_headX);
		setY(_headY);
		body.push_back('@'); //���߿� (char)BLOCK::HEAD�� �� �Ǵ� ���� ã��
	}
	~Worm();
};

