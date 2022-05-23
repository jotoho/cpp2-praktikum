build: main.cpp  stack.hpp  list.hpp
	g++ -Wall -Wextra -pedantic -march=native -mtune=native -O2 main.cpp \
	-o listtest

devbuild: main.cpp stack.hpp list.hpp
	g++ -Wall -Wextra -pedantic -Werror -pedantic-errors -fsanitize=undefined -march=native \
	-mtune=native -Og -g main.cpp -o listtest

clean:
	rm -f ./listtest
