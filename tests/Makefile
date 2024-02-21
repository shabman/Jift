STD_VER := -std=c++11
INCLUDES := -I../include -I../tests

COMPILED_SOURCES = ../src/compiler/lexer/*.cpp

all: build

build: clean
	mkdir bin
	g++ $(STD_VER) jift_test.cpp -o bin/jtests $(INCLUDES) $(COMPILED_SOURCES) -D__JIFT_DEBUG_TEST__

clean:
	rm -rf bin

run:
	./bin/jtests

.PHONY: build