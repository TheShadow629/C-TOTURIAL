// This stuff belongs in Stack.h
// so doxygen comments are needed in here.
// Stack class
// Nicola Ritter

// modified smr
//-------------------------------------------

#ifndef MY_STACK
#define MY_STACK

//-------------------------------------------


#include <stack> // Our Stack uses the STL stack. Encapsulates the STL stack.
// #include <iostream> Do not include unnecessary stuff
//using namespace std; Do not expose namespaces. Your client will not like this,
//  because you data structure exposes or includes something that they do not want.

// NO I/O HERE. LET THE CLIENT DEAL WITH I/O

//-------------------------------------------

template <class T>
class Stack
{
public:
	Stack () {};
	~Stack () {};
	bool Push(const T &data);
	bool Pop (T &data);  // version from reference book Introduction to Algorithms by Cormen et al
	bool Empty ();
private:
	std::stack<T> m_stack; // most appropriate STL data structure to use for this Type
};

//-------------------------------------------
// It is a template, so we have to put all the implementation code
//   in the header file after the class (interface) declaration above.
// If it wasn't a template, it would go into Stack.cpp
//-------------------------------------------

template<class T>
inline bool Stack<T>::Empty()
{
    return m_stack.empty();
}

template<class T>
bool Stack<T>::Push(const T &data)
{
	bool okay = true;
	try
	{
		m_stack.push(data);
	}
	catch (...)
	{
		okay = false;
	}

	return okay;
}

//-------------------------------------------

template<class T>
bool Stack<T>::Pop(T &data)
{
	if (m_stack.size() > 0)
	{
		data = m_stack.top();

		m_stack.pop();
		return true;
	}
	else
	{
		return false;
	}
}

//-------------------------------------------

#endif
