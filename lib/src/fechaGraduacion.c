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
