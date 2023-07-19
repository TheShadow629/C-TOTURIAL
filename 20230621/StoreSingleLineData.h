#ifndef StoreSingleLineData_h__
#define StoreSingleLineData_h__

#include "Date.h"
#include "Time.h"
#include "Vector.h"
#include <map> 
class StoreSingleLineData
{
public:
	void SetDate(string& d);
	Date GetDate() const;
	void SetTime(string& T);
	Time GetTime();

	//void AddData(const double& n);
	void AddData(const std::pair<std::string, double>& d);

	//UserSpace::MyVector<double>& GetSensorsData();
	std::map<std::string, double>& GetMapSensorsData();
private:
	Date m_d;
	Time m_t;
	//UserSpace::MyVector<double> m_SensorsData;
	std::map<std::string, double> m_MapSensorsData;
};
typedef StoreSingleLineData SLWDT;

bool operator>(const StoreSingleLineData& lhs, const StoreSingleLineData& rhs);
bool operator<(const StoreSingleLineData& lhs, const StoreSingleLineData& rhs);

#endif // SingleLineWithDataAndTime_h__
