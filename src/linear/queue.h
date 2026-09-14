//
// Created by francesco on 9/13/26.
//

#ifndef DES_AED_2026_2_QUEUE_H
#define DES_AED_2026_2_QUEUE_H

#include <vector>

template<typename T>
struct my_queue {
    std::vector<T> data;
    int head = 0, tail = 0, _size = 0, cap = 4;

    my_queue() { data.resize(cap); }

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

    void push(const T &x) {
        if (_size == cap) resize_buffer(cap * 2);
        data[tail] = x;
        tail = (tail + 1) % cap;
        ++_size;
    }

    void pop() {
        head = (head + 1) % cap;
        --_size;
    }

    T& front() { return data[head]; }
    const T& front() const { return data[head]; }

    bool empty() const { return _size == 0; }
    int size() const { return _size; }
};

#endif //DES_AED_2026_2_QUEUE_H
