//
// Created by francesco on 9/13/26.
//

#ifndef DES_AED_2026_2_STACK_H
#define DES_AED_2026_2_STACK_H

#include <vector>

template<typename T>
struct my_stack {
    std::vector<T> data;

    void push(const T &x) { data.push_back(x); }
    void pop() { data.pop_back(); }

    T& top() { return data.back(); }
    const T& top() const { return data.back(); }

    bool empty() const { return data.empty(); }
    int size() const { return data.size(); }
};

#endif //DES_AED_2026_2_STACK_H
