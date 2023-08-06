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






	//��Ϣ���أ�Information Hiding���ͳ���Abstraction�������������������ض��ֻ���֧�ֵĸ��������UML��C++ʾ���п��Ը��õز������ϵ��

	//    ������һ�ֽ����ӵ���ʵ���������Ϊ�������ʹ����ģ�͵Ĺ��̡���ͨ�����Բ���Ҫ��ϸ�ڣ�ֻ��ע�ؼ��������ṩ����ĸ�������ͼ�����������UML��ͼ��ʾ��

	//    ������һ����UML��ʾ�ĳ������ʾ����
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
		//�����ʾ���У�������һ����Ϊ`Shape`�ĳ����ࡣ��������һ������ĸ����ʾ��״�����ṩ�˼���������������`setColor()`��`getColor()`��`area()`������������ɫ����ȡ��ɫ�Լ�������״�������
		//��Ϣ������ʵ�ֳ����һ����Ҫ��������ͨ�����ƶ��ڲ�ʵ��ϸ�ڵķ���������ʵ��ϸ�ڡ���C++�У����ǿ���ʹ�÷������η���ʵ����Ϣ���ء�
		//������һ��ʹ��C++ʵ�ֵĳ��������Ϣ���ص�ʾ����

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

//����������У�`Shape`����һ�������࣬������`setColor()`��`getColor()`�ʹ��麯��`area()`�Ĺ����ӿڡ�`Circle`��̳���`Shape`�࣬��ʵ����`area()`�����Լ���Բ�������
//ͨ����Ϣ���أ�`color`��Ա����������Ϊ˽�еģ�ֻ��ͨ�������������з��ʡ��������ͻ��˴���ֻ��ͨ�������ӿ��������ͷ�����ɫ���ԡ����ַ�װ������ʵ��ϸ�ڣ�ʹ�ÿͻ��˴����޷�ֱ�ӷ��ʻ��޸�����ڲ�״̬���Ӷ����������ݵ������Ժ�һ���ԡ�
//��֮����Ϣ���غͳ������ศ��ɵĸ�������ṩ�˶�����ĸ�������ͼ������Ϣ����ͨ�����ƶ��ڲ�ʵ��ϸ�ڵķ�����ʵ�ֳ�����������������У�����һ��ٽ���ģ�黯������ԺͿ�ά���ԡ�