#ifndef SingleLineWithDataAndTime_h__
#define SingleLineWithDataAndTime_h__

#include "Date.h"
#include "Time.h"
#include "Vector.h"

class SingleLineWithDataAndTime
{
public:
	void setDate(string& d);
	Date getDate();
	void setTime(string& T);
	Time getTime();

	void addData(const double& n);
	UserSpace::MyVector<double>& getSensorsData();

private:
	Date m_d;
	Time m_t;
	UserSpace::MyVector<double> sensorsData;
};
typedef SingleLineWithDataAndTime SLWDT;

#endif // SingleLineWithDataAndTime_h__
