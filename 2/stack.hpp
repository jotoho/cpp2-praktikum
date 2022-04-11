// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum
#include <cstddef>

class Stack {
   public:
    Stack();                               // Konstruktor
    Stack(const Stack&);                   // Kopierkonstrutor
    ~Stack();                              // Destruktor
    const Stack& operator=(const Stack&);  // Zuweisungsoperator
    void init();                           // Initialisierung
    void push(int datum);                  // Element hinzufügen
    int pop();                             // Element entfernen
    int peek();                            // Wert des obersten Elementes
    int size();                            // Anzahl der Elemente
    int get_capacity();                    // Stapelgröße
    bool is_empty();                       // Stapel leer
    bool is_not_empty();                   // Stapel nicht leer

   private:
    int* value = nullptr;  // Zeiger zum Datenbereich
    std::size_t next;      // Stapelzeiger eigentlich Index
    std::size_t currentCapacity;
    static constexpr std::size_t INCREMENT = 16;
    static constexpr std::size_t STARTING_CAPACITY = 100;
};
