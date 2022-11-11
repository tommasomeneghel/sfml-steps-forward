CC := g++
CXX := g++
SFML_FLAGS := -lsfml-graphics -lsfml-system -lsfml-window
CXXFLAGS := -Os -Wall -Wpedantic -Werror

DEFAULT_FILE := int main() { return -1; }

visualizer: visualizer.o
	${CXX} $^ -o $@ ${SFML_FLAGS}

visualizer.cpp:
	echo '${DEFAULT_FILE}' > visualizer.cpp

list: $(wildcard *.cpp)
	echo $?

run: visualizer
	./$?

clean_all:
	rm visualizer visualizer.o