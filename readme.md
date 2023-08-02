# Benchmarks

Este repositorio es un benchmark que compara haskell y javascript

## Resultados

Las medidas se hicieron bajo un hexa-core 2.9GHz Intel® i5-10400f®, 32 GiB of RAM y 2TB M.2; corriendo en Ubuntu™ 22.10 x86_64 GNU/Linux.

|      | Haskell   | Javascript |
| ---- | --------- | ---------- |
| sort | 0.00022ms | 0.02138ms  |
| find | 0.00023ms | 0.00188ms  |

## Como se midieron las ejecuciones

1. Warmup-stage: Se corre el programa 10.000 veces sin medir el tiempo
2. Measure-stage: Se corre el programa otras 10.000 veces esta vez midiendo el tiempo
3. Calculation: Se calcula el promedio de ejecución, conocido como MEAN, y se devuelve el resultado

## Correlo en tu compu!

### Linux

1. Dale permiso: `chmod +x ./run_benchmarks.sh`
2. Ejecuta el script: `./run_benchmarks.sh`

### Windows

Perdón pero no tenemos idea como se hace en windows :)
