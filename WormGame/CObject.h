#pragma once

class CObject
{
private:
	int x;
	int y;

public:
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	void setX(int _x)
	{
		x = _x;
	}
	void setY(int _y)
	{
		y = _y;
	}

public:
	CObject();
	~CObject();
};