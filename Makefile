CXX=g++
CXXFLAGS=-std=c++14 -Wall -Werror=vla -g -Iinclude/
EXEC=sorcery
OBJECTS=source/main.o source/ascii_graphics.o source/Subject.o source/TextDisplay.o source/Board.o source/
DEPENDS=${OBJECTS .o=.d}

$(EXEC): $(OBJECTS)
	@$(CXX) $^ -o $@ $(CXXFLAGS)

-include ${DEPENDS}

clean:
	@rm $(OBJECTS) $(EXEC) ${DEPENDS}

.PHONY: clean

