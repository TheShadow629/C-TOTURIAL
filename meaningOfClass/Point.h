#pragma once
class Point
{
public:
	double m_x;
	double m_y;
	
	Point(double x=0, double y=0)
	{
		m_x = x;
		m_y = y;
	}

	double calculateDis(Line l)
	{
		return l.startPoint.m_y;
	}

};

