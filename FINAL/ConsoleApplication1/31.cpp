//In C++, the concepts of deep copy and shallow copy relate to how data is copied from one object to another.Let's explore these concepts with examples.
//
//1. Shallow Copy :
//Shallow copy involves copying the values of the members from one object to another, including pointers.However, the copied pointers still point to the same memory locations as the original object.This means that changes made to the data pointed to by the copied pointers will affect both the original and copied objects.

#include <iostream>

class ShallowCopy {
private:
    int* data;

public:
    ShallowCopy(int value) {
        data = new int;
        *data = value;
    }

    void setData(int value) {
        *data = value;
    }

    void printData() {
        std::cout << *data << std::endl;
    }
};

int TestShallowCopy() {
    ShallowCopy obj1(5);
    ShallowCopy obj2 = obj1;  // Shallow copy

    obj1.setData(10);

    obj1.printData();  // Output: 10
    obj2.printData();  // Output: 10 (data is shared)

    return 0;
}

//In this example, the `ShallowCopy` class has a member variable `data`, which is a pointer to an integer.During the shallow copy, the pointer `data` of `obj2` is assigned the same memory address as `obj1`. As a result, modifying the data using `obj1` also affects `obj2`, as they share the same memory location.Both objects end up pointing to the same data, resulting in a shallow copy.

//2. Deep Copy :
//Deep copy, on the other hand, creates a separate copy of the pointed - to data in addition to copying the values of the members.This way, each object has its own memory for the data, and changes made to one object do not affect the other.

class DeepCopy {
private:
    int* data;

public:
    DeepCopy(int value) {
        data = new int;
        *data = value;
    }

    DeepCopy(const DeepCopy& other) {
        data = new int;
        *data = *other.data;
    }

    ~DeepCopy() {
        delete data;
    }

    void setData(int value) {
        *data = value;
    }

    void printData() {
        std::cout << *data << std::endl;
    }
};

int TestDeepCopy() {
    DeepCopy obj1(5);
    DeepCopy obj2 = obj1;  // Deep copy 调用的是拷贝构造函数

    //DeepCopy obj2(6);
    //obj2 = obj1; 调用系统自带的operator = ,导致浅拷贝

    obj1.setData(10);

    obj1.printData();  // Output: 10
    obj2.printData();  // Output: 5 (data is independent)

    return 0;
}

//In this example, the `DeepCopy` class includes a copy constructor that allocates separate memory for `data` and assigns the value from the original object.When `obj2` is created via the copy constructor, it has its own memory for `data`, resulting in a deep copy.Modifying the data using `obj1` does not impact `obj2`, as they have separate memory locations for the data.

//By implementing a deep copy, each object maintains its own independent copy of any dynamically allocated data, ensuring that modifications to one object do not affect others that share the same data.