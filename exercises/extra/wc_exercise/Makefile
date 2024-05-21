CC = gcc
CFLAGS = -Wall -g -std=c99 -pedantic -Werror -Wextra
PROG = wc

SOL = solution.c
MAIN_SRC = wc.c

OBJS = solution.o wc.o

all: $(PROG)

solution.o: $(SOL) solution.h
	$(CC) $(CFLAGS) -c $< -o $@

wc.o: $(MAIN_SRC) solution.h
	$(CC) $(CFLAGS) -c $< -o $@

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(PROG)
