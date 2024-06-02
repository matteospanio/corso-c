CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -Wextra
PROG = wc
SRC = wc.c

all: $(PROG)

$(PROG): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
	@./$(PROG)

.PHONY: clean
clean:
	rm -f $(PROG)
