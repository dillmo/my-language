# -ansi sets the standard to 1989 ANSI C as described in Dennis Ritchie's book
# -Wall makes the compiler print all warnings
CFLAGS = -ansi -Wall

build/generator: generator/generator.c
	mkdir -p build
	$(CC) $(CFLAGS) -o build/generator generator/generator.c