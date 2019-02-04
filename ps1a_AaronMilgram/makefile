#compiler
cc = g++
#flags by category
cflags = --std=c++11 -g -Wall -c -O0 -Og -Werror -pedantic -ansi#always use
boostflags = -lboost_system -lboost_unit_test_framework -lpthread -lboost_filesystem #unit testing
lsfmlflags = -lsfml-graphics -lsfml-window -lsfml-syste

#objects and executable used by the old makefile
objects = main
executable = ps1a



#here is the current makefile
All: ps1a
ps1a: test.o
	$(cc) $(cflags) -o ps1a.o main.cpp
test.o: test.cpp LFSR.o
	$(cc) $(cflags) -o test.o test.cpp $(boostflags)
LFSR.o: LFSR.cpp
	$(cc) $(cflags) -o LFSR.o LFSR.cpp
clean:
	rm test.o ps1a.o LFSR.o





#old makefile with one or two changes I made to it in an attempt to get it working for this project
oldcc: $(objects)
ifndef executables #the ifndef is here to prevent recompilations when multiple exe are being made
	$(cc) $(cflags) -o $(executables) $(objects).cpp $(boostflags)
endif
oldClean:
	rm $(executable)
