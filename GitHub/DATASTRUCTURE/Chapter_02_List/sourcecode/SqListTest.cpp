typedef int ElemType; // ˳�����Ԫ������Ϊint
#include "stdio.h"
#include "stdlib.h"  // ���ļ�����malloc()��realloc()��free()�Ⱥ���
#include "iomanip.h" // ���ļ�������׼���������cout��cin�����Ʒ�setw()�Ⱥ���
#include "SqList.h"  // ���ļ��а����������ݶ������������ز���

int main()
{
  SqList mylist;
  int i, j, temp, forLocate, forGet, forInsert, forDelete;

  InitList_Sq(mylist, 50, 10);
  for (i = 0, j = 1; i < 10; i++, j++)
    if (!ListInsert_Sq(mylist, i, 2 * j))
    {
      cout << "����!" << endl;
      return 0;
    }
  cout << "�Ҵ�����һ��˳���������Ϊ��" << ListLength_Sq(mylist) << endl;
  cout << endl
       << "���е�Ԫ������Ϊ��" << endl;
  ListTraverse_Sq(mylist);

  cout << endl
       << "***����ִ��Ԫ�ض�λ����,��������Ҫ���ҵ�Ԫ�أ�***" << endl;
  cin >> forLocate;
  j = LocateElem_Sq(mylist, forLocate);
  if (j != -1)
    cout << "�ҵ��ˣ����ǵ�" << j + 1 << "��Ԫ�ء�" << endl;
  else
    cout << "��λʧ�ܣ�" << endl;

  cout << endl
       << "***����ִ��ȡԪ�ز���,��Ҫ�ҵڼ���Ԫ�أ������룺***" << endl;
  cin >> forGet;
  if (GetElem_Sq(mylist, forGet - 1, temp))
    cout << "��" << forGet << "��Ԫ�ص�ֵ��:" << temp << endl;
  else
    cout << "ȡԪ��ʧ�ܣ�" << endl;

  cout << endl
       << "***����ִ�в������,��Ҫ��ʲôԪ�ز���˳����������룺***" << endl;
  cin >> forInsert;
  cout << "***���뵽�ڼ���λ�ã�***" << endl;
  cin >> temp;
  if (!ListInsert_Sq(mylist, temp - 1, forInsert))
  {
    cout << "����!" << endl;
    return 0;
  }
  else
    cout << "����ɹ���������˳���Ϊ��" << endl;
  ListTraverse_Sq(mylist);

  cout << endl
       << "***����ִ��ɾ������,��Ҫɾ���ڼ���Ԫ�أ������룺***" << endl;
  cin >> forDelete;
  if (!ListDelete_Sq(mylist, forDelete - 1, temp))
  {
    cout << "ɾ��ʧ��!" << endl;
    return 0;
  }
  else
    cout << "ɾ���ɹ���ɾ�����˳���Ϊ��" << endl;
  ListTraverse_Sq(mylist);

  //  visualization(mylist,"showsqlist.dot");

  cout << endl
       << "***����ִ�г�������***" << endl;
  DestroyList_Sq(mylist);

  cout << "***˳����Ѿ����٣�***" << endl;
  return 0;
}