//The Open - Closed Principle(OCP) states that software entities(classes, modules, functions, etc.) should be open for extension but closed for modification.This principle promotes the idea of designing software in a way that allows the behavior of existing code to be extended without modifying that code, preventing the need for frequent changes to the existing codebase.

//Let's consider an example to understand the Open-Closed Principle in C++:

#include <iostream>
#include <vector>

// Abstract base class representing a shape
class Shape {
public:
    virtual double calculateArea() const = 0;
};

// Derived classes implementing specific shapes
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double calculateArea() const override {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return 3.14 * radius * radius;
    }
};

// Function that operates on the shapes
double calculateTotalArea(const std::vector<const Shape*>&shapes) {
    double totalArea = 0.0;
    for (const Shape* shape : shapes) {
        totalArea += shape->calculateArea();
    }
    return totalArea;
}

int main() {
    Rectangle rect(5, 3);
    Circle circle(2);

    std::vector<const Shape*> shapes = { &rect, &circle };

    double totalArea = calculateTotalArea(shapes);
    std::cout << "Total area: " << totalArea << std::endl;

    return 0;
}

//In this example, we have an abstract base class `Shape` with a pure virtual function `calculateArea()`. The `Rectangle` and `Circle` classes derive from `Shape` and implement the `calculateArea()` function according to their respective shapes.
//
//The `calculateTotalArea()` function takes a vector of `Shape` pointers and calculates the total area by calling the `calculateArea()` function on each shape.
//
//Now, let's say we want to introduce a new shape, a triangle, without modifying the existing code. We can simply extend the functionality by adding a new class:

class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double calculateArea() const override {
        return 0.5 * base * height;
    }
};

//We can now create and use instances of the `Triangle` class without needing to modify the existing codebase :

int main() {
    Rectangle rect(5, 3);
    Circle circle(2);
    Triangle triangle(4, 6);

    std::vector<const Shape*> shapes = { &rect, &circle, &triangle };

    double totalArea = calculateTotalArea(shapes);
    std::cout << "Total area: " << totalArea << std::endl;

    return 0;
}

//By following the Open - Closed Principle, we were able to introduce a new shape class (`Triangle`)
//without modifying the existing codebase.The existing `calculateTotalArea()` function was open for
//extension to accommodate the new shape, and the behavior of the existing code remained closed for
//modification.This allows for greater flexibility and maintainability in the codebase, as new shapes
//can be added without impacting the existing functionality.

//________________________________________________________________________________________________________________
//开闭原则（Open - Closed Principle，OCP）是面向对象设计中的一个原则，它指出软件实体（类、模块、函数等）应该对扩展开放，
//对修改关闭。这个原则的目标是通过设计软件的方式，使得现有代码的行为能够被扩展，而不需要修改已有代码，
//从而降低频繁修改现有代码的需求。
//
//让我们用一个例子来说明开闭原则在C++中的应用：
//
//#include <iostream>
//#include <vector>
//
//// 抽象基类，代表一个形状
//class Shape {
//public:
//    virtual double calculateArea() const = 0;
//};
//
//// 派生类，实现具体的形状
//class Rectangle : public Shape {
//private:
//    double width, height;
//
//public:
//    Rectangle(double w, double h) : width(w), height(h) {}
//
//    double calculateArea() const override {
//        return width * height;
//    }
//};
//
//class Circle : public Shape {
//private:
//    double radius;
//
//public:
//    Circle(double r) : radius(r) {}
//
//    double calculateArea() const override {
//        return 3.14 * radius * radius;
//    }
//};
//
//// 函数操作形状的逻辑
//double calculateTotalArea(const std::vector<const Shape*>& shapes) {
//    double totalArea = 0.0;
//    for (const Shape* shape : shapes) {
//        totalArea += shape->calculateArea();
//    }
//    return totalArea;
//}
//
//int main() {
//    Rectangle rect(5, 3);
//    Circle circle(2);
//
//    std::vector<const Shape*> shapes = { &rect, &circle };
//
//    double totalArea = calculateTotalArea(shapes);
//    std::cout << "总面积：" << totalArea << std::endl;
//
//    return 0;
//}
//```
//
//在这个示例中，我们有一个抽象基类 `Shape`，其中定义了一个纯虚函数 `calculateArea()`。`Rectangle` 和 `Circle` 类继承自 `Shape` 并根据各自的形状实现了 `calculateArea()` 函数。
//
//`calculateTotalArea()` 函数接受一个 `Shape` 指针的向量，并通过调用每个形状的 `calculateArea()` 函数来计算总面积。
//
//现在，假设我们想要引入一个新的形状，比如三角形，而不修改现有的代码。我们可以简单地添加一个新的类来扩展功能：
//
//```cpp
//class Triangle : public Shape {
//private:
//    double base, height;
//
//public:
//    Triangle(double b, double h) : base(b), height(h) {}
//
//    double calculateArea() const override {
//        return 0.5 * base * height;
//    }
//};
//```
//
//现在，我们可以创建并使用 `Triangle` 类的实例，而无需修改现有的代码：
//
//```cpp
//int main() {
//    Rectangle rect(5, 3);
//    Circle circle(2);
//    Triangle triangle(4, 6);
//
//    std::vector<const Shape*> shapes = { &rect, &circle, &triangle };
//
//    double totalArea = calculateTotalArea(shapes);
//    std::cout << "总面积：" << totalArea << std::endl;
//
//    return 0;
//}
//```
//
//遵循开闭原则，我们能够在不修改现有代码的情况下引入新的形状类（`Triangle`）。
//现有的 `calculateTotalArea()` 函数对于新形状的扩展是开放的，而现有代码的行为对于修改是关闭的。
//这使得代码更加灵活和易于维护，可以添加新的形状而不影响现有功能。