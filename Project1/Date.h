#pragma once

#include <iostream>
using namespace std;
class Date
{
public:
	Date();
	Date(int y, int m, int d);
	void setYear(int y);
	int getYear() const;

	void setMonth(int m);//TO DO: impl
	int getMonth() const;//TO DO: impl

	void setDay(int y);//TO DO: impl
	int getDay() const;//TO DO: impl



	//friend ostream& operator <<(ostream& os, const Date& C);//os�൱��cout����ϵͳ�Դ��ģ�C������һ��������������ΪDate��
	//friend istream& operator >>(istream& input, Date& C);//istream&ʱ�������ͣ����ص���һ��������,�����ǲ���ϵͳ�Լ������һ��basic�ࡣ
	////��Ԫ���� ����ֱ�ӷ���˽�б���C.Year
private:
	int year;
	int month;
	int day;
};

ostream& operator <<(ostream& os, const Date& C);
istream& operator >>(istream& input, Date& C);


////
////ֵ���ݣ����ô��Σ�ָ���ַ����
//int num1 = 3;
//int num2 = 5;
//int fun1(const int& a,int& b)//a��num��С�����������µ��ڴ棬&�����ô��εı�־
//{
//	a = 100;//a��ֵ������ͨ��const int& a���иı�
//	b = 100;
// return 0;
// 
// 
//}
//fun(num1,num2);//ֻҪ���Ϸ�����Ĳ������ͣ����ֿ����ظ�
//
//
////����������أ���������㣬�������
//int a = 0;   a.value + b.value
//int b = 3;
//int c=a + b;
//
//Unit a, b, c; a.ID+b.ID  c.ID
//c = a + b;
//
//int operator +(Unit u1,Unit u2)//����������Ӧ�������������Ķ����ࣩ
//{
//	cout << "reload operator + for class unit";
//	return u1.ID + U2.ID;
//}
//
//cout << a;

