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
        free(_allocator->addrs_mem);

    if(_allocator != NULL)
        free(_allocator);
}

void allocator_add_element(allocator* _allocator, void* addr, size_t size)
{
    assert(_allocator != NULL && "allocator* _allocator is NULL.");

    _allocator->bytes_allocated += size; 

    if(_allocator->addrs_mem == NULL)
    {
        _allocator->addrs_mem = malloc(sizeof(addr));   
    }
    else 
    {
        _allocator->addrs_mem = realloc(_allocator->addrs_mem, sizeof(addr));
    }

    // todo : allocation tableau 2D
    //_allocator->addrs_mem[_allocator->length] = &addr;
    _allocator->length++;
}

void allocator_display(allocator* _allocator)
{
    size_t i = 0;

    for(i = 0; i < _allocator->length; i++)
    {
        if(i % 4 == 0)
            printf("\n");
        
        printf("%p\t", _allocator->addrs_mem[i]);
     }
}