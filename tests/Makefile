STD_VER := -std=c++11
INCLUDES := -Iplog -Ilexer

all: build

build: clean
	mkdir bin
	g++ $(STD_VER) jift_test.cpp -o bin/jtests $(INCLUDES)

clean:
	rm -rf bin

run:
	./bin/jtests

.PHONY: build