# Proyecto de Almacenamiento en Árbol B para 1 Millón de Datos `float`

Este proyecto implementa un árbol tipo B para almacenar eficientemente un conjunto de **1 millón de datos** de tipo `float`, utilizando una estructura con un máximo de 4 llaves por nodo. Este tipo de estructura es útil para gestionar grandes cantidades de datos en aplicaciones donde se requiere acceso rápido y almacenamiento eficiente.

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
