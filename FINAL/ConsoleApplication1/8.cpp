//word 20
//Designing or coding classes in a minimal but complete manner means creating classes that have just enough functionality to fulfill their intended purpose, without including unnecessary or extraneous features.It involves keeping the class focused, cohesive, and reusable.
//
//To provide additional functionality to a class without creating additional methods or friends of the class, we can use the concept of "composition over inheritance" and leverage other existing classes or components.We can achieve this by using composition or by utilizing existing functions and libraries within our class.
//
//Here is an example to illustrate this concept :

    // Example class with minimal but complete functionality
    class Calculator {
    private:
        int m_value;

    public:
        Calculator(int value) : m_value(value) {}

        int GetValue() const {
            return m_value;
        }

        int Add(int num) {
            m_value += num;
            return m_value;
        }
};

//In the above code, the `Calculator` class has a minimal set of methods to perform basic calculations.It has a constructor to set an initial value and methods to get the current value and to add a number to the value.
//
//Now, let's say we want to provide additional functionality to calculate the square of the value without adding a new method to the `Calculator` class. We can achieve this by utilizing the `std::pow` function from the `<cmath>` library:

#include <iostream>
#include <cmath>

int main() {
    Calculator calc(5);
    std::cout << "Initial value: " << calc.GetValue() << std::endl;

    // Additional functionality to calculate square without modifying the Calculator class
    int square = std::pow(calc.GetValue(), 2);
    std::cout << "Square: " << square << std::endl;

    return 0;
}

//In this example, we include the `<cmath > ` library and use the `std::pow` function to calculate the square of the value obtained from the `Calculator` object.By doing this, we extend the functionality of the `Calculator` class without modifying its original implementation.
//
//Regarding the usage of namespaces to manage the design, namespaces allow us to organize and group related classes, functions, or variables within a separate scope.We can create a namespace to encapsulate our classes and other related components, providing a clear and structured design.
//
//For example, we can define a namespace called `MyCalculator` to contain the `Calculator` class and any other related classes or functions :
//
    //namespace MyCalculator {
    //class Calculator {
    //    // ...
    //}

    // other related classes/functions
//}

//By using namespaces, we can avoid naming conflicts and organize our codebase more effectively, especially when dealing with larger projects or when collaborating with other developers.