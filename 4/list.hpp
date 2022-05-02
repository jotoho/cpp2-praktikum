// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum
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

   public:
    Liste();
    ~Liste();
    Liste(const Liste& other) = delete;
    Liste& operator=(const Liste& other) = delete;

    void add(int wert);
    void clear();
    bool contains(int wert);
};
