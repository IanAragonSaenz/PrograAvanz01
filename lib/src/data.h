#ifndef _DATA_H
#define _DATA_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Alumno{
	int id;
	char nombre[15];
	char apellido[15];
	char carrera[15];
	char ciudad[15];
	char graduacion[15];
	int A;
	int B;
	int C;
	int D;
} Alumno;

void readInfo(Alumno *alumno, char *line);

void readGrades(Alumno *alumno, char *line);

void printMenu();

void printHelp();

#endif
