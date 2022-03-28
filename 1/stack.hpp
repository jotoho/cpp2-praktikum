const int N_MAX_STACK = 1000;  // maximale Stapelgröße

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

    // This should be here
    static const auto maxSize = N_MAX_STACK;

   private:
    int value[N_MAX_STACK];  // Feld zur Aufnahme der Datenelemente
    int next;                // Stapelzeiger
    int capacity;            // maximale Elementzahl
};
