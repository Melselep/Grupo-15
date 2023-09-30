#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "./input.h"
#include "./utils.h"

const char unoalsiete[7] = "1234567";
const char ochoynueve[2] = "89";
const char letrasHexa[13] = "abcdefABCDEF";
char *alfabetoCompleto = "0123456789abcdefABCDEFx$";

int columna(char c)
{
    if (c == '0')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (caracterPerteceneACadena(c, unoalsiete))
        return 2;
    if (caracterPerteceneACadena(c, ochoynueve))
        return 3;
    if (caracterPerteceneACadena(c, letrasHexa))
        return 4;
    if (c == 'x')
        return 5;
    if (c == '$')
        return 6;
}

typedef struct Contadores
{
    int decimales;
    int octales;
    int hexadecimales;
} Contadores;

void conteo(int estado, Contadores *contador)
{
    if (estado == 2 || estado == 3)
        (*contador).decimales++;
    else if (estado == 4 || estado == 5)
        (*contador).octales++;
    else if (estado == 7 || estado == 8)
        (*contador).hexadecimales++;
}

int automataYConteo(char *cadena, Contadores *contador)
{
    const int tablaDeTransicion[10][7] = {
        {3, 1, 2, 2, 9, 9, 9},
        {9, 9, 2, 2, 9, 9, 9},
        {2, 9, 2, 2, 9, 9, 0},
        {4, 9, 5, 9, 9, 6, 0},
        {9, 9, 9, 9, 9, 9, 0},
        {5, 9, 5, 9, 9, 9, 0},
        {7, 9, 8, 8, 8, 9, 9},
        {9, 9, 9, 9, 9, 9, 0},
        {8, 9, 8, 8, 8, 9, 0},
        {9, 9, 9, 9, 9, 9, 9},
    };
    int estadosAceptacion[5] = {2, 3, 5, 7, 8};
    int estado = 0;
    int i = 0;
    char c = cadena[i];
    while (c != '\0')
    {
        if (c == '$')
        {
            conteo(estado, contador);
        }
        estado = tablaDeTransicion[estado][columna(c)];
        c = cadena[++i];
    }

    conteo(estado, contador);

    for (int i = 0; i < 5; i++)
    {
        if (estado == estadosAceptacion[i])
            return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    char *palabra = obtenerArgumento(argc, argv, "input_1.txt");
    Contadores contador = {0, 0, 0};
    if (!formaParteAlfabeto(palabra, alfabetoCompleto))
    {
        printf("Hay caracteres que no pertenecen al alfabeto\n");
        return 0;
    }
    if (automataYConteo(palabra, &contador))
    {
        printf("El conteo de cada numero es: \ndecimal: %d \noctal: %d\nhexa: %d\n", contador.decimales, contador.octales, contador.hexadecimales);
    }
    else
        printf("No pertenece al lenguaje\n");
    return 0;
}
