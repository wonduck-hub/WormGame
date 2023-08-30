#include "Worm.h"
#include "Struct.h"
#include "Define.h"


#include <cassert>


void Worm::show(vector<vector<char>>& _map, const int _sizeX, const int _sizeY)
{
	if (getX() >= (_sizeX - 1) || getX() <= 0 || getY() >= (_sizeY - 1) || getY() <= 0)
	{
		assert(nullptr);
	}

	//머리
	_map[getY()][getX()] = (char)BLOCK::HEAD;

	//몸통
	for (int i = 0; i < length; ++i)
	{
		_map[body[i].y][body[i].x] = (char)BLOCK::BODY;
	}

}

void Worm::moveLeft()
{
	if (getX() <= 1) //벽에 닿을때
	{
		setX(1);
	}
	else if (getX() - 1 == body[0].x) //유턴 불가능
	{

	}
	else
	{
		//이전까지 꼬리가 있던 위치 저장
		prevPos = body[length - 1];

		//몸통 위치값 변경
		for (int i = (body.size() - 1); i >= 0; --i)
		{
			if (i == 0)
			{
				body[i].x = getX();
				body[i].y = getY();
			}
			else
			{
				body[i] = body[i - 1];
			}
		}

		//머리 위치값 변경
		setX(getX() - 1);
	}
}

void Worm::moveRight()
{
	if (getX() >= X - 2)
	{
		setX(X - 2);
	}
	else if (getX() + 1 == body[0].x)
	{

	}
	else
	{
		//이전까지 꼬리가 있던 위치 저장
		prevPos = body[length - 1];

		//몸통 위치값 변경
		for (int i = (body.size() - 1); i >= 0; --i)
		{
			if (i == 0)
			{
				body[i].x = getX();
				body[i].y = getY();
			}
			else
			{
				body[i] = body[i - 1];
			}
		}

		//머리 위치값 변경
		setX(getX() + 1);
	}
}

void Worm::moveUp()
{
	if (getY() <= 1)
	{
		setY(1);
	}
	else if (getY() - 1 == body[0].y)
	{

	}
	else
	{
		//이전까지 꼬리가 있던 위치 저장
		prevPos = body[length - 1];

		//몸통 위치값 변경
		for (int i = (body.size() - 1); i >= 0; --i)
		{
			if (i == 0)
			{
				body[i].x = getX();
				body[i].y = getY();
			}
			else
			{
				body[i] = body[i - 1];
			}
		}

		//머리 위치값 변경
		setY(getY() - 1);
	}
}

void Worm::moveDown()
{
	if (getY() >= Y - 2)
	{
		setY(Y - 2);
	}
	else if (getY() + 1 == body[0].y)
	{
	}
	else
	{
		//이전까지 꼬리가 있던 위치 저장
		prevPos = body[length - 1];

		//몸통 위치값 변경
		for (int i = (body.size() - 1); i >= 0; --i)
		{
			if (i == 0)
			{
				body[i].x = getX();
				body[i].y = getY();
			}
			else
			{
				body[i] = body[i - 1];
			}
		}

		//머리 위치값 변경
		setY(getY() + 1);
	}
}

void Worm::eatApple()
{
	body.push_back(prevPos);
	++length;
}

Worm::Worm(int _headX, int _headY) : length(1)
{
	setX(_headX);
	setY(_headY);
	body.push_back(Vec2{ getX(), (getY() + 1) });
}

Worm::~Worm()
{
}
