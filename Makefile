CC = gcc
VER = -std=c99
LIB = -Llib -lcsv -lplane
IN = -Iinclude

all: main.o libplane.so
	$(CC) $(VER) temp/main.o $(LIB) -lm -o main

main.o: bin/main.c include/csv.h include/plane.h temp
	$(CC) $(VER) $(IN) -c bin/main.c -o temp/main.o

plane.o: bin/plane.c include/plane.h temp
	$(CC) $(VER) $(IN) -c bin/plane.c -o temp/plane.o

libplane.so: plane.o
	$(CC) $(VER) -shared temp/plane.o -o lib/libplane.so

temp:
	mkdir temp

clean:
	rm -rf temp
	rm -f main
