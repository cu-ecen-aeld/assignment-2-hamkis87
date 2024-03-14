# Default target
.PHONY: all
all: writer

CROSS_COMPILE ?=

CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -g

SRC := writer.c

OBJ := $(SRC:.c=.o)

EXEC := writer

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	$(RM) $(EXEC) $(OBJ)
