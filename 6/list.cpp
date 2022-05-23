// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum
// Individual work for assignment 4, based on shared group work of commit:
// https://github.com/jotoho/cpp2-praktikum/commit/92ffbeacb68b05d2e79185959109fa8dfe0b3ffe

#include "./list.hpp"
#include <stdexcept>

void Liste::add(int wert) {
    this->add_last(wert);
}

void Liste::add_first(int wert) {
    auto oldhead = this->head;
    this->head = new Liste::Element(wert, static_cast<Liste::Element*>(nullptr),
                                    oldhead);
    if (oldhead != nullptr)
        oldhead->prev = this->head;
    else
        this->tail = this->head;
}

void Liste::add_last(int wert) {
    auto oldtail = this->tail;
    this->tail = new Liste::Element(wert, this->tail,
                                    static_cast<Liste::Element*>(nullptr));
    if (oldtail != nullptr)
        oldtail->next = this->tail;
    else
        this->head = this->tail;
}

void Liste::clear() {
    while (head != nullptr) {
        auto oldhead = head;
        head = head->next;
        delete oldhead;
    }
    tail = nullptr;
}

bool Liste::contains(int wert) const {
    auto currentElement = head;
    while (head != nullptr)
        if (currentElement->wert == wert)
            return true;
        else
            currentElement = currentElement->next;
    return false;
}

Liste::Liste() {}

Liste::~Liste() {
    this->clear();
}

int Liste::remove_first() {
    if (this->head == nullptr)
        throw std::logic_error{"Can't remove first element from empty list"};

    const int wert = this->head->wert;
    Liste::Element* const oldhead = this->head;
    this->head = this->head->next;
    this->head->prev = nullptr;
    delete oldhead;
    return wert;
}

int Liste::remove_last() {
    if (this->head == nullptr)
        throw std::logic_error{"Can't remove last element from empty list"};

    const int wert = this->tail->wert;
    Liste::Element* const oldtail = this->tail;
    this->tail = this->tail->prev;
    this->tail->next = nullptr;
    delete oldtail;
    return wert;
}

int& Liste::getRefFromIndex(std::size_t index) const {
    if (this->head == nullptr)
        throw std::out_of_range{"Tried to access element of empty list"};

    Liste::Element* currentElement = this->head;

    for (std::size_t currentElementIndex = 0; currentElementIndex < index;
         currentElementIndex++)
        if (currentElement->next != nullptr)
            currentElement = currentElement->next;
        else
            throw std::out_of_range{"Tried to access element not inside list"};

    return currentElement->wert;
}

int& Liste::operator[](const std::size_t index) {
    return getRefFromIndex(index);
}

const int& Liste::operator[](const std::size_t index) const {
    return getRefFromIndex(index);
}

int Liste::get(const std::size_t index) const {
    return getRefFromIndex(index);
}

std::size_t Liste::size() const {
    std::size_t elementsCounted = 0;
    for (Liste::Element* countingPointer = this->head;
         countingPointer != nullptr; countingPointer = countingPointer->next)
        elementsCounted++;
    return elementsCounted;
}
