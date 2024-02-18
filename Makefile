STD_VER := -std=c++11
BUILD := -o build/jiftc
INCLUDES := -Iinclude
SRC_FILES := $(filter-out ./src/main.cpp, $(wildcard ./src/*.cpp))
COMPILED_SOURCES := ./src/compiler/lexer/*.cpp

all: build

build: clean
	g++ $(STD_VER) src/main.cpp $(BUILD) $(INCLUDES) $(SRC_FILES) $(COMPILED_SOURCES)

clean:
	rm -rf build
	mkdir build

run:
	./build/jiftc

bin:
	sudo cp -r ./build/jiftc /usr/local/bin

.PHONY: build