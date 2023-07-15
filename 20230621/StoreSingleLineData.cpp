#include "StoreSingleLineData.h"

void StoreSingleLineData::SetDate(string& d)////1.readfile save date save in the sld setdate.2.sld.cpp involke date class de set date.
{
	m_d.SetDate(d);
}

Date StoreSingleLineData::GetDate()
{
	return m_d;
}

void StoreSingleLineData::SetTime(string& t)
{
	m_t.SetTime(t);//sld settime invloke date(m_t).settime.
}

Time StoreSingleLineData::GetTime()
{
	return m_t;
}

void StoreSingleLineData::AddData(const double& n)
{
	m_SensorsData.Add(n);
}

UserSpace::MyVector<double>& StoreSingleLineData::GetSensorsData()
{
	return m_SensorsData;
}