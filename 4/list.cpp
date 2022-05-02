// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum
#include "./list.hpp"

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

bool Liste::contains(int wert) {
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
