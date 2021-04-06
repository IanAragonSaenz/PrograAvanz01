#include "data.h"

void printMenu(){
    printf("\nElija una opcion: \n");
    printf("1. Mostrar los estudiantes\n");
    printf("2. Mostrar toda la informacion de todos los estudiantes\n");
    printf("3. Mostrar todas las calificaciones de los estudiantes\n");
    printf("4. Hacer una consulta\n");
    printf("Para cerrar el programa elija 0\n");
}

void printHelp(){
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
}
