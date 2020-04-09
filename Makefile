# Makefile for the smash program
CXX = g++
CFLAGS = -g -Wall
CCLINK = $(CXX)
DEPS = Command.h State.h PWDcommand.h Terminal.h
OBJ = Command.o State.o PWDcommand.o Terminal.o smash.o
RM = rm -f
# Creating the  executable
%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS)
# Cleaning old files before new make
clean:
	$(RM) $(TARGET) *.o *~ "#"* core.*




