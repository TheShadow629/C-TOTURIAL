//The "Law of Demeter" (LoD), also known as the principle of least knowledge,
//is a design guideline in object - oriented programming that promotes loose
//coupling and information hiding.According to the LoD, an object should only
//interact with its immediate neighbors, and not have knowledge of the inner
//workings of other objects or their relationships.Let's understand the LoD
//with C++ code examples.
//
//Consider the following scenario :

#include <iostream>
#include <string>

class Car {
public:
	std::string getName() const { return "Car"; }
};

class Person {
private:
    Car* car;
public:
    Person() : car(nullptr) {}
    void setCar(Car* c) { car = c; }
    void drive() {
        if (car != nullptr) {
	        std::cout << "Driving " << car->getName() << std::endl;
        }
    }
};

int main() {
    Car car;
    Person person;
    person.setCar(&car);
    person.drive();
    return 0;
}

//In the above code, we have a `Car` class and a `Person` class.The `Person` class
//has a pointer to a `Car` object.The `Person` class has a `drive()` method that
//checks if a car is set and then calls `getName()` method of the `Car` object to drive it.
//This violates the Law of Demeter because the `Person` class has knowledge of the
//internal structure(`getName()`) of the `Car` object.It creates a tight coupling between `Person` and `Car` classes, which can lead to maintenance issues if the implementation of the `Car` class changes.
//We can refactor the code to adhere to the Law of Demeter :

class Car {
public:
	std::string getName() const { return "Car"; }
};

class Person {
private:
    Car* car;
public:
    Person() : car(nullptr) {}
    void setCar(Car* c) { car = c; }
    void drive() {
        if (car != nullptr) {
            driveCar();
        }
    }
private:
    void driveCar() {
	    std::cout << "Driving " << car->getName() << std::endl;
    }
};

int main() {
    Car car;
    Person person;
    person.setCar(&car);
    person.drive();
    return 0;
}

//In the refactored code, the `Person` class no longer has knowledge of the `Car` class's internal structure.
//Instead, it delegates the responsibility of driving the car to a private `driveCar()` method. The `Person`
//class only interacts with its immediate neighbor (`Car` object) and does not expose the internal details of
//the `Car` class.
//This adheres to the Law of Demeter because it promotes loose coupling and encapsulation.It reduces the
//dependencies and potential ripple effects when making changes to the implementation of the `Car` class.
//The `Person` class only needs to know how to drive a car, not the details of the car itself.
//By following the Law of Demeter, code becomes more modular, maintainable, and less prone to breaking with
//changes in the underlying implementation of other classes.It helps to achieve high cohesion and low coupling
//in object - oriented design.


/*“德米特法则”（Law of Demeter），也称为最少知识原则，是面向对象编程中的设计准则，旨在促进松耦合和信息隐藏。根据德米特法则，一个对象只应该与其直接邻居进行交互，而不应该了解其他对象的内部工作或它们之间的关系。让我们通过中文代码示例来理解德米特法则。

考虑以下情况：

class Car {
public:
    string getName() const { return "Car"; }
};

class Person {
private:
    Car* car;
public:
    Person() : car(nullptr) {}
    void setCar(Car* c) { car = c; }
    void drive() {
        if (car != nullptr) {
            cout << "Driving " << car->getName() << endl;
        }
    }
};

int main() {
    Car car;
    Person person;
    person.setCar(&car);
    person.drive();
    return 0;
}
```

在上述代码中，我们有一个 `Car` 类和一个 `Person` 类。`Person` 类有一个指向 `Car` 对象的指针。`Person` 类有一个 `drive()` 方法，它检查是否设置了一辆车，然后调用 `Car` 对象的 `getName()` 方法来驾驶车辆。

这违反了德米特法则，因为 `Person` 类了解 `Car` 对象的内部结构（`getName()` 方法）。这样会造成 `Person` 类和 `Car` 类之间的紧耦合，如果 `Car` 类的实现发生变化，就会产生维护问题。

我们可以重构代码以遵循德米特法则：

```cpp
class Car {
public:
    string getName() const { return "Car"; }
};

class Person {
private:
    Car* car;
public:
    Person() : car(nullptr) {}
    void setCar(Car* c) { car = c; }
    void drive() {
        if (car != nullptr) {
            driveCar();
        }
    }
private:
    void driveCar() {
        cout << "Driving " << car->getName() << endl;
    }
};

int main() {
    Car car;
    Person person;
    person.setCar(&car);
    person.drive();
    return 0;
}
```

在重构后的代码中，`Person` 类不再了解 `Car` 类的内部结构。相反，它将驾驶车辆的责任委托给一个私有的 `driveCar()` 方法。`Person` 类只与其直接邻居（`Car` 对象）进行交互，不暴露 `Car` 类的内部细节。

这遵循了德米特法则，因为它促进了松耦合和封装。当对 `Car` 类的实现进行更改时，减少了依赖关系和潜在的波及效应。`Person` 类只需要知道如何驾驶一辆汽车，而不需要了解汽车本身的细节。

遵循德米特法则，代码变得更模块化、可维护，并且在其他类的底层实现发生变化时更不容易出错。它有助于实现高内聚和低耦合的面向对象设计。*/