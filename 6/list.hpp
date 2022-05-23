// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum
// Individual work for assignment 4, based on shared group work of commit:
// https://github.com/jotoho/cpp2-praktikum/commit/92ffbeacb68b05d2e79185959109fa8dfe0b3ffe

#ifndef INCLUDE_GUARD_LIST_HPP
#define INCLUDE_GUARD_LIST_HPP

#include <cstddef>

struct Liste {
    struct Element {
        int wert;
        Element* prev = nullptr;
        Element* next = nullptr;
        Element(int wert, Element* prev, Element* next)
            : wert(wert), prev(prev), next(next) {}
    };

   private:
    Element* head = nullptr;
    Element* tail = nullptr;

    int& getRefFromIndex(std::size_t index) const;

   public:
    Liste();
    ~Liste();
    Liste(const Liste& other) = delete;
    Liste& operator=(const Liste& other) = delete;

    void add(int wert);
    void clear();
    bool contains(int wert) const;

    std::size_t size() const;

    void add_first(int wert);
    void add_last(int wert);

    int remove_first();
    int remove_last();

    int get(const std::size_t index) const;

    int& operator[](const std::size_t index);
    const int& operator[](const std::size_t index) const;
};

#endif  // INCLUDE_GUARD_LIST_HPP
