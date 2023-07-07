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



	//friend ostream& operator <<(ostream& os, const Date& C);//os相当于cout，是系统自带的，C是另外一个操作数（类型为Date）
	//friend istream& operator >>(istream& input, Date& C);//istream&时返回类型，返回的是一个输入流,具体是操作系统自己定义的一个basic类。
	////友元函数 可以直接访问私有变量C.Year
private:
	int year;
	int month;
	int day;
};

ostream& operator <<(ostream& os, const Date& C);
istream& operator >>(istream& input, Date& C);


////
////值传递，引用传参，指针地址传参
//int num1 = 3;
//int num2 = 5;
//int fun1(const int& a,int& b)//a是num的小名，不开辟新的内存，&是引用传参的标志
//{
//	a = 100;//a的值不可以通过const int& a进行改变
//	b = 100;
// return 0;
// 
// 
//}
//fun(num1,num2);//只要符合方法里的参数类型，名字可以重复
//
//
////运算符的重载，是类的运算，例如相加
//int a = 0;   a.value + b.value
//int b = 3;
//int c=a + b;
//
//Unit a, b, c; a.ID+b.ID  c.ID
//c = a + b;
//
//int operator +(Unit u1,Unit u2)//两个参数对应的是两个操作的对象（类）
//{
//	cout << "reload operator + for class unit";
//	return u1.ID + U2.ID;
//}
//
//cout << a;

