
SrcFiles = $(wildcard ./src/*.cpp)

ObjFiles = $(patsubst %.cpp,%.o,$(SrcFiles))

CC = g++

INCLUDES = -I./include

LIBS = -L./libs

#Release
CPPFLAGS = -g -Wall
 
#Debug

all:run_test

run_test : $(ObjFiles)
	$(CC) $^ -o $@ $(INCLUDES) $(LIBS)

%.o : %.cpp
	$(CC) -c $< $(INCLUDES) $(CPPFLAGS)

.PHONY:clean

clean:
	rm -f *.o
	rm -f run_test)


