// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>
using namespace std;
class Time
{
public:
	Time(int sec=0){m_seconds = sec;}

	int GetSeconds() const;
	void SetSeconds(const int m_seconds);
	void Process();
private:
	int m_seconds;
};

void testQ2();

int main()
{
	//testQ2();
	int input = 0;
	cin >> input;
	Time t(input);
	t.Process();
	return 0;
}

int Time::GetSeconds() const
{
	return m_seconds;
}

void Time::SetSeconds(const int m_seconds)
{
	this->m_seconds = m_seconds;
}

void Time::Process()
{
	int hours = 0, minutes = 0, seconds = 0;
	cout << "Please Enter seconds" << endl;
	if (m_seconds > 0)
	{
		hours = m_seconds / 3600;
		minutes = m_seconds % 3600;
		seconds = minutes % 60;
		minutes = minutes/60;
		cout << "Hours: " << hours << 
			" Minutes: " << minutes << " Seconds: " << seconds << endl;
	}
	else
	{
		cout << "Seconds must be positive" << endl;
	}
}

void testQ2()
{
	Time t(10000);
	t.Process();
	t.SetSeconds(0);
	t.Process();
	t.SetSeconds(-10000);
	t.Process();
	t.SetSeconds(3600);
	t.Process();

}