//
// Created by francesco on 8/30/26.
//

#ifndef DES_AED_2026_2_CIRCULARLINKEDLIST_H
#define DES_AED_2026_2_CIRCULARLINKEDLIST_H

#include <iostream>
#include <string>

// Estructura específica para el problema de Round-Robin
struct process {
    std::string name;
    int pending;

    process(std::string name, int pending) : name(name), pending(pending) {}

    void operator -= (const int &value) {
        pending -= value;
    }
};

template<typename data_type>
struct LinkedNode {
    data_type data;
    LinkedNode* next;

    LinkedNode() {
        next = nullptr;
    }

    LinkedNode(data_type data, LinkedNode<data_type>* next = nullptr) : data(data), next(next) {}
};

template<typename data_type>
struct CircularLinkedList {
    LinkedNode<data_type>* head;
    LinkedNode<data_type>* tail;

    CircularLinkedList() {
        head = tail = nullptr;
    }

    // Destructor para evitar fugas de memoria
    ~CircularLinkedList() {
        while (!empty()) {
            pop_front();
        }
    }

    data_type front() {
        return head->data;
    }

    // Nota: Esta función utiliza el operador -=, lo cual es muy específico
    // para el struct "process" o tipos numéricos.
    void send_front_to_back(int quantum) {
        if (head == nullptr) return;

        head->data -= quantum;
        head = head->next;
        tail = tail->next;
    }

    void pop_front() {
        if (head == nullptr) return;

        LinkedNode<data_type>* current = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            tail->next = head;
        }
        delete current;
    }

    void push_back(data_type value) {
        if (head == nullptr) {
            LinkedNode<data_type>* new_node = new LinkedNode<data_type>(value);
            head = tail = new_node;
            new_node->next = head;
        }
        else {
            LinkedNode<data_type>* new_node = new LinkedNode<data_type>(value, head);
            tail->next = new_node;
            tail = tail->next;
        }
    }

    bool empty() {
        return head == nullptr;
    }
};

#endif //DES_AED_2026_2_CIRCULARLINKEDLIST_H1