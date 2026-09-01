//
// Created by francesco on 8/27/26.
//

#ifndef DES_AED_2026_2_LINKEDLIST_H
#define DES_AED_2026_2_LINKEDLIST_H
#include <iostream>

template <typename T>
struct LinkedNode {
    T data;
    LinkedNode<T>* next;

    // Consolidated constructor with default arguments
    LinkedNode(T data = T(), LinkedNode<T>* next = nullptr) : data(data), next(next) {}
};

template <typename T>
struct LinkedList {
    LinkedNode<T>* head;
    LinkedNode<T>* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Destructor to prevent memory leaks
    ~LinkedList() {
        while (head != nullptr) {
            pop_front();
        }
    }

    void push_front(T value) {
        LinkedNode<T>* new_node = new LinkedNode<T>(value, head);
        head = new_node;
        if (tail == nullptr) {
            tail = new_node; // If list was empty, tail is also the new node
        }
    }

    void push_back(T value) {
        LinkedNode<T>* new_node = new LinkedNode<T>(value, nullptr);
        if (tail == nullptr) {
            head = tail = new_node; // If list was empty, head and tail are the new node
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void insert(LinkedNode<T>* node, T value) {
        if (!node) return;
        LinkedNode<T>* new_node = new LinkedNode<T>(value, node->next);
        node->next = new_node;
        if (node == tail) {
            tail = new_node;
        }
    }

    void insert(int pos, T value) {
        if (pos == 0) {
            push_front(value);
        } else {
            LinkedNode<T>* current = head;
            // Stop at pos - 1 to insert AFTER that node
            for (int i = 0; i < pos - 1 && current != nullptr; i++) {
                current = current->next;
            }

            if (current != nullptr) {
                insert(current, value);
            } else {
                throw std::out_of_range("Position out of bounds");
            }
        }
    }

    void pop_front() {
        if (head == nullptr) return;
        LinkedNode<T>* current = head;
        head = head->next;
        delete current;

        // If the list is now empty, ensure tail doesn't point to deleted memory
        if (head == nullptr) {
            tail = nullptr;
        }
    }

    void erase(LinkedNode<T>* node) {
        if (node != nullptr && node->next != nullptr) {
            LinkedNode<T>* to_delete = node->next;
            node->next = to_delete->next;
            if (to_delete == tail) {
                tail = node;
            }
            delete to_delete;
        }
    }

    void erase(int pos) {
        if (pos == 0) {
            pop_front();
        } else {
            LinkedNode<T>* current = head;
            // Stop at pos - 1 to erase the node AFTER it
            for (int i = 0; i < pos - 1 && current != nullptr; i++) {
                current = current->next;
            }

            if (current != nullptr && current->next != nullptr) {
                erase(current);
            } else {
                throw std::out_of_range("Position out of bounds");
            }
        }
    }

    void print() {
        LinkedNode<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif //DES_AED_2026_2_LINKEDLIST_H
