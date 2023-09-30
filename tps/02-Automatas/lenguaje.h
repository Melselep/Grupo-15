#ifndef LANGUAGE_INCLUDED_H
#define LANGUAGE_INCLUDED_H

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

#endif