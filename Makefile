# Makefile for the smash program
CXX = g++
CFLAGS = -std=c++11 -Wall -Werror -pedantic-errors -DNDEBUG
CCLINK = $(CXX)
DEPS = Command.h State.h PWDcommand.h Terminal.h
OBJ = Command.o State.o PWDcommand.o Terminal.o smash.o
RM = rm -f
# Creating the  executable
%.o: %.c $(DEPS)
	$(CXX) -c -o -std=c++11 $@ $< $(CFLAGS)

smash: $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS)
# Cleaning old files before new make
clean:
	$(RM) $(TARGET) *.o *~ "#"* core.*




