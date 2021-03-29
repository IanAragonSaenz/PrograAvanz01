#ifndef _DATA_H
#define _DATA_H

typedef struct Alumno{
	int id;
	char *nombre;
	char *carrera;
	char *ciudad;
	char *graduacion;
	int A;
	int B;
	int C;
	int D;
} Alumno;

void readInfo(Alumno *alumno, char *line);

void readGrades(Alumno *alumno, char *line);

#endif
