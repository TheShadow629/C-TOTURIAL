//If a class has pointer data, the following methods should be provided by the class to ensure proper memory management and prevent issues :
//
//1. Constructor : A constructor is needed to initialize the pointer and allocate memory for the dynamic data.
//
//2. Destructor : A destructor is necessary to deallocate the memory pointed to by the pointer and prevent memory leaks.
//
//3. Copy constructor : A copy constructor is required to create a deep copy of the pointer and the data it points to when a new object is created, preventing shallow copies that can lead to issues like double deletion or sharing of memory.
//
//4. Copy assignment operator (operator=) : This operator is needed to assign the values from one object to another, including creating a deep copy of the pointer and the data it points to.
//
//Without these methods, the class may lead to issues such as memory leaks, double deletes, or unwanted sharing of memory.
//
//Here's an example to illustrate the necessity of these methods:

#include <iostream>

class MyClass {
private:
    int* data;

public:
    // Constructor
    MyClass() {
        data = new int;
        *data = 0;
    }

    // Destructor
    ~MyClass() {
        delete data;
    }

    // Copy constructor
    MyClass(const MyClass& other) {
        data = new int;
        *data = *other.data;
    }

    // Copy assignment operator
    MyClass& operator=(const MyClass& other) {
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

//In this example, the `MyClass` class has a pointer `data` to dynamically allocated `int` data.The constructor allocates memory for `data`, the destructor deallocates the memory, the copy constructor creates a deep copy of `data` when a new object is created, and the copy assignment operator assigns the values from one object to another, including creating a deep copy of `data`.
//
//If these methods were not provided, issues could occur :

int main() {
    MyClass obj1;
    obj1.setData(5);

    MyClass obj2 = obj1;  // Shallow copy without a custom copy constructor

    obj1.setData(10);

    std::cout << obj1.getData() << std::endl;  // Output: 10
    std::cout << obj2.getData() << std::endl;  // Output: 10 (data is shared)

    return 0;
}

//Without a custom copy constructor, a shallow copy is made, resulting in `obj2` sharing the same memory
//location as `obj1`. Modifying the data using `obj1` affects `obj2` since they have the same memory location.
//
//Providing the required methods ensures proper memory management and creates separate copies of the dynamically allocated data, avoiding issues like double deletion and unwanted sharing of memory.