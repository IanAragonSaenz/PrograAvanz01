#include "data.h"

void nombreAlumnos(char *argv[], int argc, Alumno alumnos[], int alumnoC, int vflag, char *ovalue){
	if(vflag == 1){
		printf("Buscando el nombre de alumnos\n");
	}
	
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
	
	if(!strcmp(argv[1], "*")){
		printf("ID\tNombre\n");
		for(int j = 0; j < alumnoC; j++){
			printf("%d\t%s %s\n", alumnos[j].id, alumnos[j].nombre, alumnos[j].apellido);
			if(ovalue != NULL){
				fprintf(fp, "%d\t%s %s\n", alumnos[j].id, alumnos[j].nombre, alumnos[j].apellido);
			}
		}
	} else if(!strcmp(argv[1], ">")){
		if(argc != 3){
			printf("Cantidad de datos no dada correctamente, vuelva a intentar\n");
			if(ovalue != NULL){
				fprintf(fp, "Cantidad de datos no dada correctamente, vuelva a intentar\n");
			}
			fclose(fp);
			return;
		}
		
		int num = atoi(argv[2]);
		
		printf("ID\tNombre\n");
		for(int j = 0; j < alumnoC; j++){
			if((alumnos[j].A + alumnos[j].B + alumnos[j].C + alumnos[j].D) / 4.0 > num){
				printf("%d\t%s %s\n", alumnos[j].id, alumnos[j].nombre, alumnos[j].apellido);
				if(ovalue != NULL){
					fprintf(fp, "%d\t%s %s\n", alumnos[j].id, alumnos[j].nombre, alumnos[j].apellido);
				}
			}
		}
	} else if(!strcmp(argv[1], "<")){
		if(argc != 3){
			printf("Cantidad de datos no dada correctamente, vuelva a intentar\n");
			if(ovalue != NULL){
				fprintf(fp, "Cantidad de datos no dada correctamente, vuelva a intentar\n");
			}
			fclose(fp);
			return;
		}
		
		int num = atoi(argv[2]);
		
		printf("ID\tNombre\n");
		for(int j = 0; j < alumnoC; j++){
			if((alumnos[j].A + alumnos[j].B + alumnos[j].C + alumnos[j].D) / 4.0 < num){
				printf("%d\t%s %s\n", alumnos[j].id, alumnos[j].nombre, alumnos[j].apellido);
				if(ovalue != NULL){
					fprintf(fp, "%d\t%s %s\n", alumnos[j].id, alumnos[j].nombre, alumnos[j].apellido);
				}
			}
		}
	} else if(!strcmp(argv[1], "==")){
		if(argc != 3){
			printf("Cantidad de datos no dada correctamente, vuelva a intentar\n");
			if(ovalue != NULL){
				fprintf(fp, "Cantidad de datos no dada correctamente, vuelva a intentar\n");
			}
			fclose(fp);
			return;
		}
		
		int num = atoi(argv[2]);
		
		printf("ID\tNombre\n");
		for(int j = 0; j < alumnoC; j++){
			if((alumnos[j].A + alumnos[j].B + alumnos[j].C + alumnos[j].D) / 4.0 == num){
				printf("%d\t%s %s\n", alumnos[j].id, alumnos[j].nombre, alumnos[j].apellido);
				if(ovalue != NULL){
					fprintf(fp, "%d\t%s %s\n", alumnos[j].id, alumnos[j].nombre, alumnos[j].apellido);
				}
			}
		}
	} else if(!strcmp(argv[1], "!=")){
		if(argc != 3){
			printf("Cantidad de datos no dada correctamente, vuelva a intentar\n");
			if(ovalue != NULL){
				fprintf(fp, "Cantidad de datos no dada correctamente, vuelva a intentar\n");
			}
			fclose(fp);
			return;
		}
		
		int num = atoi(argv[2]);
		
		printf("ID\tNombre\n");
		for(int j = 0; j < alumnoC; j++){
			if((alumnos[j].A + alumnos[j].B + alumnos[j].C + alumnos[j].D) / 4.0 != num){
				printf("%d\t%s %s\n", alumnos[j].id, alumnos[j].nombre, alumnos[j].apellido);
				if(ovalue != NULL){
					fprintf(fp, "%d\t%s %s\n", alumnos[j].id, alumnos[j].nombre, alumnos[j].apellido);
				}
			}
		}
	} else {
		printf("ID\tNombre\n");
		for(int i = 0; i < alumnoC; i++){
			if(!strcmp(alumnos[i].carrera, argv[1])){
				if(argc == 3){
					if(!strcmp(alumnos[i].ciudad, argv[2])){
						printf("%d\t%s %s\n", alumnos[i].id, alumnos[i].nombre, alumnos[i].apellido);
						if(ovalue != NULL){
							fprintf(fp, "%d\t%s %s\n", alumnos[i].id, alumnos[i].nombre, alumnos[i].apellido);
						}
					}
				} else {
					printf("%d\t%s %s\n", alumnos[i].id, alumnos[i].nombre, alumnos[i].apellido);
					if(ovalue != NULL){
						fprintf(fp, "%d\t%s %s\n", alumnos[i].id, alumnos[i].nombre, alumnos[i].apellido);
					}
				}
			}
		}
	}
	if(ovalue != NULL){
		fclose(fp);
	}
}

