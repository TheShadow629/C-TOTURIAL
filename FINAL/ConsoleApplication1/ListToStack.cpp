#include <iostream>
#include <list>

template<typename T>
class Stack {
private:
    std::list<T> data; // ʹ��list������Ϊ�ײ�洢�ṹ

public:
    void push(const T& element) {
        data.push_back(element); // ��Ԫ����ӵ�listĩβ
    }

    void pop() {
        if (!empty()) {
            data.pop_back(); // �Ƴ�listĩβ��Ԫ��
        }
    }

    T& top() {
        return data.back(); // ����listĩβ��Ԫ��
    }

    bool empty() const {
        return data.empty(); // ���list�Ƿ�Ϊ��
    }

    size_t size() const {
        return data.size(); // ����list�Ĵ�С
    }
};

int main() {
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Stack size: " << stack.size() << std::endl;
    std::cout << "Top element: " << stack.top() << std::endl;

    stack.pop();

    std::cout << "Stack size: " << stack.size() << std::endl;
    std::cout << "Top element: " << stack.top() << std::endl;

    return 0;
}
