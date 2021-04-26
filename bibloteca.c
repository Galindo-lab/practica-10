
#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int *array;                /* direccionde puntero */
     int used;                  /* posisciones usadas */
     int last_position;         /* ultima pocicion utilizada */
     int size;                  /* tamaño de la memoria reservada*/
} Array;

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

/* 3. Añadir un nuevo elemento en algún lugar que se seleccione del
 * arreglo (dentro del límite de elementos de éste). */

/* NOTE: esto se puede optimizar, pero por ahora no tengo tiempo */

void insert_array(Array *a, int element, int position)
{
    int mov = a->used - position; /* mov es la candidad de veces que se
                                   * copiara de una posiscion a la pocicion
                                   * anterior */

    /* Sí mov es menor a 0 significa que la posicion seleccionada es mas
     * grande que la cantidad de elementos disponibles en el array
     *
     * Sí mov es 0 se insertara el elemento en la ultima pocicion
     * Ex. si tiene 5 elementos y quiero insertar un elemento en la
     * posicion 5 entonces, 5 - 5
     *
     * Sí mov es mayor a la cantidad de elementos en el arreglo eso
     * significa que el parametro position es negativo */

    if( mov >= 0 && mov <= a->used  )
    {
        add_array(a, a->array[a->last_position]); /* incrementa el tamaño
                                                   * del array y copia el
                                                   * ultimo elemento al
                                                   * final. */
        for(int i = 0; i < mov; i++)
        {
            /* copia el elemento en una posicion anterior hasta llegar a la
             * posicion que se desea rempalzar */
            a->array[ a->last_position-i ] = a->array[ a->last_position-1-i ];
        }

        a->array[position] = element;
    }
    else
    {
        fprintf(stderr, "Fuera de rango!, funcion insert_array\n");
        exit(EXIT_FAILURE);
    }

}

/* 4. Eliminar un elemento del arreglo en cierta posición (dentro del límite
 * de elementos de éste). */

void remove_array(Array *a, int pos)
{
    for(int i = pos; i < a->last_position ; i++){
        a->array[i] = a->array[i+1];
    }

    a->used--;
    a->last_position--;
}

/* 5. Imprimir elementos. */

void diplay_array(Array *a)
{
    printf("   id | value\n");
    printf("------+------\n");
    for(int i = 0 ; i < a->used ; i++)
    {
        printf("%5d | %5d\n",i ,a->array[i]);
    }
    printf("------+------\n");
    printf(" reservado: %d\n", a->size);
    printf("     usado: %d\n", a->used);
    printf("    ultimo: %d\n", a->last_position);
}

/* 6. Reemplazar los elementos que coincidan con el valor dado por el usuario,
 * por otro valor otorgado. */

void replace_element_array(Array *a, int int_a, int int_b)
{
    for(int i = 0;i < a->used;i++)
    {
        if(a->array[i] == int_a)
            a->array[i] = int_b;
    }
}

/* 7. Función para vaciar el bloque que contiene los valores, liberando la
 * memoria ocupada. */

void free_array(Array *a)       /* libera el array */
{
     free(a->array);            /* libera la memoria */
     a->array = NULL;           /* el puntero se le indica que deje de
                                 * señalar esa pocicion de memoria */

     a->used = a->size = 0;     /* se cambia el tamaño a 0 y la memoria
                                 * usada a 0 */
     a->last_position = 0;
}

/* 8. Realizar funci ón que hace una copia de la estructura arreglo y la
 * regresa como salida de la función. */

Array copy_array(Array *a)
{
    Array cpy;
    init_array(&cpy,a->size);

    for(int i = 0; i < a->used; i++)
    {
        add_array(&cpy, a->array[i]);
    }

    return cpy;
}

/* 9. Realizar función “únicos”, que dado un arreglo regresa un arreglo
 * nuevo con los valores no repetidos de este. */

Array eliminate_duplicates_array(Array *a)
{
    Array l;                    /* lista de repetidos */
    init_array(&l,1);
    int a_size = a->used;

    if(a_size > 0)
    {
        add_array(&l, a->array[0]); /* añade el primer elemento a la lista
                                     * para tener algo para comparar*/
        while(a_size--)
        {
            for(int i = 0; i < l.used; i++)
            {
                /* compara que no se repitan los elementos del array */
                if( a->array[a_size] == l.array[i] )
                {
                    break;      /* sí se repiten se detiene el bucle */
                }
                else if( i+1 >= l.used )
                {
                    /* si se acaban las itineraciones se agrega a
                     * la lista */
                    add_array(&l, a->array[a_size]);
                }

            }
        }

    }
    else
    {
        fprintf(stderr, "Fuera de rango!, funcion eliminate_duplicates_array\n");
        exit(EXIT_FAILURE);
    }

    return l;

}







int main() {
    Array a;
    Array b;

    init_array(&a, 1);

    for(int i = 0; i < 15; i++)
    {
        add_array(&a, 1);
    }

    insert_array(&a, 10, 2);
    remove_array(&a, 2);
    insert_array(&a, 100, 2);
    replace_element_array(&a,0,100);

    b = eliminate_duplicates_array(&a);

    printf("\narray a:\n");
    diplay_array(&a);
    printf("\n\narray b:\n");
    diplay_array(&b);
    free_array(&a);
    free_array(&b);

    return 0;
}
