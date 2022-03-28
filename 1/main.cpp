#include <iostream>
#include "./stack.hpp"

/*
    Tested with g++ (GCC) 11.2.0 on x86-64 Linux
    using this command:
    g++ -std=c++17 -Wall -Wextra -Werror -pedantic -pedantic-errors ./main.cpp
   ./stack.cpp
*/

int main() {
    Stack myStack{};
    std::cout << "Stack empty: " << myStack.is_empty() << std::endl;
    myStack.push(8444845);
    std::cout << "Elements in Stack: " << myStack.size() << std::endl;
    std::cout << "Stack empty: " << myStack.is_empty() << std::endl;
    std::cout << "Top value: " << myStack.peek() << std::endl;
    std::cout << "Popped value: " << myStack.pop() << std::endl;
    std::cout << "New size: " << myStack.size() << std::endl;
}
