TARGET = bin/out
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

run : clean default
	./$(TARGET)
	./$(TARGET) -n
	./$(TARGET) -f prout.db
	
# Execute target
default : $(TARGET)

# Purge object and binary folders, and remove created database
clean :
	rm -f obj/*.o
	rm -f bin/*

# Link objects into executable file
$(TARGET) : $(OBJ)
	gcc -o $@ $?
	
# Compile source files into objects
obj/%.o : src/%.c
	gcc -c $< -o $@ -Iinclude
