#ifndef _TMat2dh_
#define _TMat2dh_

#include <stdio.h>
#include <stdlib.h>
//Matriz de inteiros.

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#define MATRIZ_NOT_ALlOCATED -6

typedef struct matriz matriz;

matriz *matriz_create(int nRow, int nCol);
int matriz_free(matriz *auxiliar);
int matriz_set(matriz *auxiliar, int i, int j, int val);
int matriz_get(matriz *auxiliar, int i, int j, int *val);
short matriz_print(matriz *mat);

int matriz_get_dados(matriz *mat, int *column, int *line);
int matriz_get_column(matriz *mat, int *column);
int matriz_get_line(matriz *mat, int *line);

#endif