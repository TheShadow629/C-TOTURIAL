//Inheritance is a fundamental concept in object - oriented programming that allows a class to inherit properties and behavior from another class, known as the base class or parent class.The class that inherits from the base class is called the derived class or child class.Inheritance facilitates code reuse, as derived classes can inherit the properties and methods of the base class, while also adding or modifying their own functionality.
//
//Here's an example in C++ that demonstrates inheritance:

#include <iostream>

// Base class
class Shape {
protected:
    int width;
    int height;

public:
    Shape(int w, int h) : width(w), height(h) {}

    void printArea() {
        std::cout << "Area: " << calculateArea() << std::endl;
    }

    virtual int calculateArea() {
        return 0;
    }
};

// Derived class
class Rectangle : public Shape {
public:
    Rectangle(int w, int h) : Shape(w, h) {}

    int calculateArea() override {
        return width * height;
    }
};

// Derived class
class Triangle : public Shape {
public:
    Triangle(int w, int h) : Shape(w, h) {}

    int calculateArea() override {
        return (width * height) / 2;
    }
};

int main() {
    Rectangle rectangle(4, 5);
    rectangle.printArea();  // Output: Area: 20

    Triangle triangle(4, 5);
    triangle.printArea();  // Output: Area: 10

    return 0;
}

//In this example, we have a base class `Shape` that has two data members `width` and `height`
//and a member function `printArea()` that calls the virtual function `calculateArea()`.
//The `calculateArea()` function is declared as `virtual` in the base class, indicating that
//derived classes can provide their own implementation.
//
//Two derived classes, `Rectangle` and `Triangle`, are created to inherit from the `Shape` class
//.Each derived class overrides the `calculateArea()` function to provide their own implementation
//specific to their shape.
//
//In the `main()` function, we instantiate objects of both `Rectangle` and `Triangle` classes and
//call the `printArea()` function, which internally calls the overridden `calculateArea()` function
//based on the type of the object.The output shows the calculated area based on the respective shape.
//
//Through inheritance, the derived classes `Rectangle` and `Triangle` inherit the properties and
//behavior from the base class `Shape`. This allows us to write common code in the base class and
//reuse it in the derived classes, while still allowing the derived classes to have their own
//specialized behavior.