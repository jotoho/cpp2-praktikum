// SPDX-License-Identifier: GPL-3.0-or-later
// Repository: https://github.com/jotoho/cpp2-praktikum

#include <ctime>
#include <iostream>
#include "./list.hpp"
#include "./stack.hpp"

void testAddAndSearch() {
    Liste<int> list{};

    list.add(42);
    if (list.contains(42))
        std::cout << "Success: Adding and searching works\n";
    else {
        std::cerr << "Error: Where is my 42? >:(\n";
        std::exit(EXIT_FAILURE);
    }
}

void testDeletingOnEmptyList() {
    Liste<int> list{};
    try {
        list.remove_first();
        std::cout << "Error: Removing from empty list didn't throw\n";
        std::exit(EXIT_FAILURE);
    } catch (const std::logic_error& e) {
        std::cout << "Success: Attempt to delete from empty list successfully "
                     "detected\n";
    }
}

void testAddingAndDeleting() {
    Liste<int> list{};

    if (list.size() != 0) {
        std::cout << "Error: New list already started with elements?\n";
        std::exit(EXIT_FAILURE);
    }

    for (const int toAdd :
         {std::rand(), std::rand(), std::rand(), std::rand(), std::rand()})
        list.add_last(toAdd);

    for (std::size_t amountToDelete = 2; amountToDelete > 0; amountToDelete--)
        list.remove_last();

    if (list.size() == 3) {
        std::cout << "Success: Added and removed correct number of elements\n";
    } else {
        std::cout << "Error: Incorrect number of elements in list: "
                  << std::to_string(list.size()) << '\n';
        std::exit(EXIT_FAILURE);
    }
}

void testClearing() {
    Liste<int> list{};
    for (std::size_t numElementsLeftToAdd = 16; numElementsLeftToAdd > 0;
         numElementsLeftToAdd--)
        list.add(std::rand());
    list.clear();
    if (list.size() == 0)
        std::cout << "Success: Filling and clearing list worked\n";
    else {
        std::cout << "Error: There's still stuff in there\n";
        std::exit(EXIT_FAILURE);
    }
}

void testIndexedAccess() {
    Liste<int> list{};

    for (const int toAdd :
         {std::rand(), std::rand(), 42, std::rand(), std::rand(), std::rand()})
        list.add_last(toAdd);

    if (list.get(2) != 42 || list[2] != 42) {
        std::cout << "Error: Inserted value is not there\n";
        std::exit(EXIT_FAILURE);
    }

    if (list.get(4) != list[4]) {
        std::cout << "Error: values provided by get and operator[] differ\n";
        std::exit(EXIT_FAILURE);
    }

    std::cout << "Success: indexed accessing of list worked\n";
}

void testList() {
    testAddAndSearch();
    testDeletingOnEmptyList();
    testAddingAndDeleting();
    testClearing();
    testIndexedAccess();
}

int main() {
    std::srand(std::time(nullptr));
    testList();
    return EXIT_SUCCESS;
}
