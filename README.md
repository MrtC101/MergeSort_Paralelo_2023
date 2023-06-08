# MergeSort con MPI

### Generación datos de entrada

```sh
python generator.py [cantidad_de_listas] [cantidad_de_elementos] [elemento_máximo]
```

Salida: `input.data`

Más info: `python generator.py --help`

### Ejecución `Secuential`

Datos de entrada, nombre del archivo hardcodeado (debe estar en /data)

```sh
cd src/secuential
make
```

Salida: `secuential.x`

### Ejecución `Parallel`

```sh
cd src/parallel
make
```

Salida: `mergempi.x`

Ejecución:

```sh
mpirun -np [numero_de_procesos] ./mergempi.x
```
