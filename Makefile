# -ansi sets the standard to 1989 ANSI C as described in Dennis Ritchie's book
# -Wall makes the compiler print all warnings
CFLAGS = -ansi -Wall

# `make` makes the first target in the Makefile
# 'build/generator' is the target, 'generator/generator.c' is needed to make it
# $(CC) is a macro which invokes the system C compiler
build/generator: generator/generator.c
	mkdir -p build
	$(CC) $(CFLAGS) -o build/generator generator/generator.c