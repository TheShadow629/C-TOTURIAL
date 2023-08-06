//In C++, a pure virtual method is a virtual method that is declared in a base class but has no implementation.It is denoted by adding "= 0" after the method declaration.Pure virtual methods act as placeholders or contracts that derived classes are required to implement.A class that contains at least one pure virtual method becomes an abstract class, and objects cannot be instantiated from it.
//Let's understand pure virtual methods with a C++ example:

#include <iostream>

class Shape {
public:
    virtual double area() const = 0; // Pure virtual method
    virtual void draw() const = 0; // Pure virtual method
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override { return length * width; }
    void draw() const override { std::cout << "Drawing a rectangle." << std::endl; }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14 * radius * radius; }
    void draw() const override { std::cout << "Drawing a circle." << std::endl; }
};
//
//In the above code, the `Shape` class is an abstract class that contains pure virtual methods `area()` and `draw()`. The `Rectangle` and `Circle` classes are derived from `Shape` and must implement these pure virtual methods.The `Shape` class acts as an interface or contract that defines the common behavior expected for shapes.Each derived class provides its own implementation of the pure virtual methods.
//
//Now let's discuss situations where classes with pure virtual methods are useful in software design:
//
//1. Interface / Contract Definition :
//Pure virtual methods are often used to define interfaces or contracts in software systems.It allows different classes to adhere to a common set of behaviors without specifying the implementation details.This provides flexibility and allows for different implementations as long as they fulfill the required contract.In this way, pure virtual methods aid in achieving loose coupling and modularity in the system.
//
//2. Polymorphism and Runtime Binding :
//Using pure virtual methods allows for polymorphism in C++.By creating pointers or references to the base abstract class and assigning them to derived class objects, we can achieve runtime binding of the overridden methods.This means that the appropriate method will be called based on the actual object type, allowing for dynamic behavior based on the runtime context.
//
//3. Frameworks and Libraries :
//    Pure virtual methods are commonly used in frameworks and library designs.They provide a generic skeleton or blueprint for users to extend and customize the functionality.Users can derive their own classes from the abstract base class, implement the pure virtual methods, and plug them into the framework.This enables code reuse, modularity, and extensibility.
//
//    Using classes with pure virtual methods in these situations promotes code organization, flexibility, and
//    modularity.It allows for the creation of well - defined interfaces and contracts, as well as enabling
//    polymorphism and runtime binding.These features are essential in complex software systems where different
//    modules need to communicate and work together efficiently while allowing for customization and extension.
//������ʾ���У�`Shape` ��һ��������࣬����������������麯�� `area()` �� `draw()`��`Rectangle` �� `Circle` �ֱ��������� `Shape` �����������࣬���Ǳ���ʵ�����������麯������ `main` �����У����Ǵ�����һ�����ζ��� `rect` ��һ��Բ�ζ��� `circle`��Ȼ�����Ǵ���������ָ�� `Shape` ���͵�ָ�룬�ֱ�ָ�� `rect` �� `circle` ����ͨ����Щָ�룬���ǵ��� `area()` �� `draw()` ������ʵ���˶�̬�ԣ�����ʵ�ʶ�������͵�������Ӧ��ʵ�֡�



int main() {
    Rectangle rect(5.0, 3.0);
    Circle circle(2.5);

    Shape* shape1 = &rect;
    Shape* shape2 = &circle;

    std::cout << "Rectangle area: " << shape1->area() << std::endl; // �����Rectangle area: 15
    std::cout << "Circle area: " << shape2->area() << std::endl; // �����Circle area: 19.625

    shape1->draw(); // �����Drawing a rectangle.
    shape2->draw(); // �����Drawing a circle.

    return 0;
}

//
//��������ʾ������������п�����
//```
//Rectangle area : 15
//Circle area : 19.625
//Drawing a rectangle.
//Drawing a circle.
//
//���ʾ����ʾ�����ͨ��ָ���������ָ��ʵ�ֶ�̬�ԣ��Լ����ʹ��������ľ���ʵ�������ô��麯����
//�����������������ͨ������Ľӿ���������ͬ���͵Ķ��󣬶�������ľ����ʵ��ϸ�ڡ�
//����������ԺͿ���չ�Զ��ڴ������ϵͳ����ƺͿ����ǳ����á�