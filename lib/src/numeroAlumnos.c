#include "data.h"

void numeroAlumnos(char *argv[], int argc, Alumno alumnos[], int alumnoC, int vflag, char *ovalue){
	if(vflag == 1){
		printf("Buscando el numero de alumnos\n");
	}

	FILE * fp = NULL;
	if(ovalue != NULL){
		fp = fopen (ovalue,"w");
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
	
	int num = 0;
	if(!strcmp(argv[1], "*")){
		printf("Cantidad de alumnos: %d\n", alumnoC);	
		if(ovalue != NULL){
			fprintf(fp, "Cantidad de alumnos: %d\n", alumnoC);
		}		
	} else {
		for(int i = 0; i < alumnoC; i++){
			if(!strcmp(alumnos[i].carrera, argv[1])){
				if(argc == 3){
					if(!strcmp(alumnos[i].ciudad, argv[2])){
						num++;
					}
				} else {
					num++;
				}
			}
		}
		printf("Cantidad de alumnos: %d\n", num);	
		if(ovalue != NULL){
			fprintf(fp, "Cantidad de alumnos: %d\n", num);
		}
	}
	if(ovalue != NULL){
		fclose(fp);
	}
}
