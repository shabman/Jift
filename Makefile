STD_VER := -std=c++11
BUILD := -o build/jiftc
INCLUDES := -Isrc
SRC_FILES := $(filter-out ./src/main.cpp, $(wildcard ./src/*.cpp))

all: build

build: clean
	g++ $(STD_VER) src/main.cpp $(BUILD) $(INCLUDES) $(SRC_FILES)

clean:
	rm -rf build
	mkdir build

run:
	./build/jiftc

bin:
	sudo cp -r ./build/jiftc /usr/local/bin

.PHONY: build