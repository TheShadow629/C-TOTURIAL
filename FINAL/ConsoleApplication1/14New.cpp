#include <iostream>
#include <string>
#include <vector>
#include <fstream>
class BookNames_Model
{
private:
	std::vector<std::string> m_BooKTitle;
public:
	BookNames_Model(const std::vector<std::string>& bt)	{m_BooKTitle = bt;	}
	BookNames_Model() = default;
	std::vector<std::string> GetBookTitle() const;
	void SetBookTitle(const std::vector<std::string>& m_boo_k_title);
};

std::vector<std::string> BookNames_Model::GetBookTitle() const
{
	return m_BooKTitle;
}

void BookNames_Model::SetBookTitle(const std::vector<std::string>& m_boo_k_title)
{
	m_BooKTitle = m_boo_k_title;
}

class ShowTitle_View
{
public:
	void showTitle(std::vector<std::string> t);
	void StoreTitle(std::vector<std::string> t);
};

void ShowTitle_View::StoreTitle(std::vector<std::string> t)
{
	std::ofstream fout("data.csv");
	//for (int i = 0; i < t.size(); i++)
	//{
	//	fout << t[i] << std::endl;
	//}
	for(auto obj:t)
	{
		fout << obj<< std::endl;
	}
	fout.close();
}

void ShowTitle_View::showTitle(std::vector<std::string> t)
{
	//for(int i=0;i<t.size();i++)
	//{
	//	std::cout << t[i] << std::endl;
	//}
	for (auto obj:t)
	{
		std::cout << obj << std::endl;
	}
}

class Cotroller
{
private:
	BookNames_Model m_model;
	ShowTitle_View m_view;
public:
	Cotroller(const BookNames_Model& m, const ShowTitle_View& v);
	Cotroller() = default;
	void ReadBookTitle(std::string name = "titles.txt");
	void UpdateView();
};

void Cotroller::ReadBookTitle(std::string name)
{
	std::ifstream file(name);
	std::vector<std::string> titles;
	std::string title;
	while(std::getline(file,title))
	{
		titles.push_back(title);
	}
	m_model.SetBookTitle(titles);

}

void Cotroller::UpdateView()
{
	m_view.showTitle(m_model.GetBookTitle());
	m_view.StoreTitle(m_model.GetBookTitle());
}

Cotroller::Cotroller(const BookNames_Model& m, const ShowTitle_View& v)
{
	m_model = m;
	m_view = v;
}
int main()
{
	BookNames_Model m;
	ShowTitle_View v;
	Cotroller c(m,v);
	c.ReadBookTitle();
	c.UpdateView();
	return 0;
}
