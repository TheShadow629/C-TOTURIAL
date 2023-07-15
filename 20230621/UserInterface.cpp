#include "UserInterface.h"
#include <iostream>
#include "ReadFile.h"
#include "MathUtils.h"
#include "Vector.h"
#include <iomanip>

int UserInterface::Function1( ReadFile& f1) {
	std::cout << "Please input year and month to get wind data" << std::endl;
	int year = 0, month = 0;
	std::cin >> year >> month;

	//ReadFile f1;
	//f1.initialize();

	UserSpace::MyVector<double> result = f1.GetSpecificDataOfMonth(year, month, "S", true);
	double ave = 0, stdev = 0;
	ave = MathUtils::CalculateAve(result);
	stdev = MathUtils::CalculateStand(result);

	std::cout << endl << MathUtils::GetMonthFromNum(month) << " " << year << ":";

	if (result.GetSize() > 0)
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

int UserInterface::Function2(ReadFile& f1) {
	std::cout << "Please input year to get Average ambient air temperature and sample standard deviation for each month of a specified year.(print on screen only)" << std::endl;
	int year = 0;
	std::cin >> year;

	//ReadFile f1;
	//f1.initialize();

	cout << endl << year << endl;
	for (int i = 1; i < 13; i++)
	{
		UserSpace::MyVector<double> result = f1.GetSpecificDataOfMonth(year, i, "T", true);
		double ave = 0, stdev = 0;
		ave = MathUtils::CalculateAve(result);
		stdev = MathUtils::CalculateStand(result);
		cout << MathUtils::GetMonthFromNum(i) << ": ";
		if (result.GetSize() > 0)
		{
			cout << "average: " << setiosflags(ios::fixed) << setprecision(1) << ave
				<< " degrees C, stdev: " << setiosflags(ios::fixed) << setprecision(1) << stdev << endl;
		}
		else
		{
			std::cout << "No Data" << endl;
		}
	}
	return 0;
}

int UserInterface::Function3(ReadFile& f1) {
	cout << "Total solar radiation in kWh/m2 for each month of a specified year.(print on screen only)";
	int year = 0;
	cout << endl;
	std::cin >> year;

	//ReadFile f1;
	//f1.initialize();

	for (int i = 1; i < 13; i++)
	{
		UserSpace::MyVector<double> result = f1.GetSpecificDataOfMonth(year, i, "SR", false);
		double sum = 0;
		cout << MathUtils::GetMonthFromNum(i) << ": ";
		if (result.GetSize() > 0)
		{
			for (int i = 0; i < result.GetSize(); i++)
			{
				sum += result[i];
			}
			sum /= 6000;
			cout << setiosflags(ios::fixed) << setprecision(1) << sum << " kWh/m2";
		}
		else
		{
			std::cout << "No Data";
		}
		cout << endl;
	}

	return 0;
}

int UserInterface::Function4(ReadFile& f1) {
	std::cout << "Average wind speed (km/h), average ambient air temperature and total"
		"solar radiation in"
		"kWh / m2for each month of a specified year.The standard deviation is printed in()nextto the average. (print to a file called\"WindTempSolar.csv\")"
		<< std::endl;
	int year = 0;
	std::cin >> year;

	//ReadFile f1;
	//f1.initialize();

	ofstream file("WindTempSolar.csv");
	file << year << endl;

	for (int i = 1; i < 13; i++)
	{
		UserSpace::MyVector<double> result = f1.GetSpecificDataOfMonth(year, i, "S", true);
		double ave = MathUtils::CalculateAve(result);
		double stdev = MathUtils::CalculateStand(result);
		if (result.GetSize() != 0)
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


		result = f1.GetSpecificDataOfMonth(year, i, "T", true);
		ave = MathUtils::CalculateAve(result);
		stdev = MathUtils::CalculateStand(result);
		if (result.GetSize() != 0)
		{
			file << "," << setiosflags(ios::fixed) << setprecision(1) << ave
				<< "(" << setiosflags(ios::fixed) << setprecision(1) << stdev
				<< ")";
		}
		else
		{
			file << ",";
		}

		result = f1.GetSpecificDataOfMonth(year, i, "SR", false);
		double sum = 0;
		for (int i = 0; i < result.GetSize(); i++)
		{
			sum += result[i];
		}
		sum /= 6000;
		if (result.GetSize() != 0)
		{
			file << "," << setiosflags(ios::fixed) << setprecision(1) << sum << endl;
		}
		else
		{
			file << "," << endl;
		}
	}
	return 0;
}

int UserInterface::Function5_EXIT(bool& flag)
{
	flag = false;
	return 0;
}


