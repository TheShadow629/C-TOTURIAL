//The Liskov Substitution Principle (LSP) states that objects of a superclass should be replaceable with objects of its subclasses without affecting the correctness of the program. In other words, a subclass should be able to substitute its superclass in any program without causing unexpected behavior.
//
//To demonstrate the LSP, let's consider a simple example using UML class diagrams:
//
//a. Violation of LSP:
//In this example, we have a superclass `Bird` and two subclasses `Duck` and `Ostrich`. The `Bird` superclass has a method called `fly()`, which is overridden in both subclasses. However, the `Ostrich` class cannot fly, so it throws an exception when the `fly()` method is called.
//
//```
//_________________        __________________
//|      Bird     |        |      Duck      |
//|---------------|        |----------------|
//|               |        |                |
//|   + fly()     | <----  |   + fly()      |
//-----------------        ------------------
//         ^
//         |
//------------------
//|   Ostrich    |
//|--------------|
//|              |
//|   + fly()    |
//------------------
//```
//
//In this case, the `Ostrich` subclass violates the LSP. While it is a subclass of `Bird`, it throws an exception when the `fly()` method is called. This violates the behavior expected from the superclass and breaks the substitution principle.
//
//b. Non-violation of LSP:
//Now let's consider an example where the LSP is not violated. Suppose we have a superclass `Shape` and two subclasses `Rectangle` and `Square`. The `Shape` superclass has a method `calculateArea()`, which is then overridden in both subclasses to provide the specific area calculation for each shape.

//________________       ___________________
//|     Shape    |       |     Rectangle     |
//|--------------|       |------------------|
//|              |       |                  |
//| + calculateArea() | <---- |  + calculateArea() |
//------------------       -------------------
//        ^                     ^
//        |                     |
//------------------       -----------------
//|     Square    |       |    Circle     |
//|--------------|       |---------------|
//|              |       |               |
//| + calculateArea() | <----- | + calculateArea() |
//------------------       ------------------
//
//In this case, both subclasses `Rectangle` and `Square` provide the expected behavior for the `calculateArea()` method without breaking or violating the superclass's behavior. This demonstrates the LSP as both subclasses can be substituted for the superclass `Shape` without causing unexpected issues.
//
//Consequences of violating LSP:
//When LSP is violated, it can lead to unexpected behavior and logical errors in the code. The consequences can include:
//- The program may produce incorrect results or behave unexpectedly when substituting objects of a subclass for objects of a superclass.
//- The code becomes less maintainable and harder to reason about, as the behavior of the superclass cannot be relied upon by the client code.
//- Subclasses that violate LSP may have limited reuse potential since they cannot be used interchangeably with the superclass or other subclasses.
//
//Here's a C++ code example to demonstrate the violation of LSP:

#include <iostream>

class Bird {
public:
    virtual void fly() {
        std::cout << "Bird is flying..." << std::endl;
    }
};

class Duck : public Bird {
public:
    void fly() override {
        std::cout << "Duck is flying..." << std::endl;
    }
};

class Ostrich : public Bird {
public:
    void fly() override {
        throw std::runtime_error("Ostrich cannot fly!");
    }
};


int main() {
    Bird* bird = new Ostrich();
    bird->fly();

    delete bird;
    return 0;
}

//In this example, when we try to call the `fly()` method on an instance of `Ostrich`,
//it throws an exception, violating the LSP.

//里氏替换原则（Liskov Substitution Principle，LSP）指出，
//超类的对象在程序中应该可以被其子类对象替换而不影响程序的正确性。
//换句话说，子类应该能够在任何程序中代替其超类而不引起意外行为。
//
//我们用一个简单的示例和UML类图来演示LSP：
//
//a. LSP违规：
//在这个例子中，我们有一个超类 `Bird` 和两个子类 `Duck` 和 `Ostrich`。
//超类 `Bird` 有一个名为 `fly()` 的方法，这个方法在两个子类中被重写。
//然而，`Ostrich` 类不能飞行，所以当调用 `fly()` 方法时会抛出异常。
//
//```
//_________________        __________________
//|      Bird     |        |      Duck      |
//|---------------|        |----------------|
//|               |        |                |
//|   + fly()     | <----  |   + fly()      |
//-----------------        ------------------
//         ^
//         |
//------------------
//|   Ostrich    |
//|--------------|
//|              |
//|   + fly()    |
//------------------
//```
//
//在这种情况下，`Ostrich` 子类违反了LSP。虽然它是 `Bird` 的子类，但在调用 `fly()` 方法时会引发异常。
//这违反了超类期望的行为，破坏了替换原则。
//
//b. LSP未违规：
//现在我们来考虑一个LSP未违规的例子。假设我们有一个超类 `Shape` 和两个子类 `Rectangle` 和 `Square`。
//超类 `Shape` 有一个 `calculateArea()` 方法，然后这个方法在两个子类中被重写以提供每种形状的具体面积计算逻辑。
//
//```
//________________       ___________________
//|     Shape    |       |     Rectangle     |
//|--------------|       |------------------|
//|              |       |                  |
//| + calculateArea() | <---- |  + calculateArea() |
//------------------       -------------------
//        ^                     ^
//        |                     |
//------------------       -----------------
//|     Square    |       |    Circle     |
//|--------------|        |---------------|
//|              |        |               |
//| + calculateArea() | <----- | + calculateArea() |
//------------------       ------------------
//```
//
//在这种情况下，`Rectangle` 和 `Square` 子类都提供了 `calculateArea()` 方法的期望行为，
//没有违反超类的行为。这展示了LSP，因为这两个子类可以替代超类 `Shape` 而不会引发意外问题。
//
//违反LSP的后果：
//当违反LSP时，可能会导致意外行为和逻辑错误。违反LSP的后果包括：
//- 当用子类对象替代超类对象时，程序可能产生不正确的结果或表现出意外行为。
//- 代码变得难以维护和理解，因为无法依赖客户端代码中超类的行为。
//- 违反LSP的子类可能具有受限的重用潜力，因为它们无法与超类或其他子类互换使用。
//
//这是一个用C++代码示例来演示违反LSP的例子：
//
//```cpp
//#include <iostream>
//
//class Bird {
//public:
//    virtual void fly() {
//        std::cout << "Bird is flying..." << std::endl;
//    }
//};
//
//class Duck : public Bird {
//public:
//    void fly() override {
//        std::cout << "Duck is flying..." << std::endl;
//    }
//};
//
//class Ostrich : public Bird {
//public:
//    void fly() override {
//        throw std::runtime_error("Ostrich cannot fly!");
//    }
//};
//
//
//int main() {
//    Bird* bird = new Ostrich();
//    bird->fly();
//
//    delete bird;
//    return 0;
//}
//```
//
//在这个例子中，当我们尝试在 `Ostrich` 实例上调用 `fly()` 方法时，它抛出一个异常，违反了LSP。
//
