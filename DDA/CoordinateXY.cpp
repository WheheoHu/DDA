#include "CoordinateXY.h"



CoordinateXY::CoordinateXY()
{
}


CoordinateXY::~CoordinateXY()
{
}

void CoordinateXY::setx(int x)
{
	CoorX = x;
}

void CoordinateXY::sety(int y)
{
	CoorY = y;
}

int CoordinateXY::getx()
{
	return CoorX;
}

int CoordinateXY::gety()
{
	return CoorY;
}



