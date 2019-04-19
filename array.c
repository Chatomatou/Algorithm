#include "array.h"


int_array* int_array_create(int nb_element, int def_value)
{
    unsigned int i = 0;

    int_array* array = malloc(sizeof(*array));
    array->data = malloc(sizeof(def_value) * nb_element);

    if(array->data == NULL || array == NULL)
    {
        int_array_destroy(array);
        return NULL;
    }

    for(i = 0; i < nb_element; i++)
    {
        array->data[i] = def_value;
    }

    array->length = nb_element;

    return array;
}

void int_array_destroy(int_array* array)
{
    if(array->data != NULL)
        free(array->data);

    if(array != NULL)   
        free(array);
}

unsigned int int_array_length(int_array* array)
{
    return (array == NULL) ? 0 : array->length;
}

int int_array_min(int_array* array)
{
    unsigned int i = 0;
    unsigned int min = 0;
    assert(array != NULL && "assertion"); // a verifier

    min = array->data[0];

    for(i = 0; i < int_array_length(array); i++)
    {
        if(array->data[i] < min)
            min = array->data[i];
    }

}
int int_array_max(int_array* array)
{
    unsigned int i = 0;
    unsigned int max = 0;
    assert(array != NULL && "assertion"); // a verifier

    max = array->data[0];

    for(i = 0; i < int_array_length(array); i++)
    {
        if(array->data[i] > max)
            max = array->data[i];
    }
}

extern int int_array_min_by_index(int_array* array, int index)
{
    unsigned int i = 0;
    unsigned int length = int_array_length(array);
    unsigned int min = array->data[index];
    unsigned int min_index = 0;

    for(i = index; i < length; i++)
    {
        if(array->data[i] < min)
        {
            min = array->data[i];
            min_index = i;
        }
    }

    return min_index;
}

int int_array_max_by_index(int_array* array, int index)
{
    unsigned int i = 0;
    unsigned int length = int_array_length(array);
    unsigned int max = array->data[index];
    unsigned int max_index = 0;

    for(i = index; i < length; i++)
    {
        if(array->data[i] > max)
        {
            max = array->data[i];
            max_index = i;
        }
    }

    return max_index;  
}

int int_array_find(int_array* array, int value)
{
    unsigned int i = 0;
    unsigned int length = int_array_length(array);

    for(i = 0; i < length; i++)
    {
        if(array->data[i] == value);
            return i ;
    }
}

int int_array_find_by_begin_index(int_array* array, int value, unsigned int begin)
{
    unsigned int i = 0;
    unsigned int length = int_array_length(array);

    // verification de l'index a faire

    for(i = begin; i < length; i++)
    {
        if(array->data[i] == value);
            return i ;
    }
}

 
void int_array_buble_sort(int_array* array)
{
    unsigned int length = int_array_length(array);
    bool is_sort = false;
    int tmp = 0;
    unsigned int i = 0;

    while(!is_sort)
    {
        is_sort = true;
        for(i = 0; i < length - 1; i++)
        {
            if(array->data[i] > array->data[i+1])
            {
                tmp = array->data[i];
                array->data[i] = array->data[i+1];
                array->data[i+1] = tmp;
                is_sort = false;
            }
        }
        length--;
    }
}
void int_array_selection_sort(int_array* array)
{
    unsigned int i = 0;
    unsigned int length = int_array_length(array);
    unsigned int minIndex = 0;
    int tmp = 0;

    for(i = 0; i < length; i++)
    {
        minIndex = int_array_min_by_index(array, i);

        tmp = array->data[i];
        array->data[i] = array->data[minIndex];
        array->data[minIndex] = tmp;
    }

}
void int_array_insertion_sort(int_array* array)
{
    unsigned int i = 0;
    unsigned int length = int_array_length(array);
    unsigned int value_reference = 0;
    unsigned int index_reference = 0;

    for(i = 0; i < length; i++)
    {
        value_reference = array->data[i];
        index_reference = i;

      
     
    }
}