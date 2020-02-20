CC = g++
CFLAGS = -g -Wall

SRC := sources
OBJ := objects

SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES))

hashcode_solution: $(OBJECTS)
	$(CC) $(CFLAGS) solution/hashcode_solution.cpp $^ -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) -I$(SRC) -c $< -o $@

clean:
	@rm -f D ./objects/*.o core
	@rm -f hashcode_solution
