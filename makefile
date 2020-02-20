CC = g++
CFLAGS = -g -Wall

SRC := sources
OBJ := objects

SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(patsubst $(SRC)/%.cpp, %.o, $(SOURCES))

hashcode_solution: $(OBJECTS)
	$(CC) $(CFLAGS) solution/hashcode_solution.cpp $^ -o $@
	rm -f $(OBJECTS)

%.o: $(SRC)/%.cpp
	$(CC) -I$(SRC) -c $< -o $@


clean:
	rm -f $(OBJECTS)
	@rm -f hashcode_solution
