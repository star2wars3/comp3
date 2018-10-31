#.PHONY:clean
cc = g++
cflags = --std=c++11 -g #-wall
objects = shape_client Polynomial_client
all: cc
cc: $(objects)
ifndef objects
	$(cc) $(cflags) -o $(objects) $(objects).cpp
endif
clean:
	rm $(objects)
#death:
#	rm -rf
