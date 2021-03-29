#ifndef _DATA_H
#define _DATA_H

struct Alumno{
	int id;
	char *nombre;
	char *carrera;
	char *ciudad;
	char *graduacion;
	int A;
	int B;
	int C;
	int D;
};

void readInfo(struct Alumno *alumno, char *line);

void readGrades(struct Alumno *alumno, char *line);

#endif
