//1. �ػ���Specialisation��ʾ����
//����һ��ͼ���ࣨShape����һ�������ࣨRectangle����������һ���������͵�ͼ�Σ���˾���������ػ�Ϊͼ��������ࡣ�������ػ���ϵ��ʾ����
//
//```
//+------------+
//|   Shape    |
//+------------+
//|            |
//|            |
//|            |
//+------+-----+
//|      ^
//|      |
//|      |
//|      |
//|      |
//|      |
//| +---------+
//| | Rectangle|
//| +---------+
//```
//
//�����ʾ���У���������ͼ��������࣬���̳���ͼ��������Ժͷ��������ҿ�������ض��ھ��ε����Ժͷ�����
//
//2. ʵ�֣�Realisation��ʾ����
//����һ�����нӿڣ�Flyable����һ�����ࣨBird��������Է��У�����������ʵ�ַ��нӿڡ�������ʵ�ֹ�ϵ��ʾ����
//
//```
//+-----------------+
//|    Flyable      |
//+-----------------+
//|                 |
//| +---------------+
//| |   Bird        |
//| +---------------+
//```
//
//�����ʾ���У�����ʵ���˷��нӿڣ���ζ����������ṩ�˷��нӿ��ж�������з�����
//
//�ܽ᣺
//�ػ���ϵ��ʾһ��������һ������������ͣ���ʵ�ֹ�ϵ��ʾһ����ʵ����һ���ӿڡ��ػ���ϵ����֮���γɼ̳в�νṹ����ʵ�ֹ�ϵʹ������ӿڵ�Ҫ��

//1. �ػ���Specialisation��ʾ�����룺

#include <iostream>
#include <ostream>

// ���� Shape
class Shape {
public:
    double CalculateArea() { return 0; };
};

// ������ Rectangle���ػ�Ϊ Shape ������
class Rectangle : public Shape {
private:
    double m_width;
    double m_height;

public:
    Rectangle(double width, double height) : m_width(width), m_height(height) {}

    double CalculateArea()  {  return m_width * m_height; }
};


//�����ʾ���У����� `Shape` ��һ�������࣬������һ�����麯�� `CalculateArea`�������� `Rectangle` �ػ�Ϊ `Shape` �����࣬��ʵ���� `CalculateArea` ������

//2. ʵ�֣�Realisation��ʾ�����룺

// ���нӿ� Flyable
class Flyable {
public:
    virtual void Fly() = 0;

};

// ���� Bird��ʵ���˷��нӿ�
class Bird : public Flyable {
public:
    void Fly() override {//�Խӿ��麯�����и�д
        // ��ķ���ʵ��
        std::cout << "Bird is flying." << std::endl;
    }
};

//�����ʾ���У����нӿ� `Flyable` ��һ������ӿڣ������˴��麯�� `Fly`���� `Bird` ʵ���� `Flyable` �ӿڣ�����ʵ�ֲ��ṩ `Fly` �����ľ���ʵ�֡�

//�ػ���ϵͨ����ļ̳���ʵ�֣���ʵ�ֹ�ϵͨ����ʵ�ֽӿ���ʵ�֡����ֹ�ϵ��ʹ�ÿ��Ը��ݾ�����������������ѡ��
//file:///C:/Users/laptop/Desktop/LabExc-1-ass/PPT/4-32.pdf 302


int main()
{
    // ���� Rectangle ����
    Rectangle rectangle(5.0, 3.0);

    // ���� CalculateArea ����������������
    double area = rectangle.CalculateArea();
    std::cout << "Rectangle area: " << area << std::endl;

    // ���� Bird ����
    Bird bird;

    // ���� Fly �����������
    bird.Fly();

    return 0;
}


//#include <iostream>       // std::cout
//
//class Base {
//
//public:
//    Base() {};
//    virtual void func_a(int a) = 0; //������麯��������ֻ�̳нӿڣ������ʵ�֣�������ȥʵ��
//    void func_b(int b) { std::cout << b + 10 << "\n"; }; //�����ʵ��������ӿں�ʵ�֣����ᱻ����̳�
//};
//
//class Base_A : public Base {
//public:
//    void func_a(int a) { std::cout << a << "\n"; };
//};
//
//class Base_B : public Base {
//public:
//    void func_a(int a) { std::cout << a + 15 << "\n"; };
//};
//
//int main()
//{
//    Base_A a;
//    Base_B b;
//
//    a.func_a(10); //�����̳��˻���Ľӿڣ���û�м̳�ʵ��
//    a.func_b(10); //�̳��˻���Ľӿڼ�ʵ��
//
//    std::cout << std::endl;
//
//    b.func_a(10); //�����̳��˻���Ľӿڣ���û�м̳�ʵ��
//    b.func_b(10); //�̳��˻���Ľӿڼ�ʵ��
//
//    return 0;
//}
////�����������һ�����࣬������������Ա������һ�����麯����һ����ʵ�ʺ�����
////Ȼ���ֶ������������࣬Base_A��Base_B����������Ի����е�func_b�����в�һ����ʵ�֣�
////һ���Ǽ�10���ӡ��һ���Ǽ�15���ӡ��