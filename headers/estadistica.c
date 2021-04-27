#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdio.h>
#include <stdlib.h>

#include "array.h"

float suma(Array *a) /* sumatoria */
{
    float s = 0;
    for(int i = 0 ; i < a->used ; i++)
    {
        s += (float)a->array[i];
    }
    return s;
}

int upward_filter(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

Array ordenar_cpy(Array *a)
{
    Array cpy = copy_array(a);
    qsort(cpy.array, cpy.used, sizeof(int), &upward_filter);
    return cpy;
}

/* ordenar de forma ascendente */
void ordenar(Array *a)
{
    qsort(a->array, a->used, sizeof(int), &upward_filter);
}

/* mínimo */
int minimo(Array *a)
{
    Array b = ordenar_cpy(a);
    return b.array[b.used];
}

/* máximo */
int maximo(Array *a)
{
    Array b = ordenar_cpy(a);
    return b.array[0];
}

/* media */
float media(Array *a)
{
    float s = suma(a);
    return s/a->used;
}


/* mediana */
/* desviación estándar */


#endif
