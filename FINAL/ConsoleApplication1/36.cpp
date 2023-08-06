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

//�����滻ԭ��Liskov Substitution Principle��LSP��ָ����
//����Ķ����ڳ�����Ӧ�ÿ��Ա�����������滻����Ӱ��������ȷ�ԡ�
//���仰˵������Ӧ���ܹ����κγ����д����䳬���������������Ϊ��
//
//������һ���򵥵�ʾ����UML��ͼ����ʾLSP��
//
//a. LSPΥ�棺
//����������У�������һ������ `Bird` ���������� `Duck` �� `Ostrich`��
//���� `Bird` ��һ����Ϊ `fly()` �ķ�����������������������б���д��
//Ȼ����`Ostrich` �಻�ܷ��У����Ե����� `fly()` ����ʱ���׳��쳣��
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
//����������£�`Ostrich` ����Υ����LSP����Ȼ���� `Bird` �����࣬���ڵ��� `fly()` ����ʱ�������쳣��
//��Υ���˳�����������Ϊ���ƻ����滻ԭ��
//
//b. LSPδΥ�棺
//��������������һ��LSPδΥ������ӡ�����������һ������ `Shape` ���������� `Rectangle` �� `Square`��
//���� `Shape` ��һ�� `calculateArea()` ������Ȼ��������������������б���д���ṩÿ����״�ľ�����������߼���
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
//����������£�`Rectangle` �� `Square` ���඼�ṩ�� `calculateArea()` ������������Ϊ��
//û��Υ���������Ϊ����չʾ��LSP����Ϊ�������������������� `Shape` �����������������⡣
//
//Υ��LSP�ĺ����
//��Υ��LSPʱ�����ܻᵼ��������Ϊ���߼�����Υ��LSP�ĺ��������
//- ���������������������ʱ��������ܲ�������ȷ�Ľ������ֳ�������Ϊ��
//- ����������ά������⣬��Ϊ�޷������ͻ��˴����г������Ϊ��
//- Υ��LSP��������ܾ������޵�����Ǳ������Ϊ�����޷��볬����������໥��ʹ�á�
//
//����һ����C++����ʾ������ʾΥ��LSP�����ӣ�
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
//����������У������ǳ����� `Ostrich` ʵ���ϵ��� `fly()` ����ʱ�����׳�һ���쳣��Υ����LSP��
//
