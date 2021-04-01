main: main.o data.o menu.o
	gcc -g -Wall -o main main.o data.o menu.o
data.o: ../lib/src/data.c ../lib/src/data.h
	gcc -g -Wall -c ../lib/src/data.c
menu.o: ../lib/src/menu.c ../lib/src/data.h
	gcc -g -Wall -c ../lib/src/menu.c
main.o: ../src/main.c
	gcc -g -Wall -c ../src/main.c
clean:
	rm main.o data.o menu.o main
