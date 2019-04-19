#include "tools.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{ 
    int d1 = 0;
    int d2 = 0;
    int d3 = 0;
    int d4 = 0;
    int d5 = 0;

    allocator* allocation_familial_mdr = allocator_init();

    allocator_add_element(allocation_familial_mdr, &d1, sizeof(d1));
    allocator_add_element(allocation_familial_mdr, &d2, sizeof(d2));
    allocator_add_element(allocation_familial_mdr, &d3, sizeof(d3));
    allocator_add_element(allocation_familial_mdr, &d4, sizeof(d4));
    allocator_add_element(allocation_familial_mdr, &d5, sizeof(d5));

    allocator_display(allocation_familial_mdr);

    allocator_delete(allocation_familial_mdr);

   

    return 0;
}

/* 
    int** grid = malloc(sizeof(int*) * 1);

        // cas ou y'a rien de base 
    grid[0] = malloc(sizeof(int*) * 1);
        // cas ou y'a quelque chose
    grid[taille] = malloc(sizeof(int*) * 1);

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            printf("*");
        }
        printf("\n");
    }


    for(int i = 0; i < 10; i++)
    {
        free(grid[i]);
    }


    free(grid);

    */
