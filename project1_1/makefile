#.PHONY:clean
cc = g++
cflags = --std=c++11 -g -wall -O0
objects = project1_1
all: cc
cc: $(objects)
ifndef objects
	$(cc) $(cflags) -o $(objects) $(objects).cpp
endif
clean:
	rm $(objects)
#death:
#	rm -rf
