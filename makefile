
output: debug/main.o debug/array.o
	gcc debug/main.o debug/array.o -o output

debug/main.o: main.c
	gcc -c main.c -o debug/main.o

debug/array.o: headers/array.c headers/array.h
	gcc -c headers/array.c -o debug/array.o

test:
	./output

clean:
	rm output debug/*.o
