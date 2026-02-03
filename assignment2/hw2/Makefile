CC = gcc
CFLAGS = -std=c99 -O2 -Werror -Wextra -Wall

# External Libraries
LIB = 

# .h files
DEPS = functions.h

# Compiled .o files
OBJECTS = main.o functions.o

# Program name
PROGRAM = main

all: $(PROGRAM)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm *.o $(PROGRAM)