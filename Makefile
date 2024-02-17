STD_VER := -std=c11
BUILD := -o build/jiftc

all: build

build: clean
	gcc $(STD_VER) src/main.c $(BUILD)

clean:
	rm -rf build
	mkdir build

run:
	./build/jiftc

.PHONY: build