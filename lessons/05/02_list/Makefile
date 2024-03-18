CC = gcc
CFLAGS = -Wall -g -std=c99 -pedantic -Werror -Wextra
PROG = list

AL_SRC = src/arraylist.c
LL_SRC = src/linkedlist.c
L_SRC = src/list.c src/list.h
TYPES = src/types.h
MAIN_SRC = src/main.c

OBJS = arraylist.o linkedlist.o list.o main.o

all: $(PROG)

arraylist.o: $(AL_SRC) src/arraylist.h $(TYPES)
	$(CC) $(CFLAGS) -c $< -o $@

linkedlist.o: $(LL_SRC) src/linkedlist.h $(TYPES)
	$(CC) $(CFLAGS) -c $< -o $@

list.o: $(L_SRC) src/linkedlist.h src/arraylist.h $(TYPES)
	$(CC) $(CFLAGS) -c $< -o $@

main.o: $(MAIN_SRC) src/list.h
	$(CC) $(CFLAGS) -c $< -o $@

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(PROG)
