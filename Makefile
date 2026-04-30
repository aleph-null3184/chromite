PROJECT_NAME := chromite
CC := gcc
CFLAGS := -Wall -Werror -pedantic -std=c99 -lncurses

SRC := src/main.c src/state.c

chromite: $(SRC)
	$(CC) $(SRC) -o chromite $(CFLAGS)
