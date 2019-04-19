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
    int i = 0;

    for(i = 0; i < _allocator->length; i++)
    {
        if(_allocator->addrs_mem[i] != NULL)
            free(_allocator->addrs_mem[i]);
    }

    if(_allocator->addrs_mem != NULL)
        free(_allocator->addrs_mem);

    if(_allocator != NULL)
        free(_allocator);
}

void allocator_add_element(allocator* _allocator, void* addr, size_t size)
{   
    size_t i = 0;
    
    if(_allocator->addrs_mem == NULL)
    {
        _allocator->addrs_mem = malloc(sizeof(addr)); 

        if(_allocator->addrs_mem == NULL)
            assert("_allocator->addrs_mem is NULL.");
        
    }
 
    _allocator->addrs_mem[_allocator->length] = malloc(sizeof(addr));

    if(_allocator->addrs_mem[_allocator->length] == NULL)
    {
        for(i = 0; i < _allocator->length; i++)
            free(_allocator->addrs_mem[i]);
        assert("_allocator->addrs_mem[indexes] is NULL.");
     }

    _allocator->addrs_mem[_allocator->length] = addr;
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