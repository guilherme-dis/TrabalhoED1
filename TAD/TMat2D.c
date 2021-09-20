
#include "TMat2D.h"
struct matriz
{
    int nRow;
    int nCol;
    int *data;
};

matriz *matriz_create(int nRow, int nCol)
{
    if (nCol < 1 || nRow < 1)
        return NULL;

    matriz *auxiliar;
    auxiliar = malloc(sizeof(matriz));
    if (auxiliar == NULL)
        return NULL;

    auxiliar->nRow = nRow;
    auxiliar->nCol = nCol;
    auxiliar->data = malloc((nCol * nRow) * sizeof(int));
    if (auxiliar->data == NULL)
    {
        free(auxiliar);
        return NULL;
    }
    return auxiliar;
}

int matriz_free(matriz *auxiliar)
{
    if (auxiliar == NULL)
        return INVALID_NULL_POINTER;
    else
    {
        free(auxiliar->data);
        free(auxiliar);
        return SUCCESS;
    }
}

int matriz_set(matriz *auxiliar, int i, int j, int val)
{
    if (auxiliar == NULL)
        return INVALID_NULL_POINTER;
    if (i < 0)
        return OUT_OF_RANGE;
    if (j < 0)
        return OUT_OF_RANGE;
    auxiliar->data[j * auxiliar->nRow + i] = val;
    return SUCCESS;
}
int matriz_get(matriz *auxiliar, int i, int j, int *val)
{
    if (auxiliar == NULL)
        return INVALID_NULL_POINTER;
    if (i < 0)
        return OUT_OF_RANGE;
    if (j < 0)
        return OUT_OF_RANGE;
    *val = auxiliar->data[j * auxiliar->nRow + i];
    return SUCCESS;
}


short matriz_print(matriz *mat)
{
    if (mat == NULL)
        return INVALID_NULL_POINTER;
    int aux;
    for (int i = 0; i < mat->nRow; i++)
    {
        for (int j = 0; j < mat->nCol; j++)
        {
            matriz_get(mat, i,j, &aux);
            printf("%d\t ", aux);
        }
        printf("\n");
        
    }
    return INVALID_NULL_POINTER;
}

int matriz_get_dados(matriz *mat, int *column, int *line)
{
    if (mat == NULL || column == NULL || line == NULL)
        return INVALID_NULL_POINTER;
    *column = mat->nCol;
    *line = mat->nRow;
    return SUCCESS;
}

int matriz_get_column(matriz *mat, int *column)
{
    if (mat == NULL || column == NULL)
        return INVALID_NULL_POINTER;
    *column = mat->nCol;
    return SUCCESS;
}
int matriz_get_line(matriz *mat, int *line)
{
    if (mat == NULL || line == NULL)
        return INVALID_NULL_POINTER;
    *line = mat->nRow;
    return SUCCESS;
}