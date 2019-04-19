#include "Queue.h"


queue_int* queue_int_create(void)
{
    return NULL;
}
void queue_int_destroy(queue_int* queue)
{
    while(queue != NULL)
        queue = queue_int_dequeue(queue);
}

queue_int* queue_int_enqueue(queue_int* queue, int value)
{
    queue_int* element = malloc(sizeof(*element));

    if(element == NULL)
        return NULL;

    
    if(queue == NULL)
    {
        element->data = value;
        element->next = queue;    
    }
    else 
    {
        while(queue->next->next != NULL)
        {
            queue = queue->next;
        }

        element->data = value;
        element->next = queue;
    }        
    return element;
}
queue_int* queue_int_dequeue(queue_int* queue)
{
    assert(queue != NULL && "queue_int* queue is NULL.");

    while(queue->next->next != NULL)
        queue = queue->next;

    free(queue->next);
    queue->next = NULL;
    return queue;
}
unsigned int queue_int_size(queue_int* queue)
{
    unsigned int i = 0;

    while(queue != NULL)
        queue = queue->next;

    return i;
}

int queue_int_front(queue_int* queue)
{
    assert(queue != NULL && "queue_int* queue is NULL.");

    return queue->data;
}