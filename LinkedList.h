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
    LinkedNode() {next = nullptr;}
    LinkedNode(T data, LinkedNode<T>* next): data(data), next(next) {}
};

template <typename T>
struct LinkedList {
    LinkedNode<T>* head;
    LinkedNode<T>* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push_front(T value) {
        LinkedNode<T>* new_node = new LinkedNode<T>(value);
        if (head == nullptr) tail = new_node;
        head->next = new_node;
        head = new_node;
    }

    void push_back(T value) {
        LinkedNode<T>* new_node = new LinkedNode<T>(value);
        if (tail == nullptr) head = new_node;
        tail->next = new_node;
        tail = new_node;
    }

    void insert(LinkedNode<T>* node, T value) {
        LinkedNode<T>* new_node = new LinkedNode<T>(value, node->next);
        if (node == tail) tail = new_node;
        node->next = new_node;
    }

    void insert(int pos, T value) {
        if (pos == 0) push_front(value);
        else {
            LinkedNode<T>* current = head;
            for (int i = 0; i < pos; i++) {
                current = current->next;
            }
            insert(current, value);
        }
    }

    void pop_front() {
        if (head == nullptr) return;
        LinkedNode<T>* current = head;
        head = head->next;
        delete current;
    }

    void erase(LinkedNode<T>* node) {
        if (node->next) {
            LinkedNode<T>* current = node->next;
            if (current == tail) tail = node;
            node->next = node->next->next;
            delete current;
        }
    }

    void erase(int pos) {
        if (pos == 0) pop_front();
        else {
            LinkedNode<T>* current = head;
            for (int i = 0; i < pos; i++) {
                current = current->next;
            }
            erase(current);
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
