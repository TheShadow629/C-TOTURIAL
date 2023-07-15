#ifndef StoreSingleLineData_h__
#define StoreSingleLineData_h__

#include "Date.h"
#include "Time.h"
#include "Vector.h"

class StoreSingleLineData
{
public:
	void SetDate(string& d);
	Date GetDate();
	void SetTime(string& T);
	Time GetTime();

	void AddData(const double& n);
	UserSpace::MyVector<double>& GetSensorsData();

private:
	Date m_d;
	Time m_t;
	UserSpace::MyVector<double> m_SensorsData;
};
typedef StoreSingleLineData SLWDT;

#endif // SingleLineWithDataAndTime_h__
