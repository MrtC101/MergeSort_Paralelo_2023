# MergeSort con MPI

### Generación datos de entrada

```sh
python generator.py [cantidad_de_listas] [cantidad_de_elementos] [elemento_máximo]
```

Salida: `input.data`

Más info: `python generator.py --help`

### Ejecución `Secuential`

Datos de entrada hardcodeados (deben estar en /data)

```sh
cd src/secuential
make
```

Salida: `secuential.x`
