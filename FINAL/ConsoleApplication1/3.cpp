#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class CentsValue_Model
{
private:
	std::vector<int> m_Cents;

public:
	CentsValue_Model(const std::vector<int>& cents) { m_Cents = cents; }
	CentsValue_Model() = default;
	std::vector<int> GetCents() const;
	void SetCents(const std::vector<int>& cents);
};

std::vector<int> CentsValue_Model::GetCents() const
{
	return m_Cents;
}

void CentsValue_Model::SetCents(const std::vector<int>& cents)
{
	this->m_Cents = cents;
}

class Display_View
{
public:
	void print(const std::vector<std::vector<int>>& centsResult);
};

void Display_View::print(const std::vector<std::vector<int>>& centsResult)
{
	for (auto oneTrans : centsResult)
	{
		std::cout << oneTrans[0] << " cents is " << oneTrans[1] << " dollars and " << oneTrans[2] << " cents" << std::endl;
	}
}

class Transfer_Controller
{
private:
	CentsValue_Model model;
	Display_View view;
public:
	Transfer_Controller(const CentsValue_Model& m, const Display_View& v) { model = m; view = v; }
	void SetCentsValue(const std::vector<int>& cents);
	std::vector<int> GetCentsValue();
	std::vector<std::vector<int>>& FormatTransfer();
	void UpdateView();
};

void Transfer_Controller::UpdateView()
{
	view.print(FormatTransfer());
}

std::vector<int> Transfer_Controller::GetCentsValue()
{
	return model.GetCents();
}

std::vector<std::vector<int>>& Transfer_Controller::FormatTransfer()
{
	std::vector<int> cents = GetCentsValue();
	std::vector<std::vector<int>> result;
	for (int value : cents)
	{
		int dollars = value / 100;
		int cents = value % 100;
		result.push_back(std::vector<int>{value, dollars, cents});
	}
	return result;
}

void Transfer_Controller::SetCentsValue(const std::vector<int>& cents)
{
	model.SetCents(cents);
}

CentsValue_Model loadFile(const std::string& filename = "cents.txt")
{
	std::vector<int> cents;
	std::ifstream file(filename);
	int value;
	while (file >> value) {
		cents.push_back(value);
	}
	file.close();
	CentsValue_Model model(cents);
	return model;
}

int main()
{
	CentsValue_Model model = loadFile();
	Display_View view;
	Transfer_Controller controller(model, view);
	controller.UpdateView();
	return 0;
}

