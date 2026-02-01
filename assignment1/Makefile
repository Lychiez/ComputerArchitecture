CC = gcc
CFLAGS = =std=c99 -0 -Werror -Wextra -Wall
LIB =
# Your .hpp files
DEPS =
# Your compiled .o files
OBJECTS = 
# The name of your program
PROGRAM = assn1.c -o assn1

all: $(PROGRAM)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(PROGRAM): main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm *.o $(PROGRAM)