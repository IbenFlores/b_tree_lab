# Proyecto de Almacenamiento en Árbol B para 1 Millón de Datos `float`

Este proyecto implementa un árbol tipo B para almacenar eficientemente un conjunto de **1 millón de datos** de tipo `float`, utilizando una estructura con un máximo de 4 llaves por nodo. Este tipo de estructura es útil para gestionar grandes cantidades de datos en aplicaciones donde se requiere acceso rápido y almacenamiento eficiente.

## Integrantes
- Iben Omar Flores Polanco
- Joshua Dvaid Ortiz Rosas

## Descripción

El árbol B es una estructura de datos auto-balanceada que optimiza la búsqueda, inserción y eliminación de datos. En este proyecto, se utiliza un árbol B de **orden 4** (grado 4), donde cada nodo puede almacenar hasta 4 llaves y tener un máximo de 5 hijos. Esta configuración permite que el árbol esté balanceado, minimizando la profundidad del árbol y maximizando la eficiencia en el acceso a los datos.

### Características

- **Orden del Árbol**: Este árbol B es de orden 4:
  - Cada nodo puede almacenar **hasta 4 llaves**.
  - Cada nodo puede tener **hasta 5 hijos**.
- **Capacidad de Datos**: Diseñado para almacenar **1 millón de valores** de tipo `float`.
- **Operaciones Implementadas**:
  - **Inserción** de valores `float` en el árbol, asegurando que el árbol se mantenga balanceado mediante el método `split` cuando un nodo excede el número máximo de llaves.
  - **Búsqueda** de un valor específico dentro del árbol B, recorriendo de forma eficiente los nodos y sus hijos.

## Uso

### Compilación

Para compilar el código, asegúrate de tener instalado un compilador de C como `gcc`. Puedes compilar el proyecto ejecutando el siguiente comando:

```bash
gcc main.c b_tree.c -o b_tree_program
```
## Informe

### Informe de pruebas

En el código realizado se probó en los 3 casos pedidos en el documento GitHub, sobre la comparación experimental de los tiempos de ejecución cuando usamos diferentes valores de B, osea la variable "MAX_KEYS", MAX_KEYS=2, MAX_KEYS=3, MAX_KEYS=4 Y MAX_KEYS=5, por ejemplo cuanto demora la carga de datos, cuando tiempo demora buscar la misma llave en los tres árboles.

#### MAX_KEYS=2

En MAX_KEYS=2 debido a una falla en segementación producida por el método split child que no separa correctamente los datos, ocurre esta falla: [1]    15207 segmentation fault  ./output, en este caso y en otros parecidos cuando el número de llaves a a tratar es de números pares, y en este caso debido a eso solo llega a cargar 8 datos.

#### MAX_KEYS=3

En MAX_KEYS=3 debido a que el método split child si funciona en numeros de llaves de valor impar como en este caso:
Compilación:
Carga completa del archivo en el B-tree. Tiempo de carga: 1.8838509999999999 segundos.
llave 0.546430 encontrada
llave 0.019913 no encontrada
llave 0.875243 encontrada
Tiempo de búsqueda: 0.0000050000000000 segundos

- En carga de datos al probar con el millón de datos tarda apróximadamente un total de 2 segundos en realizar la carga de todos los datos.
- En la búsqueda al probar un total de 3 veces, en total de 3 a 5 millonésimas de segundos en buscar las llaves.

#### MAX_KEYS=4

En MAX_KEYS=4 debido a la misma falla en segementación producida por el método split child que no separa correctamente los datos, ocurre esta falla: [1]    15207 segmentation fault  ./output, en este caso y en otros parecidos como se dijo anteriormente cuando el número de llaves a tratar es de números pares, y en este caso debido a eso solo llega a cargar 15 datos.

#### MAX_KEYS=5

En MAX_KEYS=5 debido a que el método split child igual que en MAX_KEYS=3, si funciona en numeros de llaves de valor impar como en este caso:
Carga completa del archivo en el B-tree. Tiempo de carga: 1.7298370000000001 segundos.
llave 0.546430 encontrada
llave 0.019913 no encontrada
llave 0.875243 encontrada
Tiempo de búsqueda: 0.0000040000000000 segundos

- En carga de datos al probar con el millón de datos tarda apróximadamente un total de 2 segundos en realizar la carga de todos los datos.
- En la búsqueda al probar un total de 3 veces, en total de 3 a 5 millonésimas de segundos en buscar las llaves.

Esto similar al caso MAX_KEYS=3.
