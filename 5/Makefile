build: main.cpp Simulation.cpp Spiel.cpp Spieler.cpp SturerSpieler.cpp WechselnderSpieler.cpp UnentschlossenerSpieler.cpp
	g++ -Wall -Wextra -pedantic -march=native -mtune=native -O2 main.cpp Simulation.cpp Spiel.cpp \
	Spieler.cpp SturerSpieler.cpp WechselnderSpieler.cpp UnentschlossenerSpieler.cpp\
	-o simulatechances

devbuild: main.cpp Simulation.cpp Spiel.cpp Spieler.cpp SturerSpieler.cpp WechselnderSpieler.cpp UnentschlossenerSpieler.cpp
	g++ -Wall -Wextra -pedantic -Werror -pedantic-errors -fsanitize=undefined -march=native \
	-mtune=native -Og -g main.cpp Simulation.cpp Spiel.cpp Spieler.cpp SturerSpieler.cpp \
	WechselnderSpieler.cpp UnentschlossenerSpieler.cpp -o simulatechances

clean:
	rm -f ./simulatechances
