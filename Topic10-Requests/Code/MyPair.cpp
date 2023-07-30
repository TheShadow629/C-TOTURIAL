#include "MyPair.h"

MyPair::MyPair(const std::string& key, const double value)
{
	SetKey(key);
	SetValue(value);
}

std::string MyPair::GetKey() const
{
	return m_Key;
}

void MyPair::SetKey(const std::string& key)
{
	this->m_Key = key;
}

double MyPair::GetValue() const
{
	return m_Value;
}

void MyPair::SetValue(const double value)
{
	this->m_Value = value;
}

MyPair& MyPair::operator=(MyPair& other)
{
	if (this != &other) {
		m_Value = other.m_Value;
		m_Key = other.m_Key;
	}
	return *this;
}


bool operator>(const MyPair& lhs, const MyPair& rhs)
{
	return lhs.GetKey() > rhs.GetKey();
}

bool operator<(const MyPair& lhs, const MyPair& rhs)
{
	return lhs.GetKey() < rhs.GetKey();
}


