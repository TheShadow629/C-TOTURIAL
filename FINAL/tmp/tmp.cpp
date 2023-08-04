#include <iostream>

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        clear();
    }

    bool isEmpty() const {
        return (head == nullptr);
    }

    void insertFront(const T& data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertBack(const T& data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void removeFront() {
        if (!isEmpty()) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
        }
    }

    void removeBack() {
        if (!isEmpty()) {
            if (head == tail) {
                delete head;
                head = tail = nullptr;
            }
            else {
                Node* temp = head;
                while (temp->next != tail) {
                    temp = temp->next;
                }
                delete tail;
                tail = temp;
                tail->next = nullptr;
            }
        }
    }

    void clear() {
        while (!isEmpty()) {
            removeFront();
        }
    }
};

int main()
{
    LinkedList<int> list;
    list.insertBack(10);
    list.insertBack(20);
    list.insertFront(5);
    list.removeBack();
    list.removeFront();
}