#ifndef Vector_h__
#define Vector_h__

#include "stddef.h"
namespace UserSpace
{
	template <class T>
	class MyVector
	{
		typedef T value_type;
		typedef T* iterator;
	private:
		iterator m_data;
		size_t m_size;
		size_t m_capacity;
	public:
		MyVector();//函数的声明，定义
		~MyVector();
		MyVector(const T& vec);
		MyVector& operator=(const MyVector& vec);
		T& operator[](size_t index) const; 

		T& GetPosition(size_t index) const;
		bool operator==(const MyVector& vec)const;
		void Add(const value_type& val);
		void Insert(iterator it, value_type val);
		void RemoveElements();
		void DeletePosition(iterator it);
		int GetSize() const;
		bool Empty() const;

		iterator begin() { return m_data; }
		iterator end() { return m_data + m_size; }

	};



	template <class T>
	T& UserSpace::MyVector<T>::GetPosition(size_t index) const
	{
		if (index < m_size)
			return m_data[index];
	}

	template <class T>
	MyVector<T>::MyVector()
	{
		m_data = NULL;
		m_size = 0;
		m_capacity = 0;
	}

	template <class T>
	MyVector<T>::~MyVector()
	{
		delete[] m_data;
		m_data = NULL;
		m_size = 0;
		m_capacity = 0;
	}

	template <class T>
	MyVector<T>::MyVector(const T& vec)
	{
		m_size = vec.m_size;
		m_capacity = vec.m_capacity;
		m_data = new value_type[m_capacity];
		for (int i = 0; i < m_size; ++i) {
			m_data[i] = vec.m_data[i];
		}
	}

	template<typename T>
	MyVector<T>& MyVector<T>::operator=(const MyVector<T>& vec)
	{
		if (this == &vec)
			return *this;

		value_type* temp = new value_type[vec.m_capacity];
		for (int i = 0; i < vec.m_size; ++i) {
			temp[i] = vec.m_data[i];
		}

		delete[] m_data;
		m_data = temp;
		m_size = vec.m_size;
		m_capacity = vec.m_capacity;
		return *this;
	}

	template<typename T>
	T& MyVector<T>::operator[](size_t index) const
	{
		if (index < m_size)
			return m_data[index];
	}

	template<typename T>
	bool MyVector<T>::operator==(const MyVector& vec)const
	{
		if (m_size != vec.m_size)
			return false;
		for (int i = 0; i < m_size; ++i)
		{
			if (!(m_data[i] == vec.m_data[i]))
				return false;
		}
		return true;
	}

	template<typename T>
	void MyVector<T>::Add(const value_type& val)
	{
		if (0 == m_capacity) {
			m_capacity = 1;
			m_data = new value_type[1];
		}
		else if (m_size + 1 > m_capacity)
		{
			m_capacity *= 2;
			value_type* temp = new value_type[m_capacity];
			for (int i = 0; i < m_size; ++i)
			{
				temp[i] = m_data[i];
			}
			delete[] m_data;
			m_data = temp;
		}
		m_data[m_size] = val;
		++m_size;
	}

	template<typename T>
	void MyVector<T>::Insert(iterator it, value_type val) {
		int index = it - m_data;
		if (0 == m_capacity) {
			m_capacity = 1;
			m_data = new value_type[1];
			m_data[0] = val;
		}
		else if (m_size + 1 > m_capacity) {
			m_capacity *= 2;
			value_type* temp = new value_type[m_capacity];
			for (int i = 0; i < index; ++i) {
				temp[i] = m_data[i];
			}
			temp[index] = val;
			for (int i = index; i < m_size; i++) {
				temp[i + 1] = m_data[i];
			}
			//delete[] _data;
			m_data = temp;
		}
		else {
			for (int i = m_size - 1; i >= index; --i) {
				m_data[i + 1] = m_data[i];
			}
			m_data[index] = val;
		}
		++m_size;
	}

	template<typename T>
	void MyVector<T>::RemoveElements() {
		if (m_size != 0)
			--m_size;
	}

	template<typename T>
	void MyVector<T>::DeletePosition(iterator it) {
		size_t index = it - m_data;
		for (int i = index; i < m_size - 1; ++i) {
			m_data[i] = m_data[i + 1];
		}
		--m_size;
	}

	template<typename T>
	int MyVector<T>::GetSize() const
	{
		return m_size;
	}

	template <class T>
	bool MyVector<T>::Empty() const
	{
		return (bool)m_size;
	}

	//https://blog.csdn.net/weixin_50941083/article/details/122354948
}
#endif // Vector_h__
