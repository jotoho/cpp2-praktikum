// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum

#ifndef INCLUDE_GUARD_STACK_HPP
#define INCLUDE_GUARD_STACK_HPP

#include "list.hpp"

template <typename T>
class Stack {
    Liste<T> underlyingList{};

   public:
    Stack() = default;
    Stack(const Stack& other) = delete;
    Stack& operator=(const Stack& other) = delete;

    // add new item to the top of the stack
    void push(const T value);
    // Remove and return item at top of stack
    T pop();
    // Deletes all entries
    void clear();
    // Get number of stored items
    std::size_t size();
};

template <typename T>
void Stack<T>::push(const T value) {
    this->underlyingList.add_last(value);
}

template <typename T>
T Stack<T>::pop() {
    return this->underlyingList.remove_last();
}

template <typename T>
void Stack<T>::clear() {
    this->underlyingList.clear();
}

template <typename T>
std::size_t Stack<T>::size() {
    return this->underlyingList.size();
}

#endif  // INCLUDE_GUARD_STACK_HPP
