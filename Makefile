PROJECT_NAME := chromite
CC := gcc
CFLAGS := -Wall -Werror -pedantic -std=c99 -lncurses

SRC := src/main.c

chromite: $(SRC)
	$(CC) $(SRC) -o chromite $(CFLAGS)
