//Information hiding and abstraction are closely related concepts in software engineering.Abstraction involves representing complex real - world entities as simplified models.It aims to capture the essential characteristics and behavior of an entity while hiding unnecessary details.Information hiding, on the other hand, is a technique used to implement abstraction by encapsulating implementation details and revealing only the necessary information through a well - defined interface.
//
//To illustrate the relationship between information hiding and abstraction, let's consider an example of a simple banking system.
//
//1. Abstraction : In the UML diagram, we can use classes to represent the abstraction.For example, we can have a `BankAccount` class that abstracts the concept of a bank account.It will define the essential characteristics and behaviors of a bank account, such as `balance`, `deposit()`, and `withdraw()`. The UML class diagram will show the public interface of the class, hiding the internal implementation details.
//
//![UML Diagram](https ://i.imgur.com/r3k9tsY.png)
//
//    2. Information Hiding : In C++, we can implement information hiding by using access modifiers to control the visibility of members.The public interface of the `BankAccount` class will be accessible to the clients, while the private members will be hidden.

#include <iostream>
#include <string>

	// BankAccount.h
class BankAccount {
public:
	void deposit(double amount);
	void withdraw(double amount);
	double getBalance();

private:
	double balance;
};
//
//In the above C++ example, the public methods `deposit()`, `withdraw()`, and `getBalance()` are part of the public interface,
//while the `balance` data member is private.Clients interacting with the `BankAccount` object can only access the public
//methods and have no direct access to the private `balance` member.
//
//The combination of information hiding and abstraction allows clients to work with simplified and well - defined interfaces
//while hiding the internal implementation details.Changes made to the implementation of the `BankAccount` class, such as
//modifying the data structure or adding validations, will not affect the clients as long as the public interface remains
//unchanged.This allows for flexibility, maintainability, and code evolution without breaking client code.
//
//In summary, abstraction provides a conceptual model of an entity, while information hiding enables the implementation of
//that abstraction by hiding internal details and exposing a well - defined interface.Together, they promote modular design,
//code reuse, and separation of concerns in software development.






	//信息隐藏（Information Hiding）和抽象（Abstraction）是软件开发中两个相关而又互相支持的概念。它们在UML和C++示例中可以更好地阐明其关系。

	//    抽象是一种将复杂的现实世界问题简化为易于理解和处理的模型的过程。它通过忽略不必要的细节，只关注关键部分来提供问题的概念性视图。抽象可以用UML类图表示。

	//    下面是一个用UML表示的抽象类的示例：
		//```
		//+ ------------------------------------------ +
		//| Shape |
		//+------------------------------------------ +
		//| -color: string                           |
		//| +setColor(color : string) : void           |
		//| +getColor() : string                      |
		//| +area() : double |
		//+------------------------------------------ +
		//```
		//在这个示例中，我们有一个名为`Shape`的抽象类。它定义了一个抽象的概念，表示形状，并提供了几个公共方法，如`setColor()`、`getColor()`和`area()`，用于设置颜色、获取颜色以及计算形状的面积。
		//信息隐藏是实现抽象的一种重要技术，它通过限制对内部实现细节的访问来隐藏实现细节。在C++中，我们可以使用访问修饰符来实现信息隐藏。
		//以下是一个使用C++实现的抽象类和信息隐藏的示例：

class Shape {
private:
	std::string color;

public:
	void setColor(std::string c) {
		color = c;
	}

	std::string getColor() {
		return color;
	}

	virtual double area() = 0;
};

class Circle : public Shape {
private:
	double radius;

public:
	Circle(double r) : radius(r) {}

	double area() {
		return 3.14 * radius * radius;
	}
};

int main() {
	Circle c(5);
	c.setColor("Red");
	std::cout << "Area of the circle: " << c.area() << std::endl;
	std::cout << "Color of the circle: " << c.getColor() << std::endl;

	return 0;
}

//在这个例子中，`Shape`类是一个抽象类，定义了`setColor()`、`getColor()`和纯虚函数`area()`的公共接口。`Circle`类继承自`Shape`类，并实现了`area()`方法以计算圆的面积。
//通过信息隐藏，`color`成员变量被声明为私有的，只能通过公共方法进行访问。这样，客户端代码只能通过公共接口来操作和访问颜色属性。这种封装隐藏了实现细节，使得客户端代码无法直接访问或修改类的内部状态，从而保护了数据的完整性和一致性。
//总之，信息隐藏和抽象是相辅相成的概念。抽象提供了对问题的概念性视图，而信息隐藏通过限制对内部实现细节的访问来实现抽象。在软件开发过程中，它们一起促进了模块化、灵活性和可维护性。