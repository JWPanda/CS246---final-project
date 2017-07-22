CXX=g++
CXXFLAGS=-std=c++14 -Wall -Werror=vla -g -Iinclude/
EXEC=sorcery
OBJECTS=src/main.o src/ascii_graphics.o src/Subject.o src/TextDisplay.o src/Board.o src/Player.o src/Card.o src/Unit.o src/Face.o src/Minion.o
DEPENDS=${OBJECTS .o=.d}

$(EXEC): $(OBJECTS)
	@$(CXX) $^ -o $@ $(CXXFLAGS)

-include ${DEPENDS}

clean:
	@rm $(OBJECTS) $(EXEC) ${DEPENDS}

.PHONY: clean

