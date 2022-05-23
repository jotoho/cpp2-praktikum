build: main.cpp stack.cpp stack.hpp list.cpp list.hpp
	g++ -Wall -Wextra -pedantic -march=native -mtune=native -O2 main.cpp list.cpp stack.cpp \
	-o listtest

devbuild: main.cpp stack.cpp stack.hpp list.cpp list.hpp
	g++ -Wall -Wextra -pedantic -Werror -pedantic-errors -fsanitize=undefined -march=native \
	-mtune=native -Og -g main.cpp list.cpp stack.cpp -o listtest

clean:
	rm -f ./listtest
