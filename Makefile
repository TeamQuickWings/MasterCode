CC = gcc
VER = -std=c99
LIB = -Llib -lcsv -lplane -lmyfunctions
IN = -Iinclude

all: main.o libplane.so libmyfunctions.so
	$(CC) $(VER) temp/main.o $(LIB) -lm -o main

test: test.o libplane.so libmyfunctions.so
	$(CC) $(VER) temp/test.o $(LIB) -lm -o test

main.o: bin/main.c include/csv.h include/plane.h include/myfunctions.h temp
	$(CC) $(VER) $(IN) -c bin/main.c -o temp/main.o

plane.o: bin/plane.c include/plane.h temp
	$(CC) $(VER) $(IN) -c bin/plane.c -lm -o temp/plane.o

libplane.so: plane.o
	$(CC) $(VER) -shared temp/plane.o -o lib/libplane.so

myfunctions.o: bin/myfunctions.c include/myfunctions.h temp
	$(CC) $(VER) $(IN) -c bin/myfunctions.c -lm -o temp/myfunctions.o

libmyfunctions.so: myfunctions.o
	$(CC) $(VER) -shared temp/myfunctions.o -o lib/libmyfunctions.so

test.o: bin/test.c include/plane.h include/myfunctions.h temp
	$(CC) $(VER) $(IN) -c bin/test.c -o temp/test.o

temp:
	mkdir temp

clean:
	rm -rf temp
	rm -f main
	rm -f test
