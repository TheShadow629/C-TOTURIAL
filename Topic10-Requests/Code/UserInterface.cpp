#include "UserInterface.h"
#include <iostream>
#include "ReadWindLog.h"
#include "MathUtils.h"
//#include "Vector.h"
#include <iomanip>
#include <list>

//#include "CollectDouble.h"
const double UnitConversionFactor = 6000;
const int STARTYEAR = 2010;
const int ENDYEAR = 2016;


int UserInterface::Function1( ReadWindLog& f1) {
	std::cout << "Please input year and month to get wind data" << std::endl;
	int year = 0, month = 0;
	std::cin >> year >> month;

	std::list<double> result = f1.GetMonthData(year, month, "S", true);
	std::cout << endl << MathUtils::GetMonthFromNum(month) << " " << year << ":";
	double ave = 0, stdev = 0;
	if (MathUtils::CalculateAve(result, ave)&& MathUtils::CalculateStand(result, stdev))
	{
		std::cout << std::endl
			<< "Average Speed: " << setiosflags(ios::fixed) << setprecision(1) << ave << "km/h" << endl
			<< "Sample Stdev: " << setiosflags(ios::fixed) << setprecision(1) << stdev << std::endl;
	}
	else
	{
		std::cout << "No Data" << endl;
	}

	return 0;
}

int UserInterface::Function2(ReadWindLog& f1) {
	std::cout << "Please input year to get Average ambient air temperature and sample standard deviation for each month of a specified year.(print on screen only)" << std::endl;
	int year = 0;
	std::cin >> year;

	cout << endl << year << endl;
	for (int i = 1; i < 13; i++)
	{
		std::list<double> result = f1.GetMonthData(year, i, "T", true);
		//CollectD<double> cd;
		//result.InOrderTraversal(CollectD<double>::Add);
		//std::list<double> tmp;
		//CollectD<double>::Get(tmp);

		cout << MathUtils::GetMonthFromNum(i) << ": ";
		double ave = 0, stdev = 0;
		if (MathUtils::CalculateAve(result, ave) && MathUtils::CalculateStand(result, stdev))
		{
			cout << "average: " << setiosflags(ios::fixed) << setprecision(1) << ave
				<< " degrees C, stdev: " << setiosflags(ios::fixed) << setprecision(1) << stdev << endl;
		}
		else
		{
			std::cout << "No Data" << endl;
		}
		/*result.DeleteTree(result.GetTree());*/
	}

	return 0;
}

int UserInterface::Function3(ReadWindLog& f1)
{
	int month = 0;
	std::cin >> month;
	cout << endl;
	cout << "Sample Pearson Correlation Coefficient for " << MathUtils::GetMonthFromNum(month) << endl;

	std::list<double> SData, TData, RData;
	for (int year = STARTYEAR; year < ENDYEAR; year++)
	{
		std::list<double> tmp = f1.GetMonthData(year, month, "S", true);
		SData.insert(SData.end(), tmp.begin(), tmp.end());

		tmp = f1.GetMonthData(year, month, "T", true);
		TData.insert(TData.end(), tmp.begin(), tmp.end());

		tmp = f1.GetMonthData(year, month, "SR", false);
		RData.insert(RData.end(), tmp.begin(), tmp.end());
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
		//·Ö×Ónum£¬·ÖÄ¸den
		double num = p_sum - (sum1 * sum2 / n);
		double den = sqrt((sum1_pow - pow(sum1, 2) / n) * (sum2_pow - pow(sum2, 2) / n));
		if (den == 0) {
			return 0.0;
		}
		return num / den;
	};

	std::cout << "S_T:" << pearson(SData, TData) << std::endl;
	std::cout << "S_R:" << pearson(SData, RData) << std::endl;
	std::cout << "T_R:" << pearson(TData, RData) << std::endl;

	return 0;
}

int UserInterface::Function4(ReadWindLog& f1) {
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
		std::list<double> result = f1.GetMonthData(year, i, "S", true);
		double ave = 0, stdev = 0;

		if (MathUtils::CalculateAve(result, ave) && MathUtils::CalculateStand(result, stdev))
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


		result = f1.GetMonthData(year, i, "T", true);

		if (MathUtils::CalculateAve(result, ave) && MathUtils::CalculateStand(result, stdev))
		{
			file << "," << setiosflags(ios::fixed) << setprecision(1) << ave
				<< "(" << setiosflags(ios::fixed) << setprecision(1) << stdev
				<< ")";
		}
		else
		{
			file << ",";
		}


		result = f1.GetMonthData(year, i, "SR", false);
		if (!result.empty())
		{
			double sum = 0;
			for (double num : result)
			{
				sum += num;
			}
			sum /= UnitConversionFactor;
			file << "," << setiosflags(ios::fixed) << setprecision(1) << sum << endl;
		}
		else
		{
			file << "," << endl;
		}
	}
	return 0;
}

int UserInterface::Function5(ReadWindLog& f1)
{
	//reload 
	//std::multimap <Date, std::map<std::string, double>> v2;
	for (auto obj : f1.GetMapDataWithoutHead())
		obj.second.DeleteTree(obj.second.GetTree());

	std::multimap <Date, Bst<MyPair>> v2;

	std::cout << "Reloading files from data/data_source.txt, please wait ......" << endl;
	ReadWindLog f2(v2);
	f1 = f2;
	std::cout << "Reload successful,please enter 1-5 to analyze data" << endl;

	return 0;
}

int UserInterface::Function6_EXIT(bool& flag)
{
	flag = false;
	return 0;
}


