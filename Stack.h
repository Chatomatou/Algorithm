#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct s_stack_int
{
    int data;
    struct s_stack_int* next;
}stack_int;

extern stack_int* stack_int_create(void);
extern void stack_int_destroy(stack_int* stack);

extern stack_int* stack_int_push(stack_int* stack, int value);
extern stack_int* stack_int_pop(stack_int* stack);
extern bool stack_int_empty(stack_int* stack);
extern unsigned int stack_int_size(stack_int* stack);
extern int stack_int_top(stack_int* stack);
#endif 