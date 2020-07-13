CXX = g++

CXXFLAGS = -g -Wall -Wno-uninitialized

BINARIES = tdd

COMMON_OBJECT_FILES = MyChunkyNode.o tdd.o MyChunkyList.o

all: ${BINARIES}

tdd: ${COMMON_OBJECT_FILES}
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@


clean:
	/bin/rm -f ${BINARIES} *.o

