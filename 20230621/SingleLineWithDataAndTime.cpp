#include "SingleLineWithDataAndTime.h"

void SingleLineWithDataAndTime::setDate(string& d)////1.readfile save date save in the sld setdate.2.sld.cpp involke date class de set date.
{
	m_d.setDate(d);
}

Date SingleLineWithDataAndTime::getDate()
{
	return m_d;
}

void SingleLineWithDataAndTime::setTime(string& t)
{
	m_t.setTime(t);//sld settime invloke date(m_t).settime.
}

Time SingleLineWithDataAndTime::getTime()
{
	return m_t;
}

void SingleLineWithDataAndTime::addData(const double& n)
{
	sensorsData.Add(n);
}

UserSpace::MyVector<double>& SingleLineWithDataAndTime::getSensorsData()
{
	return sensorsData;
}