#ifndef ReadWindLog_h__
#define ReadWindLog_h__

#include<string>
#include <fstream>
#include <list>
#include <sstream>

#include "BinerySearchTree.h"
#include "Date.h"
#include "StoreSingleLineData.h"
#include "Mypair.h"
const int DayNums = 32;

class ReadWindLog
{
private:
	string m_DataSourcePath;
	std::list<string> m_DataFilePaths;
	std::list<string> m_ColNames;
	//std::multimap <Date, std::map<std::string, double>> m_MapDataWithoutHead1;
	std::multimap <Date, Bst<MyPair>> m_MapDataWithoutHead2;

public:
	void SetDataSourcePath(string path);
	string GetDataSourcePath() const;

	//ReadWindLog(std::multimap <Date, std::map<std::string, double>>& outData,string source="data_source.txt");
	ReadWindLog(std::multimap <Date, Bst<MyPair>>& outData, string source = "data_source.txt");
	void Initialize(std::multimap <Date, Bst<MyPair>>& outData);
	std::list<double> GetMonthData(int year, int month, string colName, bool flag);
	double GetDayData(int year, int month, int day, string colName, bool flag);

	std::multimap <Date, Bst<MyPair>>& GetMapDataWithoutHead();
};

template<typename T>
void selectValueFromKey(T d,string colName,double& res);


#endif // ReadWindLog_h__
