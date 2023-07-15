#include <cassert>
#include <sstream>
#include "Date.h"
#include "MathUtils.h"
#include "ReadFile.h"
#include "Vector.h"

void testDateConstructor()
{
	// 测试 Date 的构造函数是否正常工作
	Date d(2022, 2, 27);
	assert(d.GetYear() == 2022);
	assert(d.GetMonth() == 2);
	assert(d.GetDay() == 27);
}

void testDateSettersAndGetters()
{
	// 测试 Date 的 setter 和 getter 方法是否正常工作
	Date d;
	d.SetYear(2022);
	assert(d.GetYear() == 2022);
	d.SetMonth(12);
	assert(d.GetMonth() == 12);
	d.SetDay(31);
	assert(d.GetDay() == 31);
}

void testDateSetDate()
{
	// 测试 Date 的 setDate 方法是否正常工作
	Date d;
	d.SetDate("1/03/2014");
	assert(d.GetYear() == 2014);
	assert(d.GetMonth() == 3);
	assert(d.GetDay() == 1);
}

void testDateIO()
{
	// 测试 Date 的输入输出操作符是否正常工作
  // Test output operator (operator <<)
	{
		std::ostringstream oss;
		Date date(2022, 1, 1);
		oss << date;
		assert(oss.str() == "1 January 2022\n");
	}

	// Test input operator (operator >>)
	{
		std::istringstream iss("2022 12 31");
		Date date;
		iss >> date;
		assert(date.GetDay() == 31);
		assert(date.GetMonth() == 12);
		assert(date.GetYear() == 2022);
		//assert means if the program satisfied () conditions, continue the next step, if false, stop the prograqm and threw the exception. 
	}
}
int testDate()
{
	testDateConstructor();
	testDateSettersAndGetters();
	testDateSetDate();
	testDateIO();
	return 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void testCalculateAve()
{
	UserSpace::MyVector<double> nums;
	nums.Add(1.0);
	nums.Add(2.0);
	nums.Add(3.0);
	assert(MathUtils::AlmostEqual(MathUtils::CalculateAve(nums), 2.0) == true);
}

void testCalculateStand()
{
	UserSpace::MyVector<double> nums;
	nums.Add(1.0);
	nums.Add(2.0);
	nums.Add(3.0);
	assert(MathUtils::AlmostEqual(MathUtils::CalculateStand(nums), 2.0) == true);
}

 void testAlmostEqual()
 {
 	assert(MathUtils::AlmostEqual(1.0, 1.0 + 0.000999999, 0.001) == true);
 	assert(MathUtils::AlmostEqual(1.0, 1.0 + 0.001, 0.001) == false);
 	assert(MathUtils::AlmostEqual(1.0, 1.0 + 0.000999, 0.001) == false);
 }

void testGetMonthFromNum()
{
	assert(MathUtils::GetMonthFromNum(1) == "January");
	assert(MathUtils::GetMonthFromNum(2) == "February");
	assert(MathUtils::GetMonthFromNum(3) == "March");
	assert(MathUtils::GetMonthFromNum(4) == "April");
	assert(MathUtils::GetMonthFromNum(5) == "May");
	assert(MathUtils::GetMonthFromNum(6) == "June");
	assert(MathUtils::GetMonthFromNum(7) == "July");
	assert(MathUtils::GetMonthFromNum(8) == "August");
	assert(MathUtils::GetMonthFromNum(9) == "September");
	assert(MathUtils::GetMonthFromNum(10) == "October");
	assert(MathUtils::GetMonthFromNum(11) == "November");
	assert(MathUtils::GetMonthFromNum(12) == "December");
	assert(MathUtils::GetMonthFromNum(13) == ""); // invalid month number
}

int testMathUtils()
{
	testCalculateAve();
	testCalculateStand();
	testAlmostEqual();
	testGetMonthFromNum();
	return 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void testSetDataSourcePath()
{
	UserSpace::MyVector<SLWDT> outData;
	ReadFile rf(outData);
	rf.SetDataSourcePath("test.txt");
	assert(rf.GetDataSourcePath() == "test.txt");
}
void testSetDataFilePaths()
{
	UserSpace::MyVector<SLWDT> outData;
	ReadFile rf(outData);

	UserSpace::MyVector<string> paths;
	paths.Add("file1.csv");
	paths.Add("file2.csv");
	paths.Add("file3.csv");
	rf.SetDataFilePaths(paths);
	assert(rf.GetDataFilePaths() == paths);
}
void testSetRawCsvData()
{
	UserSpace::MyVector<SLWDT> outData;
	ReadFile rf(outData);

	UserSpace::MyVector<UserSpace::MyVector<string>> data;
	UserSpace::MyVector<string> tmp;
	tmp.Add("a");
	tmp.Add("b");
	tmp.Add("c");
	data.Add(tmp);

	rf.SetRawCsvData(data);
	assert(rf.GetRawCsvData()[0] == data[0]);
}

void testSetColNames()
{
	UserSpace::MyVector<SLWDT> outData;
	ReadFile rf(outData);

	UserSpace::MyVector<string> colnames;
	colnames.Add("name");
	colnames.Add("age");

	rf.SetColNames(colnames);
	assert(rf.GetColNames() == colnames);
}

void testSetDataWithoutHead()
{
	UserSpace::MyVector<SLWDT> outData;
	ReadFile rf(outData);

	UserSpace::MyVector<SLWDT> data;
	SLWDT tmps;
	string tmpp = "1/03/2014";
	tmps.SetDate(tmpp);
	tmpp = "9:00";
	tmps.SetTime(tmpp);
	tmps.AddData(12.5);
	data.Add(tmps);

	rf.SetDataWithoutHead(data);
	assert(!rf.GetDataWithoutHead().Empty());
}

void testInitialize()
{
	UserSpace::MyVector<SLWDT> data;
	ReadFile rf(data);
	rf.Initialize(data);
	assert(!rf.GetDataFilePaths().Empty());
	assert(!rf.GetRawCsvData().Empty());
	assert(!rf.GetColNames().Empty());
	assert(!rf.GetDataWithoutHead().Empty());
}

void testGetColIndex()
{
	UserSpace::MyVector<SLWDT> data;
	ReadFile rf(data);
	UserSpace::MyVector<string> colnames;
	colnames.Add("empty");
	colnames.Add("name");
	colnames.Add("age");
	colnames.Add("gender");

	rf.SetColNames(colnames);
	assert(rf.GetColIndex("name") == 0);
	assert(rf.GetColIndex("age") == 1);
	assert(rf.GetColIndex("gender") == 2);
}

void testGetSpecificDataOfMonth()
{
	UserSpace::MyVector<SLWDT> data;
	ReadFile rf(data);
	UserSpace::MyVector<double> monthData = rf.GetSpecificDataOfMonth(2014, 3, "T", false);
	assert(!monthData.Empty());
}

void testGetSpecificDataOfDay()
{
	UserSpace::MyVector<SLWDT> data;
	ReadFile rf(data);
	UserSpace::MyVector<double> dayData = rf.GetSpecificDataOfDay(2014, 3, 1, "T");
	assert(!dayData.Empty());
}

int testReadFile()
{
	testSetDataSourcePath();
	testSetDataFilePaths();
	testSetRawCsvData();
	testSetColNames();
	testSetDataWithoutHead();
	testInitialize();
	testGetColIndex();
	testGetSpecificDataOfMonth();
	testGetSpecificDataOfDay();
	return 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void testSetDateAndGetDate()
{
	StoreSingleLineData slwdt;
	string dateStr = "1/03/2014";
	slwdt.SetDate(dateStr);
	assert(slwdt.GetDate().GetYear() == 2014);
	assert(slwdt.GetDate().GetMonth() == 3);
	assert(slwdt.GetDate().GetDay() == 1);
}

void testSetTimeAndGetTime()
{
	StoreSingleLineData slwdt;
	string timeStr = "9:00";
	slwdt.SetTime(timeStr);
	assert(slwdt.GetTime().GetHour() == 9);
	assert(slwdt.GetTime().GetMin() == 0);
}

void testAddDataAndGetSensorsData()
{
	StoreSingleLineData slwdt;
	slwdt.AddData(1.0);
	slwdt.AddData(2.0);
	slwdt.AddData(3.0);
	UserSpace::MyVector<double> data = slwdt.GetSensorsData();
	assert(data.GetSize() == 3);
	assert(data[0] == 1.0);
	assert(data[1] == 2.0);
	assert(data[2] == 3.0);
}

int testSingleLineWithDataAndTime()
{
	testSetDateAndGetDate();
	testSetTimeAndGetTime();
	testAddDataAndGetSensorsData();
	return 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void testDefaultConstructor()
{
	Time t;
	assert(t.GetHour() == 0);
	assert(t.GetMin() == 0);
}

void testCustomConstructor()
{
	Time t(10, 30);
	assert(t.GetHour() == 10);
	assert(t.GetMin() == 30);
}

void testGetHour()
{
	Time t(9, 40);
	assert(t.GetHour() == 9);
}

void testSetHour()
{
	Time t(15, 20);
	t.SetHour(16);
	assert(t.GetHour() == 16);
}

void testGetMin()
{
	Time t(11, 45);
	assert(t.GetMin() == 45);
}

void testSetMin()
{
	Time t(14, 50);
	t.SetMin(55);
	assert(t.GetMin() == 55);
}

void testSetTime()
{
	Time t;
	t.SetTime(12, 30);
	assert(t.GetHour() == 12);
	assert(t.GetMin() == 30);
}

void testSetTimeFromString()
{
	Time t;
	t.SetTime("09:30");
	assert(t.GetHour() == 9);
	assert(t.GetMin() == 30);
}

void testSetTimeFromStringIncorrectFormat()
{
	Time t;
	try
	{
		t.SetTime("9-30");
	}
	catch (const std::exception& e)
	{
		std::string expectedMsg = "Invalid time format, should be HH:MM";
		assert(e.what() == expectedMsg);
	}
}

int testTime()
{
	testDefaultConstructor();
	testCustomConstructor();
	testGetHour();
	testSetHour();
	testGetMin();
	testSetMin();
	testSetTime();
	testSetTimeFromString();
	testSetTimeFromStringIncorrectFormat();

	return 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int testUserInterface()
{
	return 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
template <class T>
void TestMyVectorConstructor()
{
	UserSpace::MyVector<T> vec;
	assert(vec.GetSize() == 0);
}

template <class T>
void TestMyVectorAdd()
{
	UserSpace::MyVector<T> vec;
	vec.Add(1);
	vec.Add(2);
	assert(vec.GetSize() == 2);
	assert(vec[0] == 1);
	assert(vec[1] == 2);
}

template <class T>
void TestMyVectorInsert()
{
	UserSpace::MyVector<T> vec;
	vec.Add(1);
	vec.Add(3);
	vec.Insert(vec.begin() + 1, 2);
	assert(vec.GetSize() == 3);
	assert(vec[0] == 1);
	assert(vec[1] == 2);
	assert(vec[2] == 3);
}

template <class T>
void TestMyVectorRemoveElements()
{
	UserSpace::MyVector<T> vec;
	vec.Add(1);
	vec.Add(2);
	vec.RemoveElements();
	assert(vec.GetSize() == 0);
}

template <class T>
void TestMyVectorDeletePosition()
{
	UserSpace::MyVector<T> vec;
	vec.Add(1);
	vec.Add(2);
	vec.DeletePosition(vec.begin() + 1);
	assert(vec.GetSize() == 1);
	assert(vec[0] == 1);
}

template <class T>
void TestMyVectorGetSize()
{
	UserSpace::MyVector<T> vec;
	assert(vec.GetSize() == 0);
	vec.Add(1);
	vec.Add(2);
	vec.Add(3);
	assert(vec.GetSize() == 3);
}

template <class T>
void TestMyVectorEmpty()
{
	UserSpace::MyVector<T> vec;
	assert(vec.Empty());
	vec.Add(1);
	assert(!vec.Empty());
}

int testMyVector()
{
	TestMyVectorConstructor<int>();
	TestMyVectorAdd<int>();
	TestMyVectorInsert<int>();
	TestMyVectorRemoveElements<int>();
	TestMyVectorDeletePosition<int>();
	TestMyVectorGetSize<int>();
	TestMyVectorEmpty<int>();
	cout << "All tests passed!" << endl;
	return 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
