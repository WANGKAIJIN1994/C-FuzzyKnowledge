ROOT = ..

SrcFiles = $(wildcard *.cpp)

ObjFiles = $(patsubst %.cpp, %.o, $(SrcFiles))

CXX      = g++ -std=c++17

RM       = rm -f

TARGET   = run_test

INCLUDES = $(ROOT)/include

#static library
#LDFLAGS  = -L$(ROOT)/lib 

#dynamic library
LDFLAGS  = -L$(ROOT)/lib -Wl,-rpath=$(ROOT)/lib

#if you have both static and dynamic libraries, should use -Bstatic to link static libray
#g++ default behavior is link dynamic.
#LIBS    = -Wl,-Bstatic -lgtest -Wl,-Bdynamic -lpthread 
LIBS     = -lgtest -lpthread

#Release
#CXXFLAGS= -Wall -O2
 
#Debug
CPPFLAGS = -Wall -g

all : $(TARGET)

$(TARGET) : $(ObjFiles)
	$(CXX) $^ -o $@ -I$(INCLUDES) $(LDFLAGS) $(LIBS)

%.o : %.cpp
	$(CXX) -c $< -I$(INCLUDES) $(CXXFLAGS)

.PHONY:clean

clean:
	$(RM) *.o
	$(RM) $(TARGET)


