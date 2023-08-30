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

	//�Ӹ�
	_map[getY()][getX()] = (char)BLOCK::HEAD;

	//����
	for (int i = 0; i < length; ++i)
	{
		_map[body[i].y][body[i].x] = (char)BLOCK::BODY;
	}

}

void Worm::moveLeft()
{
	if (getX() <= 1) //���� ������
	{
		setX(1);
	}
	else if (getX() - 1 == body[0].x) //���� �Ұ���
	{

	}
	else
	{
		//�������� ������ �ִ� ��ġ ����
		prevPos = body[length - 1];

		//���� ��ġ�� ����
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

		//�Ӹ� ��ġ�� ����
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
		//�������� ������ �ִ� ��ġ ����
		prevPos = body[length - 1];

		//���� ��ġ�� ����
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

		//�Ӹ� ��ġ�� ����
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
		//�������� ������ �ִ� ��ġ ����
		prevPos = body[length - 1];

		//���� ��ġ�� ����
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

		//�Ӹ� ��ġ�� ����
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
		//�������� ������ �ִ� ��ġ ����
		prevPos = body[length - 1];

		//���� ��ġ�� ����
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

		//�Ӹ� ��ġ�� ����
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
