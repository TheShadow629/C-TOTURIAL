#include "StoreSingleLineData.h"

void StoreSingleLineData::SetDate(string& d)////1.readfile save date save in the sld setdate.2.sld.cpp involke date class de set date.
{
	m_d.SetDate(d);
}

Date StoreSingleLineData::GetDate() const
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

//void StoreSingleLineData::AddData(const double& n)
//{
//	m_SensorsData.Add(n);
//}

void StoreSingleLineData::AddData(const std::pair<std::string, double>& d)
{
	m_MapSensorsData.insert(d);
}

//UserSpace::MyVector<double>& StoreSingleLineData::GetSensorsData()
//{
//	return m_SensorsData;
//}

std::map<std::string, double>& StoreSingleLineData::GetMapSensorsData()
{
	return m_MapSensorsData;
}

bool operator>(const StoreSingleLineData& lhs, const StoreSingleLineData& rhs) 
{
	//TODO:只比较日期来作为SLWDT类的比较，有无问题呢，暂时先这样
	return lhs.GetDate() > rhs.GetDate();
}

bool operator<(const StoreSingleLineData& lhs, const StoreSingleLineData& rhs)
{
	return lhs.GetDate() < rhs.GetDate();
}
