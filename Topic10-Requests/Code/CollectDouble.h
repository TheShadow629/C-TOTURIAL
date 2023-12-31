#ifndef CollectDouble_h__
#define CollectDouble_h__
#include <list>
template<typename T>
class CollectD
{
public:
	static void Add(T& d);
	static void Get(std::list<T>& outD);
	static void Clear();
	//static void Search(string colName,double& res);
private:
	static std::list<T> m_data;
};

template<typename T>
std::list<T> CollectD<T>::m_data;

template<typename T>
void CollectD<T>::Get(std::list<T>& outD)
{
	//outD = m_data;
	outD.insert(outD.end(), m_data.begin(), m_data.end());
}

template<typename T>
void CollectD<T>::Add(T& d)
{
	m_data.push_back(d);
}

template<typename T>
void CollectD<T>::Clear()
{
	m_data.clear();
}

//template<typename T>
// void CollectD<T>::Search(string colName, double& res)
//{
//	 for (MyPair obj : m_data) 
//	 {
//		 if (obj.GetKey() == colName)
//		 {
//			 res = obj.GetValue();
//		 }
//	 }
//}
#endif // CollectDouble_h__

