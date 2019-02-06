#.PHONY:clean
cc = g++
cflags = --std=c++11 -g -wall -O0
objects = main
all: cc

#creates an executable file for ech object in objects
#the ifndef avoids unnecessary recompiles that result from
#having multiple objects in the objects list
cc: $(objects)
ifndef objects
	$(cc) $(cflags) -o $(objects) $(objects).cpp
endif

#in this case reads from inmain.txt and writes to outmain.txt
run:
	./$(objects) < in$(objects).txt > out$(objects).txt

clean:
	rm $(objects)


#death:
#	rm -rf
