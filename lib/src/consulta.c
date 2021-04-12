#include "data.h"

void consultaQ(char *argv[], int argc, Alumno alumnos[], int alumnoC, int vflag, char *ovalue){

	if(argc < 2){
		printf("La consulta no tiene suficientes datos, vuelva a intentar\n");
		return;
	}
	
	if(!strcmp(argv[0], "Kardex")){
		kardex(argv, argc, alumnos, alumnoC, vflag, ovalue);
	} else if(!strcmp(argv[0], "Fecha_estimada_graduacion")){
		fechaGraduacion(argv, argc, alumnos, alumnoC, vflag, ovalue);
	} else if(!strcmp(argv[0], "Numero_alumnos")){
		numeroAlumnos(argv, argc, alumnos, alumnoC, vflag, ovalue);
	} else if(!strcmp(argv[0], "Nombre_alumnos")){
		nombreAlumnos(argv, argc, alumnos, alumnoC, vflag, ovalue);
	} else {
		exit(1);
	}
	
	if(vflag == 1){
		printf("Consulta finalizada\n");
	}
}

