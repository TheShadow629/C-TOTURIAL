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
//在上述示例中，`Shape` 是一个抽象基类，里面包含了两个纯虚函数 `area()` 和 `draw()`。`Rectangle` 和 `Circle` 分别是派生自 `Shape` 的两个具体类，它们必须实现这两个纯虚函数。在 `main` 函数中，我们创建了一个矩形对象 `rect` 和一个圆形对象 `circle`。然后，我们创建了两个指向 `Shape` 类型的指针，分别指向 `rect` 和 `circle` 对象。通过这些指针，我们调用 `area()` 和 `draw()` 方法，实现了多态性，根据实际对象的类型调用了相应的实现。



int main() {
    Rectangle rect(5.0, 3.0);
    Circle circle(2.5);

    Shape* shape1 = &rect;
    Shape* shape2 = &circle;

    std::cout << "Rectangle area: " << shape1->area() << std::endl; // 输出：Rectangle area: 15
    std::cout << "Circle area: " << shape2->area() << std::endl; // 输出：Circle area: 19.625

    shape1->draw(); // 输出：Drawing a rectangle.
    shape2->draw(); // 输出：Drawing a circle.

    return 0;
}

//
//运行上述示例，将在输出中看到：
//```
//Rectangle area : 15
//Circle area : 19.625
//Drawing a rectangle.
//Drawing a circle.
//
//这个示例演示了如何通过指向抽象基类的指针实现多态性，以及如何使用派生类的具体实现来调用纯虚函数。
//这样的设计允许我们通过抽象的接口来操作不同类型的对象，而无需关心具体的实现细节。
//这样的灵活性和可扩展性对于大型软件系统的设计和开发非常有用。