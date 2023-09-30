#ifndef UTILS_INCLUDED_H
#define UTILS_INCLUDED_H

int charAnumero(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    return -1;
};

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
        if (!(caracterPerteceneACadena(s[i], alfabeto)))
            return 0;
        i++;
    }
    return 1;
}

int automata(char *cadena, int cols, int matrizDeTransicion[][cols], int (*getCol)(char), int sizeEstadosFinales, int estadosFinales[sizeEstadosFinales])
{
    int estadosAceptacion[2] = {1, 3};
    int estado = 0;
    int i = 0;
    char c = cadena[i];
    while (c != '\0')
    {
        int col = getCol(c);
        estado = matrizDeTransicion[estado][col];
        c = cadena[++i];
    }
    for (int i = 0; i < 2; i++)
    {
        if (estado == estadosAceptacion[i])
            return 1;
    }
    return 0;
}

#endif