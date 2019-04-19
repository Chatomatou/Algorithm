#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct s_queue_int 
{
    int data;
    struct s_queue_int* next;
}queue_int;

queue_int* queue_int_create(void);
void queue_int_destroy(queue_int* queue);

queue_int* queue_int_enqueue(queue_int* queue, int value);
queue_int* queue_int_dequeue(queue_int* queue);
unsigned int queue_int_size(queue_int* queue);
int queue_int_front(queue_int* queue);

#endif 