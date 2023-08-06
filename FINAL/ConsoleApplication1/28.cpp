////内聚：模块内各元素彼此结合的紧密程度；
////耦合：不同模块间的依赖紧密程度。
////https://blog.csdn.net/weixin_55267022/article/details/118070794
////模块化的组织方式：将整个系统分解为若干模块，模块之间通过接口传递信息，模块划分应尽可能高内聚，低耦合。
//Cohesion and coupling are important concepts in software design that describe the relationships between modules or components of a system.A software designer aims to achieve appropriate levels of cohesion and coupling to ensure a well - designed, maintainable, and scalable software system.
//
//1. Cohesion:
//Cohesion refers to the measure of how closely the responsibilities and functionality of a module or component are related.It is a measure of how well the elements within a module work together to achieve a common purpose.High cohesion implies that a module has a clear, well - defined responsibility and contains related functions that work together to achieve that responsibility.
//
//In terms of software design, achieving high cohesion is desired as it brings several benefits :
//-Better maintainability : Modules with high cohesion are easier to understand, modify, and maintain because they are focused and have a clear purpose.
//- Reusability : Modules with high cohesion are more likely to be reusable in other parts of the system or in future projects.
//- Testability : Modules with high cohesion are easier to test as they have specific, well - defined functionality.
//
//Let's consider an example of a class that represents a shopping cart in an e-commerce system:
//
//```cpp
//class ShoppingCart {
//public:
//    void addItem(Item item);
//    void removeItem(Item item);
//    void displayCart();
//    float calculateTotalPrice();
//};
//```
//
//In this example, the `ShoppingCart` class has high cohesion because all the methods(`addItem()`, `removeItem()`, `displayCart()`, and `calculateTotalPrice()`) are related to the responsibility of managing a shopping cart.The methods work together to achieve the purpose of the class, which is to handle cart operations.
//
//2. Coupling :
//    Coupling refers to the degree of interdependence between modules or components.It measures how closely one module relies on or is connected to another module.Low coupling implies that modules are independent and can be modified or replaced without affecting other modules.
//
//    In software design, achieving low coupling is desirable as it brings several benefits :
//-Modularity : Modules can be developed and modified independently, making the system more flexible and scalable.
//- Maintainability : Changes in one module have minimal impact on other modules, making the system easier to maintain.
//- Reusability : Modules with low coupling can be reused in different contexts or systems more easily.
//
//Let's consider an example of two classes, `Customer` and `Order`, where the `Order` class depends on the `Customer` class:
//
//```cpp
//class Customer {
//public:
//    void setName(std::string name);
//    void setContactInfo(std::string contactInfo);
//    // ...
//};
//
//class Order {
//private:
//    Customer customer;
//    // ...
//public:
//    void createOrder();
//    void displayOrder();
//    // ...
//};
//```
//
//In this example, the `Order` class has a high coupling with the `Customer` class because it directly uses an instance of the `Customer` class.If changes are made to the `Customer` class (e.g., adding or removing member functions, changing data types), it may require modifications in the `Order` class as well.To achieve low coupling, we could introduce an interface or abstraction for the `Customer` class, allowing the `Order` class to depend on the interface rather than the specific implementation.
//
//In summary, a software designer aims to achieve high cohesion within individual modules or components, ensuring that their responsibilities are well - defined and related.They also aim to achieve low coupling between modules, reducing dependencies and making the system more flexible, maintainable, and reusable.These principles contribute to the overall quality and maintainability of the software system.