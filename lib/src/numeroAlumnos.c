void numeroAlumnos(char *argv[], int argc, Alumno alumnos[], int alumnoC, int vflag, char *ovalue){
	if(vflag == 1){
		printf("Buscando el numero de alumnos\n");
	}

	int num = 0;
	if(!strcmp(argv[1], "*")){
		printf("Cantidad de alumnos: %d\n", alumnoC);			
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
	}
}
