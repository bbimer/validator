#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <memory>

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> next;
        Node(T val) : data(val), next(nullptr) {}
    };
    std::unique_ptr<Node> topNode;

public:
    Stack() = default;

    void push(T value) {
        auto newNode = std::make_unique<Node>(value); 
        newNode->next = std::move(topNode);  
        topNode = std::move(newNode); 
    }

    void pop() {
        if (!isEmpty()) {
            topNode = std::move(topNode->next)
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
        Node* temp = topNode.get();
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next.get();
        }
        std::cout << std::endl;
    }
};

#endif // STACK_H
