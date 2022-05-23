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

    void push(const T value) { this->underlyingList.add_last(value); }

    T pop() { return this->underlyingList.remove_last(); }

    void clear() { this->underlyingList.clear(); }

    std::size_t size() { return this->underlyingList.size(); }
};

#endif  // INCLUDE_GUARD_STACK_HPP
