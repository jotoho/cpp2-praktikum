// SPDX-License-Identifier: GPL-3.0-or-later
#include "./stack.hpp"
#include <stdexcept>

Stack::Stack() {
    this->init();
}

void Stack::init() {
    this->next = 0;
    this->capacity = maxSize;
}

void Stack::push(int datum) {
    if (this->size() + 1 < this->get_capacity())
        this->value[this->next++] = datum;
    else
        throw std::logic_error{"No space left inside Stack"};
}

int Stack::pop() {
    if (this->is_not_empty())
        return this->value[--(this->next)];
    else
        throw std::logic_error{
            "Can't take something from the stack if it's empty"};
}

int Stack::peek() {
    return this->value[this->next - 1];
}

int Stack::size() {
    return this->next;
}

int Stack::get_capacity() {
    return Stack::maxSize;
}

bool Stack::is_empty() {
    return this->next == 0;
}

bool Stack::is_not_empty() {
    return this->next != 0;
}
