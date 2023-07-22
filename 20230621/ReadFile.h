#ifndef ReadFile_h__
#define ReadFile_h__

#include<string>
#include <fstream>
#include <list>
#include <sstream>

#include "BinerySearchTree.h"
#include"Vector.h"
#include "Date.h"
#include "Time.h"
#include "StoreSingleLineData.h"

const int dayNums = 32;
//typedef struct {
//	Date d;
//	Time t;
//	UserSpace::MyVector<double> sensorsData;
//} SingleLineWithDataAndTime;
//typedef StoreSingleLineData SLWDT;

class ReadFile
{
private:
	string m_DataSourcePath;
	//UserSpace::MyVector<string> m_DataFilePaths;
	std::list<string> m_DataFilePaths;
	//UserSpace::MyVector<UserSpace::MyVector<string>> m_RawCsvData;
	//UserSpace::MyVector<string> m_ColNames;
	std::list<string> m_ColNames;

	//UserSpace::MyVector<SLWDT>m_DataWithoutHead;
	//std::multimap <Date, SLWDT> m_MapDataWithoutHead;
	std::multimap <Date, std::map<std::string, double>> m_MapDataWithoutHead1;

public:
	void SetDataSourcePath(string path);
	string GetDataSourcePath() const;
	//void SetDataFilePaths(UserSpace::MyVector<string> paths);
	//UserSpace::MyVector<string> GetDataFilePaths() const;
	//void SetRawCsvData(UserSpace::MyVector<UserSpace::MyVector<string>> data);
	//UserSpace::MyVector<UserSpace::MyVector<string>> GetRawCsvData() const;
	//void SetColNames(UserSpace::MyVector<string> colnames);
	//UserSpace::MyVector<string> GetColNames() const;
	//void SetDataWithoutHead(UserSpace::MyVector<SLWDT> data);
	//UserSpace::MyVector<SLWDT> GetDataWithoutHead() const;

	ReadFile(std::multimap <Date, std::map<std::string, double>>& outData,string source="data_source.txt");
	void Initialize(std::multimap <Date, std::map<std::string, double>>& outData);
	//int GetColIndex(string colName);
	Bst<double>& GetSpecificDataOfMonth(int year, int month, string colName, bool flag);
	double GetSpecificDataOfDay(int year, int month, int day, string colName, bool flag);
};
#endif // ReadFile_h__
