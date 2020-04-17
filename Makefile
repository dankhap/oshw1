# Makefile for the smash program
CXX = g++
CPPFLAGS = -std=c++11 -Wall -Werror -pedantic-errors -DNDEBUG
CCLINK = $(CXX)

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
DEPS = $(wildcard *.h)

RM = rm -f
# Creating the  executable
%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)

smash: $(OBJS)
	$(CXX) -o $@ $^ $(CPPFLAGS)
# Cleaning old files before new make
clean:
	$(RM) $(TARGET) *.o *~ "#"* core.*

