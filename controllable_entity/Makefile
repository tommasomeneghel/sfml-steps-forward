CC := g++
CXX := g++
SFML_FLAGS := -lsfml-graphics -lsfml-system -lsfml-window
CXXFLAGS := -Os -Wall -Wpedantic -Werror

DEFAULT_FILE := int main() { return -1; }

objs := model/entity.o funcs/utils.o visualizer.o

visualizer: $(objs)
	${CXX} $^ -o $@ ${SFML_FLAGS}

$(objs): %.o: %.cpp
	${CXX} $^ -c -o $@

visualizer.cpp:
	echo '${DEFAULT_FILE}' > visualizer.cpp

run: visualizer
	./$?

clean:
	rm -f **/*.o visualizer.o visualizer