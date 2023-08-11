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
/*�����麯����Ϊ�ǹ����ģ�������������Ϊ����ġ��������������������������ӿڵ�һ��ָ��ԭ����Ȼ�Ⲣ���ϸ�Ĺ��򣬵���ĳЩ�������ѭ���ԭ��������ġ�

���ָ��ԭ������ۻ����Ǵٽ���װ����Ϣ���ء�ͨ�����麯����Ϊ�ǹ����ģ����ǽ���ɼ������������νṹ�У�����ֹ�ⲿ����ֱ�ӷ��ʡ��������ƽӿ�ֻ��¶����Ĺ�����������Щ�������ⲿ��������ڵ㡣

��������ѭ���ָ��ԭ��ļ���ԭ��

1. �ӿ������ȣ�ͨ�������麯���ǹ��������ǽ����˹����ӿڵĸ����ԡ���ʹ�����ʹ���߸���������ʹ�ñ�¶�Ĺ��ܣ��������ܵ��ڲ�ʵ��ϸ�ڵĸ��š�

2. ����ԺͿ�ά���ԣ�����Ĺ�������Ϊ�ⲿ�����ṩ��һ����ȷ�������ȶ��Ľӿڡ�ֻҪ����������ָ������Ϊ����һ�£��ڲ�ʵ�ֿ��Ըı����Ӱ���ⲿ�ͻ��ˡ�

3. ��װ����Ϣ���أ��麯��ͨ����ʾʵ���ض���ϸ�ڻ�������νṹ�ڲ�������ı仯��ͨ����������Ϊ�ǹ��������Ƿ�ֹ�ⲿ������������Щʵ��ϸ�ڣ�������ϲ���߷�װ�ԡ�

4. ��̬�Կ��ƣ�ͨ�������麯���Ŀɼ��ԣ����ǿ��Ը��õؿ��ƶ�̬��Ϊ������ĳЩ����º����ã�����ĳЩ����Ҫ�����ض���Ϊ����������Ӧ����Ĭ��ʵ�֡�

Ȼ������Ҫע����ǣ����ָ��ԭ�򲢲���Ӳ�Թ涨��Ӧ�ý���Ӧ�á����ݾ�������Ҫ���Լ�����������ܴ��ڽ��麯����Ϊ�����򽫷��麯����Ϊ�������Ǻ��ʵġ����磬��ģ�巽�������������ģʽ������Ҫ�����麯����ʵ������Ķ��ƻ���

���գ��Ƿ���ѭ���ָ��ԭ��ȡ���ھ���������ġ����Ŀ���Լ����ϵͳ��Ȩ�⿼�ǡ����������������ѡ��ʱ����Ҫ���ǿ���չ�ԡ���ά���Ժʹ���ɶ��Ե����ء�*/