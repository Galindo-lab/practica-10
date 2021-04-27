
#include <stdio.h>
#include <stdlib.h>

#include "headers/array.h"



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
