//ppt366
#include <vector>

template<typename T>
class MySet {
private:
    std::vector<T> data;
public:
    // 构造函数
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
1. `bool isSubsetOf(const MySet<T>& other) const`函数的时间复杂度为O(min(n, m))，其中n是当前集合的大小，
m是其他集合的大小。在最坏情况下，当当前集合与其他集合都有共同元素时，它需要同时遍历当前集合和其他集合的所有元素。

2. `void SetUnion(const MySet<T>& other, MySet<T>& newSet) const`函数的时间复杂度为O(n + m)，其中n是当前集合的大小，
m是其他集合的大小。在这个函数中，我们同时遍历了当前集合和其他集合的元素，然后将它们插入到新的集合中。
因此，时间复杂度是这两个集合大小之和。

3. `void Insert(T obj)`函数的时间复杂度为O(1)，因为它只是在当前集合的末尾添加一个元素，这个操作的时间与当前集合的大小无关。

4. `void Intersection(const MySet<T>& other, MySet<T>& newSet) const`函数的时间复杂度为O(n + m)，
其中n是当前集合的大小，m是其他集合的大小。在这个函数中，我们同时遍历了当前集合和其他集合的元素，
并将它们相同的元素插入到新的集合中。因此，时间复杂度是这两个集合大小之和。

5. `void Difference(const MySet<T>& other, MySet<T>& newSet) const`函数的时间复杂度为O(n + m)，
其中n是当前集合的大小，m是其他集合的大小。在这个函数中，我们同时遍历了当前集合和其他集合的元素。
如果两个元素相等，我们将移动两个索引；如果当前集合的元素小于其他集合的元素，我们将当前集合的元素插入到新的集合中，
并移动当前集合的索引；如果当前集合的元素大于其他集合的元素，我们只移动其他集合的索引。
最后，我们需要将当前集合剩余的元素插入到新的集合中。因此，时间复杂度是这两个集合大小之和。

。*/

