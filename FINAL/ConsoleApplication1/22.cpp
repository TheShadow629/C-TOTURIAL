//Dynamic polymorphism in C++ is achieved through the use of virtual
//functions and pointers or references to base class objects.It allows
//a program to determine at runtime which derived class implementation
//of a function should be called.
//
//Here's an example to demonstrate how dynamic polymorphism works:

#include <iostream>

// Base class
class Shape {
public:
    // Virtual function
    virtual void draw() {
        std::cout << "Drawing a shape." << std::endl;
    }
};

// Derived class 1
class Circle : public Shape {
public:
    // Override the base class function
    void draw() override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

// Derived class 2
class Square : public Shape {
public:
    // Override the base class function
    void draw() override {
        std::cout << "Drawing a square." << std::endl;
    }
};

int main() {
    // Create base class pointers
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    // Call the draw() function
    shape1->draw(); // Calls the derived class function for Circle
    shape2->draw(); // Calls the derived class function for Square

    // Clean up memory
    delete shape1;
    delete shape2;

    return 0;
}
//
//In this example, we have a base class `Shape` with a virtual function `draw()`.
//The derived classes `Circle` and `Square` override the `draw()` function to provide their own implementation.
//
//To achieve dynamic polymorphism, we create pointers of the base class type(`Shape*`) and
//assign them objects of the derived classes.When calling the `draw()` function through these pointers,
//the appropriate derived class implementation is invoked based on the actual type of the object pointed to.
//
//Key requirements for dynamic polymorphism in C++ :
//    1. Have a base class with at least one virtual function.
//    2. Derived classes must override the virtual function.
//    3. Use pointers or references of the base class type to point to derived class objects.
//    4. Call the virtual function through the base class pointer or reference.
//
//    Note : It's important to delete dynamically allocated objects to avoid memory leaks.