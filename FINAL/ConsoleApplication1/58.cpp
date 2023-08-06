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


/*�������ط��򡱣�Law of Demeter����Ҳ��Ϊ����֪ʶԭ��������������е����׼��ּ�ڴٽ�����Ϻ���Ϣ���ء����ݵ����ط���һ������ֻӦ������ֱ���ھӽ��н���������Ӧ���˽�����������ڲ�����������֮��Ĺ�ϵ��������ͨ�����Ĵ���ʾ�����������ط���

�������������

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

�����������У�������һ�� `Car` ���һ�� `Person` �ࡣ`Person` ����һ��ָ�� `Car` �����ָ�롣`Person` ����һ�� `drive()` ������������Ƿ�������һ������Ȼ����� `Car` ����� `getName()` ��������ʻ������

��Υ���˵����ط�����Ϊ `Person` ���˽� `Car` ������ڲ��ṹ��`getName()` ����������������� `Person` ��� `Car` ��֮��Ľ���ϣ���� `Car` ���ʵ�ַ����仯���ͻ����ά�����⡣

���ǿ����ع���������ѭ�����ط���

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

���ع���Ĵ����У�`Person` �಻���˽� `Car` ����ڲ��ṹ���෴��������ʻ����������ί�и�һ��˽�е� `driveCar()` ������`Person` ��ֻ����ֱ���ھӣ�`Car` ���󣩽��н���������¶ `Car` ����ڲ�ϸ�ڡ�

����ѭ�˵����ط�����Ϊ���ٽ�������Ϻͷ�װ������ `Car` ���ʵ�ֽ��и���ʱ��������������ϵ��Ǳ�ڵĲ���ЧӦ��`Person` ��ֻ��Ҫ֪����μ�ʻһ��������������Ҫ�˽����������ϸ�ڡ�

��ѭ�����ط��򣬴����ø�ģ�黯����ά����������������ĵײ�ʵ�ַ����仯ʱ�������׳�����������ʵ�ָ��ھۺ͵���ϵ����������ơ�*/