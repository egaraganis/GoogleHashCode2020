CC=g++

SRC := sources
OBJ := objects

SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES))

hashcode_solution: $(OBJECTS)
	$(CC) -g -Wall solution/hashcode_solution.cpp $^ -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) -g -I$(SRC) -c $< -o $@

clean:
	@rm -f D ./objects/*.o core
	@rm -f hashcode_solution
