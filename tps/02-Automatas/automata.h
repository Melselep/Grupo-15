int automata(char *cadena, int columnas, int tablaDeTransicion[][columnas], int cantidadEstadosAceptacion, int estadosAceptacion[cantidadEstadosAceptacion])
{
    int estado = 0;
    int i = 0;
    char c = cadena[i];
    while (c != '\0')
    {
        estado = tablaDeTransicion[estado][columna(c)];
        c = cadena[++i];
    }
    for (int i = 0; i < cantidadEstadosAceptacion; i++)
    {
        if (estado == estadosAceptacion[i])
            return 1;
    }
    return 0;
}