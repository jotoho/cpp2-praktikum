#!/bin/sh

g++ -Wall -Wextra -pedantic -Werror -pedantic-errors -fsanitize=undefined -march=native -mtune=native main.cpp list.cpp -o listtest
