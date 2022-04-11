// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum
#include "./stack.hpp"
#include <cstring>
#include <memory>
#include <stdexcept>

Stack::Stack() {
    this->init();
}

Stack::Stack(const Stack& other) {
    *this = other;
}

Stack::~Stack() {
    std::free(this->value);
}

const Stack& Stack::operator=(const Stack& other) {
    if (this == &other)
        return *this;

    this->currentCapacity = other.currentCapacity;
    this->next = other.next;
    if (other.value == nullptr) {
        this->value = nullptr;
    } else {
        this->value =
            reinterpret_cast<int*>(malloc(sizeof(int) * this->currentCapacity));
        if (this->value == nullptr)
            throw std::bad_alloc{};
        else
            std::memcpy(this->value, other.value,
                        currentCapacity * sizeof(int));
    }
    return *this;
}

void Stack::init() {
    if (value != nullptr) {
        std::free(this->value);
    }
    this->next = 0;
    this->currentCapacity = Stack::STARTING_CAPACITY;
    this->value =
        reinterpret_cast<int*>(malloc(sizeof(int) * Stack::STARTING_CAPACITY));
    if (this->value == nullptr) {
        throw std::bad_alloc{};
    }
}

void Stack::push(int datum) {
    while (this->next >= this->currentCapacity - 1) {
        this->currentCapacity += Stack::INCREMENT;
        this->value = reinterpret_cast<int*>(
            std::realloc(this->value, this->currentCapacity));
        if (this->value == nullptr) {
            throw std::bad_alloc{};
        }
    }
    this->value[this->next++] = datum;
}

int Stack::pop() {
    if (is_not_empty()) {
        const auto result = this->value[--this->next];
        while (this->next >= Stack::STARTING_CAPACITY &&
               this->next + 1 <= this->currentCapacity - Stack::INCREMENT) {
            this->currentCapacity -= Stack::INCREMENT;
            this->value = reinterpret_cast<int*>(
                std::realloc(this->value, this->currentCapacity));
            if (this->value == nullptr)
                throw std::bad_alloc{};
        }
        return result;
    } else
        throw std::underflow_error{"Tried to pop from empty stack!"};
}

int Stack::peek() {
    if (is_not_empty())
        return this->value[this->next - 1];
    else
        throw std::underflow_error{"Tried to peek at empty stack!"};
}

int Stack::size() {
    return this->next;
}

int Stack::get_capacity() {
    return this->currentCapacity;
}

bool Stack::is_empty() {
    return this->next == 0;
}

bool Stack::is_not_empty() {
    return this->next != 0;
}
