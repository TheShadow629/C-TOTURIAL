#include <iostream>
#include "Point.h"
#include "Line.h"
int main()
{
	//double x1, y1, x2, y2;
	//return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	//int num1;
	//num1 = 10;
	//std::cout << num1;
	Line l1;
	for (;;)
	{
		Point p1;
		p1.m_x = 10;
		p1.m_y = 20;

		Point p2(15, 13);
		p2.m_x = 1;
		p2.m_y = 1;


		std::cout << p1.m_x << p1.m_y;
		l1.startPoint = p1;
		l1.endPoint = p2;
		p1.calculateDis(l1);
		break;
	}
	std::cout << l1.startPoint.m_x;

	int i;
	for (;;)
	{
		int a = 10;
		i = a;
		break;
	}
}