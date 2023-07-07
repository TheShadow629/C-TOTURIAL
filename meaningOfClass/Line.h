#pragma once
#include "Point.h"
class Line
{
public:
	Point startPoint;
	Point endPoint;

	Line(Point p1,Point p2)
	{
		startPoint = p1;
		endPoint = p2;
	}

	Line()
	{
		;
	}
};

