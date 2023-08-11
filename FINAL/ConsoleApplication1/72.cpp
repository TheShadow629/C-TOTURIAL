
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

/*����ӿڣ�Nonvirtual Interface��NVI��ģʽ��һ�����ģʽ�����ᳫ��װ�����ƿͻ��������Ĺ����ӿڽ�����ʽ��
 *��ģʽ�����ඨ��һ������Ĺ����ӿڣ�ͬʱ��ʵ�ʵ�ʵ��ϸ�ڱ���Ϊ˽�л��ܱ����ġ�

NVI ģʽ�������¹ؼ�˼�룺

1. ��������ӿڣ����ṩһ�����Ĺ�����������Щ���������˿ͻ�������󽻻��Ľӿڡ���Щ����������Ϊ�ⲿ������ʶ����ܵ���ڵ㡣

2. ˽�л��ܱ�����ʵ�֣�ʵ�ʵ�ʵ��ϸ�ں��ڲ�����������Ϊ˽�л��ܱ����ġ��ⲿ�ͻ����޷�ֱ�ӷ������ǡ�����������ʵ�ַ�װ��
���ض�����ڲ�����ԭ��

3. ��˽�к�������˽�л��ܱ�����ʵ���У�����Զ�����˽�к�������Щ�������Ա���������д�����޸Ļ���չ�������Ϊ��
ͨ������Щ��������Ϊ�麯����������ڱ��ֶ�������Ϊ���Ƶ�ͬʱ�������ƻ����޸ġ�

NVI ģʽ�ṩ�˼����ô���

1. ��װ�ԣ�ͨ������˽�л��ܱ�����ʵ��ϸ�ڣ�NVI ģʽ�ٽ��˷�װ�ԡ��ͻ���ֻ�ܷ��ʹ����ӿڣ������˶����ڲ��ĸ����ԡ�

2. ����ԺͿ�ά���ԣ�NVI ģʽ�������ڲ�Ӱ��ͻ��˵�����¸ı��Ľ��ڲ�ʵ�֡�ֻҪ�������麯�����涨����Ϊ����һ�£�
˽�л��ܱ�����ʵ�ֿ������ɽ����޸ġ�

3. ��������Ŀ��ƣ�ͨ��������˽�к�����NVI ģʽ���������ඨ�ƶ�����Ϊ���ض����档������Ȼ���ֶ���Щ�������Ա���д
�Լ��������Ӱ�����幦�ܵĿ���Ȩ��

������һ���򻯵�ʾ����˵�� NVI ģʽ��

```cpp
class Base {
public:
    // ��������ӿ�
    void execute() {
        // ִ��ǰ������
        preExecute();

        // ����˽��ʵ��
        performExecute();

        // ִ�к�������
        postExecute();
    }

private:
    // ˽�д��麯����ʵ�ֵ�һ���֣�
    virtual void performExecute() = 0;  // ��������ʵ��

    // ����ǰ�úͺ�������ķ��麯��
    void preExecute() {
        // ...
    }

    void postExecute() {
        // ...
    }
};

class Derived : public Base {
private:
    // ��д˽���麯��
    void performExecute() override {
        // �������ض���ʵ��
        // ...
    }
};
```

�����ʾ���У�`Base` �ඨ����һ����Ϊ `execute` �Ĺ������麯������Ϊ�ͻ��˵���ڵ㡣����һ����Ϊ `performExecute`
��˽�д��麯��������ʵ��ʵ�ֵ�һ���֡������� `Derived` ��д�����˽���麯�����ṩ�Լ���ʵ�֡�

ͨ��ʹ�� NVI ģʽ��`Base` ����������ִ�����̣���������ǰ�úͺ�������ͬʱ����������ͨ����д˽���麯�������ƺ�����Ϊ��

ͨ�� NVI ģʽ���ͻ��˿���ʹ����ȷ����Ĺ����ӿ�����󽻻������ౣ����ʵ��ϸ�ڵĿ��ƣ�������δ�����޸Ļ�������Ķ��ƻ���*/