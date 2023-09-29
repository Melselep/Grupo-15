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
        if (string == "")
        {
            printf("No ingreso ningún argumento");
            exit(1);
        }
        return string;
    };
    return argv[1];
}
