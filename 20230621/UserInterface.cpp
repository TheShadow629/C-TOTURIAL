#include "UserInterface.h"
#include <iostream>
#include "ReadFile.h"
#include "MathUtils.h"
//#include "Vector.h"
#include <iomanip>
#include <list>

#include "CollectDouble.h"
const double UnitConversionFactor = 6000;
const int STARTYEAR = 2010;
const int ENDYEAR = 2016;


int UserInterface::Function1( ReadFile& f1) {
	std::cout << "Please input year and month to get wind data" << std::endl;
	int year = 0, month = 0;
	std::cin >> year >> month;

	Bst<double> result= f1.GetSpecificDataOfMonth(year, month, "S", true);
	CollectD<double> cd;
	result.InOrderTraversal(CollectD<double>::Add);
	std::list<double> tmp;
	CollectD<double>::Get(tmp);

	std::cout << endl << MathUtils::GetMonthFromNum(month) << " " << year << ":";
	double ave = 0, stdev = 0;
	if (MathUtils::CalculateAve(tmp, ave)&& MathUtils::CalculateStand(tmp, stdev))
	{
		std::cout << std::endl
			<< "Average Speed: " << setiosflags(ios::fixed) << setprecision(1) << ave << "km/h" << endl
			<< "Sample Stdev: " << setiosflags(ios::fixed) << setprecision(1) << stdev << std::endl;
	}
	else
	{
		std::cout << "No Data" << endl;
	}

	result.DeleteTree(result.GetTree());
	return 0;
}

int UserInterface::Function2(ReadFile& f1) {
	std::cout << "Please input year to get Average ambient air temperature and sample standard deviation for each month of a specified year.(print on screen only)" << std::endl;
	int year = 0;
	std::cin >> year;

	cout << endl << year << endl;
	for (int i = 1; i < 13; i++)
	{
		Bst<double> result = f1.GetSpecificDataOfMonth(year, i, "T", true);
		CollectD<double> cd;
		result.InOrderTraversal(CollectD<double>::Add);
		std::list<double> tmp;
		CollectD<double>::Get(tmp);

		cout << MathUtils::GetMonthFromNum(i) << ": ";
		double ave = 0, stdev = 0;
		if (MathUtils::CalculateAve(tmp, ave) && MathUtils::CalculateStand(tmp, stdev))
		{
			cout << "average: " << setiosflags(ios::fixed) << setprecision(1) << ave
				<< " degrees C, stdev: " << setiosflags(ios::fixed) << setprecision(1) << stdev << endl;
		}
		else
		{
			std::cout << "No Data" << endl;
		}
		result.DeleteTree(result.GetTree());
	}

	return 0;
}

int UserInterface::Function3(ReadFile& f1) {
	//cout << "Total solar radiation in kWh/m2 for each month of a specified year.(print on screen only)";
	//int year = 0;
	//cout << endl;
	//std::cin >> year;

	////ReadFile f1;
	////f1.initialize();

	//for (int i = 1; i < 13; i++)
	//{
	//	//UserSpace::MyVector<double> result = f1.GetSpecificDataOfMonth(year, i, "SR", false);
	//	Bst<double> result = f1.GetSpecificDataOfMonth(year, i, "SR", false);
	//	CollectD<double> cd;
	//	result.InOrderTraversal(CollectD<double>::Add);
	//	std::list<double> tmp;
	//	CollectD<double>::Get(tmp);

	//	cout << MathUtils::GetMonthFromNum(i) << ": ";
	//	if (!tmp.empty())
	//	{
	//		double sum = 0;
	//		for (double num : tmp)
	//		{
	//			sum += num;
	//		}
	//		sum /= UnitConversionFactor;
	//		cout << setiosflags(ios::fixed) << setprecision(1) << sum << " kWh/m2";
	//	}
	//	else
	//	{
	//		std::cout << "No Data";
	//	}
	//	cout << endl;
	//}

	//return 0;
	//改成spcc分析的功能
	int month = 0;
	std::cin >> month;
	cout << endl;
	cout << "Sample Pearson Correlation Coefficient for " << MathUtils::GetMonthFromNum(month) << endl;

	CollectD<double> cd;
	std::list<double> SData, TData, RData;
	for (int year = STARTYEAR; year < ENDYEAR; year++)
	{
		Bst<double> result = f1.GetSpecificDataOfMonth(year, month, "S", true);
		CollectD<double>::Clear();
		result.InOrderTraversal(CollectD<double>::Add);
		CollectD<double>::Get(SData);

		result.DeleteTree(result.GetTree());

	}

	for (int year = STARTYEAR; year < ENDYEAR; year++)
	{
		Bst<double> result = f1.GetSpecificDataOfMonth(year, month, "T", true);
		CollectD<double>::Clear();
		result.InOrderTraversal(CollectD<double>::Add);
		CollectD<double>::Get(TData);

		result.DeleteTree(result.GetTree());

	}

	for (int year = STARTYEAR; year < ENDYEAR; year++)
	{
		Bst<double> result = f1.GetSpecificDataOfMonth(year, month, "SR", false);
		CollectD<double>::Clear();
		result.InOrderTraversal(CollectD<double>::Add);
		CollectD<double>::Get(RData);

		result.DeleteTree(result.GetTree());

	}
	for (double num : RData)
	{
		num /= UnitConversionFactor;
	}

	auto pearson = [](std::list<double> list1, std::list<double> list2) {
		int n = std::distance(list1.begin(), list1.end());
		//simple sums
		double sum1 = 0.0;
		double sum2 = 0.0;
		for (auto it = list1.begin(); it != list1.end(); ++it) {
			sum1 += *it;
		}
		for (auto it = list2.begin(); it != list2.end(); ++it) {
			sum2 += *it;
		}
		//sum up the squares
		double sum1_pow = 0.0;
		double sum2_pow = 0.0;
		for (auto it = list1.begin(); it != list1.end(); ++it) {
			sum1_pow += pow(*it, 2.0);
		}
		for (auto it = list2.begin(); it != list2.end(); ++it) {
			sum2_pow += pow(*it, 2.0);
		}
		//sum up the products
		double p_sum = 0.0;
		auto it1 = list1.begin();
		auto it2 = list2.begin();
		for (; it1 != list1.end() && it2 != list2.end(); ++it1, ++it2) {
			p_sum += (*it1) * (*it2);
		}
		//分子num，分母den
		double num = p_sum - (sum1 * sum2 / n);
		double den = sqrt((sum1_pow - pow(sum1, 2) / n) * (sum2_pow - pow(sum2, 2) / n));
		if (den == 0) {
			return 0.0;
		}
		return num / den;
	};

	//double S_T = pearson(SData, TData);
	//double S_R = pearson(SData, RData);
	//double T_R = pearson(TData, RData);

	std::cout << "S_T:" << pearson(SData, TData) << std::endl;
	std::cout << "S_R:" << pearson(SData, RData) << std::endl;
	std::cout << "T_R:" << pearson(TData, RData) << std::endl;

	return 0;
}

int UserInterface::Function4(ReadFile& f1) {
	std::cout << "Average wind speed (km/h), average ambient air temperature and total"
		"solar radiation in"
		"kWh / m2for each month of a specified year.The standard deviation is printed in()nextto the average. (print to a file called\"WindTempSolar.csv\")"
		<< std::endl;
	int year = 0;
	std::cin >> year;

	ofstream file("WindTempSolar.csv");
	file << year << endl;

	for (int i = 1; i < 13; i++)
	{
		//UserSpace::MyVector<double> result = f1.GetSpecificDataOfMonth(year, i, "S", true);
		//double ave = MathUtils::CalculateAve(result);
		//double stdev = MathUtils::CalculateStand(result);

		Bst<double> result = f1.GetSpecificDataOfMonth(year, i, "S", true);
		CollectD<double> cd;
		result.InOrderTraversal(CollectD<double>::Add);
		std::list<double> tmp;
		CollectD<double>::Get(tmp);
		double ave = 0, stdev = 0;

		if (MathUtils::CalculateAve(tmp, ave) && MathUtils::CalculateStand(tmp, stdev))
		{
			file << MathUtils::GetMonthFromNum(i)
				<< "," << setiosflags(ios::fixed) << setprecision(1) << ave
				<< "(" << setiosflags(ios::fixed) << setprecision(1) << stdev << ")";
		}
		else
		{
			file << MathUtils::GetMonthFromNum(i)
				<< ",";
		}
		result.DeleteTree(result.GetTree());

		//result = f1.GetSpecificDataOfMonth(year, i, "T", true);
		//ave = MathUtils::CalculateAve(result);
		//stdev = MathUtils::CalculateStand(result);
		result = f1.GetSpecificDataOfMonth(year, i, "T", true);
		CollectD<double>::Clear();
		result.InOrderTraversal(CollectD<double>::Add);
		tmp.clear();
		CollectD<double>::Get(tmp);

		if (MathUtils::CalculateAve(tmp, ave) && MathUtils::CalculateStand(tmp, stdev))
		{
			file << "," << setiosflags(ios::fixed) << setprecision(1) << ave
				<< "(" << setiosflags(ios::fixed) << setprecision(1) << stdev
				<< ")";
		}
		else
		{
			file << ",";
		}
		result.DeleteTree(result.GetTree());


		result = f1.GetSpecificDataOfMonth(year, i, "SR", false);
		CollectD<double>::Clear();
		result.InOrderTraversal(CollectD<double>::Add);
		tmp.clear();
		CollectD<double>::Get(tmp);

		if (!tmp.empty())
		{
			double sum = 0;
			for (double num : tmp) 
			{
				sum += num;
			}
			sum /= 6000;
			file << "," << setiosflags(ios::fixed) << setprecision(1) << sum << endl;
		}
		else
		{
			file << "," << endl;
		}
		result.DeleteTree(result.GetTree());

	}
	return 0;
}

int UserInterface::Function5(ReadFile& f1)
{
	//reload 
	std::multimap <Date, std::map<std::string, double>> v2;
	std::cout << "Reloading files from data/data_source.txt, please wait ......" << endl;
	ReadFile f2(v2);
	f1 = f2;
	std::cout << "Reload successful,please enter 1-5 to analyze data" << endl;

	return 0;
}

int UserInterface::Function6_EXIT(bool& flag)
{
	flag = false;
	return 0;
}


