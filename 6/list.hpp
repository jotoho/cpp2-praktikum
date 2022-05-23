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
    Liste();
    ~Liste();
    Liste(const Liste& other) = delete;
    Liste& operator=(const Liste& other) = delete;

    void add(T wert);
    void clear();
    bool contains(T wert) const;

    std::size_t size() const;

    void add_first(T wert);
    void add_last(T wert);

    T remove_first();
    T remove_last();

    T get(const std::size_t index) const;

    T& operator[](const std::size_t index);
    const T& operator[](const std::size_t index) const;
};

template <typename T>
void Liste<T>::add(T wert) {
    this->add_last(wert);
}

template <typename T>
void Liste<T>::add_first(T wert) {
    auto oldhead = this->head;
    this->head = new Liste::Element(wert, static_cast<Liste::Element*>(nullptr),
                                    oldhead);
    if (oldhead != nullptr)
        oldhead->prev = this->head;
    else
        this->tail = this->head;
}

template <typename T>
void Liste<T>::add_last(T wert) {
    auto oldtail = this->tail;
    this->tail = new Liste::Element(wert, this->tail,
                                    static_cast<Liste::Element*>(nullptr));
    if (oldtail != nullptr)
        oldtail->next = this->tail;
    else
        this->head = this->tail;
}

template <typename T>
void Liste<T>::clear() {
    while (head != nullptr) {
        auto oldhead = head;
        head = head->next;
        delete oldhead;
    }
    tail = nullptr;
}

template <typename T>
bool Liste<T>::contains(T wert) const {
    auto currentElement = head;
    while (head != nullptr)
        if (currentElement->wert == wert)
            return true;
        else
            currentElement = currentElement->next;
    return false;
}

template <typename T>
Liste<T>::Liste() {}

template <typename T>
Liste<T>::~Liste() {
    this->clear();
}

template <typename T>
T Liste<T>::remove_first() {
    if (this->head == nullptr)
        throw std::logic_error{"Can't remove first element from empty list"};

    const T wert = this->head->wert;
    Liste::Element* const oldhead = this->head;
    this->head = this->head->next;
    this->head->prev = nullptr;
    delete oldhead;
    return wert;
}

template <typename T>
T Liste<T>::remove_last() {
    if (this->head == nullptr)
        throw std::logic_error{"Can't remove last element from empty list"};

    const T wert = this->tail->wert;
    Liste::Element* const oldtail = this->tail;
    this->tail = this->tail->prev;
    this->tail->next = nullptr;
    delete oldtail;
    return wert;
}

template <typename T>
T& Liste<T>::getRefFromIndex(std::size_t index) const {
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

template <typename T>
T& Liste<T>::operator[](const std::size_t index) {
    return getRefFromIndex(index);
}

template <typename T>
const T& Liste<T>::operator[](const std::size_t index) const {
    return getRefFromIndex(index);
}

template <typename T>
T Liste<T>::get(const std::size_t index) const {
    return getRefFromIndex(index);
}

template <typename T>
std::size_t Liste<T>::size() const {
    std::size_t elementsCounted = 0;
    for (Liste::Element* countingPointer = this->head;
         countingPointer != nullptr; countingPointer = countingPointer->next)
        elementsCounted++;
    return elementsCounted;
}

#endif  // INCLUDE_GUARD_LIST_HPP
