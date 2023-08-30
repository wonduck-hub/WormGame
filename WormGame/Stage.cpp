#include <conio.h>
#include <cstdlib>
#include <Windows.h>

#include "Stage.h"
#include "Apple.h"



void Stage::start()
{
	// 기본 지렁이 생성
	Worm* w = new Worm(25, 10);
	Apple* a = new Apple();

	obj.push_back(w);
	obj.push_back(a);
}

void Stage::show()
{
	//map 초기화
	for (int i = 0; i < ySize; ++i)
	{
		for (int j = 0; j < xSize; ++j)
		{
			if (i == 0 || i == (ySize - 1) || j == 0 || j == (xSize - 1))
			{
				map[i][j] = ((char)BLOCK::WALL);
			}
			else
			{
				map[i][j] = ((char)BLOCK::NOMAL);
			}
		}
	}

	//show worm and apple
	for (int i = 0; i < obj.size(); ++i)
	{
		obj[i]->show(map, xSize, ySize);
	}

	//show map
	for (int i = 0; i < ySize; ++i)
	{
		for (int j = 0; j < xSize; ++j)
		{
			cout << map[i][j];
		}
		cout << std::endl;
	}

}

void Stage::update(const int _input)
{

	// 키보드 입력


	switch (_input)
	{
	case RIGHT_ARROW:
		((Worm*)obj[0])->moveRight();
		break;
	case LEFT_ARROW:
		((Worm*)obj[0])->moveLeft();
		break;
	case UP_ARROW:
		((Worm*)obj[0])->moveUp();
		break;
	case DOWN_ARROW:
		((Worm*)obj[0])->moveDown();
		break;
	default:
		break;
	}

	//사과를 먹었을 때
	if (obj[0]->getX() == obj[1]->getX() &&
		obj[0]->getY() == obj[1]->getY())
	{
		((Apple*)obj[1])->setPos(map);
		((Worm*)obj[0])->eatApple();
	}

}

Stage::Stage(int _xSize, int _ySize)
	: xSize(_xSize), ySize(_ySize), run(true)
{
	for (int i = 0; i < ySize; ++i)
	{
		vector<char> vec;
		for (int j = 0; j < xSize; ++j)
		{
			if (i == 0 || i == (ySize - 1) || j == 0 || j == (xSize - 1))
			{
				vec.push_back((char)BLOCK::WALL);
			}
			else
			{
				vec.push_back((char)BLOCK::NOMAL);
			}
		}
		map.push_back(vec);
	}
}

Stage::~Stage()
{
	for (size_t i = 0; i < obj.size(); ++i)
	{
		delete obj[i];
	}
}
