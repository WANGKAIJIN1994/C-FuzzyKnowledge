ROOT = ..

SrcFiles = $(wildcard *.cpp)

ObjFiles = $(patsubst %.cpp, %.o, $(SrcFiles))

CXX      = g++ -std=c++17

RM       = rm -f

TARGET   = run_test

INCLUDES = $(ROOT)/include

LDFLAGS  = $(ROOT)/lib 

LIBS     = -Wl,-Bstatic -lgtest -Wl,-Bdynamic -lpthread 

#Release
CXXFLAGS = -Wall -O2
 
#Debug
#CPPFLAGS = -Wall -g -O0

all : $(TARGET)

$(TARGET) : $(ObjFiles)
	$(CXX) $^ -o $@ -I$(INCLUDES) -L$(LDFLAGS) $(LIBS)

%.o : %.cpp
	$(CXX) -c $< -I$(INCLUDES) $(CXXFLAGS)

.PHONY:clean

clean:
	$(RM) *.o
	$(RM) $(TARGET)


