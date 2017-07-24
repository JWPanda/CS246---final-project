CXX=g++
CXXFLAGS=-std=c++14 -Wall -Werror=vla -g -Iinclude/
EXEC=sorcery
<<<<<<< HEAD
OBJECTS=src/main.o src/ascii_graphics.o src/Subject.o src/TextDisplay.o src/Board.o src/Player.o src/Card.o src/Unit.o src/Face.o src/Minion.o src/Ability.o src/ActiveAbility.o src/TriggeredAbility.o src/Ritual.o src/Factory.o src/Enchantment.o
=======
OBJECTS=src/main.o src/ascii_graphics.o src/Subject.o src/TextDisplay.o src/Board.o src/Player.o src/Card.o src/Unit.o src/Face.o src/Minion.o
>>>>>>> Fix throws
DEPENDS=${OBJECTS .o=.d}

$(EXEC): $(OBJECTS)
	@$(CXX) $^ -o $@ $(CXXFLAGS)

-include ${DEPENDS}

clean:
	@rm $(OBJECTS) $(EXEC) ${DEPENDS}

.PHONY: clean
<<<<<<< HEAD
=======

>>>>>>> Fix throws
