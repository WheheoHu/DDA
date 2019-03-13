#pragma once
class CoordinateXY
{
public:
	CoordinateXY();
	~CoordinateXY();
	void setx(int x);
	void sety(int y);
	int getx();
	int gety();
private:
	int CoorX;
	int CoorY;
};

