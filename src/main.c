#include "../lib/src/data.h"
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv){
  int vflag = 0;
  char *ovalue = NULL;
  int c, size = 10;
  int i = 0;
  Alumno *alumnos = malloc(size * sizeof(*alumnos));

  while ((c = getopt (argc, argv, "hvo:")) != -1)
    switch (c)
      {
      case 'h':
        printHelp();
        return 0;
      case 'v':
        vflag = 1;
        break;
      case 'o':
        ovalue = optarg;
        break;
      case '?':
        if (optopt == 'o') //prints error when there is no value given to -o
          fprintf (stderr, "Opcion -%c requiere un argumento.\n", optopt);
        else // prints error when the option given doesnt exist
          fprintf (stderr, "Opcion`-%c' no existe.\n", optopt);
      default:
        return 1;
     }

  if(argc-optind != 2){
  	printf("No todos los archivos necesarios fueron dados como argumento\n");
  	return 1;
  }
  
  for (int index = optind; index < argc; index++){
    FILE *file;
    
    file = fopen(argv[index], "r");
    if(file == NULL){
    	printf("El archivo %s no existe o no se encontro.", argv[index]);
    	return 1;
    }
    
    if(vflag == 1){
		printf("leyendo datos de archivos\n");
    }
      
    while(!feof(file)){
      if(i >= size){
      	size += 10;
      	alumnos = (Alumno *)realloc(alumnos, (size * sizeof(Alumno)));
      }
      
      if(index == optind){
    	fscanf(file, "%d %s %s %s %s %s", &alumnos[i].id, alumnos[i].nombre, alumnos[i].apellido, alumnos[i].carrera, alumnos[i].ciudad, alumnos[i].graduacion);
		i++;
      } else {
		int id = 0;
      	fscanf(file, "%d", &id);
		for(int j = 0; j < size; j++){
	 		if(alumnos[j].id == id){
	  			fscanf(file, "%d%d%d%d", &alumnos[j].A, &alumnos[j].B, &alumnos[j].C, &alumnos[j].D);
	  			break;
	 		}
		}
      }
     }
  }
  
  int option = 0;
  if(vflag == 1){
     printf("Entrando al menu\n");
  }
  while(1){
  	printMenu();
  	scanf("%d", &option);
  	char line[80];
  	char *newLine;
  	char* consulta[4];
  	int consulta_i = 0;
  	
  	if(vflag == 1){
     	printf("Procesando la opcion\n");
  	}
  	
  	switch(option){
  		case 0:
  			printf("El programa ha terminado\n");
  			return 0;
  		case 1:
  			printf("ID\tNombre\n");
  			for(int j = 0; j < i-1; j++){
  				printf("%d\t%s %s\n", alumnos[j].id, alumnos[j].nombre, alumnos[j].apellido);
  			}
  			break;
  		case 2:
  			printf("ID\tNombre\tCarrera\tCiudad\tGraduacion Aprox\n");
  			for(int j = 0; j < i-1; j++){
  				printf("%d\t%s %s\t%s\t%s\t%s\n", alumnos[j].id, alumnos[j].nombre, alumnos[j].apellido, alumnos[j].carrera, alumnos[j].ciudad, alumnos[j].graduacion);
  			}
  			break;
  		case 3:
  			printf("ID\tNombre\tMateria A\tMateria B\tMateria C\tMateria D\n");
  			for(int j = 0; j < i-1; j++){
  				printf("%d\t%s %s\t%d\t%d\t%d\t%d\n", alumnos[j].id, alumnos[j].nombre, alumnos[j].apellido, alumnos[j].A, alumnos[j].B, alumnos[j].C, alumnos[j].D);
  			}
  			break;
  		case 4:
  			printf("Introduzca su consulta: \n");
  			fflush(stdin);
  			fflush(stdout);
  			while ( (c = getchar()) != '\n' && c != EOF ) { }
  			fgets(line, 80, stdin);
  			newLine = strtok(line, " ");
  			while(newLine != NULL){
  				consulta[consulta_i++] = newLine;
  				newLine = strtok(NULL, " \n");
  			}
  			/*
  			for(int j = 0; j < consulta_i; j++){
  				printf("%d\t%s\t%d\n", j, consulta[j], i);
  			}
  			*/
  			if(vflag == 1){
     			printf("Procesando la consulta\n");
  			}
  			
  			consultaQ(consulta, consulta_i, alumnos, i-1, vflag, ovalue);
  			
  			break;
  		default: 
  			printf("Opcion no especificada, se cerrara el programa\n");
  			return 1;
  	}
  }
  
  return 0;
}
