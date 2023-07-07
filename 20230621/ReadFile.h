#ifndef ReadFile_h__
#define ReadFile_h__

#include<string>
#include <fstream>
#include <sstream>
#include"Vector.h"
#include "Date.h"
#include "Time.h"
#include "SingleLineWithDataAndTime.h"

//typedef struct {
//	Date d;
//	Time t;
//	UserSpace::MyVector<double> sensorsData;
//} SingleLineWithDataAndTime;
typedef SingleLineWithDataAndTime SLWDT;

class ReadFile
{
private:
	string m_DataSourcePath;
	UserSpace::MyVector<string> m_DataFilePaths;
	UserSpace::MyVector<UserSpace::MyVector<string>> m_RawCsvData;
	UserSpace::MyVector<string> m_ColNames;
	UserSpace::MyVector<SLWDT>m_DataWithoutHead;
public:
	void setDataSourcePath(string path);
	string getDataSourcePath() const;
	void setDataFilePaths(UserSpace::MyVector<string> paths);
	UserSpace::MyVector<string> getDataFilePaths() const;
	void setRawCsvData(UserSpace::MyVector<UserSpace::MyVector<string>> data);
	UserSpace::MyVector<UserSpace::MyVector<string>> getRawCsvData() const;
	void setColNames(UserSpace::MyVector<string> colnames);
	UserSpace::MyVector<string> getColNames() const;
	void setDataWithoutHead(UserSpace::MyVector<SLWDT> data);
	UserSpace::MyVector<SLWDT> getDataWithoutHead() const;

	ReadFile(UserSpace::MyVector<SLWDT>& outData,string source="data_source.txt");
	void initialize(UserSpace::MyVector<SLWDT>& outData);
	int getColIndex(string colName);
	UserSpace::MyVector<double> getSpecificDataOfMonth(int year, int month, string colName, bool flag);
	UserSpace::MyVector<double> getSpecificDataOfDay(int year, int month, int day, string colName);

};


#endif // ReadFile_h__
