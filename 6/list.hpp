// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum

#ifndef INCLUDE_GUARD_LIST_HPP
#define INCLUDE_GUARD_LIST_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
struct Liste {
    struct Element {
        T wert;
        Element* prev = nullptr;
        Element* next = nullptr;
        Element(T wert, Element* prev, Element* next)
            : wert(wert), prev(prev), next(next) {}
    };

   private:
    Element* head = nullptr;
    Element* tail = nullptr;

    T& getRefFromIndex(std::size_t index) const;

   public:
    Liste(const Liste& other) = delete;
    Liste& operator=(const Liste& other) = delete;

    void add(T wert) { this->add_last(wert); }

    void add_first(T wert) {
        auto oldhead = this->head;
        this->head = new Liste::Element(
            wert, static_cast<Liste::Element*>(nullptr), oldhead);
        if (oldhead != nullptr)
            oldhead->prev = this->head;
        else
            this->tail = this->head;
    }

    void add_last(T wert) {
        auto oldtail = this->tail;
        this->tail = new Liste::Element(wert, this->tail,
                                        static_cast<Liste::Element*>(nullptr));
        if (oldtail != nullptr)
            oldtail->next = this->tail;
        else
            this->head = this->tail;
    }

    void clear() {
        while (head != nullptr) {
            auto oldhead = head;
            head = head->next;
            delete oldhead;
        }
        tail = nullptr;
    }

    bool contains(T wert) const {
        auto currentElement = head;
        while (head != nullptr)
            if (currentElement->wert == wert)
                return true;
            else
                currentElement = currentElement->next;
        return false;
    }

    Liste() = default;

    ~Liste() { this->clear(); }

    T remove_first() {
        if (this->head == nullptr)
            throw std::logic_error{
                "Can't remove first element from empty list"};

        const T wert = this->head->wert;
        Liste::Element* const oldhead = this->head;
        this->head = this->head->next;
        this->head->prev = nullptr;
        delete oldhead;
        return wert;
    }

    T remove_last() {
        if (this->head == nullptr)
            throw std::logic_error{"Can't remove last element from empty list"};

        const T wert = this->tail->wert;
        Liste::Element* const oldtail = this->tail;
        this->tail = this->tail->prev;
        this->tail->next = nullptr;
        delete oldtail;
        return wert;
    }

    T& getRefFromIndex(std::size_t index) const {
        if (this->head == nullptr)
            throw std::out_of_range{"Tried to access element of empty list"};

        Liste::Element* currentElement = this->head;

        for (std::size_t currentElementIndex = 0; currentElementIndex < index;
             currentElementIndex++)
            if (currentElement->next != nullptr)
                currentElement = currentElement->next;
            else
                throw std::out_of_range{
                    "Tried to access element not inside list"};

        return currentElement->wert;
    }

    T& operator[](const std::size_t index) { return getRefFromIndex(index); }

    const T& operator[](const std::size_t index) const {
        return getRefFromIndex(index);
    }

    T get(const std::size_t index) const { return getRefFromIndex(index); }

    std::size_t size() const {
        std::size_t elementsCounted = 0;
        for (Liste::Element* countingPointer = this->head;
             countingPointer != nullptr;
             countingPointer = countingPointer->next)
            elementsCounted++;
        return elementsCounted;
    }
};

#endif  // INCLUDE_GUARD_LIST_HPP
