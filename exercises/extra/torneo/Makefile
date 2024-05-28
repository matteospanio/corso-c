CC = gcc
CFLAGS = -Wall -g -std=c99 -pedantic -Werror -Wextra
PROG = torneo
SOL = solution.c
MAIN_SRC = torneo.c

OBJS = solution.o torneo.o

all: $(PROG)

solution.o: $(SOL) solution.h
	$(CC) $(CFLAGS) -c $< -o $@

secrets.o: $(MAIN_SRC) solution.h
	$(CC) $(CFLAGS) -c $< -o $@

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	@./$(PROG)
	@rm torneo.o

.PHONY: clean
clean:
	rm -f $(OBJS) $(PROG)
