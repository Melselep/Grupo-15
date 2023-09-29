#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

char *obtenerArgumento(int argc, char *argv[], char *rutaArchivo)
{
    if (argc == 1)
    {
        char *string;
        FILE *fs;
        fs = fopen(rutaArchivo, "r");
        fscanf(fs, "%[^\n]", string);
        fclose(fs);
        return string;
    };
    return argv[1];
}

#endif