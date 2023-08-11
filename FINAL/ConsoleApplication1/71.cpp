//The rule "Consider making virtual functions nonpublic, and public functions nonvirtual" is a guideline that suggests a default approach for designing class interfaces in object - oriented programming.While it may not be a strict rule, it can be beneficial to follow in certain situations.
//
//The rationale behind this guideline is to promote encapsulation and information hiding.By making virtual functions nonpublic, we limit their visibility to the class hierarchy and prevent them from being directly accessed by external code.This restricts the interface to only expose nonvirtual public functions, which are the intended entry points for external interactions.
//
//Here are a few reasons why it might make sense to follow this guideline :
//
//	1. Interface clarity : By keeping virtual functions nonpublic, we reduce the complexity of the public interface.This makes it easier for clients of the class to understand and use the exposed functionality without being concerned about the internal implementation details.
//
//	2. Flexibility and maintainability : Nonvirtual public functions provide a well - defined and stable interface for external code.This allows the internal implementation to change without affecting the external clients, as long as the behavior specified by the public functions remains consistent.
//
//	3. Encapsulation and information hiding : Virtual functions often represent implementation - specific details or variations that are relevant only within the class hierarchy.By making them nonpublic, we prevent external code from relying on these implementation details, reducing coupling and improving encapsulation.
//
//	4. Polymorphism control : By limiting the visibility of virtual functions, we can have more control over the polymorphic behavior.This can be useful in scenarios where certain classes in the hierarchy need to override specific behaviors, while others should retain the default implementation.
//
//	However, it is important to note that this guideline is not a hard rule and should be applied judiciously.There may be cases where making virtual functions public or nonvirtual functions virtual could be appropriate based on the specific design requirements and constraints.Design patterns like the Template Method may require public virtual functions to enable subclass customization, for example.
//
//	Ultimately, the decision to follow this guideline depends on the specific context, design goals,
//	and trade - offs of the software system being developed.It is essential to consider factors such as
//	extensibility, maintainability, and code readability when making such design choices.

//https://www.jianshu.com/p/3f6ce67002d4
/*“将虚函数设为非公共的，将公共函数设为非虚的”这个规则是面向对象编程中设计类接口的一项指导原则。虽然这并非严格的规则，但在某些情况下遵循这个原则是有益的。

这个指导原则的理论基础是促进封装和信息隐藏。通过将虚函数设为非公共的，我们将其可见性限制在类层次结构中，并防止外部代码直接访问。这样限制接口只暴露非虚的公共函数，这些函数是外部交互的入口点。

以下是遵循这个指导原则的几个原因：

1. 接口清晰度：通过保持虚函数非公共，我们降低了公共接口的复杂性。这使得类的使用者更容易理解和使用暴露的功能，而不会受到内部实现细节的干扰。

2. 灵活性和可维护性：非虚的公共函数为外部代码提供了一个明确定义且稳定的接口。只要公共函数所指定的行为保持一致，内部实现可以改变而不影响外部客户端。

3. 封装和信息隐藏：虚函数通常表示实现特定的细节或仅在类层次结构内部有意义的变化。通过将它们设为非公共，我们防止外部代码依赖于这些实现细节，减少耦合并提高封装性。

4. 多态性控制：通过限制虚函数的可见性，我们可以更好地控制多态行为。这在某些情况下很有用，其中某些类需要覆盖特定行为，而其他类应保留默认实现。

然而，需要注意的是，这个指导原则并不是硬性规定，应该谨慎应用。根据具体的设计要求和约束条件，可能存在将虚函数设为公共或将非虚函数设为虚的情况是合适的。例如，像“模板方法”这样的设计模式可能需要公共虚函数以实现子类的定制化。

最终，是否遵循这个指导原则取决于具体的上下文、设计目标以及软件系统的权衡考虑。在做出这样的设计选择时，需要考虑可扩展性、可维护性和代码可读性等因素。*/