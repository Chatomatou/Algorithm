#include "Stack.h"

stack_int* stack_int_create(void)
{
    return NULL;
}
void stack_int_destroy(stack_int* stack)
{
    while(stack != NULL)
        stack_int_pop(stack);
}

stack_int* stack_int_push(stack_int* stack, int value)
{
    stack_int* element = malloc(sizeof(*element));

    if(element == NULL)
        return stack;
    
    element->data = value;
    element->next = stack;

    return element;
}

stack_int* stack_int_pop(stack_int* stack)
{
    assert(stack != NULL && "stack_int* stack is NULL.");
    stack_int* element_next_save = NULL;
    
    if(stack == NULL)
        return stack_int_create();

    element_next_save = stack->next;
    free(stack);
    stack = element_next_save->next;

    return stack;
}

bool stack_int_empty(stack_int* stack)
{
    return (stack == NULL) ? true : false;
}

unsigned int stack_int_size(stack_int* stack)
{
    unsigned int i = 0;
    while(stack != NULL)
    {
        stack = stack->next;
        i++;
    }
    return i;
}

int stack_int_top(stack_int* stack)
{
    assert(stack != NULL && "stack_int* stack is NULL.");

    return stack->data;
}