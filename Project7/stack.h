#ifndef STACK_H
#define STACK_H

#include <iostream>

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val, Node* ptr = nullptr) : data(val), next(ptr) {}
    };
    Node* topNode;

public:
    Stack() : topNode(nullptr) {}
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(T value) {
        topNode = new Node(value, topNode);
    }

    void pop() {
        if (!isEmpty()) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    T top() const {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        return topNode->data;
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }

    void print() const {
        Node* temp = topNode;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

#endif // STACK_H
