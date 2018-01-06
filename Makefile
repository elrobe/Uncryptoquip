
CC=g++
FLAGS=-ansi -pedantic -Wall -g

build: encrypt

encrypt: ./src/encrypt/encrypt.cpp
	$(CC) $(FLAGS) ./src/encrypt/encrypt.cpp
