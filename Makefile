CC=gcc
SRC=src/*.c
BIN=bin
ARGS=-Wall -O2
DEBARGS=-Wall -g -DDEBON
LIBS=-pthread

all:
	$(CC) $(ARGS) $(SRC) -o $(BIN)/app.out $(LIBS)
	$(CC) $(DEBARGS) $(SRC) -o $(BIN)/deb_app.out $(LIBS)

debug:
	$(CC) $(DEBARGS) $(SRC) -o $(BIN)/deb_app.out $(LIBS)
