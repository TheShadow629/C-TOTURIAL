#include <iostream>
using namespace std;
int q1();

int main1()
{
	q1();
	return 0;
}

int q1()
{
	int hours = 0, minutes = 0, seconds = 0;
	cout << "Enter hours:";
	cin >> hours;
	cout << "Enter minutes:";
	cin >> minutes;
	cout << "Enter seconds:";
	cin >> seconds;

	if (hours >= 0 && minutes >= 0 && seconds >= 0)
	{
		seconds = seconds + minutes * 60 + hours * 60 * 60;
		cout << "Totle Seconds:" << seconds << endl;
	}
	else
	{
		cout << "Please input correct time";
	}
	return 0;
}

