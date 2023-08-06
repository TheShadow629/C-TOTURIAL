#include <vector>
#include <cassert>
#include <iostream>
#include <ostream>

template <typename T>
class Vector {
private:
    std::vector<T> m_data;

public:
    // Default constructor
    Vector() {}

    // Constructor with an initial size
    Vector(size_t size){ m_data(size); }

    // Constructor with initial size and default value
    Vector(size_t size, const T& value) { m_data(size, value); }

    // Copy constructor
    Vector(const Vector& other) { m_data(other.m_data); }

    // Assignment operator
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            m_data = other.m_data;
        }
        return *this;
    }

    // Destructor
    ~Vector() {}

    // Access element at index
    T& operator[](size_t index) const {
        assert(index < m_data.size());
        return m_data[index];
    }

    // Get the size of the vector
    size_t size() const {
        return m_data.size();
    }

    // Add an element to the end of the vector
    void push_back(const T& value) {
        m_data.push_back(value);
    }

    // Remove the last element from the vector
    void pop_back() {
        assert(!m_data.empty());
        m_data.pop_back();
    }

    // Remove all elements from the vector
    void clear() {
        m_data.clear();
    }
};
//
//In the above implementation :
//
//-The `Vector` class is a template class that can be instantiated with any type `T`.
//- It internally uses `std::vector<T>` to store the elements of the vector. `std::vector` is an appropriate data structure because it provides dynamic array - like behavior with automatic memory management, bounds - checking, and efficient insertions and deletions at the end.
//- The class provides a minimal but complete set of public methods to manage and manipulate the vector.It includes constructors, assignment operator, destructor, subscript operator `[]` for element access, `size()` method to get the size of the vector, `push_back()` method to add an element to the end, `pop_back()` method to remove the last element, and `clear()` method to remove all elements.
//- Appropriate assertions are used to ensure the correctness of the operations, such as checking the index bounds and preventing popping from an empty vector.

//以下是单元测试
#include <cassert>

void TestDefaultConstructor() {
    Vector<int> vec;
    assert(vec.size() == 0);
}

void TestConstructorWithSizeAndValue() {
    Vector<int> vec(3, 5);
    assert(vec.size() == 3);
    assert(vec[0] == 5);
    assert(vec[1] == 5);
    assert(vec[2] == 5);
}

void TestCopyConstructorAndAssignmentOperator() {
    Vector<int> vec1(3, 5);
    Vector<int> vec2(vec1);
    assert(vec2.size() == vec1.size());
    assert(vec2[1] == vec1[1]);

    Vector<int> vec3;
    vec3 = vec1;
    assert(vec3.size() == vec1.size());
    assert(vec3[2] == vec1[2]);
}

void TestPushAndPop() {
    Vector<int> vec;
    for (int i = 1; i <= 3; ++i) {
        vec.push_back(i);
    }
    assert(vec.size() == 3);
    assert(vec[1] == 2);
    vec.pop_back();
    assert(vec.size() == 2);
    assert(vec[1] == 2);
}

void TestClear() {
    Vector<int> vec(3, 5);
    vec.clear();
    assert(vec.size() == 0);
}

int main() {
    TestDefaultConstructor();
    TestConstructorWithSizeAndValue();
    TestCopyConstructorAndAssignmentOperator();
    TestPushAndPop();
    TestClear();

    // Add more test functions to cover other functionality and edge cases

    std::cout << "All tests passed!" << std::endl;
    return 0;
}