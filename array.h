#ifndef ARRAY_H
#define ARRAY_H 

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct s_int_array
{
    int* data;
    unsigned int length;
}int_array;

extern int_array* int_array_create(int nb_element, int def_value);
extern void int_array_destroy(int_array* array);

extern unsigned int int_array_length(int_array* array);

extern int int_array_min(int_array* array);
extern int int_array_max(int_array* array);

extern int int_array_min_by_index(int_array* array, int index);
extern int int_array_max_by_index(int_array* array, int index);

extern int int_array_find(int_array* array, int value);
extern int int_array_find_by_begin_index(int_array* array, int value, unsigned int begin);


extern void int_array_buble_sort(int_array* array);
extern void int_array_selection_sort(int_array* array);
extern void int_array_insertion_sort(int_array* array);
#endif 