CC = gcc
VER = -std=c99
LIB = -Llib -lplane -lmyfunctions
IN = -Iinclude

all: main.o libplane.so libmyfunctions.so
	$(CC) $(VER) temp/main.o $(LIB) -lm -o main

test: test.o libplane.so libmyfunctions.so
	$(CC) $(VER) temp/test.o $(LIB) -lm -o test

main.o: src/main.c include/plane.h include/myfunctions.h temp
	$(CC) $(VER) $(IN) -c src/main.c -o temp/main.o

plane.o: src/plane.c include/plane.h temp
	$(CC) $(VER) $(IN) -c src/plane.c -fPIC -lm -o temp/plane.o

libplane.so: plane.o
	$(CC) $(VER) -shared temp/plane.o -o lib/libplane.so

myfunctions.o: src/myfunctions.c include/myfunctions.h temp
	$(CC) $(VER) $(IN) -c src/myfunctions.c -fPIC -lm -o temp/myfunctions.o

libmyfunctions.so: myfunctions.o
	$(CC) $(VER) -shared temp/myfunctions.o -o lib/libmyfunctions.so

test.o: src/test.c include/plane.h include/myfunctions.h temp
	$(CC) $(VER) $(IN) -c src/test.c -o temp/test.o

temp:
	mkdir temp

clean:
	rm -rf temp
	rm -f main
	rm -f test
