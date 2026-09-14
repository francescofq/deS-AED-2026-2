cmake_minimum_required(VERSION 4.3)
project(deS_AED_2026_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(deS_AED_2026_2 main.cpp
        src/linear/LinkedList.h
        src/linear/DoubleLinkedList.h
        src/linear/CircularLinkedList.h
        src/hash/hashMap.h
        src/linear/stack.h
        src/linear/queue.h
        src/linear/deque.h)
