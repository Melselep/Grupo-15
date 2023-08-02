# Benchmarks

Este repositorio es un benchmark que compara haskell y javascript

## Resultados

Las medidas se hicieron bajo un hexa-core 2.9GHz Intel® i5-10400f®, 32 GiB de RAM y 2TB M.2; corriendo en Ubuntu™ 22.10 x86_64 GNU/Linux.

-   Haskell
    | Algoritmos | Single shot | Average time |
    | ---------- | ----------- | ------------ |
    | sort | 0.00041ms | 0.00022ms |
    | find | 0.00038ms | 0.00021ms |

-   Javascript
    | Algoritmos | Single shot | Average time |
    | ---------- | ----------- | ------------ |
    | sort | 0.31418ms | 0.02003ms |
    | find | 0.14543ms | 0.00147ms |

## Como se midieron las ejecuciones

Se hacen dos tipos de mediciones:

-   **Single shot**: Se mide el tiempo de la primera ejecución del algoritmo. Esto mide el "cold" performance.
-   **Average Time**: El mismo consiste en:
    1. Warmup-stage: Se corre el programa 10.000 veces sin medir el tiempo.
    2. Measure-stage: Se corre el programa otras 10.000 veces esta vez midiendo el tiempo.
    3. Calculation: Se calcula el promedio de ejecución, y se muestra el resultado.

## Correlo en tu compu!

### Linux

1. Dale permiso: `chmod +x ./run_benchmarks.sh`
2. Ejecuta el script: `./run_benchmarks.sh` o `./run_benchmarks.sh --help` para ver como funciona

### Windows

Si posee wsl o git bash entonces
