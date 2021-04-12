#ifndef _DATA_H
#define _DATA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Alumno{
	int id;
	char nombre[15];
	char apellido[15];
	char carrera[15];
	char ciudad[15];
	char graduacion[15];
	float A;
	float B;
	float C;
	float D;
} Alumno;

void readInfo(Alumno *alumno, char *line);

void readGrades(Alumno *alumno, char *line);

void printMenu();

void printHelp();

void consultaQ(char *argv[], int argc, Alumno alumnos[], int alumnoC, int vflag, char *ovalue);

void kardex(char *argv[], int argc, Alumno alumnos[], int alumnoC, int vflag, char *ovalue);

void fechaGraduacion(char *argv[], int argc, Alumno alumnos[], int alumnoC, int vflag, char *ovalue);

void numeroAlumnos(char *argv[], int argc, Alumno alumnos[], int alumnoC, int vflag, char *ovalue);

void nombreAlumnos(char *argv[], int argc, Alumno alumnos[], int alumnoC, int vflag, char *ovalue);

#endif
