#include <iostream>
#include "./list.hpp"

int main() {
    Liste list{};

    list.add(42);
    if (list.contains(42))
        std::cout << "Adding and searching works\n";
    else
        std::cerr << "Where is my 42? >:(\n";
}
