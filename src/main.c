//#include "../lib/src/data.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){
  int vflag = 0;
  char *ovalue = NULL;
  int c;

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
        printf("./programa archivo1.txt archivo2.txt\n")'
        pritnf("./programa archivo1.txt -v archivo2.txt\n");
        pritnf("./programa archivo1.txt -h archivo2.txt\n");
        pritnf("./programa archivo1.txt -o salida.txt archivo2.txt\n");
        return 0;
      case 'v':
        vflag = 1;
        break;
      case 'o':
        ovalue = optarg;
        break;
      case '?':
        if (optopt == 'o') //prints error when there is no value given to -o
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else // prints error when the option given doesnt exist
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
      default:
        return 1;
     }

  for (int index = optind; index < argc; index++)
    //read each file with arg[index]
  return 0;
}
