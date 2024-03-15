PROG = main

LIST_H = src/list.h
SOL_H = src/soluzione.h

LIST_SRC := src/list.c $(LIST_H)
SOL_SRC := src/soluzione.c $(SOL_H)
MAIN_SRC = src/main.c
TEST_SRC = tests/test_list.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic

all: $(PROG) test

list.o: $(LIST_SRC)
	$(CC) $(CFLAGS) -c -g $< -o $@

test.o: $(TEST_SRC) $(LIST_H)
	$(CC) $(CFLAGS) -c -g $< -o $@

test: test.o list.o
	$(CC) $^ -g -o $@

# compila il file soluzione
soluzione.o: $(SOL_SRC) $(LIST_H)
	$(CC) $(CFLAGS) -c -g $< -o $@

# compila il main
main.o: $(MAIN_SRC) $(SOL_H)
	$(CC) $(FLAGS) -g -c $< -o $@

# linka i file oggetto
$(PROG): main.o soluzione.o list.o
	$(CC) $^ -o  $@

# clean artifacts
clean:
	rm -f $(PROG) test *.o
