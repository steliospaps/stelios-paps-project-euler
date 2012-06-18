TARGET=main

TESTS_SOURCE=$(wildcard *_test.cc)
TESTS=$(TESTS_SOURCE:.cc=)
all: $(TARGET)
#	./main
$(TARGET): CC=$(CXX)




CXXFLAGS=-O3 -Wall
#CXXFLAGS=-g -Wall

clean:
	rm -f *.o
	rm -f $(TARGET) $(TESTS)

test: CXXFLAGS= -Wall -g -I../../libs/gtest-1.6.0/include 
test: LDFLAGS+= -L../../libs/gtest-1.6.0/lib 
test: LDLIBS+=  -lgtest -lgtest_main  -lpthread
sudoku_test:sudoku.h
test: $(TESTS)
	for i in $(TESTS);do ./$$i;done
