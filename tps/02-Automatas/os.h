#include <stdio.h>
#include <stdlib.h>

/**
 * Calling this fn makes argument mandatory to run the program.
 * If an argument is not provided, then the program exits
 */
char *obtenerUnSoloArgumento(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("No se ingreso ningun argumento. Salida del programa...\n");
        exit(-1);
    };
    return argv[1];
}