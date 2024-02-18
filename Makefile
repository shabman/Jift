STD_VER := -std=c11
BUILD := -o build/jiftc
INCLUDES := -Iinclude

all: build

build: clean
	gcc $(STD_VER) src/main.c $(BUILD) $(INCLUDES)

clean:
	rm -rf build
	mkdir build

run:
	./build/jiftc

bin:
	sudo cp -r ./build/jiftc /usr/local/bin

.PHONY: build