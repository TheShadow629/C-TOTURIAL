#include <cassert>
#include <sstream>
#include "BinerySearchTree.h"
#include "Date.h"
#include "MathUtils.h"
#include "MyPair.h"
#include "ReadWindLog.h"

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

void testDateReloadOperator()
{
	Date d1,d2;
	d1.SetDate("1/03/2014");
	d2.SetDate("1/03/2010");
	assert((d1 > d2)==true);
	assert((d2<d1) == true);	
}

int testDate()
{
	testDateConstructor();
	testDateSettersAndGetters();
	testDateSetDate();
	testDateIO();
	testDateReloadOperator();
	return 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void testCalculateAve()
{
	std::list<double> nums;
	nums.push_back(1.0);
	nums.push_back(2.0);
	nums.push_back(3.0);
	double res = 0;
	assert(MathUtils::CalculateAve(nums, res) == true);
}

void testCalculateStand()
{
	std::list<double> nums;
	nums.push_back(1.0);
	nums.push_back(2.0);
	nums.push_back(3.0);
	double res = 0;
	assert(MathUtils::CalculateStand(nums, res) == true);
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

void TestConstructorAndGetKey()
{
	std::string key = "Test";
	double value = 10.0;
	MyPair pair(key, value);
	assert(pair.GetKey() == key);  // 检查 GetKey 函数返回的键是否与给定的键相等
}

void TestSetKeyAndGetValue()
{
	std::string key = "Test";
	double value = 10.0;
	MyPair pair;

	pair.SetKey(key);
	pair.SetValue(value);

	assert(pair.GetKey() == key);  // 检查 SetKey 函数设置的键是否与给定的键相等
	assert(MathUtils::AlmostEqual(pair.GetValue(), value, 0.001) == true);  // 检查 SetValue 函数设置的值是否与给定的值相等
}

void TestAssignmentOperator()
{
	std::string key1 = "Test1";
	double value1 = 10.0;

	std::string key2 = "Test2";
	double value2 = 20.0;

	MyPair pair1(key1, value1);
	MyPair pair2(key2, value2);

	pair1 = pair2;

	assert(pair1.GetKey() == key2);  // 检查赋值操作符是否正确复制了键
	assert(MathUtils::AlmostEqual(pair1.GetValue(), value2, 0.001) == true);  // 检查赋值操作符是否正确复制了值
}

void TestComparisonOperators()
{
	std::string key1 = "Test1";
	double value1 = 10.0;

	std::string key2 = "Test2";
	double value2 = 20.0;

	MyPair pair1(key1, value1);
	MyPair pair2(key2, value2);

	assert(pair2 > pair1);  // 检查 operator> 是否正确比较了两个 MyPair 实例的值
	assert(pair1 < pair2);  // 检查 operator< 是否正确比较了两个 MyPair 实例的值
}

int TestMyPair()
{
	TestConstructorAndGetKey();
	TestSetKeyAndGetValue();
	TestAssignmentOperator();
	TestComparisonOperators();
	return 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void TestSetAndGetDataSourcePath()
{
	std::string path = "data_source.txt";
	std::multimap <Date, Bst<MyPair>> out;
	ReadWindLog reader(out);
	reader.SetDataSourcePath(path);
	assert(reader.GetDataSourcePath() == path);  
}

void TestInitializeAndGetMapDataWithoutHead()
{
	std::multimap<Date, Bst<MyPair>> mapData;
	ReadWindLog reader(mapData, "data_source.txt");

	reader.Initialize(mapData);
	assert(&reader.GetMapDataWithoutHead() == &mapData);  
}

void TestGetMonthData()
{
	std::multimap<Date, Bst<MyPair>> mapData;
	ReadWindLog reader(mapData, "data_source.txt");

	int year = 2014;
	int month = 3;
	std::string colName = "S";
	bool flag = true;

	std::list<double> monthData = reader.GetMonthData(year, month, colName, flag);
	assert(!monthData.empty());
}

void TestGetDayData()
{
	std::multimap<Date, Bst<MyPair>> mapData;
	ReadWindLog reader(mapData, "data_source.txt");

	int year = 2014;
	int month = 3;
	int day = 1;
	std::string colName = "S";
	bool flag = true;

	double dayData = reader.GetDayData(year, month, day, colName, flag);
	assert(MathUtils::AlmostEqual(dayData, 0, 0.00001) == false);
}

int TestReadWindLog() {
	TestSetAndGetDataSourcePath();
	TestInitializeAndGetMapDataWithoutHead();
	TestGetMonthData();
	TestGetDayData();

	return 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void testConstructor()
{
	Bst<int> tree;

	assert(tree.GetTree() != nullptr);
	assert(tree.GetTree()->Left == nullptr);
	assert(tree.GetTree()->Right == nullptr);

	tree.DeleteTree(tree.GetTree());
}

void testConstructorWithPara()
{
	int data = 10;
	Bst<int> tree(data);

	assert(tree.GetTree() != nullptr);
	assert(tree.GetTree()->GetData() == data);
	assert(tree.GetTree()->Left == nullptr);
	assert(tree.GetTree()->Right == nullptr);

	tree.DeleteTree(tree.GetTree());
}

void testInsert()
{
	Bst<int> tree;

	nodeType<int>* result=nullptr;
	tree.Insert(tree.GetTree(), 10);
	tree.Insert(tree.GetTree(), 15);
	tree.Insert(tree.GetTree(), 3);
	tree.Insert(tree.GetTree(), 7);
	tree.Insert(tree.GetTree(), 25);
	tree.Insert(tree.GetTree(), 8);
	tree.Insert(tree.GetTree(), 17);
	tree.Insert(tree.GetTree(), 1);
	result = tree.Insert(tree.GetTree(), 6);

	auto disp = [](int& x) {cout << " " << x << " "; };
	tree.InOrderTraversal(disp);
	assert(result!=nullptr);

	tree.DeleteTree(tree.GetTree());
}

void testDeleteTree()
{
	Bst<int> tree;

	nodeType<int>* result = nullptr;
	tree.Insert(tree.GetTree(), 10);
	tree.Insert(tree.GetTree(), 15);
	tree.Insert(tree.GetTree(), 3);
	tree.Insert(tree.GetTree(), 7);
	tree.Insert(tree.GetTree(), 25);
	tree.Insert(tree.GetTree(), 8);
	tree.Insert(tree.GetTree(), 17);
	tree.Insert(tree.GetTree(), 1);
	result = tree.Insert(tree.GetTree(), 6);

	auto disp = [](int& x) {cout << " " << x << " "; };
	tree.InOrderTraversal(disp);
	assert(result != nullptr);

	tree.DeleteTree(tree.GetTree());

	tree.InOrderTraversal(disp);
	assert(tree.GetTree() == nullptr);
}

void testFind()
{
	Bst<int> tree;

	nodeType<int>* result = nullptr;
	tree.Insert(tree.GetTree(), 10);
	tree.Insert(tree.GetTree(), 15);
	tree.Insert(tree.GetTree(), 3);
	tree.Insert(tree.GetTree(), 7);
	tree.Insert(tree.GetTree(), 25);
	tree.Insert(tree.GetTree(), 8);
	tree.Insert(tree.GetTree(), 17);
	tree.Insert(tree.GetTree(), 1);
	result = tree.Insert(tree.GetTree(), 6);

	result=tree.Find(10, tree.GetTree());
	assert(result != nullptr);

	tree.DeleteTree(tree.GetTree());
}

void testInorderTraversal()
{
	Bst<int> tree;

	nodeType<int>* result = nullptr;
	tree.Insert(tree.GetTree(), 10);
	tree.Insert(tree.GetTree(), 15);
	tree.Insert(tree.GetTree(), 3);
	tree.Insert(tree.GetTree(), 7);
	tree.Insert(tree.GetTree(), 25);
	tree.Insert(tree.GetTree(), 8);
	tree.Insert(tree.GetTree(), 17);
	tree.Insert(tree.GetTree(), 1);
	result = tree.Insert(tree.GetTree(), 6);

	auto disp = [](int& x) {cout << " " << x << " "; };
	tree.InOrderTraversal(disp);

	tree.DeleteTree(tree.GetTree());

	Bst<MyPair> ptree(MyPair("NA",0));
	ptree.Insert(ptree.GetTree(), MyPair("ST",1));
	ptree.Insert(ptree.GetTree(), MyPair("C", 2));
	ptree.Insert(ptree.GetTree(), MyPair("X", 5));
	ptree.Insert(ptree.GetTree(), MyPair("DX", 6));
	ptree.Insert(ptree.GetTree(), MyPair("T", 4));
	ptree.Insert(ptree.GetTree(), MyPair("A", 3));
	
	auto selectValueFromKey1 = [](MyPair& d, string colName, double& res)
	{
		if (d.GetKey() == colName)
			res = d.GetValue();
	};
	double res=0;
	ptree.InOrderTraversal(selectValueFromKey1, "A", res);
	assert(MathUtils::AlmostEqual(res,3, 0.00001) == true);

	ptree.DeleteTree(ptree.GetTree());
}

void testPostOrderTraversal()
{
	Bst<int> tree;

	nodeType<int>* result = nullptr;
	tree.Insert(tree.GetTree(), 10);
	tree.Insert(tree.GetTree(), 15);
	tree.Insert(tree.GetTree(), 3);
	tree.Insert(tree.GetTree(), 7);
	tree.Insert(tree.GetTree(), 25);
	tree.Insert(tree.GetTree(), 8);
	tree.Insert(tree.GetTree(), 17);
	tree.Insert(tree.GetTree(), 1);
	result = tree.Insert(tree.GetTree(), 6);

	auto disp = [](int& x) {cout << " " << x << " "; };
	tree.PostOrderTraversal(disp);

	tree.DeleteTree(tree.GetTree());
}

void testpreOrderTraversal()
{
	Bst<int> tree;

	nodeType<int>* result = nullptr;
	tree.Insert(tree.GetTree(), 10);
	tree.Insert(tree.GetTree(), 15);
	tree.Insert(tree.GetTree(), 3);
	tree.Insert(tree.GetTree(), 7);
	tree.Insert(tree.GetTree(), 25);
	tree.Insert(tree.GetTree(), 8);
	tree.Insert(tree.GetTree(), 17);
	tree.Insert(tree.GetTree(), 1);
	result = tree.Insert(tree.GetTree(), 6);

	auto disp = [](int& x) {cout << " " << x << " "; };
	tree.PreOrderTraversal(disp);

	tree.DeleteTree(tree.GetTree());
}

void testGetTree()
{
	Bst<int> tree;
	nodeType<int>*& rootRef = tree.GetTree();

	assert(rootRef !=nullptr);
	tree.DeleteTree(tree.GetTree());

}

void testCloneAndOperator()
{
	Bst<int> tree1, tree2;

	nodeType<int>* result = nullptr;
	tree1.Insert(tree1.GetTree(), 10);
	tree1.Insert(tree1.GetTree(), 15);
	tree1.Insert(tree1.GetTree(), 3);
	tree1.Insert(tree1.GetTree(), 7);
	tree1.Insert(tree1.GetTree(), 25);
	tree1.Insert(tree1.GetTree(), 8);
	tree1.Insert(tree1.GetTree(), 17);
	tree1.Insert(tree1.GetTree(), 1);
	tree1.Insert(tree1.GetTree(), 6);

	tree2 = tree1;
	assert(tree2.GetTree() != nullptr);
	auto disp = [](int& x) {cout << " " << x << " "; };
	tree2.InOrderTraversal(disp);

	tree1.DeleteTree(tree1.GetTree());
	tree2.DeleteTree(tree2.GetTree());

}

int trstBST()
{
	testConstructor();
	testConstructorWithPara();
	testInsert();
	testDeleteTree();
	testFind();
	testInorderTraversal();
	testPostOrderTraversal();
	testpreOrderTraversal();
	testGetTree();
	testCloneAndOperator();
	return 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int testUserInterface()
{
	return 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
