//
// Created by francesco on 9/13/26.
//

#ifndef DES_AED_2026_2_DEQUE_H
#define DES_AED_2026_2_DEQUE_H

#include <vector>

template<typename T>
struct my_deque {
    std::vector<T> data;
    int head = 0, tail = 0, _size = 0, cap = 4;

    my_deque() { data.resize(cap); }

    void resize_buffer(int new_cap) {
        std::vector<T> new_data(new_cap);
        for (int i = 0; i < _size; ++i) {
            new_data[i] = data[(head + i) % cap];
        }
        data = std::move(new_data);
        head = 0;
        tail = _size;
        cap = new_cap;
    }

    void push_back(const T &x) {
        if (_size == cap) resize_buffer(cap * 2);
        data[tail] = x;
        tail = (tail + 1) % cap;
        ++_size;
    }

    void push_front(const T &x) {
        if (_size == cap) resize_buffer(cap * 2);
        head = (head - 1 + cap) % cap;
        data[head] = x;
        ++_size;
    }

    void pop_back() {
        tail = (tail - 1 + cap) % cap;
        --_size;
    }

    void pop_front() {
        head = (head + 1) % cap;
        --_size;
    }

    T& front() { return data[head]; }
    const T& front() const { return data[head]; }

    T& back() { return data[(tail - 1 + cap) % cap]; }
    const T& back() const { return data[(tail - 1 + cap) % cap]; }

    // Acceso directo por índice en O(1)
    T& operator[](int idx) { return data[(head + idx) % cap]; }
    const T& operator[](int idx) const { return data[(head + idx) % cap]; }

    bool empty() const { return _size == 0; }
    int size() const { return _size; }
};

#endif //DES_AED_2026_2_DEQUE_H
