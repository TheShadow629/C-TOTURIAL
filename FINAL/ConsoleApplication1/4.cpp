#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
class Tickets_Model
{
private:
	std::vector<std::vector<double>> m_Tickets;

public:
	Tickets_Model(const std::vector<std::vector<double>>& tickets){	m_Tickets = tickets;}
	Tickets_Model() = default;
	std::vector<std::vector<double>> GetTickets() const;
	void SetTickets(const std::vector<std::vector<double>>& m_tickets);
	void AddTicket(const std::vector<double>& t);
};

void Tickets_Model::AddTicket(const std::vector<double>& t)
{
	m_Tickets.push_back(t);
}

std::vector<std::vector<double>> Tickets_Model::GetTickets() const
{
	return m_Tickets;
}

void Tickets_Model::SetTickets(const std::vector<std::vector<double>>& m_tickets)
{
	m_Tickets = m_tickets;
}


class DisplayTickets_View
{
public:
	void print(int ticketsNum,int amount);
};

void DisplayTickets_View::print(int ticketsNum, int amount)
{
	std::cout << "the number of tickets sold is : " << ticketsNum << " the total sale amount is " << amount << std::endl;
}

class TicketsController
{
public:
	TicketsController(const Tickets_Model& m, const DisplayTickets_View& v);
	void SetTickets(std::vector<std::vector<double>> d);
	std::vector<std::vector<double>> GetTickets();
	int GetTicketNum();
	int GetTicketAmount();
	void updateView();
private:
	Tickets_Model model;
	DisplayTickets_View view;
};

TicketsController::TicketsController(const Tickets_Model& m, const DisplayTickets_View& v)
{
	model = m;
	view = v;
}

void TicketsController::SetTickets(std::vector<std::vector<double>> d)
{
	model.SetTickets(d);
}

std::vector<std::vector<double>> TicketsController::GetTickets()
{
	return model.GetTickets();
}

int TicketsController::GetTicketNum()
{
	std::vector<std::vector<double>> tickets= model.GetTickets();
	int num = 0;
	for(int i=0;i< tickets.size();i++)
	{
		num += tickets[i][1];
	}
	return num;
}

int TicketsController::GetTicketAmount()
{
	std::vector<std::vector<double>> tickets = model.GetTickets();
	int amount = 0;
	for (int i = 0; i < tickets.size(); i++)
	{
		amount += (tickets[i][0]* tickets[i][1]);
	}
	return amount;
}

void TicketsController::updateView()
{
	view.print(GetTicketNum(), GetTicketAmount());
}

Tickets_Model GetTicketsInfo(std::string fileName="sales.txt")
{
	std::vector<std::vector<double>> Tickets;
	std::ifstream txtFile(fileName, std::ios::in);
	std::string singleTicket;
	while(std::getline(txtFile, singleTicket))
	{
		std::stringstream ss(singleTicket);
		std::string price, num;
		getline(ss, price, ' ');
		getline(ss, num, ' ');
		Tickets.push_back(std::vector<double>{stod(price),stod(num)});
	}
	Tickets_Model model(Tickets);
	return model;
}

int main()
{
	Tickets_Model model= GetTicketsInfo();
	DisplayTickets_View view;
	TicketsController controller(model, view);
	controller.updateView();
	return 0;
}