#include "../lib/src/data.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
        printf("Este programa lee varios archivos con la informacion de estudiantes y permite el uso de queries estructurados.\n");
        printf("Algunas opciones a usar:\n");
        printf("-h\t\tImprime la guia de ayuda\n");
        printf("-v\t\tMuestra como se van ejecutando varias partes del programa\n");
        printf("-o\t\tImprime los resultados en un archivo dado como argumento\n");
        printf("Ejemplos de uso:\n");
        printf("./programa -h\n");
        printf("./programa archivo1.txt archivo2.txt\n");
        printf("./programa archivo1.txt -v archivo2.txt\n");
        printf("./programa archivo1.txt -h archivo2.txt\n");
        printf("./programa archivo1.txt -o salida.txt archivo2.txt\n");
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
  
  char *line = NULL;
  size_t len = 0;
  size_t readLen = 0;
  int option = 0;
  while(1){
  	printMenu();
  	scanf("%d", &option);
  	switch(option){
  		case 1:
  			printf("ID\tNombre\n");
  			for(int j = 0; j < i; j++){
  				printf("%d\t%s %s", alumnos[j].id, alumnos[j].nombre, alumnos[j].apellido);
  			}
  			break;
  		case 2:
  			break;
  		case 3:
  			break;
  		default: 
  			printf("Opcion no especificada, se cerrara el programa\n");
  			return 1;
  	}
  }
  
  return 0;
}
