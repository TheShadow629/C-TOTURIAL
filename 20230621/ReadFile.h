#ifndef ReadFile_h__
#define ReadFile_h__

#include<string>
#include <fstream>
#include <sstream>
#include"Vector.h"
#include "Date.h"
#include "Time.h"
#include "StoreSingleLineData.h"

//#define dayNums 32
const int dayNums = 32;
//typedef struct {
//	Date d;
//	Time t;
//	UserSpace::MyVector<double> sensorsData;
//} SingleLineWithDataAndTime;
typedef StoreSingleLineData SLWDT;

class ReadFile
{
private:
	string m_DataSourcePath;
	UserSpace::MyVector<string> m_DataFilePaths;
	UserSpace::MyVector<UserSpace::MyVector<string>> m_RawCsvData;
	UserSpace::MyVector<string> m_ColNames;
	UserSpace::MyVector<SLWDT>m_DataWithoutHead;
public:
	void SetDataSourcePath(string path);
	string GetDataSourcePath() const;
	void SetDataFilePaths(UserSpace::MyVector<string> paths);
	UserSpace::MyVector<string> GetDataFilePaths() const;
	void SetRawCsvData(UserSpace::MyVector<UserSpace::MyVector<string>> data);
	UserSpace::MyVector<UserSpace::MyVector<string>> GetRawCsvData() const;
	void SetColNames(UserSpace::MyVector<string> colnames);
	UserSpace::MyVector<string> GetColNames() const;
	void SetDataWithoutHead(UserSpace::MyVector<SLWDT> data);
	UserSpace::MyVector<SLWDT> GetDataWithoutHead() const;

	ReadFile(UserSpace::MyVector<SLWDT>& outData,string source="data_source.txt");
	void Initialize(UserSpace::MyVector<SLWDT>& outData);
	int GetColIndex(string colName);
	UserSpace::MyVector<double> GetSpecificDataOfMonth(int year, int month, string colName, bool flag);
	UserSpace::MyVector<double> GetSpecificDataOfDay(int year, int month, int day, string colName);

};


#endif // ReadFile_h__
