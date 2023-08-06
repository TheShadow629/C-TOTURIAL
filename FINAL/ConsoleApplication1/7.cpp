//1. 特化（Specialisation）示例：
//考虑一个图形类（Shape）和一个矩形类（Rectangle）。矩形是一种特殊类型的图形，因此矩形类可以特化为图形类的子类。下面是特化关系的示例：
//
//```
//+------------+
//|   Shape    |
//+------------+
//|            |
//|            |
//|            |
//+------+-----+
//|      ^
//|      |
//|      |
//|      |
//|      |
//|      |
//| +---------+
//| | Rectangle|
//| +---------+
//```
//
//在这个示例中，矩形类是图形类的子类，它继承了图形类的属性和方法，并且可以添加特定于矩形的属性和方法。
//
//2. 实现（Realisation）示例：
//考虑一个飞行接口（Flyable）和一个鸟类（Bird）。鸟可以飞行，因此鸟类可以实现飞行接口。下面是实现关系的示例：
//
//```
//+-----------------+
//|    Flyable      |
//+-----------------+
//|                 |
//| +---------------+
//| |   Bird        |
//| +---------------+
//```
//
//在这个示例中，鸟类实现了飞行接口，意味着鸟类必须提供了飞行接口中定义的所有方法。
//
//总结：
//特化关系表示一个类是另一个类的特殊类型，而实现关系表示一个类实现了一个接口。特化关系在类之间形成继承层次结构，而实现关系使类满足接口的要求。

//1. 特化（Specialisation）示例代码：

#include <iostream>
#include <ostream>

// 基类 Shape
class Shape {
public:
    double CalculateArea() { return 0; };
};

// 派生类 Rectangle，特化为 Shape 的子类
class Rectangle : public Shape {
private:
    double m_width;
    double m_height;

public:
    Rectangle(double width, double height) : m_width(width), m_height(height) {}

    double CalculateArea()  {  return m_width * m_height; }
};


//在这个示例中，基类 `Shape` 是一个抽象类，定义了一个纯虚函数 `CalculateArea`。派生类 `Rectangle` 特化为 `Shape` 的子类，并实现了 `CalculateArea` 方法。

//2. 实现（Realisation）示例代码：

// 飞行接口 Flyable
class Flyable {
public:
    virtual void Fly() = 0;

};

// 鸟类 Bird，实现了飞行接口
class Bird : public Flyable {
public:
    void Fly() override {//对接口虚函数进行覆写
        // 鸟的飞行实现
        std::cout << "Bird is flying." << std::endl;
    }
};

//在这个示例中，飞行接口 `Flyable` 是一个抽象接口，定义了纯虚函数 `Fly`。类 `Bird` 实现了 `Flyable` 接口，必须实现并提供 `Fly` 方法的具体实现。

//特化关系通过类的继承来实现，而实现关系通过类实现接口来实现。这种关系的使用可以根据具体的需求和设计来灵活选择。
//file:///C:/Users/laptop/Desktop/LabExc-1-ass/PPT/4-32.pdf 302


int main()
{
    // 创建 Rectangle 对象
    Rectangle rectangle(5.0, 3.0);

    // 调用 CalculateArea 方法计算面积并输出
    double area = rectangle.CalculateArea();
    std::cout << "Rectangle area: " << area << std::endl;

    // 创建 Bird 对象
    Bird bird;

    // 调用 Fly 方法让鸟飞行
    bird.Fly();

    return 0;
}


//#include <iostream>       // std::cout
//
//class Base {
//
//public:
//    Base() {};
//    virtual void func_a(int a) = 0; //这个是虚函数，子类只继承接口，具体的实现，由子类去实现
//    void func_b(int b) { std::cout << b + 10 << "\n"; }; //这个是实函数，其接口和实现，都会被子类继承
//};
//
//class Base_A : public Base {
//public:
//    void func_a(int a) { std::cout << a << "\n"; };
//};
//
//class Base_B : public Base {
//public:
//    void func_a(int a) { std::cout << a + 15 << "\n"; };
//};
//
//int main()
//{
//    Base_A a;
//    Base_B b;
//
//    a.func_a(10); //仅仅继承了基类的接口，但没有继承实现
//    a.func_b(10); //继承了基类的接口及实现
//
//    std::cout << std::endl;
//
//    b.func_a(10); //仅仅继承了基类的接口，但没有继承实现
//    b.func_b(10); //继承了基类的接口及实现
//
//    return 0;
//}
////上述代码里，定一个基类，里面有两个成员函数，一个是虚函数，一个是实际函数；
////然后又定义了两个子类，Base_A和Base_B，两个子类对基类中的func_b函数有不一样的实现，
////一个是加10后打印，一个是加15后打印。