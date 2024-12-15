#pragma once

#include <iostream>
#include <cassert>

// A node of a doubly linked list
struct Node {
    Node* prev = nullptr; // A pointer to the previous element
    Node* next = nullptr; // A pointer to the next element
};

// An intrusive doubly linked list
class IntrusiveDoublyLinkedList {
public:
    IntrusiveDoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Adding an item to the end of the list
    void push_back(Node* node) {
        assert(node != nullptr); // The node must not be null
        if (tail) {
            tail->next = node;
            node->prev = tail;
            tail = node;
        } else {
            head = tail = node;
        }
        node->next = nullptr; // End of the list
    }

    // Adding an item to the top of the list
    void push_front(Node* node) {
        assert(node != nullptr); // The node must not be null
        if (head) {
            head->prev = node;
            node->next = head;
            head = node;
        } else {
            head = tail = node;
        }
        node->prev = nullptr; // The beginning of the list
    }

    // Removing an item from the list
    void remove(Node* node) {
        assert(node != nullptr); // The node must not be null
        if (node->prev) {
            node->prev->next = node->next;
        } else {
            head = node->next; // Removing the head
        }

        if (node->next) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev; // Removing the tail
        }

        node->prev = nullptr;
        node->next = nullptr;
    }

    // Iteration through the list (in direct order)
    void print_forward() const {
        Node* current = head;
        while (current) {
            std::cout << current << " -> ";
            current = current->next;
        }
        std::cout << "null\n";
    }

    // Iterating through the list (reverse order)
    void print_backward() const {
        Node* current = tail;
        while (current) {
            std::cout << current << " -> ";
            current = current->prev;
        }
        std::cout << "null\n";
    }

private:
    Node* head; // Pointer to the first element
    Node* tail; // A pointer to the last element
};

// A custom class that can be a list item
class MyData : public Node {
public:
    explicit MyData(int value) : value(value) {}
    int getValue() const { return value; }

private:
    int value; // Node Data
};

// Usage example
int main() {
    IntrusiveDoublyLinkedList list;

    MyData a(1), b(2), c(3), d(4);

    // Adding items to the list
    list.push_back(&a);
    list.push_back(&b);
    list.push_back(&c);
    list.push_front(&d);

    // Printing a list
    std::cout << "Forward: ";
    list.print_forward();

    std::cout << "Backward: ";
    list.print_backward();

    // Deleting an element
    list.remove(&b);

    std::cout << "After removing element b:\n";
    std::cout << "Forward: ";
    list.print_forward();

    std::cout << "Backward: ";
    list.print_backward();

    return 0;
}
