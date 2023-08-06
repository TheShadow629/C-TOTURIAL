//When writing a destructor in C++, it is often necessary to also implement the copy constructor and the copy assignment operator (the operator=) as part of the Rule of Three(or Rule of Five in C++11 and above).This ensures proper memory management and prevents issues such as memory leaks or double deletes.
//Let's consider an example to illustrate why a destructor, copy constructor, and copy assignment operator would need to be implemented:

#include <iostream>

class Resource {
private:
    int* data;

public:
    // Constructor
    Resource() {
        data = new int;
        *data = 0;
    }

    // Destructor
    ~Resource() {
        delete data;
    }

    // Copy constructor
    Resource(const Resource& other) {
        data = new int;
        *data = *other.data;
    }

    // Copy assignment operator
    Resource& operator=(const Resource& other) {
        if (this != &other) {
            delete data;
            data = new int;
            *data = *other.data;
        }
        return *this;
    }

    // Getter
    int getData() const {
        return *data;
    }

    // Setter
    void setData(int value) {
        *data = value;
    }
};

//In this example, the `Resource` class manages a dynamically allocated integer `data` using a pointer.The destructor `~Resource()` is responsible for deallocating the memory pointed to by `data` when an object of the class goes out of scope or is explicitly deleted.

//If the copy constructor and copy assignment operator are not properly implemented, issues can arise, such as shallow copies or double deletion :

int main() {
    Resource obj1;
    obj1.setData(5);

    Resource obj2 = obj1;  // Shallow copy without a custom copy constructor

    obj1.setData(10);

    std::cout << obj1.getData() << std::endl;  // Output: 10
    std::cout << obj2.getData() << std::endl;  // Output: 10 (data is shared)

    return 0;
}

//In this case, without a proper copy constructor, `obj2` would receive a shallow copy of `obj1`, meaning the `data` pointer would be copied but not the actual value it points to.As a result, modifying the data using `obj1` would also affect `obj2` since they share the same memory location.Implementing the copy constructor ensures that a deep copy is made, creating a separate copy of the data.
//By implementing the destructor, copy constructor, and copy assignment operator, you ensure proper memory management, prevent memory leaks, and avoid potential issues when copying objects that contain dynamically allocated resources.