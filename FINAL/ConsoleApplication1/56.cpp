#include <iostream>
//In C++, a base class is a class from which other classes can be derived.
//It provides a set of common attributes and behavior that can be inherited by
//its derived classes. An abstract base class, on the other hand, is a class that cannot be instantiated.
//It is designed to be a generic template or interface for its derived classes, defining some common
//behaviors but leaving the implementation details to its subclasses.
//
//Let's understand the difference between a base class and an abstract base class with code
//examples and UML diagrams:
//
//1. Base Class:
//A base class serves as a foundation for other classes to derive from. It can have both
//data members and member functions. The derived classes inherit the attributes and behaviors of
//the base class. Here's an example:
class Shape {
protected:
    int width;
    int height;
public:
    Shape(int w, int h) : width(w), height(h) {}
    int area() { return 0; }
};

class Rectangle : public Shape {
public:
    Rectangle(int w, int h) : Shape(w, h) {}
    int area()  { return width * height; }
};

class Circle : public Shape {
public:
    Circle(int r) : Shape(r, r) {}
    int area()  { return 3.14 * width * width; }
};
//In the above example, `Shape` is the base class with `Rectangle` and `Circle` as its derived classes.
//The base class provides the common attributes (`width` and `height`) and a pure virtual function `area()`,
//which has to be implemented by the derived classes. The derived classes inherit these attributes and behavior
//and can provide their own implementations.
//
//UML diagram for the Base Class example:
//
//```
//------------------
//|     Shape      |
//------------------
//| - width: int   |
//| - height: int  |
//------------------
//| + Shape(w, h)  |
//| + area(): int  |
//------------------
//        ^
//        |
// ---------------------
// |     Rectangle     |
// ---------------------
// | + Rectangle(w, h) |
// | + area(): int     |
// ---------------------
//        ^
//        |
// -----------------
// |     Circle    |
// -----------------
// | + Circle(r)   |
// | + area(): int |
// -----------------
//
//2. Abstract Base Class:
//An abstract base class is a class that cannot be instantiated directly. It is used as a blueprint or
//interface for its derived classes. It contains pure virtual functions that must be implemented by the
//derived classes. Here's an example:
//
class Animal {
public:
    virtual void speak() = 0; // Pure virtual function
};

class Dog : public Animal {
public:
    void speak() override { std::cout << "Woof!" << std::endl; }
};

class Cat : public Animal {
public:
    void speak() override { std::cout << "Meow!" << std::endl; }
};

//
//In the above example, `Animal` is an abstract base class with `Dog` and `Cat` as its derived classes.
//The base class defines a pure virtual function `speak()`, which must be implemented by the derived classes.
//The abstract base class serves as an interface, allowing different derived classes to have their
//own implementations of the common behavior.
//
//UML diagram for the Abstract Base Class example:
//
//```
//-----------------
//|     Animal    |
//-----------------
//| <<abstract>>  |
//-----------------
//| + speak()     |
//-----------------
//        ^
//        |
// -----------------
// |      Dog      |
// -----------------
// | + speak()     |
// -----------------
//        ^
//        |
// -----------------
// |      Cat      |
// -----------------
// | + speak()     |
// -----------------
//
//When to use base class and abstract base class:
//
//- Base Class: Use a base class when you want to define common attributes and behavior that can be inherited
//by multiple derived classes. The base class provides a common interface and avoids code duplication.
//- Abstract Base Class: Use an abstract base class when you want to define a generic template or interface
//for a group of related classes. It ensures that all derived classes provide their own implementation of
//certain functions, enforcing a consistent behavior across different subclasses.
//
//It's important to note that while you cannot create instances of an abstract base class, you can have
//pointers or references to the abstract base class type and use them to refer to derived class objects.
//This allows for polymorphism and runtime binding of overridden functions.

int main() {
    // 基类指针指向派生类对象
    Shape* shape1 = new Rectangle(1,1);
    Shape* shape2 = new Circle(1);

    // 调用基类的纯虚函数，实现多态性
    shape1->area(); // Output: Drawing a rectangle.
    shape2->area(); // Output: Drawing a circle.

    delete shape1;
    delete shape2;

    return 0;
}