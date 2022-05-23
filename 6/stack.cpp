// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum
// Individual work for assignment 4, based on shared group work of commit:
// https://github.com/jotoho/cpp2-praktikum/commit/92ffbeacb68b05d2e79185959109fa8dfe0b3ffe

#include "stack.hpp"

void Stack::push(const int value) {
    this->underlyingList.add_last(value);
}

int Stack::pop() {
    return this->underlyingList.remove_last();
}

void Stack::clear() {
    this->underlyingList.clear();
}

std::size_t Stack::size() {
    return this->underlyingList.size();
}
