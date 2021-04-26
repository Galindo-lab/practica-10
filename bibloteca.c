
#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int *array;                /* direccionde puntero */
     int used;                  /* posisciones usadas */
     int last_position;         /* ultima pocicion utilizada */
     int size;                  /* tamaño de la memoria reservada*/
} Array;


void diplay_array(Array *a)
{
    for(int i = 0 ; i < a->used ; i++)
    {
        printf("%d - %d\n",i ,a->array[i]);
    }
}


/* 1. Función que crea arreglo con N ceros. */

void init_array(Array *a, int initialSize)
{
     a->array = (int*) malloc( initialSize * sizeof(int) );
     a->size = initialSize;
     a->last_position = 0;
     a->used = 0;
}


/* 2. Añadir nuevo elemento al final */

void add_array(Array *a, int element)
{
     if(a->used == a->size)     /* cuando reservamos memoria no se usa toda
                                 * al mismo tiempo, pero para evitar
                                 * reservar memoria incesesaria revisamos
                                 * si lo elementos en el array han sido
                                 * utilizados */
     {
          a->size *= 2;
          a->array = realloc( a->array, a->size * sizeof(int) );
     }

     a->last_position = a->used;
     a->array[a->used++] = element;
}

/* 3. Añadir un nuevo elemento en algún lugar que se seleccione del arreglo */
/* (dentro del límite de elementos de éste). */

void insert_array(Array *a, int element, int position)
{
    int mov = a->used - position; /* mov es la candidad de veces que se copiara
                                   * de una posiscion a la pocicion anterior */

    /* Sí mov es menor a 0 significa que la posicion seleccionada es mas
     * grande que la cantidad de elementos disponibles en el array
     *
     * Sí mov es 0 se insertara el elemento en la ultima pocicion
     * Ex. si tiene 5 elementos y quiero insertar un elemento en la
     * posicion 5 entonces, 5 - 5
     *
     * Sí mov es mayor a la cantidad de elementos en el arreglo eso
     * significa que el parametro position es negativo */

    if( mov < 0 && mov > a->used )
    {
        add_array(a, a->array[a->last_position]); /* incrementa el tamaño
                                                   * del array y copia el
                                                   * ultimo elemento al
                                                   * final. */
        for(int i = 0; i < (mov-1); i++)
        {
            /* copia el elemento en una posicion anterior hasta llegar a la
             * posicion que se desea rempalzar */
            a->array[ a->last_position-i ] = a->array[ a->last_position-1-i ];
        }

        a->array[position] = element;
    }
    else
    {
        exit(1);
    }

}


void free_array(Array *a)       /* libera el array */
{
     free(a->array);            /* libera la memoria */
     a->array = NULL;           /* el puntero se le indica que deje de
                                 * señalar esa pocicion de memoria */

     a->used = a->size = 0;     /* se cambia el tamaño a 0 y la memoria
                                 * usada a 0 */
     a->last_position = 0;
}











int main() {
    Array a;

    init_array(&a, 1);
    printf("a\n");

    for(int i = 0; i < 10; i++)
    {
        add_array(&a, i);
    }

    insert_array(&a, 10, 3);

    diplay_array(&a);
    free_array(&a);

    return 0;
}
