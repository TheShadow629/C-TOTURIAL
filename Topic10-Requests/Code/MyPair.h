#pragma once
#include <iostream>
#include <string>

class MyPair
{
public:
	MyPair(const std::string& key, const double value);
	MyPair() = default;

	std::string GetKey() const;
	void SetKey(const std::string& key);
	double GetValue() const;
	void SetValue(const double value);

	MyPair& operator=(MyPair& other);
private:
	double m_Value;
	std::string m_Key;
};

bool operator>(const MyPair& lhs, const MyPair& rhs);
bool operator<(const MyPair& lhs, const MyPair& rhs);

