#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

char *obtenerArgumento(int argc, char *argv[], char *rutaArchivo)
{
    // Si no se paso un argumento por consola, nos fijamos si lo hizo por archivo
    if (argc == 1)
    {
        char *string = malloc(100); // el archivo puede tener hasta 100 caracteres
        if (!string)
        {
            printf("Error al asignar memoria. Saliendo del programa...");
            exit(1);
        }
        FILE *fs;
        fs = fopen(rutaArchivo, "r");
        if (!fs)
        {
            printf("No se encontró el archivo. Saliendo del programa...");
            exit(1);
        }
        fscanf(fs, "%[^\n]", string);
        fclose(fs);
        if (string[0] == '\0')
        {
            printf("Es necesario que ingrese un argumento (por CLI o por el archivo %s). Saliendo de programa...", rutaArchivo);
            exit(1);
        }
        return string;
    };
    return argv[1];
}

#endif