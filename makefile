CC = g++
CFLAGS = -g -Wall -O3

SRC := sources
OBJ := objects

SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(patsubst $(SRC)/%.cpp, %.o, $(SOURCES))

hashcode_solution: $(OBJECTS)
	$(CC) $(CFLAGS) solution/hashcodeMain.cpp $^ -o $@
	rm -f $(OBJECTS)

%.o: $(SRC)/%.cpp
	$(CC) -I$(SRC) -c $< -o $@


clean:
	rm -f $(OBJECTS)
	rm -f hashcode_solution
