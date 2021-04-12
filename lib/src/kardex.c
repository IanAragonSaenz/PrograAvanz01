#include "data.h"

void kardex(char *argv[], int argc, Alumno alumnos[], int alumnoC, int vflag, char *ovalue){

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
		printf("Buscando el kardex del alumno con id: %d\n", num);
	}
	
	printf("ID\tNombre       \tCarrera\tCiudad\tGraduacion Aprox\tMateria A\tMateria B\tMateria C\tMateria D\n");
	for(int j = 0; j < alumnoC; j++){
		if(alumnos[j].id == num){
			printf("%d\t%s %s\t%-7s\t%-6s\t%-16s\t%-9.2f\t%-9.2f\t%-9.2f\t%-9.2f\n", alumnos[j].id, alumnos[j].nombre, alumnos[j].apellido, alumnos[j].carrera, alumnos[j].ciudad, alumnos[j].graduacion, alumnos[j].A, alumnos[j].B, alumnos[j].C, alumnos[j].D);
			if(ovalue != NULL){
				fprintf(fp, "%d\t%s %s\t%-7s\t%-6s\t%-16s\t%-9.2f\t%-9.2f\t%-9.2f\t%-9.2f\n", alumnos[j].id, alumnos[j].nombre, alumnos[j].apellido, alumnos[j].carrera, alumnos[j].ciudad, alumnos[j].graduacion, alumnos[j].A, alumnos[j].B, alumnos[j].C, alumnos[j].D);
				fclose(fp);
			}
			return;
		}
	}
	printf("Alumno no fue encontrado, vuelva a intentar\n");
}
