# **Tarea de Searching Avanzada**

## **Integrantes**

+ Luis David Solano Santamaría - C17634
+ Angie Sofía Solís Manzano - C17686
+ Emilia María Víquez Mora - C18625


## **Algoritmos implementados**

Se realizó una implementación de los siguientes algoritmos:

1. Breadth First Search (BFS)
2. Greedy Breadth First Search
3. Iterative Deep Search (IDS)
4. Iterative Deep Search* (IDS*)

Con el propósito de resolver un 8 puzzle recibido como entrada, donde se considera como solución el siguiente estado:

|   |   |   |
|---|---|---|
|  | 1 | 2 |
| 3 | 4 | 5 |
| 6 | 7 | 8 |


## **Requerimientos**

El programa fue realizado y comprobado con `g++ 11.4.0` en el sistema operativo `Ubuntu 22.04.3 LTS`.

Para encontrar su versión de `g++` puede ejecutar el siguiente comando:

```
  g++ --version
```

## **Instrucciones de compilación**

Para compilar se debe encontrar dentro de la carpeta `src` y ejecutar el siguiente comando:

```
  g++ -o program *.cpp
```

Esto va a ejecutar un ejecutable con el nombre `program`.

## **Instrucciones de ejecución**

Una vez generado el ejecutable, puede ejecutarlo de la siguiente manera:

```
  ./program [initial_state] [measure_time]
```

Donde los parámetros:

1. `initial_state` representa el estado inicial para el programa, escrito utilizando un 0 para representar el espacio vacío.
2. `measure_time` representa si se desea observar las mediciones de tiempo, en caso de que sí se manda un 1.

## **Ejemplo de ejecución**

```
  ./program 142358067 1

  Breadth-First Algorithm _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
Solution printed from end to start:

_ 1 2
3 4 5
6 7 8


1 _ 2
3 4 5
6 7 8


1 4 2
3 _ 5
6 7 8


1 4 2
3 5 _
6 7 8


1 4 2
3 5 8
6 7 _


1 4 2
3 5 8
6 _ 7


1 4 2
3 5 8
_ 6 7
Time taken in breadth-first: 0.00073742   memory used:  3760


Greedy Breadth-First Algorithm _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
Solution printed from end to start:

_ 1 2
3 4 5
6 7 8


1 _ 2
3 4 5
6 7 8


1 4 2
3 _ 5
6 7 8


1 4 2
3 5 _
6 7 8


1 4 2
3 5 8
6 7 _


1 4 2
3 5 8
6 _ 7


1 4 2
3 5 8
_ 6 7
Time taken in greedy breadth-first: 6.2166e-05   memory used:  288
IDS Algorithm _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
Solution printed from start to end:

1 4 2
3 5 8
_ 6 7

1 4 2
3 5 8
6 _ 7

1 4 2
3 5 8
6 7 _

1 4 2
3 5 _
6 7 8

1 4 2
3 _ 5
6 7 8

1 _ 2
3 4 5
6 7 8

_ 1 2
3 4 5
6 7 8
Time taken in IDS: 0.00134278   memory used:  224


IDS* Algorithm _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
Solution printed from start to end:

1 4 2
3 5 8
_ 6 7

1 4 2
3 5 8
6 _ 7

1 4 2
3 5 8
6 7 _

1 4 2
3 5 _
6 7 8

1 4 2
3 _ 5
6 7 8

1 _ 2
3 4 5
6 7 8

_ 1 2
3 4 5
6 7 8
Time taken in IDS*: 0.000974725   memory used:  224
```
