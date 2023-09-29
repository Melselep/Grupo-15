#include <stdio.h>
#include <stdlib.h>
#include "./os.h"

const char unoalnueve[10] = "123456789";
const char masMenosPor[4] = "+-*";
char *alfabetoCompleto = "0123456789+-*/";

int caracterPerteceneACadena(char caracter, const char *cadena)
{
    unsigned i = 0;
    while (cadena[i] != '\0')
    {
        if (caracter == cadena[i])
            return 1;
        i++;
    }
    return 0;
}

int formaParteAlfabeto(char *s, char *alfabeto)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (!(caracterPerteceneACadena(s[i], alfabetoCompleto)))
            return 0;
        i++;
    }
    return 1;
}

int columna(char c)
{
    if (caracterPerteceneACadena(c, unoalnueve))
        return 0;
    if (caracterPerteceneACadena(c, masMenosPor))
        return 1;
    if (c == '/')
        return 2;
    if (c == '0')
        return 3;
}

int automata(char *cadena)
{
    const int tablaDeTransicion[5][4] = {
        {3, 4, 4, 1},
        {4, 0, 2, 4},
        {3, 4, 4, 4},
        {3, 0, 2, 3},
        {4, 4, 4, 4},

    };
    int estadosAceptacion[2] = {1, 3};
    int estado = 0;
    int i = 0;
    char c = cadena[i];
    while (c != '\0')
    {
        int col = columna(c);
        printf("%c \n", col);
        estado = tablaDeTransicion[estado][col];
        c = cadena[++i];
        if (estado == 4)
        {
            return 0;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        if (estado == estadosAceptacion[i])
            return 1;
    }

    return 0;
}

int charAnumero(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    return -1;
};

int combinarNumeros(int number1, int number2)
{
    return (number1 * 10 + number2);
}

int obtenerNumero(char *cadena, int *i)
{
    int numeroCompleto = charAnumero(cadena[(*i)]);
    while (1)
    {
        int numeroSiguiente = charAnumero(cadena[++(*i)]);
        if (numeroSiguiente == -1)
            return numeroCompleto;
        numeroCompleto = combinarNumeros(numeroCompleto, numeroSiguiente);
    }
}

int multiplicacionOdivision(char *cadena, int *i, int numero)
{
    char operador = cadena[*i];
    int resultado;
    (*i)++;
    int numero2 = obtenerNumero(cadena, i);
    if (operador == '*')
    {
        resultado = numero * numero2;
    }
    else
    {
        resultado = numero / numero2;
    }
    return resultado;
}

int sumaOresta(char *cadena, int *i, int acumulado)
{
    char operador = cadena[*i];
    (*i)++;
    int acumulado2 = obtenerNumero(cadena, i);
    int resultado;
    while (cadena[*i] == '*' || cadena[*i] == '/')
    {
        acumulado2 = multiplicacionOdivision(cadena, i, acumulado2);
    }
    if (operador == '+')
    {
        resultado = acumulado + acumulado2;
    }
    else
    {
        resultado = acumulado - acumulado2;
    }
    return resultado;
}

int resolverCuenta(char *cadena)
{
    int i = 0;
    int acumulado, numero;
    while (cadena[i] != '\0')
    {
        numero = charAnumero(cadena[i]);
        if (numero != -1)
        {
            acumulado = obtenerNumero(cadena, &i);
        }
        while (cadena[i] == '*' || cadena[i] == '/')
        {
            acumulado = multiplicacionOdivision(cadena, &i, acumulado);
        }
        if (cadena[i] == '+' || cadena[i] == '-')
        {
            acumulado = sumaOresta(cadena, &i, acumulado);
        }
    }
    return acumulado;
}

int main(int argc, char *argv[])
{
    char *cadena = obtenerUnSoloArgumento(argc, argv);
    int a = columna('/');
    printf("devu %d\n", a);
    if (!formaParteAlfabeto(cadena, alfabetoCompleto))
        printf("Hay caracteres que no pertenecen al alfabeto");
    if (automata(cadena))
    {
        // int resultadoDeOperacion = resolverCuenta(cadena);
        printf("El resultado de la cuenta es : %d\n", 1);
    }
    else
        printf("No pertenece al lenguaje");
    return 0;
}
