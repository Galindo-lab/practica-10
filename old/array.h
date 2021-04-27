#ifndef ARRAY_H
#define ARRAY_H

typedef struct {
     int *array;                /* direccionde puntero */
     int used;                  /* posisciones usadas */
     int last_position;         /* ultima pocicion utilizada */
     int size;                  /* tamaño de la memoria reservada*/
} Array;

/* Inicializa el array, Función que crea arreglo.
 * @param Array* direccion de una estructura de tipo Array.
 * @param int    tamaño e memoria inicial. */

void init_array(Array*, int);

/* Añade un elemento la final del array
 * @param Array* direccion de una estructura de tipo Array.
 * @param int    valor del nuevo elemento */

void add_array(Array* , int);

/* Añadir un nuevo elemento en algún lugar que se seleccione del
 * arreglo (dentro del límite de elementos de éste)
 * @param Array*   direccion de una estructura de tipo array
 * @param element  valor del nuevo elemento.
 * @param position posicion donde se quiere insertar el nuevo elemento */

/* NOTE: esto se puede optimizar, pero por ahora no tengo tiempo */

void insert_array(Array*, int, int);

/* Eliminar un elemento del arreglo en cierta posición (dentro del límite
 * de elementos de éste).
 * @param Array* direccion de una estructura de tipo array
 * @param int    posición que se desea eliminar*/

void remove_array(Array*, int);

/* Imprimir elementos.
 * @param Array* direccion de una estructura de tipo array */

void diplay_array(Array*);

/* Reemplazar los elementos que coincidan con el valor dado por el
 * usuario, por otro valor otorgado.
 * @param Array* direccion de una estructura de tipo array
 * @param int_a  elemento a buscar
 * @param int_b  elemento por el cual sera reemplazado*/

void replace_element_array(Array*, int, int);

/* Función para vaciar el bloque que contiene los valores, liberando la
 * memoria ocupada.
 * @param Array* direccion de una estructura de tipo array */

void free_array(Array*);

/* Realizar función que hace una copia de la estructura arreglo y la
 * regresa como salida de la función.
 * @param Array* direccion de una estructura de tipo array
 * @return Array una capia exacta del array parametro*/

Array copy_array(Array*);

/* Realizar función “únicos”, que dado un arreglo regresa un arreglo
 * nuevo con los valores no repetidos de este.
 * @param Array* direccion de una estructura de tipo array
 * @return Array con los elementos sin repeticion*/

Array eliminate_duplicates_array(Array*);

#endif
