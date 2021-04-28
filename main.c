
#include <stdio.h>
#include <stdlib.h>

#include "headers/array.h"
#include "headers/estadistica.c"


int main() {
    Array a;
    Array b;

    init_array(&a, 1);

    for(int i = 0; i < 15; i++)
    {
        add_array(&a, 1+ rand()%10 );
    }

    b = copy_array(&a);


    diplay_array(&a);

    printf("minimo: %d\n",minimo(&a));
    printf("maximo: %d\n",maximo(&a));
    printf("media: %f\n",media(&a));
    printf("mediana: %d\n",mediana(&a));
    printf("desviacion: %f\n",desviacion_estandar(&a));

    diplay_array(&a);

    printf("--------------- \n");
    ordenar(&a);
    diplay_array(&a);

    free_array(&a);
    free_array(&b);

    return 0;
}
