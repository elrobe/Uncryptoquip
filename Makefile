
CC=g++
FLAGS=-ansi -pedantic -Wall -g

build: encrypt

encrypt: ./src/encrypt/encrypt.cpp
	$(CC) $(FLAGS) ./src/encrypt/encrypt.cpp

ui: ./src/ui/menu.cpp
	$(CC) $(FLAGS) ./src/ui/menu.cpp
