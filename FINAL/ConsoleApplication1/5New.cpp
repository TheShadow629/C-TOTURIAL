//vector<birthday>
//birthday:name Date
//Date year month day

#include <iostream>
#include <string>
#include <vector>


class Date
{
private:
	int m_Year;
	int m_Month;
	int m_Day;

public:
	Date(const int y, const int m, const int d);
	Date() = default;
	int GetYear() const;
	void SetYear(const int m_year);
	int GetMonth() const;
	void SetMonth(const int m_month);
	int GetDay() const;
	void SetDay(const int m_day);
};

Date::Date(const int y, const int m, const int d)
{
	m_Year=y;
	m_Month=m;
	m_Day=d;
}

int Date::GetYear() const
{
	return m_Year;
}

void Date::SetYear(const int m_year)
{
	m_Year = m_year;
}

int Date::GetMonth() const
{
	return m_Month;
}

void Date::SetMonth(const int m_month)
{
	m_Month = m_month;
}

int Date::GetDay() const
{
	return m_Day;
}

void Date::SetDay(const int m_day)
{
	m_Day = m_day;
}

class BrithDay
{
private:
	std::string m_name;
	Date m_brith;

public:
	BrithDay(const std::string& n, const Date& b);
	BrithDay() = default;
	std::string GetName() const;
	void SetName(const std::string& m_name);
	Date GetBrith() const;
	void SetBrith(const Date& m_brith);
};

BrithDay::BrithDay(const std::string& n, const Date& b)
{
	m_name = n;
	m_brith = b;
}
std::string BrithDay::GetName() const
{
	return m_name;
}
void BrithDay::SetName(const std::string& n)
{
	m_name = n;
}
Date BrithDay::GetBrith() const
{
	return m_brith;
}
void BrithDay::SetBrith(const Date& b)
{
	m_brith = b;
}

class BrithDayList_Model
{
private:
	std::vector<BrithDay> m_BirList;

public:
	BrithDayList_Model(const std::vector<BrithDay>& bl){m_BirList = bl;}
	BrithDayList_Model() = default;
	std::vector<BrithDay> GetBirList() const;
	void SetBirList(const std::vector<BrithDay>& m_bir_list);
};

std::vector<BrithDay> BrithDayList_Model::GetBirList() const
{
	return m_BirList;
}

void BrithDayList_Model::SetBirList(const std::vector<BrithDay>& bl)
{
	m_BirList = bl;
}

class ShowBirthday_View
{
public:
	void DisplayBirthdayList(std::vector<BrithDay> bl);
};

void ShowBirthday_View::DisplayBirthdayList(std::vector<BrithDay> bl)
{
	for(int i=0;i<bl.size();i++)
	{
		std::cout << bl[i].GetName()<<" : "<< bl[i].GetBrith().GetYear()<<"/" << bl[i].GetBrith().GetMonth() << "/"<< bl[i].GetBrith().GetDay()<<std::endl;
	}
}

class BrithList_Controller
{
private:
	BrithDayList_Model model;
	ShowBirthday_View view;
public:
	BrithList_Controller(const BrithDayList_Model& m, const ShowBirthday_View& v);
	BrithList_Controller() = default;
	void AddBrithday(std::vector<BrithDay> bl);
	void UpdateView();
};

void BrithList_Controller::AddBrithday(std::vector<BrithDay> bl)
{
	model.SetBirList(bl);
}

void BrithList_Controller::UpdateView()
{
	view.DisplayBirthdayList(model.GetBirList());
}

BrithList_Controller::BrithList_Controller(const BrithDayList_Model& m, const ShowBirthday_View& v)
{
	model = m;
	view = v;
}


int main()
{
	std::vector<BrithDay> bl;
	bl.push_back(BrithDay("Name1",Date(2005,1,1)));
	bl.push_back(BrithDay("Name2", Date(2006, 1, 1)));
	bl.push_back(BrithDay("Name3", Date(2007, 1, 1)));
	bl.push_back(BrithDay("Name4", Date(2008, 1, 1)));

	BrithDayList_Model model(bl);
	ShowBirthday_View view;
	BrithList_Controller controller(model, view);
	controller.UpdateView();


}