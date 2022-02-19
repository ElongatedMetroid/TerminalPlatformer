CC=gcc
SRC=src/*.c
BIN=bin
ARGS=-Wall -O2
LIBS=-pthread

all:
	$(CC) $(ARGS) $(SRC) -o $(BIN)/app.out $(LIBS)
