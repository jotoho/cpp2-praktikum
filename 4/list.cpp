// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum
#include "./list.hpp"

// Voll moppelkotze - sollte append heißen
void Liste::add(int wert) {
    auto oldtail = tail;
    tail =
        new Liste::Element(wert, tail, static_cast<Liste::Element*>(nullptr));
    if (oldtail != nullptr)
        oldtail->next = tail;
    else
        head = tail;
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
