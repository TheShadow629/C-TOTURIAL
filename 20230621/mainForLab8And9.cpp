#include "ReadFile.h"
#include "Bst.h"
bool operator>(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() > rhs.GetYear())
	{
		return true;
	}
	else if (lhs.GetYear() == rhs.GetYear())
	{
		if (lhs.GetMonth() > rhs.GetMonth())
		{
			return true;
		}
		else if (lhs.GetMonth() == rhs.GetMonth())
		{
			if (lhs.GetDay() > rhs.GetDay())
			{
				return true;
			}
		}
	}
	return false;
}

bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() < rhs.GetYear())
	{
		return true;
	}
	else if (lhs.GetYear() == rhs.GetYear())
	{
		if (lhs.GetMonth() < rhs.GetMonth())
		{
			return true;
		}
		else if (lhs.GetMonth() == rhs.GetMonth())
		{
			if (lhs.GetDay() < rhs.GetDay())
			{
				return true;
			}
		}
	}
	return false;
}

int mainForLab8AndLab9()
{
	UserSpace::MyVector<SLWDT> allLines;
	ReadFile f1(allLines);

	//将文件中所有的日期都插入
	Bst<Date> dateTree(allLines[0].GetDate());
	for (size_t i = 1; i < allLines.GetSize(); i++)
	{
		dateTree.Insert(dateTree.GetTree(), allLines[i].GetDate());
	}

	dateTree.InOrderTraversal(dateTree.GetTree());
	dateTree.DeleteTree(dateTree.GetTree());
	return 0;
}