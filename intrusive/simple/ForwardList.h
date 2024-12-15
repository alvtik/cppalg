#pragma once

#include <iostream>
#include <cassert>

// List Node
struct Node {
    Node* next = nullptr; // A pointer to the next element
};

// An intrusive single-linked list
class IntrusiveList {
public:
    IntrusiveList() : head(nullptr) {}

    // Adding an item to the top of the list
    void push_front(Node* node) {
        assert(node != nullptr); // We check that the node is not null
        node->next = head;
        head = node;
    }

    // Deleting the first item in the list
    Node* pop_front() {
        if (head == nullptr) return nullptr;
        Node* node = head;
        head = head->next;
        node->next = nullptr;
        return node;
    }

    // Checking if the list is empty
    bool empty() const {
        return head == nullptr;
    }

    // Iterating through the list
    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current << " -> ";
            current = current->next;
        }
        std::cout << "null\n";
    }

private:
    Node* head; // Pointer to the first element
};

// A custom class that can be a list item
class MyData : public Node {
public:
    explicit MyData(int value) : value(value) {}
    int getValue() const { return value; }

private:
    int value; // Data
};

// Usage example
int main() {
    IntrusiveList list;

    MyData a(1), b(2), c(3);

    // Adding items to the list
    list.push_front(&a);
    list.push_front(&b);
    list.push_front(&c);

    list.print(); // List output

    // Extracting items from the list
    while (!list.empty()) {
        Node* node = list.pop_front();
        MyData* data = static_cast<MyData*>(node);
        std::cout << "Popped: " << data->getValue() << "\n";
    }

    return 0;
}