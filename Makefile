
CC=g++
FLAGS=-ansi -pedantic -Wall -g

SRC=./src
BIN=./bin

UI=ui
SHARED=shared
ENCRYPT=encrypt
DECRYPT=decrypt

build: shared encryptor ui
	$(CC) $(FLAGS) -o Decryptoquip $(BIN)/*.o

encryptor: $(SRC)/$(ENCRYPT)/Encryptor.h $(SRC)/$(ENCRYPT)/SubstitutionEncryptor.h
	$(CC) $(FLAGS) -c -o $(BIN)/Encryptor.o $(SRC)/$(ENCRYPT)/SubstitutionEncryptor.cpp

shared: $(SRC)/$(SHARED)/Message.h
	$(CC) $(FLAGS) -c -o $(BIN)/Message.o $(SRC)/$(SHARED)/Message.cpp

ui:
	$(CC) $(FLAGS) -c -o $(BIN)/menu.o $(SRC)/$(UI)/menu.cpp
