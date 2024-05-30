CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -Wextra
LIBS = -lm
PROG = torneo
SRC = torneo.c

all: $(PROG)

$(PROG): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
	@./$(PROG)

.PHONY: clean
clean:
	rm -f $(PROG)
