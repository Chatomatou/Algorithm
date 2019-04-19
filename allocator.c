#include "allocator.h"

allocator* allocator_init()
{
    allocator* _allocator = malloc(sizeof(*_allocator));

    if(_allocator == NULL);
        return _allocator;
    
    _allocator->addrs_mem = NULL;
    _allocator->length = 0;
    _allocator->bytes_allocated = 0;
}

void allocator_delete(allocator* _allocator)
{
    if(_allocator->addrs_mem != NULL)
        for (size_t i = 0; i < _allocator->length; i++){
            free(*(_allocator->addrs_mem+i));
        }
        free(_allocator->addrs_mem);

    if(_allocator != NULL)
        free(_allocator);
}

void *allocator_get_element(allocator *_allocator, int id)
{
    assert(_allocator != NULL && "allocator* _allocator is NULL.");

    if (id > _allocator->length){
        return NULL;
    }
    
    return *(_allocator->addrs_mem+id);
}

int allocator_add_element(allocator* _allocator, void* addr, size_t size)// return id
{
    assert(_allocator != NULL && "allocator* _allocator is NULL.");
    void *tmp = NULL;

    tmp = malloc(size);

    assert(tmp != NULL && "Variable not allocated !");

    for (size_t i = 0; i < size; i++){
        *(char *)(tmp+i) = *(char *)(addr+i);
    }

    _allocator->bytes_allocated += size; 

    if(_allocator->addrs_mem == NULL)
    {
        _allocator->addrs_mem = malloc(sizeof(addr));
    }
    else 
    {
        _allocator->addrs_mem = realloc(_allocator->addrs_mem, sizeof(addr)*(_allocator->length+1));
    }

    _allocator->addrs_mem[_allocator->length] = tmp;
    _allocator->length++;
    return _allocator->length;
}

void allocator_display(allocator* _allocator)
{
    assert(_allocator != NULL && "allocator* _allocator is NULL.");
    size_t i = 0;

    for(i = 0; i < _allocator->length; i++){
        if(i % 4 == 0)
            printf("\n");
        
        printf("%p\t", (_allocator->addrs_mem+i));
     }
     printf("\n");
}