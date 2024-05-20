CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -Werror -Wextra
PROG = palindromi

ifeq ($(DEBUG),1)
	CFLAGS += -DDEBUG -g
endif

SOL = solution.c
MAIN_SRC = palindromi.c

OBJS = solution.o palindromi.o

all: $(PROG)

solution.o: $(SOL) solution.h
	$(CC) $(CFLAGS) -c $< -o $@

palindromi.o: $(MAIN_SRC) solution.h
	$(CC) $(CFLAGS) -c $< -o $@

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	./$(PROG)
	@rm palindromi.o

.PHONY: clean
clean:
	rm -f $(OBJS) $(PROG)
