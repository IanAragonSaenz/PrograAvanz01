#include "data.h"

void fechaGraduacion(char *argv[], int argc, Alumno alumnos[], int alumnoC, int vflag, char *ovalue){
	FILE *fp = NULL;
	if(ovalue != NULL){
		fp = fopen(ovalue,"w");
		if(vflag == 1){
			printf("Abriendo el archivo para escribir el resultado\n");
		}
		if(fp == NULL){
			printf("El archivo no pudo abrir\n");
		}
	}
	
	if(ovalue != NULL){
		if(vflag == 1){
			printf("Escribiendo la consulta en el archivo de salida\n");
		}
		for(int i = 0; i < argc; i++){
			fprintf(fp, "%s ", argv[i]);
		}
		fprintf(fp, "\n");
	}
	
	int num = atoi(argv[1]);
	
	if(vflag == 1){
		printf("Buscando la fecha estimada de graduacion del alumno con id: %d\n", num);
	}
	
	printf("ID\tNombre\tGraduacion\n");
	for(int j = 0; j < alumnoC; j++){
		if(alumnos[j].id == num){
			printf("%d\t%s %s\t%s\n", alumnos[j].id, alumnos[j].nombre, alumnos[j].apellido, alumnos[j].graduacion);
			if(ovalue != NULL){
				fprintf(fp, "%d\t%s %s\t%s\n", alumnos[j].id, alumnos[j].nombre, alumnos[j].apellido, alumnos[j].graduacion);
				fclose(fp);
			}
			return;
		}
	}
	printf("Alumno no fue encontrado, vuelva a intentar\n");
}
