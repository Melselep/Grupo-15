#include <stdio.h>
#include <stdlib.h>
#include "./input.h"
#include "./utils.h"

const char unoalnueve[] = "123456789";
const char masMenosPor[] = "+-*";
char *alfabetoCompleto = "0123456789+-*/";

int calcular(int numero1, int numero2, char operador)
{
    switch (operador)
    {
    case '+':
        return numero1 + numero2;
    case '-':
        return numero1 - numero2;
    case '*':
        return numero1 * numero2;
    case '/':
        return numero1 / numero2;
    default:
    {
        printf("Operación no permitida. Saliendo del programa...");
        exit(1);
    };
    }
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
    return calcular(numero, numero2, operador);
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
    return calcular(acumulado, acumulado2, operador);
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
    char *cadena = obtenerArgumento(argc, argv, "input_2.txt");
    int tablaDeTransicion[5][4] = {
        {3, 4, 4, 1},
        {4, 0, 2, 4},
        {3, 4, 4, 4},
        {3, 0, 2, 3},
        {4, 4, 4, 4},
    };
    int estadosAceptacion[2] = {1, 3};
    if (!formaParteAlfabeto(cadena, alfabetoCompleto))
        printf("Hay caracteres que no pertenecen al alfabeto");
    else if (automata(cadena, 4, tablaDeTransicion, columna, 2, estadosAceptacion))
    {
        printf("El resultado de la cuenta es : %d\n", resolverCuenta(cadena));
    }
    else
        printf("No pertenece al lenguaje");
    return 0;
}
