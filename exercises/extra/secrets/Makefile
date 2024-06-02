CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -Wextra
PROG = secrets
SRC = secrets.c

all: $(PROG)

$(PROG): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@
	@./$(PROG)

.PHONY: clean
clean:
	rm -f $(PROG)
