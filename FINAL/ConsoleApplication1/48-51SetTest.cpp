//ppt366
#include <vector>

template<typename T>
class MySet {
private:
    std::vector<T> data;
public:
    // ���캯��
    MySet() {}
    std::vector<T> GetData() const
    {
        return data;
    }
    void SetData(const std::vector<T>& data)
    {
        this->data = data;
    }

    bool isSubsetOf(const MySet<T>& other) const {
        bool subset = true;
        size_t thisIndex = 0;
        size_t otherIndex = 0;

        while (thisIndex < data.size() && otherIndex < other.data.size() && subset) {
            if (data[thisIndex] == other.data[otherIndex]) {
                thisIndex++;
                otherIndex++;
            }
            else if (data[thisIndex] < other.data[otherIndex]) {
                subset = false;
            }
            else {
                otherIndex++;
            }
        }

        if (thisIndex < data.size()) {
            subset = false;
        }
        return subset;
    }
    void SetUnion(const MySet<T>& other, MySet<T>& newSet) const {
        // MySet<T> newSet;
        size_t thisIndex = 0;
        size_t otherIndex = 0;

        while (thisIndex < data.size() && otherIndex < other.data.size()) {
            if (data[thisIndex] == other.data[otherIndex]) {
                newSet.Insert(data[thisIndex]);
                thisIndex++;
                otherIndex++;
            }
            else if (data[thisIndex] < other.data[otherIndex]) {
                newSet.Insert(data[thisIndex]);
                thisIndex++;
            }
            else {
                newSet.Insert(other.data[otherIndex]);
                otherIndex++;
            }
        }

        while (thisIndex < data.size()) {
            newSet.Insert(data[thisIndex]);
            thisIndex++;
        }

        while (otherIndex < other.data.size()) {
            newSet.Insert(other.data[otherIndex]);
            otherIndex++;
        }
    }
    void Insert(T obj)
    {
        data.push_back(obj);
    }
    void Intersection(const MySet<T>& other, MySet<T>& newSet) const {
        MySet<T> newSet;
        size_t thisIndex = 0;
        size_t otherIndex = 0;

        while (thisIndex < data.size() && otherIndex < other.data.size()) {
            if (data[thisIndex] == other.data[otherIndex]) {
                newSet.Insert(data[thisIndex]);
                thisIndex++;
                otherIndex++;
            }
            else if (data[thisIndex] < other.data[otherIndex]) {
                thisIndex++;
            }
            else {
                otherIndex++;
            }
        }
    }
    void Difference(const MySet<T>& other, MySet<T>& newSet) const {
        size_t thisIndex = 0;
        size_t otherIndex = 0;

        while (thisIndex < data.size() && otherIndex < other.data.size()) {
            if (data[thisIndex] == other.data[otherIndex]) {
                thisIndex++;
                otherIndex++;
            }
            else if (data[thisIndex] < other.data[otherIndex]) {
                newSet.Insert(data[thisIndex]);
                thisIndex++;
            }
            else {
                otherIndex++;
            }
        }

        while (thisIndex < data.size()) {
            newSet.Insert(data[thisIndex]);
            thisIndex++;
        }
    }
};

template<typename T>
void UNION(const MySet<T>& set1, const MySet<T>& set2, MySet<T>& newSet)
{
    std::vector<T> data = set1.GetData();
    std::vector<T> other = set2.GetData();

    size_t thisIndex = 0;
    size_t otherIndex = 0;

    while (thisIndex < data.size() && otherIndex < other.data.size()) {
        if (data[thisIndex] == other.data[otherIndex]) {
            newSet.Insert(data[thisIndex]);
            thisIndex++;
            otherIndex++;
        }
        else if (data[thisIndex] < other.data[otherIndex]) {
            newSet.Insert(data[thisIndex]);
            thisIndex++;
        }
        else {
            newSet.Insert(other.data[otherIndex]);
            otherIndex++;
        }
    }

    while (thisIndex < data.size()) {
        newSet.Insert(data[thisIndex]);
        thisIndex++;
    }

    while (otherIndex < other.data.size()) {
        newSet.Insert(other.data[otherIndex]);
        otherIndex++;
    }
}

/*
1. `bool isSubsetOf(const MySet<T>& other) const`������ʱ�临�Ӷ�ΪO(min(n, m))������n�ǵ�ǰ���ϵĴ�С��
m���������ϵĴ�С���������£�����ǰ�������������϶��й�ͬԪ��ʱ������Ҫͬʱ������ǰ���Ϻ��������ϵ�����Ԫ�ء�

2. `void SetUnion(const MySet<T>& other, MySet<T>& newSet) const`������ʱ�临�Ӷ�ΪO(n + m)������n�ǵ�ǰ���ϵĴ�С��
m���������ϵĴ�С������������У�����ͬʱ�����˵�ǰ���Ϻ��������ϵ�Ԫ�أ�Ȼ�����ǲ��뵽�µļ����С�
��ˣ�ʱ�临�Ӷ������������ϴ�С֮�͡�

3. `void Insert(T obj)`������ʱ�临�Ӷ�ΪO(1)����Ϊ��ֻ���ڵ�ǰ���ϵ�ĩβ���һ��Ԫ�أ����������ʱ���뵱ǰ���ϵĴ�С�޹ء�

4. `void Intersection(const MySet<T>& other, MySet<T>& newSet) const`������ʱ�临�Ӷ�ΪO(n + m)��
����n�ǵ�ǰ���ϵĴ�С��m���������ϵĴ�С������������У�����ͬʱ�����˵�ǰ���Ϻ��������ϵ�Ԫ�أ�
����������ͬ��Ԫ�ز��뵽�µļ����С���ˣ�ʱ�临�Ӷ������������ϴ�С֮�͡�

5. `void Difference(const MySet<T>& other, MySet<T>& newSet) const`������ʱ�临�Ӷ�ΪO(n + m)��
����n�ǵ�ǰ���ϵĴ�С��m���������ϵĴ�С������������У�����ͬʱ�����˵�ǰ���Ϻ��������ϵ�Ԫ�ء�
�������Ԫ����ȣ����ǽ��ƶ����������������ǰ���ϵ�Ԫ��С���������ϵ�Ԫ�أ����ǽ���ǰ���ϵ�Ԫ�ز��뵽�µļ����У�
���ƶ���ǰ���ϵ������������ǰ���ϵ�Ԫ�ش����������ϵ�Ԫ�أ�����ֻ�ƶ��������ϵ�������
���������Ҫ����ǰ����ʣ���Ԫ�ز��뵽�µļ����С���ˣ�ʱ�临�Ӷ������������ϴ�С֮�͡�

��*/

