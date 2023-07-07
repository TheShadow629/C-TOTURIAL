#include <iostream>
#include <cstdlib>
#include "assert.h"
const int MAXSIZE = 512;
template <class T>
class SeqList {
public:
	SeqList() { length = 0; }  //默认构造函数
	SeqList(const T a[], int n); //含参构造函数
	int GetLength() { return length; }  //获取长度
	void Insert(int i, T x);  //插入元素
	T Delete(int i); //删除元素
	T Get(int i);  //通过下标获取元素
	int Locate(T x);  //通过元素值查找元素
	void Print();  //打印输出
private:
	int length;
	T data[MAXSIZE];
};
template <class T>
SeqList<T>::SeqList(const T a[], int n) {
	if (n > MAXSIZE) {
		throw "超过顺序表的最大长度";
	}
	for (int i = 0; i < n; i++) {
		data[i] = a[i];
	}
	length = n;
}
template <class T>
void SeqList<T>::Insert(int i, T x) {
	if (length > MAXSIZE) throw "上溢异常";
	if (i<0 || i>length) throw "位置异常";
	for (int j = length; j >= i; j--) {
		data[j] = data[j - 1];
	}
	data[i] = x;
	length++;
}
template <class T>
T SeqList<T>::Delete(int i) {
	if (length == 0) throw "下溢异常";
	if (i < 0 || i >= length) {
		throw "位置异常";
	}
	T x = data[i];
	for (int j = i; j < length - 1; j++) {
		data[j] = data[j + 1];
	}
	length--;
	return x;
}
template <class T>
T SeqList<T>::Get(int i) {
	if (0 == length) throw"上溢异常";
	if (i < 0 || i >= length) {
		throw "查找位置非法";
	}
	return data[i];
}
template <class T>
int SeqList<T>::Locate(const T x) {
	for (int i = 0; i < length; i++) {
		if (x == data[i])
			return i;
	}
	return 0;
}
template <class T>
void SeqList<T>::Print() {
	std::cout << "遍历线性表数据元素：" << std::endl;
	for (int i = 0; i < length; i++) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}