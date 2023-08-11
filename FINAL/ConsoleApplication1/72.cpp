
/*The Nonvirtual Interface (NVI) pattern is a design pattern that promotes encapsulation and controls the
 *way clients interact with an object's public interface. It allows the class to define a nonvirtual public
 *interface, while keeping the actual implementation details private or protected.

The NVI pattern consists of the following key ideas:

1. Public nonvirtual interface: The class provides a set of nonvirtual public functions that define the
interface through which clients interact with the object. These functions serve as entry points for external
code to access the object's functionality.

2. Private or protected implementation: The actual implementation details and internal functions are kept
private or protected. They are not directly accessible to external clients. This enforces encapsulation and
hides the internal workings of the object.

3. Virtual private functions: Within the private or protected implementation, the class can define virtual
private functions. These functions can be overridden by derived classes to modify or extend the behavior of
the object. By making these functions virtual, the class allows customization while maintaining control over
the overall behavior.

The NVI pattern provides several benefits:

1. Encapsulation: By keeping the private or protected implementation details hidden, the NVI pattern promotes
encapsulation. Clients can only access the public interface, which shields them from the internal complexities
of the object.

2. Flexibility and maintainability: The NVI pattern allows the class to change or improve the internal
implementation without affecting the clients. As long as the behavior specified by the public nonvirtual
functions remains consistent, modifications to the private or protected implementation can be made freely.

3. Control over derived classes: By defining virtual private functions, the NVI pattern allows derived
classes to customize certain aspects of the object's behavior. The base class retains control over which
functions can be overridden and how they influence the overall functionality.

Here is a simplified example to illustrate the NVI pattern:

```cpp
class Base {
public:
    // Public nonvirtual interface
    void execute() {
        // Perform pre-operation tasks
        preExecute();

        // Call the private implementation
        performExecute();

        // Perform post-operation tasks
        postExecute();
    }

private:
    // Private virtual function (part of the implementation)
    virtual void performExecute() = 0;  // to be implemented by derived classes

    // Nonvirtual functions for pre- and post-operation tasks
    void preExecute() {
        // ...
    }

    void postExecute() {
        // ...
    }
};

class Derived : public Base {
private:
    // Override the private virtual function
    void performExecute() override {
        // Derived class-specific implementation
        // ...
    }
};
```

In this example, the `Base` class defines a public nonvirtual function called `execute`, which serves as
the entry point for clients. The class has a private pure virtual function called `performExecute`, which
is part of the private implementation. The derived class `Derived` overrides this private virtual function to
provide its own implementation.

By using the NVI pattern, the `Base` class controls the overall execution flow and defines the pre- and
post-operation tasks while allowing derived classes to customize the core behavior by overriding the private
virtual function.

Through the NVI pattern, clients can interact with objects using a well-defined public interface, while
the class retains control over the implementation details and allows for future modifications or customization
by derived classes.*/

/*非虚接口（Nonvirtual Interface，NVI）模式是一种设计模式，它提倡封装并控制客户端与对象的公共接口交互方式。
 *该模式允许类定义一个非虚的公共接口，同时将实际的实现细节保持为私有或受保护的。

NVI 模式包括以下关键思想：

1. 公共非虚接口：类提供一组非虚的公共函数，这些函数定义了客户端与对象交互的接口。这些函数可以作为外部代码访问对象功能的入口点。

2. 私有或受保护的实现：实际的实现细节和内部函数被保持为私有或受保护的。外部客户端无法直接访问它们。这样做可以实现封装，
隐藏对象的内部工作原理。

3. 虚私有函数：在私有或受保护的实现中，类可以定义虚私有函数。这些函数可以被派生类重写，以修改或扩展对象的行为。
通过将这些函数定义为虚函数，类可以在保持对整体行为控制的同时，允许定制化的修改。

NVI 模式提供了几个好处：

1. 封装性：通过隐藏私有或受保护的实现细节，NVI 模式促进了封装性。客户端只能访问公共接口，屏蔽了对象内部的复杂性。

2. 灵活性和可维护性：NVI 模式允许类在不影响客户端的情况下改变或改进内部实现。只要公共非虚函数所规定的行为保持一致，
私有或受保护的实现可以自由进行修改。

3. 对派生类的控制：通过定义虚私有函数，NVI 模式允许派生类定制对象行为的特定方面。基类仍然保持对哪些函数可以被重写
以及它们如何影响整体功能的控制权。

以下是一个简化的示例来说明 NVI 模式：

```cpp
class Base {
public:
    // 公共非虚接口
    void execute() {
        // 执行前置任务
        preExecute();

        // 调用私有实现
        performExecute();

        // 执行后置任务
        postExecute();
    }

private:
    // 私有纯虚函数（实现的一部分）
    virtual void performExecute() = 0;  // 由派生类实现

    // 用于前置和后置任务的非虚函数
    void preExecute() {
        // ...
    }

    void postExecute() {
        // ...
    }
};

class Derived : public Base {
private:
    // 重写私有虚函数
    void performExecute() override {
        // 派生类特定的实现
        // ...
    }
};
```

在这个示例中，`Base` 类定义了一个名为 `execute` 的公共非虚函数，作为客户端的入口点。类有一个名为 `performExecute`
的私有纯虚函数，它是实际实现的一部分。派生类 `Derived` 重写了这个私有虚函数以提供自己的实现。

通过使用 NVI 模式，`Base` 类控制整体的执行流程，并定义了前置和后置任务，同时允许派生类通过重写私有虚函数来定制核心行为。

通过 NVI 模式，客户端可以使用明确定义的公共接口与对象交互，而类保留对实现细节的控制，并允许未来的修改或派生类的定制化。*/