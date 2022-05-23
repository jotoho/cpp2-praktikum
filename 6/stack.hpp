// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum
// Individual work for assignment 4, based on shared group work of commit:
// https://github.com/jotoho/cpp2-praktikum/commit/92ffbeacb68b05d2e79185959109fa8dfe0b3ffe

#ifndef INCLUDE_GUARD_STACK_HPP
#define INCLUDE_GUARD_STACK_HPP

#include "list.hpp"

class Stack {
    Liste underlyingList{};

   public:
    Stack() = default;
    Stack(const Stack& other) = delete;
    Stack& operator=(const Stack& other) = delete;

    // add new item to the top of the stack
    void push(const int value);
    // Remove and return item at top of stack
    int pop();
    // Deletes all entries
    void clear();
    // Get number of stored items
    std::size_t size();
};

#endif  // INCLUDE_GUARD_STACK_HPP
