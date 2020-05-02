# Makefile for the smash program
CXX = g++
CPPFLAGS = -std=c++11 -Wall -Werror -pedantic-errors -DNDEBUG
CCLINK = $(CXX)

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
DEPS = $(wildcard *.h)
TARGET = smash
RM = rm -f
# Creating the  executable
smash: $(OBJS)
	$(CXX) -o $@ $^ $(CPPFLAGS)

cpCOMMAND.o: cpCOMMAND.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)
cdCommand.o: cdCommand.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)
Command.o: Command.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)
difCOMMAND.o: difCOMMAND.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)
FgCommand.o: FgCommand.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)
histCOMMAND.o: histCOMMAND.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)
JobsCommand.o: JobsCommand.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)
KillCommand.o: KillCommand.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)
PWDcommand.o: PWDcommand.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)
quitCOMMAND.o: quitCOMMAND.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)
shpdCOMMAND.o: shpdCOMMAND.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)
signals.o: signals.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)
State.o: State.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)
Terminal.o: Terminal.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)


# Cleaning old files before new make
clean:
	$(RM) $(TARGET) *.o *~ "#"* core.*

