#include "Stage.h"

void Stage::start()
{
	// 기본 지렁이 생성
	Worm* w = new Worm(25, 10);

	obj.push_back(w);

}

void Stage::show()
{
	//show map
	for (int i = 0; i < ySize; ++i)
	{
		for (int j = 0; j < xSize; ++j)
		{
			cout << map[i][j];
		}
		cout << std::endl;
	}

	//show worm


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
