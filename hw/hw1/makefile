#.PHONY:clean
cc = g++
cflags = --std=c++11 -g -o
objects = main

cc: $(objects)
ifndef objects
	$(cc) $(cflags) -o $(objects) $(objects).cpp
endif
clean:
	rm $(objects)

#death:
#	rm -rf
