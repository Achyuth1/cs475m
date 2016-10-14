CC = g++
LIBS = -lGL -lglut -lGLU -lm 

SRC = main.cpp
BIN = main

all	:	$(BIN)

$(BIN)	:	HNode.hpp HNode.cpp $(SRC) 
	$(CC) $(SRC) HNode.cpp -o $(BIN) $(LIBS)

clean	:
	rm -f $(BIN) *~ *.aux *.log
