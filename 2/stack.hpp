// SPDX-License-Identifier: GPL-3.0-or-later
#include <cstddef>

class Stack {
   public:
    Stack();               // Konstruktor
    void init();           // Initialisierung
    void push(int datum);  // Element hinzufügen
    int pop();             // Element entfernen
    int peek();            // Wert des obersten Elementes
    int size();            // Anzahl der Elemente
    int get_capacity();    // Stapelgröße
    bool is_empty();       // Stapel leer
    bool is_not_empty();   // Stapel nicht leer

    // maximale Stapelgröße
    static constexpr std::size_t maxSize = 1000;

   private:
    int value[maxSize];  // Feld zur Aufnahme der Datenelemente
    int next;            // Stapelzeiger
    int capacity;        // maximale Elementzahl
};
