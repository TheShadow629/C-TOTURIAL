#include <iostream>
#include <vector>


class DateOfBirth {
private:
	int m_month;
	int m_day;
	int m_year;

public:
	DateOfBirth(int m, int d, int y);

	int GetMonth() const;
	int GetDay() const;
	int GetYear() const;
};

DateOfBirth::DateOfBirth(int m, int d, int y)
	: m_month(m), m_day(d), m_year(y) {}

int DateOfBirth::GetMonth() const {
	return m_month;
}

int DateOfBirth::GetDay() const {
	return m_day;
}

int DateOfBirth::GetYear() const {
	return m_year;
}


class Birthday {
private:
	std::string m_name;
	DateOfBirth m_dateOfBirth;

public:
	Birthday(const std::string& n, const DateOfBirth& dob);

	std::string GetName() const;
	DateOfBirth GetBirthdate() const;
	void SetName(const std::string& n);
	void SetBirthdate(int month, int day, int year);
};

Birthday::Birthday(const std::string& n, const DateOfBirth& dob)
	: m_name(n), m_dateOfBirth(dob) {}

std::string Birthday::GetName() const {
	return m_name;
}

DateOfBirth Birthday::GetBirthdate() const {
	return m_dateOfBirth;
}

void Birthday::SetName(const std::string& n) {
	m_name = n;
}

void Birthday::SetBirthdate(int month, int day, int year) {
	m_dateOfBirth = DateOfBirth(month, day, year);
}

class BirthdayModel {
private:
	std::vector<Birthday> m_birthdays;

public:
	void AddBirthday(const std::string& name, int month, int day, int year);
	std::vector<Birthday> GetBirthdays() const;
};

void BirthdayModel::AddBirthday(const std::string& name, int month, int day, int year) {
	DateOfBirth dob(month, day, year);
	Birthday birthday(name, dob);
	m_birthdays.push_back(birthday);
}

std::vector<Birthday> BirthdayModel::GetBirthdays() const {
	return m_birthdays;
}

class BirthdayView {
public:
	void PrintBirthdays(const std::vector<Birthday>& birthdays) const;
};

void BirthdayView::PrintBirthdays(const std::vector<Birthday>& birthdays) const {
	for (const Birthday& birthday : birthdays) {
		std::cout << "Name: " << birthday.GetName() << std::endl;
		std::cout << "Birthdate: " << birthday.GetBirthdate().GetMonth() << "/"
			<< birthday.GetBirthdate().GetDay() << "/"
			<< birthday.GetBirthdate().GetYear() << std::endl;
		std::cout << std::endl;
	}
}
class BirthdayController {
private:
	BirthdayModel m_model;
	BirthdayView m_view;

public:
	void AddBirthday(const std::string& name, int month, int day, int year);
	void PrintBirthdays() const;
};


void BirthdayController::AddBirthday(const std::string& name, int month, int day, int year) {
	m_model.AddBirthday(name, month, day, year);
}

void BirthdayController::PrintBirthdays() const {
	std::vector<Birthday> birthdays = m_model.GetBirthdays();
	m_view.PrintBirthdays(birthdays);
}

int main() {
	BirthdayController controller;

	// Add some birthdays
	controller.AddBirthday("John", 3, 12, 1990);
	controller.AddBirthday("Emily", 6, 25, 1985);
	controller.AddBirthday("David", 8, 10, 1995);

	// Print the birthdays
	controller.PrintBirthdays();

	return 0;
}


//                              |     BirthdayController  |
//                              +------------------------+
//                              | - model: BirthdayModel |
//                              | - view: BirthdayView   |
//                              +------------------------+
//                              | + addBirthday()        |
//                              | + printBirthdays()     |
//                              +------------------------+
//                                         ^
//                                         |
//                                         |
//                       +-----------------|------------------+
//                       |                 |                  |
//                       |uses             |uses              |uses
//+------------------------+         +-----------------+  +-----------------+
//|      BirthdayModel     |         |   BirthdayView  |  |   DateOfBirth   |
//+------------------------+         +-----------------+  +-----------------+
//| - birthdays:           |         |                 |  | - month: int    |
//|   vector<Birthday>     |         |                 |  | - day: int      |
//+------------------------+         |                 |  | - year: int     |
//| + addBirthday()        |         |                 |  +-----------------+
//| + getBirthdays()       |         |                 |  | + getMonth()    |
//+------------------------+         |                 |  | + getDay()      |
//                                    |                 |  | + getYear()     |
//                                    +-----------------+  +-----------------+
//                                                   
//                                            depends on
//                                      +------------------------+
//                                      |        Birthday        |
//                                      +------------------------+
//                                      | - name: string         |
//                                      | - dateOfBirth:         |
//                                      |   DateOfBirth          |
//                                      +------------------------+
//                                      | + getName()            |
//                                      | + getBirthdate()       |
//                                      | + setName()            |
//                                      | + setBirthdate()       |
//                                      +------------------------+