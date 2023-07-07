#include <iostream>
#include <cstdlib>
#include "assert.h"
const int MAXSIZE = 512;
template <class T>
class SeqList {
public:
	SeqList() { length = 0; }  //Ĭ�Ϲ��캯��
	SeqList(const T a[], int n); //���ι��캯��
	int GetLength() { return length; }  //��ȡ����
	void Insert(int i, T x);  //����Ԫ��
	T Delete(int i); //ɾ��Ԫ��
	T Get(int i);  //ͨ���±��ȡԪ��
	int Locate(T x);  //ͨ��Ԫ��ֵ����Ԫ��
	void Print();  //��ӡ���
private:
	int length;
	T data[MAXSIZE];
};
template <class T>
SeqList<T>::SeqList(const T a[], int n) {
	if (n > MAXSIZE) {
		throw "����˳������󳤶�";
	}
	for (int i = 0; i < n; i++) {
		data[i] = a[i];
	}
	length = n;
}
template <class T>
void SeqList<T>::Insert(int i, T x) {
	if (length > MAXSIZE) throw "�����쳣";
	if (i<0 || i>length) throw "λ���쳣";
	for (int j = length; j >= i; j--) {
		data[j] = data[j - 1];
	}
	data[i] = x;
	length++;
}
template <class T>
T SeqList<T>::Delete(int i) {
	if (length == 0) throw "�����쳣";
	if (i < 0 || i >= length) {
		throw "λ���쳣";
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
	if (0 == length) throw"�����쳣";
	if (i < 0 || i >= length) {
		throw "����λ�÷Ƿ�";
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
	std::cout << "�������Ա�����Ԫ�أ�" << std::endl;
	for (int i = 0; i < length; i++) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}