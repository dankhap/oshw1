project(smash)
# Add executable called "helloDemo" that is built from the source files
# "demo.cxx" and "demo_b.cxx". The extensions are automatically found.
set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic-errors -DNDEBUG -std=c++11")
add_executable (smash smash.cpp Command.cpp PWDcommand.cpp Terminal.cpp State.cpp)


# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
