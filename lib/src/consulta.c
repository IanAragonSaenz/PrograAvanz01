#include "data.h"
#include <string.h>

void consultaQ(char *argv[], int argc, Alumno alumnos[], int alumnoC, int vflag, char *ovalue){
	if(!strcmp(argv[0], "Kardex")){
		kardex(argv, argc, alumnos, alumnoC, vflag, ovalue);
	} else if(!strcmp(argv[0], "Fecha_estimada_graduacion")){
		
	} else if(!strcmp(argv[0], "Numero_alumnos")){
	
	} else if(!strcmp(argv[0], "Nombre_alumnos")){
	
	} else {
		exit(1);
	}
}

void kardex(char *argv[], int argc, Alumno alumnos[], int alumnoC, int vflag, char *ovalue){
	int num = atoi(argv[1]);
	if(vflag == 1){
		printf("Buscando el kardex del alumno con id: %d\n", num);
	}
	for(int j = 0; j < alumnoC; j++){
		if(alumnos[j].id == num){
			printf("%d\t%s %s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n", alumnos[j].id, alumnos[j].nombre, alumnos[j].apellido, alumnos[j].carrera, alumnos[j].ciudad, alumnos[j].graduacion, alumnos[j].A, alumnos[j].B, alumnos[j].C, alumnos[j].D);
			return;
		}
	}
	printf("Alumno no fue encontrado, vuelva a intentar\n");
}

void fechaGraduacion(char *argv[], int argc, Alumno alumnos[], int alumnoC, int vflag, char *ovalue){
	int num = atoi(argv[1]);
	if(vflag == 1){
		printf("Buscando la fecha estimada de graduacion del alumno con id: %d\n", num);
	}
	for(int j = 0; j < alumnoC; j++){
		if(alumnos[j].id == num){
			printf("%d\t%s %s\t%s\n", alumnos[j].id, alumnos[j].nombre, alumnos[j].apellido, alumnos[j].graduacion);
			return;
		}
	}
	printf("Alumno no fue encontrado, vuelva a intentar\n");
}
