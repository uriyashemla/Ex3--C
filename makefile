CC = gcc
FLAGS = -Wall

all: isort txtfind

isort: main.o isort.o
	$(CC) $(FLAGS) -o isort main.o isort.o
	
txtfind: mains.o txtfind.o
	$(CC) $(FLAG.oS) -o txtfind mains.o txtfind.o

mains.o: mains.c 
	$(CC) $(FLAG.oS) -c mains.c
	
main.o: main.c 
	$(CC) $(FLAG.oS) -c main.c 
	
isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c

txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c

.PHONY: clean all 

clean: 
	rm -f *.o  txtfind isort