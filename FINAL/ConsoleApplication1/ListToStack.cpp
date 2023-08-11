#include <iostream>
#include <list>

template<typename T>
class Stack {
private:
    std::list<T> data; // 使用list容器作为底层存储结构

public:
    void push(const T& element) {
        data.push_back(element); // 将元素添加到list末尾
    }

    void pop() {
        if (!empty()) {
            data.pop_back(); // 移除list末尾的元素
        }
    }

    T& top() {
        return data.back(); // 返回list末尾的元素
    }

    bool empty() const {
        return data.empty(); // 检查list是否为空
    }

    size_t size() const {
        return data.size(); // 返回list的大小
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
