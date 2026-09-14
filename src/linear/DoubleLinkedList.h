//
// Created by francesco on 8/30/26.
//

#ifndef DES_AED_2026_2_DOUBLELINKEDLIST_H
#define DES_AED_2026_2_DOUBLELINKEDLIST_H
#include <iostream>

template <typename T>
struct DoublyLinkedNode {
    T data;
    DoublyLinkedNode<T>* next;
    DoublyLinkedNode<T>* prev;

    DoublyLinkedNode() { next = prev = nullptr; }
    DoublyLinkedNode(T data, DoublyLinkedNode<T>* next = nullptr, DoublyLinkedNode<T>* prev = nullptr)
        : data(data), next(next), prev(prev) {}
};

template <typename T>
struct DoublyLinkedList {
    DoublyLinkedNode<T>* head;
    DoublyLinkedNode<T>* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyLinkedList() {
        while (head != nullptr) pop_front();
    }

    void push_front(T value) {
        DoublyLinkedNode<T>* new_node = new DoublyLinkedNode<T>(value, head, nullptr);
        if (head == nullptr) tail = new_node;
        else head->prev = new_node;
        head = new_node;
    }

    void push_back(T value) {
        DoublyLinkedNode<T>* new_node = new DoublyLinkedNode<T>(value, nullptr, tail);
        if (tail == nullptr) head = new_node;
        else tail->next = new_node;
        tail = new_node;
    }

    // Inserta un valor DESPUÉS del nodo dado
    void insert(DoublyLinkedNode<T>* node, T value) {
        if (node == nullptr) return;
        DoublyLinkedNode<T>* new_node = new DoublyLinkedNode<T>(value, node->next, node);

        if (node->next != nullptr) node->next->prev = new_node;
        else tail = new_node; // Si insertamos después del tail, se actualiza el tail

        node->next = new_node;
    }

    void insert(int pos, T value) {
        if (pos == 0) push_front(value);
        else {
            DoublyLinkedNode<T>* current = head;
            // Avanzamos hasta pos - 1 para insertar justo después
            for (int i = 0; i < pos - 1 && current != nullptr; i++) {
                current = current->next;
            }
            if (current != nullptr) insert(current, value);
        }
    }

    void pop_front() {
        if (head == nullptr) return;
        DoublyLinkedNode<T>* current = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        else tail = nullptr; // Si la lista quedó vacía
        delete current;
    }

    // Elimina EXACTAMENTE el nodo dado (mejor lógica para listas dobles)
    void erase(DoublyLinkedNode<T>* node) {
        if (node == nullptr) return;

        if (node == head) {
            pop_front();
            return;
        }

        if (node->prev != nullptr) node->prev->next = node->next;
        if (node->next != nullptr) node->next->prev = node->prev;

        if (node == tail) tail = node->prev;

        delete node;
    }

    void erase(int pos) {
        if (pos == 0) pop_front();
        else {
            DoublyLinkedNode<T>* current = head;
            // Avanzamos EXACTAMENTE a la posición a borrar
            for (int i = 0; i < pos && current != nullptr; i++) {
                current = current->next;
            }
            if (current != nullptr) erase(current);
        }
    }

    void print() {
        DoublyLinkedNode<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif //DES_AED_2026_2_DOUBLELINKEDLIST_H