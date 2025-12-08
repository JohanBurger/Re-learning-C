TARGET = bin/final
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

default: $(TARGET)

clean:
	rm -rf obj/*.o
	rm -f bin/*

$(TARGET): $(OBJ)
	mkdir -p bin
	gcc -o $@ $^

obj/%.o: src/%.c
	gcc -c $< -o $@ -Iinclude
