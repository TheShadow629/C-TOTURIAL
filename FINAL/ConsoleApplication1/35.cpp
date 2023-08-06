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
//����ԭ��Open - Closed Principle��OCP���������������е�һ��ԭ����ָ�����ʵ�壨�ࡢģ�顢�����ȣ�Ӧ�ö���չ���ţ�
//���޸Ĺرա����ԭ���Ŀ����ͨ���������ķ�ʽ��ʹ�����д������Ϊ�ܹ�����չ��������Ҫ�޸����д��룬
//�Ӷ�����Ƶ���޸����д��������
//
//��������һ��������˵������ԭ����C++�е�Ӧ�ã�
//
//#include <iostream>
//#include <vector>
//
//// ������࣬����һ����״
//class Shape {
//public:
//    virtual double calculateArea() const = 0;
//};
//
//// �����࣬ʵ�־������״
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
//// ����������״���߼�
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
//    std::cout << "�������" << totalArea << std::endl;
//
//    return 0;
//}
//```
//
//�����ʾ���У�������һ��������� `Shape`�����ж�����һ�����麯�� `calculateArea()`��`Rectangle` �� `Circle` ��̳��� `Shape` �����ݸ��Ե���״ʵ���� `calculateArea()` ������
//
//`calculateTotalArea()` ��������һ�� `Shape` ָ�����������ͨ������ÿ����״�� `calculateArea()` �����������������
//
//���ڣ�����������Ҫ����һ���µ���״�����������Σ������޸����еĴ��롣���ǿ��Լ򵥵����һ���µ�������չ���ܣ�
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
//���ڣ����ǿ��Դ�����ʹ�� `Triangle` ���ʵ�����������޸����еĴ��룺
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
//    std::cout << "�������" << totalArea << std::endl;
//
//    return 0;
//}
//```
//
//��ѭ����ԭ�������ܹ��ڲ��޸����д��������������µ���״�ࣨ`Triangle`����
//���е� `calculateTotalArea()` ������������״����չ�ǿ��ŵģ������д������Ϊ�����޸��ǹرյġ�
//��ʹ�ô��������������ά������������µ���״����Ӱ�����й��ܡ�