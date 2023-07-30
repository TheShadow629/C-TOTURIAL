#include "ReadWindLog.h"
#include <string>
#include <fstream>
#include <sstream>

#include "BinerySearchTree.h"
#include "CollectDouble.h"

void ReadWindLog::SetDataSourcePath(string path) {
	m_DataSourcePath = path;
}

string ReadWindLog::GetDataSourcePath() const {
	return m_DataSourcePath;
}
ReadWindLog::ReadWindLog(std::multimap <Date, Bst<MyPair>>& outData, string source)
{
	m_DataSourcePath = source;//datasource:txt filename
	Initialize(outData);
}

void ReadWindLog::Initialize(std::multimap <Date, Bst<MyPair>>& outData)
{
	ifstream inFile(m_DataSourcePath, ios::in);
	string lineStr;
	while (getline(inFile, lineStr))
	{
		m_DataFilePaths.push_back(lineStr);//CSVfilename in txt
	}
	//for (int i = 0; i < m_DataFilePaths.GetSize(); i++)//依次处理几个csv file
	for (auto CsvFileName = m_DataFilePaths.begin(); CsvFileName != m_DataFilePaths.end(); ++CsvFileName)
	{
		//此时处理的csv文件名是m_DataFilePaths[i]
		ifstream singleCSV(*CsvFileName, ios::in);//get the data from the first csv file, save in the singleCSV.
		string allColName;//save the head data.
		getline(singleCSV, allColName);
		//将表头信息读入m_ColNames
		stringstream ss(allColName);//stringstream can divide by the ',',so we need save the information into ss.
		string colName;

		m_ColNames.clear();
		while (getline(ss, colName, ','))//split the head information by',', and add in add m_colnames one by one.
		{
			m_ColNames.push_back(colName);
		}

		string line;
		while (getline(singleCSV, line))//read one line.
		{
			stringstream ss(line);//put one line data into a stream variable-ss
			string single;
			//UserSpace::MyVector<string> lineArray;
			std::list<string> lineArray;
			while (getline(ss, single, ','))//split the line by',', and save the processed data into vector-linearray.
			{
				lineArray.push_back(single);
			}

			//此时lineArray就是一行的数据，其形式为：1/03/2015 9:00	12	10.8	111	20	0.1	1011.3	1007.7
			stringstream ss1(*lineArray.begin());//read the first element in the first line and save it in ss1.
			string date/*, time*/;
			getline(ss1, date, ' ');//split the first element by' ',save in date.


			Date lineDate;
			lineDate.SetDate(date);
			//std::map<std::string, double> lineSensor;
			Bst<MyPair> LineSensors(MyPair("NA",0));
			if (lineDate.GetYear() != 0)//为了过滤空行
			{
				auto ColName = m_ColNames.begin();
				ColName++;
				auto value = lineArray.begin();
				value++;

				for ( ; 
					(ColName != m_ColNames.end())&&(value!= lineArray.end());
					ColName++, value++)
				{
					try//为了过滤NA数据,使用tryCatch过滤错误数据
					{
						MyPair tmp(*ColName, std::stod(*value));
						//lineSensor.insert(pair<string, double>(*ColName, std::stod(*m_Value)));
						LineSensors.Insert(LineSensors.GetTree(),tmp);
					}
					catch (...)
					{
						continue;//cout << "Something else" << endl;
					}
				}
				//m_MapDataWithoutHead1.insert(std::pair<Date, std::map<std::string, double>>(lineDate, lineSensor));
				//outData.insert(std::pair<Date, std::map<std::string, double>>(lineDate, lineSensor));

				m_MapDataWithoutHead2.insert(std::pair<Date, Bst<MyPair>>(lineDate, LineSensors));
				outData.insert(std::pair<Date, Bst<MyPair>>(lineDate, LineSensors));
			}
		}
	}
}

double ReadWindLog::GetDayData(int year, int month, int day, string colName, bool flag)
{
	double sum = 0;
	int Count = 0;

	Date d(year, month, day);
	auto iter1 = m_MapDataWithoutHead2.lower_bound(d);
	auto iter2 = m_MapDataWithoutHead2.upper_bound(d);
	int c = m_MapDataWithoutHead2.count(d);

	if (iter1 != std::end(m_MapDataWithoutHead2) && (c != 0))
	{
		for (auto iter = iter1; iter != iter2; ++iter)
		{
			double colValue = 0;
			iter->second.InOrderTraversal(selectValueFromKey, colName, colValue);
			sum += colValue;
			//sum += (iter->second.Find(MyPair(colName, 0), iter->second.GetTree()))->Data.GetValue();
			//sum += iter->second[colName];
			Count++;
		}
		if (flag)
			return sum / Count;
		else
			return sum;
	}
	else
	{
		return 0;
	}
}

std::list<double> ReadWindLog::GetMonthData(int year, int month, string colName, bool flag)
{
	//bool flag决定我们需要当日数据的平均值（比如风速）还是总和（比如太阳辐射量）
	//如果flag为false（0）我们就认为是需要总和，如果为true（1），我们就认为是需要平均值
	//UserSpace::MyVector<double> result;
	//Bst<double> res(0);
	std::list<double> res;
	for (int day = 1; day < DayNums; day++)
	{
		double dayValue = GetDayData(year, month, day, colName, flag);
		if (dayValue)
		{
			//result.Add(GetDayData(year, month, day, colName, flag));
			//res.Insert(res.GetTree(), dayValue);
			res.push_back(dayValue);
		}
	}
	return res;
	//return result;
}

std::multimap <Date, Bst<MyPair>>& ReadWindLog::GetMapDataWithoutHead()
{
	return m_MapDataWithoutHead2;
}

template<typename T>
void selectValueFromKey(T d, string colName, double& res)
{
	if (d.GetKey() == colName)
		res = d.GetValue();
}


