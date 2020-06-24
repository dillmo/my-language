build/generator: generator/generator.c
	mkdir -p build
	$(CC) -o build/generator generator/generator.c